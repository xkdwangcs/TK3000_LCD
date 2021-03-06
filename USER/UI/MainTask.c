#include "MainTask.h"
#include "bsp_touch.h"
#include "LCDPara.h"
#include "FileOperate.h"
#include "CMD.h"

//读取到循环数据后引发
LoopDataReadHandler LoopDataReaded;

void TouchCalibrationTask()
{
    GUI_PID_STATE PIDState;
    //GUI_Init();                /* 初始化 */
    TOUCH_Calibration();       /* 四点触摸校准 */
    GUI_CURSOR_Show();         /* 显示鼠标 */
    GUI_SetBkColor(GUI_WHITE); /* 设置背景色 */
    GUI_SetColor(GUI_BLACK);   /* 设置前景色 */
    GUI_Clear();
    GUI_SetFont(&GUI_Font24B_1);
    GUI_DispStringAt("Draw Panel", 0, 0);
    /*
    	连续读取5次，因为emWin的PID输入管理器含有一个FIFO缓冲器，
    默认情况下最多可以保存5个PID事件，下面连续读取5次相当于清空FIFO.
    防止触摸校准的时点击的点显示到画板上面。
    */
    GUI_PID_GetState(&PIDState);
    GUI_PID_GetState(&PIDState);
    GUI_PID_GetState(&PIDState);
    GUI_PID_GetState(&PIDState);
    GUI_PID_GetState(&PIDState);

    while(1)
    {
        GUI_PID_GetState(&PIDState);
        if (PIDState.Pressed == 1)
        {
            GUI_SetPenSize(5);
            /* 为了防止游标不显示或者不跟着移动，这里添加如下函数 */
            GUI_CURSOR_SetPosition(PIDState.x, PIDState.y);
            GUI_DrawPoint(PIDState.x, PIDState.y);
        }
        GUI_Delay(1);
    }
}

//桌面窗口回调函数
static void _cbBkWindow(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
//			GUI_SetBkColor(GUI_BLUE);
//			GUI_Clear();
			break;
		//case 32: //点击焦点控件
        case WM_TOUCH_CHILD:
			//LCDBeep(10); 
			break;
		default:
			WM_DefaultProc(pMsg);
            break;
	}
}

void MainTask(void)
{
    //使能窗口使用内存设备，这样可以有效避免闪烁, 
	//放在GUI_Init前面就包括桌面窗口，如果放在后面就不包括桌面窗口
	//放此处可以重绘掉背景无效窗体
	//WM_SetCreateFlags(WM_CF_MEMDEV); 
	GUI_Init();//初始化emWin/ucGUI
    /*	 关于多缓冲和窗口内存设备的设置说明
	   1. 使能多缓冲是调用的如下函数，用户要在LCDConf_Lin_Template.c文件中配置了多缓冲，调用此函数才有效：
		  WM_MULTIBUF_Enable(1);
	   2. 窗口使能使用内存设备是调用函数：WM_SetCreateFlags(WM_CF_MEMDEV);
	   3. 如果emWin的配置多缓冲和窗口内存设备都支持，二选一即可，且务必优先选择使用多缓冲，实际使用
		  STM32F429BIT6 + 32位SDRAM + RGB565/RGB888平台测试，多缓冲可以有效的降低窗口移动或者滑动时的撕裂
		  感，并有效的提高流畅性，通过使能窗口使用内存设备是做不到的。
	   4. 所有emWin例子默认是开启三缓冲。
	*/
	WM_MULTIBUF_Enable(1);	
	//设置桌面窗口的背景色，会自动重绘
	//WM_SetDesktopColor(GUI_BLUE); 
	//设置桌面窗口的回调函数,当把WM_SetCreateFlags放到GUI_Init()之前时，可以WM_SetDesktopColor替代
	WM_SetCallback(WM_HBKWIN,_cbBkWindow);	
    	
	if(_isTouchCalibration)
	{
		TouchCalibrationTask();
	}	

//    GUI_SetTextAlign(GUI_TA_HORIZONTAL|GUI_TA_LEFT);
//    GUI_SetFont(&GUI_FontHZ16);	
//	GUI_DispStringHCenterAt("16号字库测试@~%￥‘《》？<>&%$#&*，OK!!",5,0);	
//    GUI_SetFont(&GUI_FontHZ24);	
//	GUI_DispStringHCenterAt("24号字库测试@~%￥‘《》？<>&%$#&*，OK!!",5,26);	
//    GUI_SetFont(&GUI_FontHZ32);	
//	GUI_DispStringHCenterAt("32号字库测试@~%￥‘《》？<>&%$#&*，OK!!",5,60);	
//    GUI_SetFont(&GUI_FontHZ40);	
//	GUI_DispStringHCenterAt("40号字库测试@~%￥‘《》？<>&%$#&*，OK!!",5,102);	
    
    bool isExitWhile=false;		
    GUI_SetFont(&GUI_FontHZ24);	
    GUI_SetTextAlign(GUI_TA_HORIZONTAL|GUI_TA_LEFT);
    //TestPictureFontDisplay();   
    //CreateFuncMenuSelect();

    //LoadFontLib();

    char devMode[16]={0};
    while(!GetDevMode(devMode))
    {
        GUI_Clear();
        GUI_DispStringHCenterAt("设备未联机，请检查!",200,50);
        GUI_Delay(500);
    }					
    CreateNumKeyForm();                 //创建数字键盘
    CreateFullKeyForm();                //创建全键盘
    CreateMessageBox();                 //创建有按钮对话框
    CreateMessageBox_NoBtn();      		//创建无按钮对话框
    CreateMotorControl();               //创建电机点动窗体
    StatusParaStruct appStatus;
    DeviceStatusEnum lastStatus=0xFF;
    
    //显示欢迎界面
    //WM_HWIN welForm = CreateWelcomForm();
    //GUI_Delay(2000);                      
    //GUI_EndDialog(welForm,0);            
    while(true)
    {			
        isExitWhile=false;	                
        GUI_Clear(); 
        appStatus =GetCurrStatus();
        if(appStatus.DevStatus==lastStatus)
        {
            GUI_Delay(500);
            continue;
        }
        lastStatus=appStatus.DevStatus;
        switch(appStatus.DevStatus)
        {
            case NoGetStatus: //没有读取到当前状态
                GUI_DispStringHCenterAt("没有读取到设备程序当前状态",200,50);
                break;
            case DeviceIniting: //设备初始化中
                //CreateWelcomForm();
                //GUI_Delay(1000);	
                break;
            case DevReady: //设备准备就绪,进入工作主界面
            case DevWorking: //设备正在工作
                CreateWorkForm();
                isExitWhile=true;
                break;
            case DevScram: //急停中
                ShowMessageBox_NoBut("设备已急停，请弹出【急停按钮】再继续！");
                //CreateMessageBox_NoBtn();
                break;
            case RegWait: //注册码录入,进入注册码录入界面
                CreateRegister();
                isExitWhile=true;
                break;
            case USBInsert: //USB已插入
                
                break;
            default:
                GUI_DispStringHCenterAt(appStatus.StatusDescribe,200,50);
                break;
        }
        if(isExitWhile) break;
        GUI_Delay(500);
    }
    
    static char loopCount=0;   
    while(1)
    {
        if(isExitWhile)
        {
            //要改为GUI定时器的方式
            if(loopCount>=20)
            {
                loopCount=0;
                LoopDataStruct loopData = GetLoopData();
                if(LoopDataReaded!=NULL)
                    LoopDataReaded(loopData);
            }
            loopCount++;
        }
        GUI_Delay(50);
    }
}

