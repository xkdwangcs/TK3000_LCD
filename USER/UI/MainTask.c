#include "MainTask.h"
#include "bsp_touch.h"
#include "LCDPara.h"
#include "FileOperate.h"
#include "CMD.h"

//��ȡ��ѭ�����ݺ�����
LoopDataReadHandler LoopDataReaded;

void TouchCalibrationTask()
{
    GUI_PID_STATE PIDState;
    //GUI_Init();                /* ��ʼ�� */
    TOUCH_Calibration();       /* �ĵ㴥��У׼ */
    GUI_CURSOR_Show();         /* ��ʾ��� */
    GUI_SetBkColor(GUI_WHITE); /* ���ñ���ɫ */
    GUI_SetColor(GUI_BLACK);   /* ����ǰ��ɫ */
    GUI_Clear();
    GUI_SetFont(&GUI_Font24B_1);
    GUI_DispStringAt("Draw Panel", 0, 0);
    /*
    	������ȡ5�Σ���ΪemWin��PID�������������һ��FIFO��������
    Ĭ������������Ա���5��PID�¼�������������ȡ5���൱�����FIFO.
    ��ֹ����У׼��ʱ����ĵ���ʾ���������档
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
            /* Ϊ�˷�ֹ�α겻��ʾ���߲������ƶ�������������º��� */
            GUI_CURSOR_SetPosition(PIDState.x, PIDState.y);
            GUI_DrawPoint(PIDState.x, PIDState.y);
        }
        GUI_Delay(1);
    }
}

//���洰�ڻص�����
static void _cbBkWindow(WM_MESSAGE * pMsg)
{
	WM_HWIN hWin = pMsg->hWin;
	switch(pMsg->MsgId)
	{
		case WM_PAINT:
//			GUI_SetBkColor(GUI_BLUE);
//			GUI_Clear();
			break;
		//case 32: //�������ؼ�
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
    //ʹ�ܴ���ʹ���ڴ��豸������������Ч������˸, 
	//����GUI_Initǰ��Ͱ������洰�ڣ�������ں���Ͳ��������洰��
	//�Ŵ˴������ػ��������Ч����
	//WM_SetCreateFlags(WM_CF_MEMDEV); 
	GUI_Init();//��ʼ��emWin/ucGUI
    /*	 ���ڶ໺��ʹ����ڴ��豸������˵��
	   1. ʹ�ܶ໺���ǵ��õ����º������û�Ҫ��LCDConf_Lin_Template.c�ļ��������˶໺�壬���ô˺�������Ч��
		  WM_MULTIBUF_Enable(1);
	   2. ����ʹ��ʹ���ڴ��豸�ǵ��ú�����WM_SetCreateFlags(WM_CF_MEMDEV);
	   3. ���emWin�����ö໺��ʹ����ڴ��豸��֧�֣���ѡһ���ɣ����������ѡ��ʹ�ö໺�壬ʵ��ʹ��
		  STM32F429BIT6 + 32λSDRAM + RGB565/RGB888ƽ̨���ԣ��໺�������Ч�Ľ��ʹ����ƶ����߻���ʱ��˺��
		  �У�����Ч����������ԣ�ͨ��ʹ�ܴ���ʹ���ڴ��豸���������ġ�
	   4. ����emWin����Ĭ���ǿ��������塣
	*/
	WM_MULTIBUF_Enable(1);	
	//�������洰�ڵı���ɫ�����Զ��ػ�
	//WM_SetDesktopColor(GUI_BLUE); 
	//�������洰�ڵĻص�����,����WM_SetCreateFlags�ŵ�GUI_Init()֮ǰʱ������WM_SetDesktopColor���
	WM_SetCallback(WM_HBKWIN,_cbBkWindow);	
    	
	if(_isTouchCalibration)
	{
		TouchCalibrationTask();
	}	

//    GUI_SetTextAlign(GUI_TA_HORIZONTAL|GUI_TA_LEFT);
//    GUI_SetFont(&GUI_FontHZ16);	
//	GUI_DispStringHCenterAt("16���ֿ����@~%����������<>&%$#&*��OK!!",5,0);	
//    GUI_SetFont(&GUI_FontHZ24);	
//	GUI_DispStringHCenterAt("24���ֿ����@~%����������<>&%$#&*��OK!!",5,26);	
//    GUI_SetFont(&GUI_FontHZ32);	
//	GUI_DispStringHCenterAt("32���ֿ����@~%����������<>&%$#&*��OK!!",5,60);	
//    GUI_SetFont(&GUI_FontHZ40);	
//	GUI_DispStringHCenterAt("40���ֿ����@~%����������<>&%$#&*��OK!!",5,102);	
    
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
        GUI_DispStringHCenterAt("�豸δ����������!",200,50);
        GUI_Delay(500);
    }					
    CreateNumKeyForm();                 //�������ּ���
    CreateFullKeyForm();                //����ȫ����
    CreateMessageBox();                 //�����а�ť�Ի���
    CreateMessageBox_NoBtn();      		//�����ް�ť�Ի���
    CreateMotorControl();               //��������㶯����
    StatusParaStruct appStatus;
    DeviceStatusEnum lastStatus=0xFF;
    
    //��ʾ��ӭ����
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
            case NoGetStatus: //û�ж�ȡ����ǰ״̬
                GUI_DispStringHCenterAt("û�ж�ȡ���豸����ǰ״̬",200,50);
                break;
            case DeviceIniting: //�豸��ʼ����
                //CreateWelcomForm();
                //GUI_Delay(1000);	
                break;
            case DevReady: //�豸׼������,���빤��������
            case DevWorking: //�豸���ڹ���
                CreateWorkForm();
                isExitWhile=true;
                break;
            case DevScram: //��ͣ��
                ShowMessageBox_NoBut("�豸�Ѽ�ͣ���뵯������ͣ��ť���ټ�����");
                //CreateMessageBox_NoBtn();
                break;
            case RegWait: //ע����¼��,����ע����¼�����
                CreateRegister();
                isExitWhile=true;
                break;
            case USBInsert: //USB�Ѳ���
                
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
            //Ҫ��ΪGUI��ʱ���ķ�ʽ
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

