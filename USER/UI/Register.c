
/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.02 (2018.07.07)
*
******************************************/

#include  "DIALOG.h"
#include "CMD.h"

#define Register (GUI_ID_USER +0x00)
#define lbDevCode_Register (GUI_ID_USER +0x01)
#define txtDevCode_Register (GUI_ID_USER +0x02)
#define lbRegCode_Register (GUI_ID_USER +0x03)
#define txtRegCode_Register (GUI_ID_USER +0x04)
#define lbMsg_Register (GUI_ID_USER +0x05)
#define btnReg_Register (GUI_ID_USER +0x06)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"请录入注册码",Register,25,25,639,441,0, 0x0, 0 },
{ TEXT_CreateIndirect,"机器码",lbDevCode_Register,120,69,111,33,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtDevCode_Register,237,64,265,44,0, 0x0, 0 },
{ TEXT_CreateIndirect,"注册码",lbRegCode_Register,120,137,111,33,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtRegCode_Register,237,125,265,86,0, 0x0, 0 },
{ TEXT_CreateIndirect,"*",lbMsg_Register,95,235,433,41,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"注册",btnReg_Register,391,322,111,40,0, 0x0, 0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE36;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE40;


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    GetSysParameter();
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontYAHE24);
    FRAMEWIN_SetClientColor(hItem,0x00F0F0F0);
    FRAMEWIN_SetTextColor(hItem, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,lbDevCode_Register);
    TEXT_SetText(hItem,"机器码");
    TEXT_SetFont(hItem,&GUI_FontYAHE32);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtDevCode_Register);
    EDIT_SetText(hItem, SysParameter.DevNumCalc);
    //EDIT_SetFont(hItem, &GUI_FontYAHE32);
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00E1FFFF); 
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbRegCode_Register);
    TEXT_SetText(hItem,"注册码");
    TEXT_SetFont(hItem,&GUI_FontYAHE32);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtRegCode_Register);
    EDIT_SetText(hItem, "");
    //EDIT_SetFont(hItem, &GUI_FontYAHE32);
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFFFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_Register);
    TEXT_SetText(hItem,"设备有效使用日期已过，请注册设备！");
    TEXT_SetFont(hItem,&GUI_FontYAHE32);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x0000FF);

    hItem = WM_GetDialogItem(pMsg->hWin,btnReg_Register);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}


//控件事件处理函数
void DoEvent_Register(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
	WM_HWIN	hItem;
    switch(Id)
    {
     case txtRegCode_Register:
			switch(NCode) {
			case WM_NOTIFICATION_CLICKED:				
        break;
			case WM_NOTIFICATION_RELEASED:
			//弹出数字键盘
			ShowNumKeyboard1(pMsg->hWin,EDIT_SetText,Id);
        break;
			case WM_NOTIFICATION_VALUE_CHANGED:
			break;
			}
			break;
		case btnReg_Register:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					hItem = WM_GetDialogItem(pMsg->hWin,txtDevCode_Register);
					char regNum[20]={0};
					EDIT_GetText(hItem,regNum,20);
					RegisterDevice(regNum);					
					while(true)
					{
						StatusParaStruct status = GetCurrStatus();
						if(status.DevStatus==DevReady) //注册成功，跳转到主界面
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
		default:
			WM_DefaultProc(pMsg);
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
			DoEvent_Register(pMsg);
			break;
    }
}


WM_HWIN CreateRegister(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);	
    SetFormCenterScreen(hWin);
    return hWin;
}
 
