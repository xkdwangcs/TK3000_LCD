/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"


#define FuncMenuSelect (GUI_ID_USER +0x00)
#define panel1_FuncMenuSelect (GUI_ID_USER +0x01)
#define btnZBSJ_FuncMenuSelect (GUI_ID_USER +0x02)
#define btnQLZB_FuncMenuSelect (GUI_ID_USER +0x03)
#define btnWorkPara_FuncMenuSelect (GUI_ID_USER +0x04)
#define btnMotorPara_FuncMenuSelect (GUI_ID_USER +0x05)
#define btnDevPara_FuncMenuSelect (GUI_ID_USER +0x06)
#define btnIOStatus_FuncMenuSelect (GUI_ID_USER +0x07)
#define btnPortConfig_FuncMenuSelect (GUI_ID_USER +0x08)
#define btnMotionConfig_FuncMenuSelect (GUI_ID_USER +0x09)
#define btnMPXX_FuncMenuSelect (GUI_ID_USER +0x0A)
#define btnSystem_FuncMenuSelect (GUI_ID_USER +0x0B)
#define btnLogView_FuncMenuSelect (GUI_ID_USER +0x0C)
#define btnAbout_FuncMenuSelect (GUI_ID_USER +0x0D)
#define btnWorkForm_FuncMenuSelect (GUI_ID_USER +0x0E)
#define panel2_FuncMenuSelect (GUI_ID_USER +0x0F)
#define lbSystemTitle_FuncMenuSelect (GUI_ID_USER +0x10)
#define lbDateTime_FuncMenuSelect (GUI_ID_USER +0x11)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"功能菜单选择",FuncMenuSelect,0,0,800,480,0,0x0,0 },
{ EDIT_CreateIndirect,"",panel1_FuncMenuSelect,0,54,800,426,0,0x0,0 },
{ BUTTON_CreateIndirect,"坐标示教",btnZBSJ_FuncMenuSelect,22,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"取料坐标",btnQLZB_FuncMenuSelect,178,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"工作参数",btnWorkPara_FuncMenuSelect,334,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"电机参数",btnMotorPara_FuncMenuSelect,490,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"设备参数",btnDevPara_FuncMenuSelect,642,74,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"IO口状态",btnIOStatus_FuncMenuSelect,22,171,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"端口配置",btnPortConfig_FuncMenuSelect,178,171,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"动作配置",btnMotionConfig_FuncMenuSelect,334,171,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"铭牌信息",btnMPXX_FuncMenuSelect,490,171,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"系统管理",btnSystem_FuncMenuSelect,642,171,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"日志查看",btnLogView_FuncMenuSelect,22,268,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"关于",btnAbout_FuncMenuSelect,178,268,130,68,0,0x0,0 },
{ BUTTON_CreateIndirect,"工作界面",btnWorkForm_FuncMenuSelect,642,388,130,68,0,0x0,0 },
{ EDIT_CreateIndirect,"",panel2_FuncMenuSelect,0,0,800,50,0,0x0,0 },
{ TEXT_CreateIndirect,"螺丝机自动锁付系统 V4.10",lbSystemTitle_FuncMenuSelect,45,4,430,36,0,0x0,0 },
{ TEXT_CreateIndirect,"2018-07-31 08:47:00",lbDateTime_FuncMenuSelect,557,17,238,24,0,0x0,0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE14;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE18;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem,0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,panel1_FuncMenuSelect);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,btnZBSJ_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnQLZB_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnWorkPara_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnMotorPara_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnDevPara_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnIOStatus_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnPortConfig_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnMotionConfig_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnMPXX_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnSystem_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnLogView_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnAbout_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnWorkForm_FuncMenuSelect);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,panel2_FuncMenuSelect);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00808080);

    hItem = WM_GetDialogItem(pMsg->hWin,lbSystemTitle_FuncMenuSelect);
    TEXT_SetText(hItem,"螺丝机自动锁付系统 V4.10");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00808080);
    TEXT_SetTextColor(hItem,0x0000FF00);

    hItem = WM_GetDialogItem(pMsg->hWin,lbDateTime_FuncMenuSelect);
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
		case btnZBSJ_FuncMenuSelect:
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
		case btnQLZB_FuncMenuSelect:
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
		case btnWorkPara_FuncMenuSelect:
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
		case btnMotorPara_FuncMenuSelect:
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
		case btnDevPara_FuncMenuSelect:
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
		case btnIOStatus_FuncMenuSelect:
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
		case btnPortConfig_FuncMenuSelect:
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
		case btnMotionConfig_FuncMenuSelect:
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
		case btnMPXX_FuncMenuSelect:
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
		case btnSystem_FuncMenuSelect:
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
		case btnLogView_FuncMenuSelect:
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
		case btnAbout_FuncMenuSelect:
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
		case btnWorkForm_FuncMenuSelect:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					GUI_EndDialog(pMsg->hWin,0);
					CreateWorkForm();
					break;
			}
			break;
		case panel2_FuncMenuSelect:
			switch(NCode)
			{
			}
			break;
		case lbSystemTitle_FuncMenuSelect:
			switch(NCode)
			{
			}
			break;
		case lbDateTime_FuncMenuSelect:
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


WM_HWIN CreateFuncMenuSelect(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
