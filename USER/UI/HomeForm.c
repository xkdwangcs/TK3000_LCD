/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"


#define HomeForm (GUI_ID_USER +0x00)
#define IcoView_HomeForm (GUI_ID_USER +0x01)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"Welcom",HomeForm,0,0,800,480,0,0x0,0 },
{ ICONVIEW_CreateIndirect,"IcoView",IcoView_HomeForm,0,44,800,435,0,0x00640064,0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE14;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE18;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;

extern GUI_CONST_STORAGE GUI_BITMAP bmx1;


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem,0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,IcoView_HomeForm);
    ICONVIEW_EnableStreamAuto();
    ICONVIEW_SetBkColor(hItem, ICONVIEW_CI_BK, GUI_MAKE_ALPHA(0xFF, GUI_WHITE));  //ICONVIEW 控件背景色
    ICONVIEW_SetBkColor(hItem, ICONVIEW_CI_SEL, GUI_ORANGE); //ICONVIEW 选中目标景色
    ICONVIEW_SetFont(hItem, &GUI_FontYAHE14);
    ICONVIEW_SetIconAlign(hItem, ICONVIEW_IA_TOP);
    ICONVIEW_SetTextColor(hItem, ICONVIEW_CI_UNSEL, GUI_BLUE);
    ICONVIEW_SetTextColor(hItem, ICONVIEW_CI_SEL, GUI_GREEN);
    ICONVIEW_SetFrame(hItem, GUI_COORD_X, 0);//设置图标到IconView边框的间距
    ICONVIEW_SetFrame(hItem, GUI_COORD_Y, 0);
    ICONVIEW_SetSpace(hItem, GUI_COORD_X, 12);//设置图标和图标之间的间距
    ICONVIEW_SetSpace(hItem, GUI_COORD_Y, 8);
    ICONVIEW_AddBitmapItem(hItem, &bmx1, "文件编辑");//添加图标项
}


//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {
		case HomeForm:
			switch(NCode)
			{
			}
			break;
		case IcoView_HomeForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
				   switch(ICONVIEW_GetSel(WM_GetDialogItem(pMsg->hWin,IcoView_HomeForm)))
				       {
				           //case 0: DOEVENT;
				           break;
				       }
				   break;
				case WM_NOTIFICATION_RELEASED:
				    break;
				case WM_NOTIFICATION_MOVED_OUT:
				    break;
				case WM_NOTIFICATION_SCROLL_CHANGED:
				    break;
				case WM_NOTIFICATION_SEL_CHANGED:
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


WM_HWIN CreateHomeForm(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}

