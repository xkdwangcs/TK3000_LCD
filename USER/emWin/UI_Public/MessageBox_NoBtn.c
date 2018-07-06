
/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* 2018.05.16
*
******************************************/

#include  "DIALOG.h"


#define MessageBox (GUI_ID_USER +0x00)
#define lbMsg_MessageBox (GUI_ID_USER +0x01)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"提示",MessageBox,0,0,584,343,0, 0x0, 0 },
{ TEXT_CreateIndirect,"这是消息框",lbMsg_MessageBox,48,52,483,136,0, 0x0, 0 },
};

extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE36;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE40;

static WM_HWIN _thisForm=NULL;
static WM_HWIN _callForm=NULL;


//初始化窗体相关控件
static void InitDialog_MessageBox(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    //FRAMEWIN_SetTitleHeight(hItem,28);
    FRAMEWIN_SetFont(hItem, &GUI_FontYAHE24);    
    FRAMEWIN_SetClientColor(hItem,0x00808080);
    FRAMEWIN_SetTextColor(hItem, 0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_MessageBox);
    TEXT_SetText(hItem,"这是消息框");
    TEXT_SetFont(hItem,&GUI_FontYAHE32);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00808080);
    TEXT_SetTextColor(hItem,0x00FFFFFF);
}


//控件事件处理函数
static void DoEvent_MessageBox(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {		
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

WM_HWIN CreateMessageBox_NoBtn(void) {
    //是否换一种方式创建？？？
    _thisForm = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    //_thisForm=GUI_M
    WM_HideWin(_thisForm);
    return _thisForm;
}

//设备消息框为居中
static void SetMsgBoxCenter()
{
    int fW = 800;//WM_GetWindowSizeX(callForm);
    int kW = WM_GetWindowSizeX(_thisForm);
    int fH = 480;//WM_GetWindowSizeY(callForm);
    int kH = WM_GetWindowSizeY(_thisForm);
    int x0=(fW-kW)/2;
    int y0=(fH-kH)/2;
    WM_MoveTo(_thisForm, x0, y0);
}

extern WM_HWIN _currForm;
void ShowMessageBox_NoBut(char* msg)
{
    //_callForm=callForm;
    GUI_HWIN currForm = WM_GetFocussedWindow();
    currForm=WM_GetPrevSibling(_thisForm);//WM_GetDesktopWindow();
    
    if(currForm!=NULL)
    {
        GUI_EndDialog(_currForm,0);
        //WM_HideWindow(currForm);
    }
    WM_HWIN hItem = WM_GetDialogItem(_thisForm,lbMsg_MessageBox);
    TEXT_SetText(hItem,msg);
    SetMsgBoxCenter();
    WM_ShowWindow(_thisForm);
}

