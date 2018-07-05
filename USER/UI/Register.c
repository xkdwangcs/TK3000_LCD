
/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* 2018.05.16
*
******************************************/

#include "DIALOG.h"
#include "XBFFont.h"
#include "CMD.h"
#

#define Register (GUI_ID_USER +0x00)
#define lbRegCode_Register (GUI_ID_USER +0x01)
#define labDevCode_Register (GUI_ID_USER +0x02)
#define txtRegCode_Register (GUI_ID_USER +0x03)
#define txtDevCode_Register (GUI_ID_USER +0x04)
#define btnGoto_Register (GUI_ID_USER +0x05)
#define btnReg_Register (GUI_ID_USER +0x06)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"请录入注册码",Register,0,0,800,480,0, 0x0, 0 },
{ TEXT_CreateIndirect,"注册码",lbRegCode_Register,219,149,76,22,0, 0x0, 0 },
{ TEXT_CreateIndirect,"机器码",labDevCode_Register,219,93,76,22,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtRegCode_Register,301,144,265,76,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtDevCode_Register,301,88,265,32,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"跳过",btnGoto_Register,455,338,111,40,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"注册",btnReg_Register,323,338,111,40,0, 0x0, 0 },
};


//初始化窗体相关控件
void InitDialog_Register(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &XBF_Font24);
    FRAMEWIN_SetTextColor(hItem, 0x008000FF);

    hItem = WM_GetDialogItem(pMsg->hWin,lbRegCode_Register);
    TEXT_SetText(hItem,"注册码");
    TEXT_SetFont(hItem,&XBF_Font32);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);

    hItem = WM_GetDialogItem(pMsg->hWin,labDevCode_Register);
    TEXT_SetText(hItem,"机器码");
    TEXT_SetFont(hItem,&XBF_Font32);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);

    hItem = WM_GetDialogItem(pMsg->hWin,txtRegCode_Register);
    EDIT_SetText(hItem, "");
	EDIT_SetMaxLen(hItem,50);
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);

    hItem = WM_GetDialogItem(pMsg->hWin,txtDevCode_Register);
    EDIT_SetText(hItem, SysParameter.DevNumCalc);
	EDIT_SetMaxLen(hItem,50);
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);

    hItem = WM_GetDialogItem(pMsg->hWin,btnGoto_Register);
    BUTTON_SetFont(hItem, &XBF_Font24);

    hItem = WM_GetDialogItem(pMsg->hWin,btnReg_Register);
    BUTTON_SetFont(hItem, &XBF_Font24);
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
		case btnGoto_Register:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//取消跳过功能
					//DO:按钮已被释放（弹起）
//					GUI_EndDialog(pMsg->hWin, 0);
//					CreateWorkForm();
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
							//这里显注册错误信息到界面
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
			InitDialog_Register(pMsg);
			break;
		case WM_NOTIFY_PARENT:
			DoEvent_Register(pMsg);
			break;
    }
}


WM_HWIN CreateRegister(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	GetSysParameter();
    return hWin;
}
 
