
/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* 2018.05.16
*
******************************************/

#include  "DIALOG.h"
//#include "AxisControl.h"
#include "CMD.h"
#include "XBFFont.h"


#define WorkForm (GUI_ID_USER +0x00)
#define labZ_WorkForm (GUI_ID_USER +0x01)
#define labY_WorkForm (GUI_ID_USER +0x02)
#define labX_WorkForm (GUI_ID_USER +0x03)
#define txtZ_WorkForm (GUI_ID_USER +0x04)
#define txtY_WorkForm (GUI_ID_USER +0x05)
#define txtX_WorkForm (GUI_ID_USER +0x06)
#define btnYfront_WorkForm (GUI_ID_USER +0x07)
#define btnYback_WorkForm (GUI_ID_USER +0x08)
#define btnXright_WorkForm (GUI_ID_USER +0x09)
#define btnXleft_WorkForm (GUI_ID_USER +0x0A)
#define btnZdown_WorkForm (GUI_ID_USER +0x0B)
#define btnZup_WorkForm (GUI_ID_USER +0x0C)
#define btnCancel_WorkForm (GUI_ID_USER +0x0D)
#define btnOK_WorkForm (GUI_ID_USER +0x0E)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"欢迎使用拓控产品",WorkForm,0,0,800,480,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Z",labZ_WorkForm,150,109,21,22,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Y",labY_WorkForm,150,70,21,22,0, 0x0, 0 },
{ TEXT_CreateIndirect,"X",labX_WorkForm,150,31,21,22,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtZ_WorkForm,177,104,153,32,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtY_WorkForm,177,66,153,32,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtX_WorkForm,177,27,153,32,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Yfront",btnYfront_WorkForm,618,187,89,89,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Yback",btnYback_WorkForm,618,14,89,89,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Xright",btnXright_WorkForm,597,109,110,72,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Xleft",btnXleft_WorkForm,481,109,110,72,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Zdown",btnZdown_WorkForm,481,187,89,89,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Zup",btnZup_WorkForm,481,14,89,89,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"取消",btnCancel_WorkForm,260,359,110,49,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"确定",btnOK_WorkForm,129,359,110,49,0, 0x0, 0 },
};


//初始化窗体相关控件
void InitDialog_WorkForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontYAHE24);
	FRAMEWIN_SetTextColor(hItem, 0x008000FF); //加这句，点击按钮会闪烁?(经验证开启存储设备就不闪了）

    hItem = WM_GetDialogItem(pMsg->hWin,labZ_WorkForm);
    TEXT_SetText(hItem,"Z");
    TEXT_SetFont(hItem,&GUI_Font24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);
	TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_HCENTER);

    hItem = WM_GetDialogItem(pMsg->hWin,labY_WorkForm);
    TEXT_SetText(hItem,"Y");
    TEXT_SetFont(hItem,&GUI_Font24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);

    hItem = WM_GetDialogItem(pMsg->hWin,labX_WorkForm);
    TEXT_SetText(hItem,"X");
    TEXT_SetFont(hItem,&GUI_Font24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);

    hItem = WM_GetDialogItem(pMsg->hWin,txtZ_WorkForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);

    hItem = WM_GetDialogItem(pMsg->hWin,txtY_WorkForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);

    hItem = WM_GetDialogItem(pMsg->hWin,txtX_WorkForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);

    hItem = WM_GetDialogItem(pMsg->hWin,btnYfront_WorkForm);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnYback_WorkForm);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnXright_WorkForm);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnXleft_WorkForm);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnZdown_WorkForm);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);	

    hItem = WM_GetDialogItem(pMsg->hWin,btnZup_WorkForm);
    BUTTON_SetFont(hItem, GUI_FONT_16_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnCancel_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);

    hItem = WM_GetDialogItem(pMsg->hWin,btnOK_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);	
}


//控件事件处理函数
void DoEvent_WorkForm(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {
		case btnYfront_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
        AxisPTRun("Y","FFX");	
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
        AxisPTStop("Y");
					break;
			}
			break;
		case btnYback_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
        AxisPTRun("Y","ZFX");	
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
        AxisPTStop("Y");
					break;
			}
			break;
		case btnXright_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					//SendKeyStatus("XRight=Down");
           AxisPTRun("X","ZFX");
          //MoveToCoord(X,10,true); 
//          for(u8 i=0;i<5;i++)
//          {
//              MoveToCoord(X,300,true);
//              MoveToCoord(X,5,true);
//          }        
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					//SendKeyStatus("XRight=UP");
          AxisPTStop("X");
					break;
			}
			break;
		case btnXleft_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					//SendKeyStatus("XLeft=Down");
          AxisPTRun("X","FFX");	
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					//SendKeyStatus("XLeft=UP");
          AxisPTStop("X");
					break;
			}
			break;
		case btnZdown_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
        AxisPTRun("Z","ZFX");	
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
        AxisPTStop("Z");
					break;
			}
			break;
		case btnZup_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
          AxisPTRun("Z","FFX");	
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
        AxisPTStop("Z");
					break;
			}
			break;
		case btnCancel_WorkForm:
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
		case btnOK_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:					
					break;
				case WM_NOTIFICATION_RELEASED:                    
					//DO:按钮已被释放（弹起）
                    GUI_EndDialog(pMsg->hWin, 0);
					CreateMotorPara();
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
			InitDialog_WorkForm(pMsg);
			break;
		case WM_NOTIFY_PARENT:
			DoEvent_WorkForm(pMsg);
			break;
    }
}


WM_HWIN CreateWorkForm(void) {
    WM_HWIN hWin;  
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
