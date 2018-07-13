
/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* 2018.05.16
*
******************************************/

#include  "DIALOG.h"
#include "USBFunc_Ctr.h"


#define USBOpre (GUI_ID_USER +0x00)
#define button3_USBOpre (GUI_ID_USER +0x01)
#define button2_USBOpre (GUI_ID_USER +0x02)
#define button1_USBOpre (GUI_ID_USER +0x03)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"USBOpre",USBOpre,0,0,800,480,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"USB3",button3_USBOpre,81,196,111,40,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"USB2",button2_USBOpre,81,128,111,40,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"USB1",button1_USBOpre,81,67,111,40,0, 0x0, 0 },
};


//初始化窗体相关控件
void InitDialog_USBOpre(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, GUI_FONT_20_ASCII);
    FRAMEWIN_SetTextColor(hItem, 0x008000FF);

    hItem = WM_GetDialogItem(pMsg->hWin,button3_USBOpre);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,button2_USBOpre);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,button1_USBOpre);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);
}


//控件事件处理函数
void DoEvent_USBOpre(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {
		case button3_USBOpre:
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
		case button2_USBOpre:
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
		case button1_USBOpre:
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
    }
}


static void _cbDialog(WM_MESSAGE * pMsg)
{
    switch (pMsg->MsgId)
	{
		case WM_INIT_DIALOG:
			InitDialog_USBOpre(pMsg);
			break;
		case WM_NOTIFY_PARENT:
			DoEvent_USBOpre(pMsg);
			break;
		default:
		    WM_DefaultProc(pMsg);
		    break;
    }
}


WM_HWIN CreateUSBFunc_Ctr(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
