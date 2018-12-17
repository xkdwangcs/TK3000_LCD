/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"
#include "MainTask.h"

#define MessageBox (GUI_ID_USER +0x00)
#define lbMsg_MessageBox (GUI_ID_USER +0x01)
#define btnOK_MessageBox (GUI_ID_USER +0x02)
#define btnCancel_MessageBox (GUI_ID_USER +0x03)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"提示",MessageBox,0,0,584,343,0, 0x0, 0 },
{ TEXT_CreateIndirect,"这是消息框",lbMsg_MessageBox,49,49,483,136,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"确定",btnOK_MessageBox,183,225,89,41,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"取消",btnCancel_MessageBox,307,225,89,41,0, 0x0, 0 },
};

//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontHZ24);
    FRAMEWIN_SetClientColor(hItem,0x00808080);
    FRAMEWIN_SetTextColor(hItem, 0x00FFFFFF);
    FRAMEWIN_SetMoveable(hItem, 0);//窗体不可移动

    hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_MessageBox);
    TEXT_SetText(hItem,"这是消息框");
    TEXT_SetFont(hItem,&GUI_FontHZ24);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00808080);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,btnOK_MessageBox);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00808080);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnCancel_MessageBox);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00808080);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}


static WM_HWIN _thisForm;
static WM_HWIN _callForm=NULL;

//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {
		case btnOK_MessageBox:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
          WM_HideWin(pMsg->hWin);
          WM_ShowWindow(_callForm);
					break;
			}
			break;
		case btnCancel_MessageBox:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
          WM_HideWin(pMsg->hWin);
          WM_ShowWindow(_callForm);
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


WM_HWIN CreateMessageBox(void) {
    _thisForm = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWin(_thisForm);
    return _thisForm;
}

void ShowMessageBox(WM_HWIN callForm,char* msg)
{
    _callForm=callForm;
    WM_HideWindow(callForm);
    WM_HWIN hItem = WM_GetDialogItem(_thisForm,lbMsg_MessageBox);
    TEXT_SetText(hItem,msg);
    SetFormCenterScreen(callForm);
    WM_ShowWindow(_thisForm);
}

