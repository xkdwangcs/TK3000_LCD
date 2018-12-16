/*****************************************
*
* ФӦǿ��Ƶ�GUIBuilder���ɵ��ļ�
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"
#include "MainTask.h"
#include "CMD.h"

#define Register (GUI_ID_USER +0x00)
#define lbDevCode_Register (GUI_ID_USER +0x01)
#define txtDevCode_Register (GUI_ID_USER +0x02)
#define lbRegCode_Register (GUI_ID_USER +0x03)
#define mEdtRegCode_Register (GUI_ID_USER +0x04)
#define lbMsg_Register (GUI_ID_USER +0x05)
#define btnReg_Register (GUI_ID_USER +0x06)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"��¼��ע����",Register,200,200,639,441,0, 0x0, 0 },
{ TEXT_CreateIndirect,"������",lbDevCode_Register,84,66,114,41,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtDevCode_Register,201,64,337,44,0, 0x0, 0 },
{ TEXT_CreateIndirect,"ע����",lbRegCode_Register,84,141,114,41,0, 0x0, 0 },
{ MULTIEDIT_CreateIndirect,"ABC",mEdtRegCode_Register,201,137,337,111,0, 0x0, 0 },
{ TEXT_CreateIndirect,"*",lbMsg_Register,86,265,482,41,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"ע��",btnReg_Register,391,322,111,40,0, 0x0, 0 },
};

//��ʼ��������ؿؼ�
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontHZ24);
    FRAMEWIN_SetClientColor(hItem,0x00F0F0F0);
    FRAMEWIN_SetTextColor(hItem, 0x00000000);
    FRAMEWIN_SetMoveable(hItem, 0);//���岻���ƶ�

    GetSysParameter();
    hItem = WM_GetDialogItem(pMsg->hWin,lbDevCode_Register);
    TEXT_SetText(hItem,"������");
    TEXT_SetFont(hItem,&GUI_FontHZ32);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//�Զ�����
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtDevCode_Register);
    EDIT_SetText(hItem, SysParameter.DevNumCalc);
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00E1FFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //�ַ���󳤶�
    EDIT_EnableBlink(hItem, 500, 0); //��겻��˸

    hItem = WM_GetDialogItem(pMsg->hWin,lbRegCode_Register);
    TEXT_SetText(hItem,"ע����");
    TEXT_SetFont(hItem,&GUI_FontHZ32);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//�Զ�����
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,mEdtRegCode_Register);
    MULTIEDIT_SetFont(hItem, GUI_FONT_32_ASCII);
    //MULTIEDIT_CI_READONLY:ֻ��ģʽ��MULTIEDIT_CI_EDIT���༭ģʽ
    MULTIEDIT_SetTextColor(hItem, MULTIEDIT_CI_READONLY, 0x00000000);  //�����ı���ɫ
    MULTIEDIT_SetBkColor(hItem, MULTIEDIT_CI_READONLY, 0x00FFFFFF); //���ñ���ɫ
    MULTIEDIT_SetAutoScrollV(hItem, 1); //ʹ���ܴ�ֱ������
    MULTIEDIT_SetInsertMode(hItem, 0);//��ֹ����ģʽ
    MULTIEDIT_SetWrapWord(hItem); //���û���ģʽ
    MULTIEDIT_SetReadOnly(hItem, 1); //����ֻ��ģʽ
    MULTIEDIT_SetBufferSize(hItem,1024);  //�˳����޶���������û��
    //MULTIEDIT_SetMaxLen(hItem,200);       //�˳����޶���������û��
    MULTIEDIT_SetText(hItem, "");

    hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_Register);
    TEXT_SetText(hItem,"*�豸��Чʹ�������ѹ�����ע���豸��");
    TEXT_SetFont(hItem,&GUI_FontHZ24);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//�Զ�����
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x000000FF);

    hItem = WM_GetDialogItem(pMsg->hWin,btnReg_Register);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}

//�ؼ��¼�������
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
	WM_HWIN	hItem;
    switch(Id)
    {
		case txtDevCode_Register:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:��ť�ѱ����
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:��ť�ѱ��ͷţ�����
					break;
				case WM_NOTIFICATION_VALUE_CHANGED:
					//DO:�ؼ���ֵ�Ѹı�
					break;
			}
			break;
		case mEdtRegCode_Register:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:��ť�ѱ����
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:��ť�ѱ��ͷţ�����
					//ShowNumKeyboard1(pMsg->hWin,EDIT_SetText,Id);
					ShowFullKeyboard1(pMsg->hWin,MULTIEDIT_SetText,Id);
					break;
				case WM_NOTIFICATION_VALUE_CHANGED:
					//DO:�ؼ���ֵ�Ѹı�
					break;
			}
			break;
		case btnReg_Register:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:��ť�ѱ����
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:��ť�ѱ��ͷţ�����
					hItem = WM_GetDialogItem(pMsg->hWin,mEdtRegCode_Register);
					char regNum[20]={0};
					MULTIEDIT_GetText(hItem,regNum,20);
					RegisterDevice(regNum);					
					while(true)
					{
						StatusParaStruct status = GetCurrStatus();
						if(status.DevStatus==DevReady) //ע��ɹ�����ת��������
						{
							GUI_EndDialog(pMsg->hWin, 0);
							CreateWorkForm();
							return;
						}
						else if(status.DevStatus!=NoGetStatus)
						{							
							char* msg=status.StatusDescribe;
							hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_Register);
                            TEXT_SetText(hItem,msg);
						}
						GUI_Delay(500);
					}
					break;
			}
			break;
    }
}


static void _cbDialog(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
	{
		case WM_INIT_DIALOG:
			InitForm(pMsg);
			break;
		case WM_NOTIFY_PARENT:
			DoEvent(pMsg);
			break;
		default:
		    WM_DefaultProc(pMsg);
		    break;
    }
}


WM_HWIN CreateRegister(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	SetFormCenterScreen(hWin);
    return hWin;
}
 
