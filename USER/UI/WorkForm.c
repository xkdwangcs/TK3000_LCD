/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.02 (2018.07.07)
*
******************************************/

#include "DIALOG.h"
#include "CMD.h"

#define WorkForm (GUI_ID_USER +0x00)
#define lbX_WorkForm (GUI_ID_USER +0x01)
#define txtX_WorkForm (GUI_ID_USER +0x02)
#define lbY1_WorkForm (GUI_ID_USER +0x03)
#define txtY1_WorkForm (GUI_ID_USER +0x04)
#define lbY2_WorkForm (GUI_ID_USER +0x05)
#define txtY2_WorkForm (GUI_ID_USER +0x06)
#define lbZ_WorkForm (GUI_ID_USER +0x07)
#define txtZ_WorkForm (GUI_ID_USER +0x08)
#define label4_WorkForm (GUI_ID_USER +0x09)
#define cmbFileSelect_WorkForm (GUI_ID_USER +0x0A)
#define mEditMsg_WorkForm (GUI_ID_USER +0x0B)
#define label1_WorkForm (GUI_ID_USER +0x0C)
#define txtDevStatus_WorkForm (GUI_ID_USER +0x0D)
#define label8_WorkForm (GUI_ID_USER +0x0E)
#define label10_WorkForm (GUI_ID_USER +0x0F)
#define txtWorkSpeed_WorkForm (GUI_ID_USER +0x10)
#define btnJQKQ_WorkForm (GUI_ID_USER +0x11)
#define btnDDQJ_WorkForm (GUI_ID_USER +0x12)
#define btnFileEdit_WorkForm (GUI_ID_USER +0x13)
#define btnParaSet_WorkForm (GUI_ID_USER +0x14)
#define btnReset_WorkForm (GUI_ID_USER +0x15)
#define txtTotalNum_WorkForm (GUI_ID_USER +0x16)
#define btnManual_WorkForm (GUI_ID_USER +0x17)
#define btnLeftStart_WorkForm (GUI_ID_USER +0x18)
#define btnRightStart_WorkForm (GUI_ID_USER +0x19)
#define btnStop_WorkForm (GUI_ID_USER +0x1A)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"TK3000_自动点胶控制系统 V1.00",WorkForm,0,0,800,480,0, 0x0, 0 },
{ TEXT_CreateIndirect,"X",lbX_WorkForm,89,19,27,27,0, 0x0, 0 },
{ EDIT_CreateIndirect,"0.001",txtX_WorkForm,129,15,140,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Y1",lbY1_WorkForm,89,57,41,27,0, 0x0, 0 },
{ EDIT_CreateIndirect,"0.001",txtY1_WorkForm,129,52,140,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Y2",lbY2_WorkForm,89,94,41,27,0, 0x0, 0 },
{ EDIT_CreateIndirect,"0.001",txtY2_WorkForm,129,89,140,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Z",lbZ_WorkForm,89,131,27,27,0, 0x0, 0 },
{ EDIT_CreateIndirect,"0.001",txtZ_WorkForm,129,126,140,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"工作文件",label4_WorkForm,420,26,110,31,0, 0x0, 0 },
{ DROPDOWN_CreateIndirect,"",cmbFileSelect_WorkForm,524,22,246,39,0, 0x0, 0 },
{ MULTIEDIT_CreateIndirect,"",mEditMsg_WorkForm,85,173,285,187,0, 0x0, 0 },
{ TEXT_CreateIndirect,"设备状态",label1_WorkForm,419,70,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"准备就绪",txtDevStatus_WorkForm,524,66,156,39,0, 0x0, 0 },
{ TEXT_CreateIndirect,"总加工数",label8_WorkForm,420,112,110,31,0, 0x0, 0 },
{ TEXT_CreateIndirect,"工作速度",label10_WorkForm,420,152,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"100%",txtWorkSpeed_WorkForm,524,150,156,35,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"胶枪开启",btnJQKQ_WorkForm,423,227,123,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"点动出胶",btnDDQJ_WorkForm,423,291,123,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"文件编辑",btnFileEdit_WorkForm,608,231,122,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"参数设置",btnParaSet_WorkForm,608,291,122,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"复位",btnReset_WorkForm,85,376,106,54,0, 0x0, 0 },
{ EDIT_CreateIndirect,"13",txtTotalNum_WorkForm,524,110,156,35,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"手动",btnManual_WorkForm,220,376,106,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"左启动",btnLeftStart_WorkForm,355,376,129,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"右启动",btnRightStart_WorkForm,513,376,122,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"停止",btnStop_WorkForm,664,376,106,54,0, 0x0, 0 },
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
    FRAMEWIN_SetTextColor(hItem, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,lbX_WorkForm);
    TEXT_SetText(hItem,"X");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,txtX_WorkForm);
    EDIT_SetText(hItem, "0.001");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0C0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbY1_WorkForm);
    TEXT_SetText(hItem,"Y1");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,txtY1_WorkForm);
    EDIT_SetText(hItem, "0.001");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0FFC0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbY2_WorkForm);
    TEXT_SetText(hItem,"Y2");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,txtY2_WorkForm);
    EDIT_SetText(hItem, "0.001");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0FFC0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbZ_WorkForm);
    TEXT_SetText(hItem,"Z");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,txtZ_WorkForm);
    EDIT_SetText(hItem, "0.001");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFC0C0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,label4_WorkForm);
    TEXT_SetText(hItem,"工作文件");
    TEXT_SetFont(hItem,&GUI_FontYAHE24);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,cmbFileSelect_WorkForm);
    DROPDOWN_SetFont(hItem, &GUI_FontYAHE24);
    DROPDOWN_SetAutoScroll(hItem, 1);//设置自动滚动条
    DROPDOWN_SetListHeight(hItem, 100);

    hItem = WM_GetDialogItem(pMsg->hWin,mEditMsg_WorkForm);
    MULTIEDIT_SetFont(hItem, &GUI_FontYAHE24);
    //MULTIEDIT_CI_READONLY:只读模式，MULTIEDIT_CI_EDIT：编辑模式
    MULTIEDIT_SetTextColor(hItem, MULTIEDIT_CI_READONLY, 0x00000000);  //设置文本颜色
    MULTIEDIT_SetBkColor(hItem, MULTIEDIT_CI_READONLY, 0x00FFFFFF); //设置背景色
    MULTIEDIT_SetAutoScrollV(hItem, 1); //使用能垂直滚动条
    MULTIEDIT_SetInsertMode(hItem, 0);//禁止插入模式
    MULTIEDIT_SetWrapWord(hItem); //启用换行模式
    MULTIEDIT_SetReadOnly(hItem, 1); //启用只读模式
    MULTIEDIT_SetBufferSize(hItem,1024);  //此长度限定方法好像没用
    //MULTIEDIT_SetMaxLen(hItem,200);       //此长度限定方法好像没用
    MULTIEDIT_AddText(hItem, "OneText");

    hItem = WM_GetDialogItem(pMsg->hWin,label1_WorkForm);
    TEXT_SetText(hItem,"设备状态");
    TEXT_SetFont(hItem,&GUI_FontYAHE24);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,txtDevStatus_WorkForm);
    EDIT_SetText(hItem, "准备就绪");
    EDIT_SetFont(hItem, &GUI_FontYAHE24);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFFFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,label8_WorkForm);
    TEXT_SetText(hItem,"总加工数");
    TEXT_SetFont(hItem,&GUI_FontYAHE24);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,label10_WorkForm);
    TEXT_SetText(hItem,"工作速度");
    TEXT_SetFont(hItem,&GUI_FontYAHE24);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00A9A9A9);
    TEXT_SetTextColor(hItem,0x00FFFFFF);

    hItem = WM_GetDialogItem(pMsg->hWin,txtWorkSpeed_WorkForm);
    EDIT_SetText(hItem, "100%");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0FFC0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,btnJQKQ_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnDDQJ_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnFileEdit_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00008000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnParaSet_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00008000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnReset_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00008000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtTotalNum_WorkForm);
    EDIT_SetText(hItem, "13");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFFFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,btnManual_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnLeftStart_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnRightStart_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00A9A9A9);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnStop_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFFFFF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x000000FF);
}

static WM_HWIN _txtXCoord=NULL;
static WM_HWIN _txtY1Coord=NULL;
static WM_HWIN _txtY2Coord=NULL;
static WM_HWIN _txtZCoord=NULL;
static char* _coordFormat = "%.3f";//坐标格式化字符
static void ShowCurrCoord()
{
    for(int i=0;i<1000;i++)
    {
        MultiAxisCoordStruct* coord = GetCurrCoord();
       EDIT_SetText(_txtXCoord,ConvertFloatToAsciiFormat (coord->X1,_coordFormat));
        EDIT_SetText(_txtY1Coord,ConvertFloatToAsciiFormat(coord->Y1,_coordFormat));
        EDIT_SetText(_txtY2Coord,ConvertFloatToAsciiFormat(coord->Y2,_coordFormat));
        EDIT_SetText(_txtZCoord,ConvertFloatToAsciiFormat(coord->Z1,_coordFormat));
        GUI_Delay(1000);
    }
}


//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {
		case txtX_WorkForm:
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
		case txtY1_WorkForm:
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
		case txtY2_WorkForm:
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
		case txtZ_WorkForm:
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
		case cmbFileSelect_WorkForm:
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
		case mEditMsg_WorkForm:
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
		case txtDevStatus_WorkForm:
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
		case txtWorkSpeed_WorkForm:
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
		case btnJQKQ_WorkForm:
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
		case btnDDQJ_WorkForm:
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
		case btnFileEdit_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
          WM_HideWin(pMsg->hWin); 
          ShowMotorPTForm(pMsg->hWin,400,5);
					break;
			}
			break;
		case btnParaSet_WorkForm:
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
		case btnReset_WorkForm:
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
		case txtTotalNum_WorkForm:
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
		case btnManual_WorkForm:
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
		case btnLeftStart_WorkForm:
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
		case btnRightStart_WorkForm:
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
		case btnStop_WorkForm:
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


WM_HWIN CreateWorkForm(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
     _txtXCoord=WM_GetDialogItem(hWin,txtX_WorkForm);
    _txtY1Coord=WM_GetDialogItem(hWin,txtY1_WorkForm);
    _txtY2Coord=WM_GetDialogItem(hWin,txtY2_WorkForm);
    _txtZCoord=WM_GetDialogItem(hWin,txtZ_WorkForm);
    ShowCurrCoord();
    return hWin;
}
 
