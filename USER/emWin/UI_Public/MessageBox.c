
/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* 2018.05.16
*
******************************************/

#include  "DIALOG.h"


#define MessageBox (GUI_ID_USER +0x00)
#define lbMsg_MessageBox (GUI_ID_USER +0x01)
#define btnOK_MessageBox (GUI_ID_USER +0x02)
#define btnCancel_MessageBox (GUI_ID_USER +0x03)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"提示",MessageBox,0,0,584,343,0, 0x0, 0 },
{ TEXT_CreateIndirect,"这是消息框",lbMsg_MessageBox,48,52,483,136,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"确定",btnOK_MessageBox,183,225,89,41,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"取消",btnCancel_MessageBox,307,225,89,41,0, 0x0, 0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE16;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE20;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE36;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE40;


//初始化窗体相关控件
void InitDialog_MessageBox(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontYAHE16);
    FRAMEWIN_SetClientColor(hItem,0x00A9A9A9);
    FRAMEWIN_SetTextColor(hItem, 0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_MessageBox);
    TEXT_SetText(hItem,"这是消息框");
    TEXT_SetFont(hItem,&GUI_FontYAHE24);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00696969);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,btnOK_MessageBox);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnCancel_MessageBox);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}


//控件事件处理函数
void DoEvent_MessageBox(WM_MESSAGE * pMsg)
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
			InitDialog_MessageBox(pMsg);
			break;
		case WM_NOTIFY_PARENT:
			DoEvent_MessageBox(pMsg);
			break;
    }
}

static WM_HWIN _msgBoxForm;
WM_HWIN CreateMessageBox(void) {
    _msgBoxForm = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWin(_msgBoxForm);
    return _msgBoxForm;
}

//设备键盘为居中
void SetMsgBoxCenter(WM_HWIN callForm)
{
    int fW = WM_GetWindowSizeX(callForm);
    int kW = WM_GetWindowSizeX(_msgBoxForm);
    int fH = WM_GetWindowSizeY(callForm);
    int kH = WM_GetWindowSizeY(_msgBoxForm);
    int x0=(fW-kW)/2;
    int y0=(fH-kH)/2;
    WM_MoveTo(_msgBoxForm, x0, y0);
}

void ShowMessageBox(WM_HWIN callForm,char* msg)
{
    WM_HideWindow(callForm);
    WM_HWIN hItem = WM_GetDialogItem(_msgBoxForm,lbMsg_MessageBox);
    TEXT_SetText(hItem,msg);
    SetKeyboardCenter(callForm);
    WM_ShowWindow(_msgBoxForm);
}

