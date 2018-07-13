/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.02 (2018.07.07)
*
******************************************/

#include  "DIALOG.h"


#define MotorControl (GUI_ID_USER +0x00)
#define lbX_MotorControl (GUI_ID_USER +0x01)
#define lbY_MotorControl (GUI_ID_USER +0x02)
#define lbZ_MotorControl (GUI_ID_USER +0x03)
#define btnXLeft_MotorControl (GUI_ID_USER +0x04)
#define btnXRight_MotorControl (GUI_ID_USER +0x05)
#define btnYBack_MotorControl (GUI_ID_USER +0x06)
#define btnYFront_MotorControl (GUI_ID_USER +0x07)
#define btnZUp_MotorControl (GUI_ID_USER +0x08)
#define btnZDown_MotorControl (GUI_ID_USER +0x09)
#define cmbSpeedType_MotorControl (GUI_ID_USER +0x0A)
#define edtSDPer_MotorControl (GUI_ID_USER +0x0B)
#define cmbPTSelect_MotorControl (GUI_ID_USER +0x0C)
#define btnOK_MotorControl (GUI_ID_USER +0x0D)
#define btnCancel_MotorControl (GUI_ID_USER +0x0E)
#define btnReset_MotorControl (GUI_ID_USER +0x0F)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"电机点动控制",MotorControl,0,0,327,443,0, 0x0, 0 },
{ TEXT_CreateIndirect,"X:",lbX_MotorControl,26,7,36,29,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Y:",lbY_MotorControl,26,44,33,29,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Z:",lbZ_MotorControl,26,81,34,29,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"X左",btnXLeft_MotorControl,15,204,140,64,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"X右",btnXRight_MotorControl,177,204,140,64,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Y后",btnYBack_MotorControl,15,127,92,72,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Y前",btnYFront_MotorControl,15,274,92,72,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Z上",btnZUp_MotorControl,225,127,92,72,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Z下",btnZDown_MotorControl,225,274,92,72,0, 0x0, 0 },
{ DROPDOWN_CreateIndirect,"慢",cmbSpeedType_MotorControl,123,290,89,39,0, 0x0, 0 },
{ EDIT_CreateIndirect,"100%",edtSDPer_MotorControl,216,62,101,35,0, 0x0, 0 },
{ DROPDOWN_CreateIndirect,"左平台",cmbPTSelect_MotorControl,216,7,101,39,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"确定",btnOK_MotorControl,123,370,89,41,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"返回",btnCancel_MotorControl,225,370,89,41,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"复位",btnReset_MotorControl,123,138,89,50,0, 0x0, 0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE36;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE40;


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontYAHE24);
    FRAMEWIN_SetClientColor(hItem,0x00A9A9A9);
    FRAMEWIN_SetTextColor(hItem, 0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,lbX_MotorControl);
    TEXT_SetText(hItem,"X:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,lbY_MotorControl);
    TEXT_SetText(hItem,"Y:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,lbZ_MotorControl);
    TEXT_SetText(hItem,"Z:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,btnXLeft_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnXRight_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnYBack_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0FFC0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnYFront_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0FFC0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnZUp_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnZDown_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,cmbSpeedType_MotorControl);
    //DROPDOWN_SetListHeight(hItem, 39);
    DROPDOWN_SetFont(hItem, &GUI_FontYAHE24);
    DROPDOWN_AddString(hItem, "慢");
    DROPDOWN_AddString(hItem, "中");
    DROPDOWN_AddString(hItem, "快");

    hItem = WM_GetDialogItem(pMsg->hWin,edtSDPer_MotorControl);
    EDIT_SetText(hItem, "100%");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFFFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,cmbPTSelect_MotorControl);
    //DROPDOWN_SetListHeight(hItem, 39);
    DROPDOWN_SetFont(hItem, &GUI_FontYAHE24);
    DROPDOWN_AddString(hItem, "左平台");
    DROPDOWN_AddString(hItem, "右平台");

    hItem = WM_GetDialogItem(pMsg->hWin,btnOK_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnCancel_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnReset_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}


//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {
		case btnXLeft_MotorControl:
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
		case btnXRight_MotorControl:
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
		case btnYBack_MotorControl:
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
		case btnYFront_MotorControl:
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
		case btnZUp_MotorControl:
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
		case btnZDown_MotorControl:
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
		case cmbSpeedType_MotorControl:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					break;
				case WM_NOTIFICATION_SEL_CHANGED:
					//DO:选择的值已发生改变
					break;
			}
			break;
		case edtSDPer_MotorControl:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					break;
				case WM_NOTIFICATION_VALUE_CHANGED:
					//DO:控件的值已改变
					break;
			}
			break;
		case cmbPTSelect_MotorControl:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					break;
				case WM_NOTIFICATION_SEL_CHANGED:
					//DO:选择的值已发生改变
					break;
			}
			break;
		case btnOK_MotorControl:
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
		case btnCancel_MotorControl:
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
		case btnReset_MotorControl:
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


WM_HWIN CreateMotorControl(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
