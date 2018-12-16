/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"
#include "MainTask.h"
#include "FileOperate.h"

#define WelcomForm (GUI_ID_USER +0x00)
#define picture1_WelcomForm (GUI_ID_USER +0x01)
#define lbSysName_WelcomForm (GUI_ID_USER +0x02)
#define lbCompany_WelcomForm (GUI_ID_USER +0x03)
#define lbURL_WelcomForm (GUI_ID_USER +0x04)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"Welcom",WelcomForm,0,0,800,480,0, 0x0, 0 },
{ IMAGE_CreateIndirect,"",picture1_WelcomForm,0,0,800,480,0, 0x0, 0 },
{ TEXT_CreateIndirect,"自动点胶控制系统",lbSysName_WelcomForm,208,66,369,57,0, 0x0, 0 },
{ TEXT_CreateIndirect,"长沙拓控智能科技有限公司",lbCompany_WelcomForm,191,337,402,41,0, 0x0, 0 },
{ TEXT_CreateIndirect,"http://www.tkrobot.net",lbURL_WelcomForm,212,378,367,33,0, 0x0, 0 },
};

//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem,0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,picture1_WelcomForm);
    int fileSize = 0;
    u8* fData = ReadFullFile("0:/Pic/Welcome.jpg", &fileSize);
    if (fData != NULL)
    {
        IMAGE_SetJPEG(hItem, fData, fileSize);
    }

    hItem = WM_GetDialogItem(pMsg->hWin,lbSysName_WelcomForm);
    TEXT_SetText(hItem,"自动点胶控制系统");
    TEXT_SetFont(hItem,&GUI_FontHZ40);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    //TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,lbCompany_WelcomForm);
    TEXT_SetText(hItem,"长沙拓控智能科技有限公司");
    TEXT_SetFont(hItem,&GUI_FontHZ32);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    //TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,lbURL_WelcomForm);
    TEXT_SetText(hItem,"http://www.tkrobot.net");
    TEXT_SetFont(hItem,GUI_FONT_32_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_HCENTER);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    //TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);
}

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


WM_HWIN CreateWelcomForm(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
