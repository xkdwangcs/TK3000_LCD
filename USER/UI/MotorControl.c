/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"
#include "MainTask.h"


#define MotorControl (GUI_ID_USER +0x00)
#define lbX_MotorControl (GUI_ID_USER +0x01)
#define edtX_MotorControl (GUI_ID_USER +0x02)
#define lbY_MotorControl (GUI_ID_USER +0x03)
#define edtY_MotorControl (GUI_ID_USER +0x04)
#define lbZ_MotorControl (GUI_ID_USER +0x05)
#define edtZ_MotorControl (GUI_ID_USER +0x06)
#define edtSDPer_MotorControl (GUI_ID_USER +0x07)
#define cmbPTSelect_MotorControl (GUI_ID_USER +0x08)
#define btnOK_MotorControl (GUI_ID_USER +0x09)
#define btnCancel_MotorControl (GUI_ID_USER +0x0A)
#define pnlPointBut_MotorControl (GUI_ID_USER +0x0B)
#define btnXLeft_MotorControl (GUI_ID_USER +0x0C)
#define btnXRight_MotorControl (GUI_ID_USER +0x0D)
#define btnYBack_MotorControl (GUI_ID_USER +0x0E)
#define btnYFront_MotorControl (GUI_ID_USER +0x0F)
#define btnZUp_MotorControl (GUI_ID_USER +0x10)
#define btnZDown_MotorControl (GUI_ID_USER +0x11)
#define cmbSpeedType_MotorControl (GUI_ID_USER +0x12)
#define btnReset_MotorControl (GUI_ID_USER +0x13)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"电机点动控制",MotorControl,0,0,392,471,0,0x0,0 },
{ TEXT_CreateIndirect,"X:",lbX_MotorControl,14,14,36,29,0,0x0,0 },
{ EDIT_CreateIndirect,"100.256",edtX_MotorControl,53,10,123,35,0,0x0,0 },
{ TEXT_CreateIndirect,"Y:",lbY_MotorControl,14,51,33,29,0,0x0,0 },
{ EDIT_CreateIndirect,"100.256",edtY_MotorControl,53,48,123,35,0,0x0,0 },
{ TEXT_CreateIndirect,"Z:",lbZ_MotorControl,14,88,34,29,0,0x0,0 },
{ EDIT_CreateIndirect,"100.256",edtZ_MotorControl,53,86,123,35,0,0x0,0 },
{ EDIT_CreateIndirect,"100%",edtSDPer_MotorControl,259,82,101,35,0,0x0,0 },
{ DROPDOWN_CreateIndirect,"左平台",cmbPTSelect_MotorControl,259,14,101,39,0,0x0,0 },
{ BUTTON_CreateIndirect,"确定",btnOK_MotorControl,169,390,89,41,0,0x0,0 },
{ BUTTON_CreateIndirect,"返回",btnCancel_MotorControl,271,390,89,41,0,0x0,0 },
{ EDIT_CreateIndirect,"",pnlPointBut_MotorControl,1,129,385,248,0,0x0,0 },
{ BUTTON_CreateIndirect,"X左",btnXLeft_MotorControl,13,221,140,64,0,0x0,0 },
{ BUTTON_CreateIndirect,"X右",btnXRight_MotorControl,232,221,140,64,0,0x0,0 },
{ BUTTON_CreateIndirect,"Y后",btnYBack_MotorControl,13,144,92,72,0,0x0,0 },
{ BUTTON_CreateIndirect,"Y前",btnYFront_MotorControl,13,291,92,72,0,0x0,0 },
{ BUTTON_CreateIndirect,"Z上",btnZUp_MotorControl,280,144,92,72,0,0x0,0 },
{ BUTTON_CreateIndirect,"Z下",btnZDown_MotorControl,280,291,92,72,0,0x0,0 },
{ DROPDOWN_CreateIndirect,"慢",cmbSpeedType_MotorControl,154,312,89,39,0,0x0,0 },
{ BUTTON_CreateIndirect,"复位",btnReset_MotorControl,154,144,89,50,0,0x0,0 },
};


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontHZ24);
    FRAMEWIN_SetClientColor(hItem,0x00A9A9A9);
    FRAMEWIN_SetTextColor(hItem, 0x00FFFFFF);
    FRAMEWIN_SetMoveable(hItem, 0);//窗体不可移动

    hItem = WM_GetDialogItem(pMsg->hWin,lbX_MotorControl);
    TEXT_SetText(hItem,"X:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,edtX_MotorControl);
    EDIT_SetText(hItem, "100.256");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0C0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbY_MotorControl);
    TEXT_SetText(hItem,"Y:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,edtY_MotorControl);
    EDIT_SetText(hItem, "100.256");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0FFC0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbZ_MotorControl);
    TEXT_SetText(hItem,"Z:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,edtZ_MotorControl);
    EDIT_SetText(hItem, "100.256");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFC0C0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,edtSDPer_MotorControl);
    EDIT_SetText(hItem, "100%");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFFFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,cmbPTSelect_MotorControl);
    DROPDOWN_SetFont(hItem, &GUI_FontHZ24);
    DROPDOWN_AddString(hItem, "左平台");
    DROPDOWN_AddString(hItem, "右平台");
    DROPDOWN_SetAutoScroll(hItem, 1);//设置自动滚动条
    DROPDOWN_SetListHeight(hItem, 100);

    hItem = WM_GetDialogItem(pMsg->hWin,btnOK_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnCancel_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,pnlPointBut_MotorControl);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00A9A9A9);

    hItem = WM_GetDialogItem(pMsg->hWin,btnXLeft_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnXRight_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnYBack_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0FFC0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnYFront_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0FFC0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnZUp_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnZDown_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,cmbSpeedType_MotorControl);
    DROPDOWN_SetFont(hItem, &GUI_FontHZ24);
    DROPDOWN_AddString(hItem, "慢");
    DROPDOWN_AddString(hItem, "中");
    DROPDOWN_AddString(hItem, "快");
    DROPDOWN_SetAutoScroll(hItem, 1);//设置自动滚动条
    DROPDOWN_SetListHeight(hItem, 100);

    hItem = WM_GetDialogItem(pMsg->hWin,btnReset_MotorControl);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}

static WM_HWIN _thisForm;
static WM_HWIN _callForm=NULL;

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
                    AxisPTRun("X","FFX");	
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
                    AxisPTStop("X");
					break;
			}
			break;
		case btnXRight_MotorControl:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
          AxisPTRun("X","ZFX");
//           MoveToCoord(X,10,true); 
//           for(u8 i=0;i<5;i++)
//           {
//               MoveToCoord(X,300,true);
//               MoveToCoord(X,5,true);
//           }
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
          AxisPTStop("X");
					break;
			}
			break;
		case btnYBack_MotorControl:
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
		case btnYFront_MotorControl:
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
		case btnZUp_MotorControl:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
                    AxisPTRun("Z","FFX");	
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
                    AxisPTStop("Z");
					break;
			}
			break;
		case btnZDown_MotorControl:
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
                    LoopDataReaded=NULL;
                    WM_HideWin(pMsg->hWin);
                    WM_ShowWin(_callForm);
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
                    LoopDataReaded=NULL;
                    WM_HideWin(pMsg->hWin);
                    WM_ShowWin(_callForm);
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

static WM_HWIN _txtXCoord=NULL;
static WM_HWIN _txtYCoord=NULL;
static WM_HWIN _txtZCoord=NULL;
static char* _coordFormat = "%.3f";//坐标格式化字符
static void ShowCurrCoord(LoopDataStruct loopData)
{
    MultiAxisCoordStruct coord =loopData.RealCoord;
    EDIT_SetText(_txtXCoord,ConvertFloatToAsciiFormat (coord.X1,_coordFormat));
    EDIT_SetText(_txtYCoord,ConvertFloatToAsciiFormat(coord.Y1,_coordFormat));
    EDIT_SetText(_txtZCoord,ConvertFloatToAsciiFormat(coord.Z1,_coordFormat));
}

WM_HWIN CreateMotorControl(void) 
{
    _thisForm = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    _txtXCoord=WM_GetDialogItem(_thisForm,edtX_MotorControl);
    _txtYCoord=WM_GetDialogItem(_thisForm,edtY_MotorControl);
    _txtZCoord=WM_GetDialogItem(_thisForm,edtZ_MotorControl);
    WM_HideWin(_thisForm);
    return _thisForm;
}
 
//在指定的（x0,y0)位置显示电机点动控制窗体
void ShowMotorPTForm(WM_HWIN callForm,int x0,int y0)
{
    _callForm=callForm;
    WM_MoveTo(_thisForm, x0, y0);
    WM_ShowWin(_thisForm);
    LoopDataReaded=ShowCurrCoord;
}

