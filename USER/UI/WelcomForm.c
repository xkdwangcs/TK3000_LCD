/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.02 (2018.07.07)
*
******************************************/

#include  "DIALOG.h"
#include "FileOperate.h"


#define WelcomForm (GUI_ID_USER +0x00)
#define lbSysName_WelcomForm (GUI_ID_USER +0x01)
#define lbVer_WelcomForm (GUI_ID_USER +0x02)
#define lbCompany_WelcomForm (GUI_ID_USER +0x03)
#define lbURL_WelcomForm (GUI_ID_USER +0x04)
#define picWelcom_WelcomForm (GUI_ID_USER +0x05)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"Welcom",WelcomForm,0,0,800,480,0, 0x0, 0 },
{ IMAGE_CreateIndirect,"Image",picWelcom_WelcomForm,0,0,800,480,0, 0x0, 0 },
{ TEXT_CreateIndirect,"自动点胶控制系统",lbSysName_WelcomForm,172,70,343,52,0, 0x0, 0 },
{ TEXT_CreateIndirect,"V1.00",lbVer_WelcomForm,524,89,95,33,0, 0x0, 0 },
{ TEXT_CreateIndirect,"长沙拓控智能科技有限公司",lbCompany_WelcomForm,199,321,402,41,0, 0x0, 0 },
{ TEXT_CreateIndirect,"http://www.tkrobot.net",lbURL_WelcomForm,199,365,367,33,0, 0x0, 0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE36;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE40;


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    
    hItem = WM_GetDialogItem(pMsg->hWin,picWelcom_WelcomForm);
    char* picFileName = "0:/Pic/Welcome.jpg";
    int fileSize = GetFileSize(picFileName);
    GUI_HMEM hMem = GUI_ALLOC_AllocZero(fileSize);//向GUI申请内存
    u8* fileBuffer = GUI_ALLOC_h2p(hMem);//将申请到内存的句柄转换成指针类型
    bool isReadOk = ReadFile(picFileName, fileBuffer);
    if (isReadOk)
    {
        IMAGE_SetJPEG(hItem, fileBuffer, fileSize);
    }
    //GUI_ALLOC_Free(hMem);//在此不能释放内存,否则不显示图片
    
    hItem = WM_GetDialogItem(pMsg->hWin,lbSysName_WelcomForm);
    TEXT_SetText(hItem,"自动点胶控制系统");
    TEXT_SetFont(hItem,&GUI_FontYAHE40);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,lbVer_WelcomForm);
    TEXT_SetText(hItem,"V1.00");
    TEXT_SetFont(hItem,GUI_FONT_32_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,lbCompany_WelcomForm);
    TEXT_SetText(hItem,"长沙拓控智能科技有限公司");
    TEXT_SetFont(hItem,&GUI_FontYAHE32);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,lbURL_WelcomForm);
    TEXT_SetText(hItem,"http://www.tkrobot.net");
    TEXT_SetFont(hItem,GUI_FONT_32_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    //GUI_ALLOC_Free(hMem);//在此释放内存可以
}


//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
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
			InitForm(pMsg);
			break;
		case WM_NOTIFY_PARENT:
			DoEvent(pMsg);
			break;
    }
}


WM_HWIN CreateWelcomForm(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
