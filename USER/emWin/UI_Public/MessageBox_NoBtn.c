
/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* 2018.05.16
*
******************************************/

#include  "DIALOG.h"
#include "MainTask.h"

#define MessageBox (GUI_ID_USER +0x00)
#define lbMsg_MessageBox (GUI_ID_USER +0x01)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"提示",MessageBox,0,0,584,343,0, 0x0, 0 },
{ TEXT_CreateIndirect,"这是消息框",lbMsg_MessageBox,48,52,483,136,0, 0x0, 0 },
};

//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    //FRAMEWIN_SetTitleHeight(hItem,28);
    FRAMEWIN_SetFont(hItem, &GUI_FontHZ24);    
    FRAMEWIN_SetClientColor(hItem,0x00808080);
    FRAMEWIN_SetTextColor(hItem, 0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_MessageBox);
    TEXT_SetText(hItem,"这是消息框");
    TEXT_SetFont(hItem,&GUI_FontHZ32);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00808080);
    TEXT_SetTextColor(hItem,0x00FFFFFF);
}

static WM_HWIN _thisForm=NULL;
static WM_HWIN _callForm=NULL;

//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {		
		
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

WM_HWIN CreateMessageBox_NoBtn(void) 
{
    _thisForm = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    WM_HideWin(_thisForm);
    return _thisForm;
}

//extern WM_HWIN _currForm;
void ShowMessageBox_NoBut(char* msg)
{
//    GUI_HWIN showedForm = WM_GetFocussedWindow();
//    showedForm=WM_GetDesktopWindow();
//    showedForm= WM_GetParent(_thisForm);
//    showedForm=WM_GetPrevSibling(_thisForm); 
    
    GUI_HWIN showedForm= WM_GetNextSibling(_thisForm); //这个可以获取当前已经显示的窗体    
    if(showedForm!=NULL)
    {
        //这三个函数的功能似乎一样
        GUI_EndDialog(showedForm,0);
        //WM_HideWindow(currForm);
        //WM_HideWin(currForm);
    }
    WM_HWIN hItem = WM_GetDialogItem(_thisForm,lbMsg_MessageBox);
    TEXT_SetText(hItem,msg);
    SetFormCenterScreen(_thisForm);
    WM_ShowWindow(_thisForm);
    //WM_BringToTop(_thisForm); //设置当前窗体为顶层
}

