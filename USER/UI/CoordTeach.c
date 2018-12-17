/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.04 (2018.08.02)
*
******************************************/

#include "DIALOG.h"
#include "MainTask.h"

#define CoordTeach (GUI_ID_USER +0x00)
#define button2_CoordTeach (GUI_ID_USER +0x01)
#define button10_CoordTeach (GUI_ID_USER +0x02)
#define button11_CoordTeach (GUI_ID_USER +0x03)
#define button4_CoordTeach (GUI_ID_USER +0x04)
#define button6_CoordTeach (GUI_ID_USER +0x05)
#define dataGridView1_CoordTeach (GUI_ID_USER +0x06)
#define panel1_CoordTeach (GUI_ID_USER +0x07)
#define lbX_CoordTeach (GUI_ID_USER +0x08)
#define edtX_CoordTeach (GUI_ID_USER +0x09)
#define lbY_CoordTeach (GUI_ID_USER +0x0A)
#define edtY_CoordTeach (GUI_ID_USER +0x0B)
#define lbZ_CoordTeach (GUI_ID_USER +0x0C)
#define edtZ_CoordTeach (GUI_ID_USER +0x0D)
#define btnReset_CoordTeach (GUI_ID_USER +0x0E)
#define button1_CoordTeach (GUI_ID_USER +0x0F)
#define button3_CoordTeach (GUI_ID_USER +0x10)
#define button5_CoordTeach (GUI_ID_USER +0x11)
#define button7_CoordTeach (GUI_ID_USER +0x12)
#define button13_CoordTeach (GUI_ID_USER +0x13)
#define panel2_CoordTeach (GUI_ID_USER +0x14)
#define button8_CoordTeach (GUI_ID_USER +0x15)
#define button9_CoordTeach (GUI_ID_USER +0x16)
#define button12_CoordTeach (GUI_ID_USER +0x17)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"功能菜单选择",CoordTeach,0,0,800,480,0,0x0,0 },
{ BUTTON_CreateIndirect,"动作测试",button2_CoordTeach,3,419,120,50,0,0x0,0 },
{ BUTTON_CreateIndirect,"点动控制",button10_CoordTeach,540,419,119,50,0,0x0,0 },
{ BUTTON_CreateIndirect,"文件列表",button11_CoordTeach,138,419,119,50,0,0x0,0 },
{ BUTTON_CreateIndirect,"坐标列表",button4_CoordTeach,406,419,119,50,0,0x0,0 },
{ BUTTON_CreateIndirect,"坐标图例",button6_CoordTeach,272,419,119,50,0,0x0,0 },
{ LISTVIEW_CreateIndirect,"",dataGridView1_CoordTeach,222,7,574,404,0,0x0,0 },
{ EDIT_CreateIndirect,"",panel1_CoordTeach,3,7,213,278,0,0x0,0 },
{ TEXT_CreateIndirect,"X:",lbX_CoordTeach,13,16,36,29,0,0x0,0 },
{ EDIT_CreateIndirect,"100.256",edtX_CoordTeach,52,12,152,35,0,0x0,0 },
{ TEXT_CreateIndirect,"Y:",lbY_CoordTeach,13,53,33,29,0,0x0,0 },
{ EDIT_CreateIndirect,"100.256",edtY_CoordTeach,52,50,152,35,0,0x0,0 },
{ TEXT_CreateIndirect,"Z:",lbZ_CoordTeach,13,90,34,29,0,0x0,0 },
{ EDIT_CreateIndirect,"100.256",edtZ_CoordTeach,52,88,152,35,0,0x0,0 },
{ BUTTON_CreateIndirect,"新增",btnReset_CoordTeach,8,184,104,45,0,0x0,0 },
{ BUTTON_CreateIndirect,"定位",button1_CoordTeach,118,133,91,45,0,0x0,0 },
{ BUTTON_CreateIndirect,"删除",button3_CoordTeach,118,184,91,45,0,0x0,0 },
{ BUTTON_CreateIndirect,"修改",button5_CoordTeach,8,235,104,45,0,0x0,0 },
{ BUTTON_CreateIndirect,"插入",button7_CoordTeach,118,235,91,45,0,0x0,0 },
{ BUTTON_CreateIndirect,"左平台",button13_CoordTeach,8,133,104,45,0,0x0,0 },
{ EDIT_CreateIndirect,"",panel2_CoordTeach,3,291,213,120,0,0x0,0 },
{ BUTTON_CreateIndirect,"保存为取料坐标",button8_CoordTeach,8,302,201,45,0,0x0,0 },
{ BUTTON_CreateIndirect,"定位到取料坐标",button9_CoordTeach,8,353,201,45,0,0x0,0 },
{ BUTTON_CreateIndirect,"返回",button12_CoordTeach,695,419,93,50,0,0x0,0 },
};

//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem,0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,button2_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button10_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button11_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button4_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button6_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFC0FF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,dataGridView1_CoordTeach);
    LISTVIEW_AddColumn(hItem, 100, "序号", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 471, "坐标", GUI_TA_HCENTER | GUI_TA_VCENTER);
    HEADER_Handle hHeader = LISTVIEW_GetHeader(hItem);
    HEADER_SetFont(hHeader, &GUI_FontHZ16);//设置列头字体
    LISTVIEW_SetFont(hItem, &GUI_FontHZ16);//设置行字体
    LISTVIEW_SetRowHeight(hItem, 50);//设置行高
    LISTVIEW_SetHeaderHeight(hItem, 33);
    LISTVIEW_SetGridVis(hItem, 1);//网格线可见
    LISTVIEW_EnableCellSelect(hItem, 1);//使能单元格操作

    hItem = WM_GetDialogItem(pMsg->hWin,panel1_CoordTeach);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,lbX_CoordTeach);
    TEXT_SetText(hItem,"X:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,edtX_CoordTeach);
    EDIT_SetText(hItem, "100.256");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0C0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbY_CoordTeach);
    TEXT_SetText(hItem,"Y:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,edtY_CoordTeach);
    EDIT_SetText(hItem, "100.256");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0FFC0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbZ_CoordTeach);
    TEXT_SetText(hItem,"Z:");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,edtZ_CoordTeach);
    EDIT_SetText(hItem, "100.256");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFC0C0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,btnReset_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button1_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button3_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button5_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button7_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button13_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,panel2_CoordTeach);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,button8_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button9_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,button12_CoordTeach);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00ED9564);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}


//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    WM_HWIN hItem = pMsg->hWin;
    switch(Id)
    {
		case CoordTeach:
			switch(NCode)
			{
			}
			break;
		case button2_CoordTeach:
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
		case button10_CoordTeach:
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
		case button11_CoordTeach:
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
		case button4_CoordTeach:
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
		case button6_CoordTeach:
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
		case dataGridView1_CoordTeach:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					hItem = WM_GetDialogItem(pMsg->hWin, dataGridView1_CoordTeach);
					int rowIndex = LISTVIEW_GetSel(hItem);
					int colIndex = LISTVIEW_GetSelCol(hItem);
					//ShowNumKeyboard2(pMsg->hWin, LISTVIEW_SetItemText, dataGridView1_CoordTeach, colIndex, rowIndex);
					break;
				case WM_NOTIFICATION_SEL_CHANGED:
					//DO:选择的值已发生改变
					break;
			}
			break;
		case panel1_CoordTeach:
			switch(NCode)
			{
			}
			break;
		case lbX_CoordTeach:
			switch(NCode)
			{
			}
			break;
		case edtX_CoordTeach:
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
		case lbY_CoordTeach:
			switch(NCode)
			{
			}
			break;
		case edtY_CoordTeach:
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
		case lbZ_CoordTeach:
			switch(NCode)
			{
			}
			break;
		case edtZ_CoordTeach:
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
		case btnReset_CoordTeach:
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
		case button1_CoordTeach:
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
		case button3_CoordTeach:
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
		case button5_CoordTeach:
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
		case button7_CoordTeach:
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
		case button13_CoordTeach:
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
		case panel2_CoordTeach:
			switch(NCode)
			{
			}
			break;
		case button8_CoordTeach:
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
		case button9_CoordTeach:
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
		case button12_CoordTeach:
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


WM_HWIN CreateCoordTeach(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
