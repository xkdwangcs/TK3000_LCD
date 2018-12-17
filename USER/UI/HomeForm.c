/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"


#define HomeForm (GUI_ID_USER +0x00)
#define panel1_HomeForm (GUI_ID_USER +0x01)
#define btnZBSJ_HomeForm (GUI_ID_USER +0x02)
#define btnQLZB_HomeForm (GUI_ID_USER +0x03)
#define btnWorkPara_HomeForm (GUI_ID_USER +0x04)
#define btnMotorPara_HomeForm (GUI_ID_USER +0x05)
#define btnDevPara_HomeForm (GUI_ID_USER +0x06)
#define btnIOStatus_HomeForm (GUI_ID_USER +0x07)
#define btnPortConfig_HomeForm (GUI_ID_USER +0x08)
#define btnMotionConfig_HomeForm (GUI_ID_USER +0x09)
#define btnMPXX_HomeForm (GUI_ID_USER +0x0A)
#define btnSystem_HomeForm (GUI_ID_USER +0x0B)
#define btnLogView_HomeForm (GUI_ID_USER +0x0C)
#define btnAbout_HomeForm (GUI_ID_USER +0x0D)
#define btnWorkForm_HomeForm (GUI_ID_USER +0x0E)
#define panel2_HomeForm (GUI_ID_USER +0x0F)
#define lbSystemTitle_HomeForm (GUI_ID_USER +0x10)
#define lbDateTime_HomeForm (GUI_ID_USER +0x11)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"HomeForm",HomeForm,0,0,800,480,0,0x0,0 },
{ EDIT_CreateIndirect,"",panel1_HomeForm,0,54,800,426,0,0x0,0 },
{ BUTTON_CreateIndirect,"坐标示教",btnZBSJ_HomeForm,22,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"取料坐标",btnQLZB_HomeForm,178,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"工作参数",btnWorkPara_HomeForm,334,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"电机参数",btnMotorPara_HomeForm,490,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"设备参数",btnDevPara_HomeForm,642,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"IO口状态",btnIOStatus_HomeForm,22,168,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"端口配置",btnPortConfig_HomeForm,178,168,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"动作配置",btnMotionConfig_HomeForm,334,168,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"铭牌信息",btnMPXX_HomeForm,490,168,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"系统管理",btnSystem_HomeForm,642,168,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"日志查看",btnLogView_HomeForm,22,268,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"关于",btnAbout_HomeForm,178,268,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"工作界面",btnWorkForm_HomeForm,642,388,130,68,0,0x0,0 },
{ EDIT_CreateIndirect,"",panel2_HomeForm,0,0,800,50,0,0x0,0 },
{ TEXT_CreateIndirect,"螺丝机自动锁付系统 V4.10",lbSystemTitle_HomeForm,45,4,430,36,0,0x0,0 },
{ TEXT_CreateIndirect,"2018-07-31 08:47:00",lbDateTime_HomeForm,557,17,238,24,0,0x0,0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE14;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE18;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem,0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,panel1_HomeForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,btnZBSJ_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnQLZB_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnWorkPara_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnMotorPara_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnDevPara_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnIOStatus_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnPortConfig_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnMotionConfig_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnMPXX_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnSystem_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnLogView_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnAbout_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnWorkForm_HomeForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,panel2_HomeForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00808080);

    hItem = WM_GetDialogItem(pMsg->hWin,lbSystemTitle_HomeForm);
    TEXT_SetText(hItem,"螺丝机自动锁付系统 V4.10");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00808080);
    TEXT_SetTextColor(hItem,0x0000FF00);

    hItem = WM_GetDialogItem(pMsg->hWin,lbDateTime_HomeForm);
    TEXT_SetText(hItem,"2018-07-31 08:47:00");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00808080);
    TEXT_SetTextColor(hItem,0x00FFFFFF);
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
		case panel1_HomeForm:
			switch(NCode)
			{
			}
			break;
		case btnZBSJ_HomeForm:
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
		case btnQLZB_HomeForm:
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
		case btnWorkPara_HomeForm:
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
		case btnMotorPara_HomeForm:
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
		case btnDevPara_HomeForm:
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
		case btnIOStatus_HomeForm:
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
		case btnPortConfig_HomeForm:
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
		case btnMotionConfig_HomeForm:
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
		case btnMPXX_HomeForm:
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
		case btnSystem_HomeForm:
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
		case btnLogView_HomeForm:
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
		case btnAbout_HomeForm:
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
		case btnWorkForm_HomeForm:
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
		case panel2_HomeForm:
			switch(NCode)
			{
			}
			break;
		case lbSystemTitle_HomeForm:
			switch(NCode)
			{
			}
			break;
		case lbDateTime_HomeForm:
			switch(NCode)
			{
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
 
