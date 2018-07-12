#include "MainTask.h"
#include "bsp_touch.h"
#include "LCDPara.h"
#include "FileOperate.h"
#include "XBFFont.h"
#include "CMD.h"

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

void MainTask(void)
{
	GUI_Init();//初始化emWin/ucGUI	
	WM_SetCreateFlags(WM_CF_MEMDEV); //使能设备缓存，解决闪烁	
//  GUI_MEMDEV_Handle  hMem0 = GUI_MEMDEV_CreateEx(0, 0, 800, 480, GUI_MEMDEV_HASTRANS);
//  GUI_MEMDEV_Select(hMem0);
//  CreateWorkForm();
//  GUI_MEMDEV_Select(0);
//  GUI_MEMDEV_WriteAt(hMem0, 800, 480);
	if(_isTouchCalibration)
	{
		TouchCalibrationTask();
	}
//	//XBF字库的使用
//	UseXBF();
//	GUI_UC_SetEncodeUTF8();
//	GUI_SetFont(&XBF_Font);	
//	GUI_SetTextAlign(GUI_TA_HORIZONTAL|GUI_TA_LEFT);
//	GUI_DispStringHCenterAt("中文测试,XBF!",200,50);
//	GUI_DispStringHCenterAt("二行中文测试,XBF!",200,80);	
//	GUI_DispStringHCenterAt("非常好!",200,110);
//	GUI_Delay(1000);	
	
	FIL fil;
    FATFS fs;
    FRESULT res = f_mount(&fs,"0:/",0);
	res=OpenFile(_xbfLibName32,FA_READ,&fil);
	if(res!=FR_OK)
	{
		GUI_SetFont(&GUI_Font24_ASCII);	
		GUI_DispStringHCenterAt("Plase copy XBF file to disk!",200,50);		
	}
	else
	{
			CloseFile(&fil,_xbfLibName32);
			UseXBF();
			GUI_UC_SetEncodeUTF8();
			GUI_SetFont(&GUI_FontYAHE32);	
			GUI_SetTextAlign(GUI_TA_HORIZONTAL|GUI_TA_LEFT);
            //TestPictureFontDisplay();    
        
			char devMode[16]={0};
			while(!GetDevMode(devMode))
			{
				GUI_Clear();
				//GUI_DispStringHCenterAt("Device noline,Please check!",200,50);
				GUI_DispStringHCenterAt("设备未联机，请检查!",200,50);
				GUI_Delay(500);
			}
					
			//CreateKeyboard();//创建软键盘
			CreateNumKeyForm();
            CreateFullKeyForm();
            CreateMessageBox();
            CreateMessageBox_NoBtn();
			StatusParaStruct appStatus;
            DeviceStatusEnum lastStatus=0xFF;
            
             //CreateWindow();
            //显示欢迎界面
            CreateWelcomForm();
           //GUI_Delay(1000);                      
            
			/*while(true)
			{
				bool isExitWhile=false;				
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
                        CreateWelcomForm();
                        GUI_Delay(1000);				
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
			}	*/
		}
    while(1)
    {
        GUI_Delay(200);
    }
}

