/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"


#define IOStatus (GUI_ID_USER +0x00)
#define pnlInport_IOStatus (GUI_ID_USER +0x01)
#define chk1_IOStatus (GUI_ID_USER +0x02)
#define chk2_IOStatus (GUI_ID_USER +0x03)
#define chk3_IOStatus (GUI_ID_USER +0x04)
#define chk4_IOStatus (GUI_ID_USER +0x05)
#define chk5_IOStatus (GUI_ID_USER +0x06)
#define chk6_IOStatus (GUI_ID_USER +0x07)
#define chk7_IOStatus (GUI_ID_USER +0x08)
#define chk8_IOStatus (GUI_ID_USER +0x09)
#define chk9_IOStatus (GUI_ID_USER +0x0A)
#define chk10_IOStatus (GUI_ID_USER +0x0B)
#define chk11_IOStatus (GUI_ID_USER +0x0C)
#define chk12_IOStatus (GUI_ID_USER +0x0D)
#define chk13_IOStatus (GUI_ID_USER +0x0E)
#define chk14_IOStatus (GUI_ID_USER +0x0F)
#define chk15_IOStatus (GUI_ID_USER +0x10)
#define chk16_IOStatus (GUI_ID_USER +0x11)
#define chk17_IOStatus (GUI_ID_USER +0x12)
#define chk18_IOStatus (GUI_ID_USER +0x13)
#define chk19_IOStatus (GUI_ID_USER +0x14)
#define chk20_IOStatus (GUI_ID_USER +0x15)
#define chk21_IOStatus (GUI_ID_USER +0x16)
#define chk22_IOStatus (GUI_ID_USER +0x17)
#define chk23_IOStatus (GUI_ID_USER +0x18)
#define chk24_IOStatus (GUI_ID_USER +0x19)
#define pnlOutport_IOStatus (GUI_ID_USER +0x1A)
#define btn1_IOStatus (GUI_ID_USER +0x1B)
#define btn2_IOStatus (GUI_ID_USER +0x1C)
#define btn3_IOStatus (GUI_ID_USER +0x1D)
#define btn4_IOStatus (GUI_ID_USER +0x1E)
#define btn5_IOStatus (GUI_ID_USER +0x1F)
#define btn6_IOStatus (GUI_ID_USER +0x20)
#define btn7_IOStatus (GUI_ID_USER +0x21)
#define btn8_IOStatus (GUI_ID_USER +0x22)
#define btn9_IOStatus (GUI_ID_USER +0x23)
#define btn10_IOStatus (GUI_ID_USER +0x24)
#define btn11_IOStatus (GUI_ID_USER +0x25)
#define btn12_IOStatus (GUI_ID_USER +0x26)
#define btn13_IOStatus (GUI_ID_USER +0x27)
#define btn14_IOStatus (GUI_ID_USER +0x28)
#define btn15_IOStatus (GUI_ID_USER +0x29)
#define btn16_IOStatus (GUI_ID_USER +0x2A)
#define btnBack_IOStatus (GUI_ID_USER +0x2B)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"功能菜单选择",IOStatus,0,0,800,480,0,0x0,0 },
{ EDIT_CreateIndirect,"",pnlInport_IOStatus,0,12,800,170,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I01",chk1_IOStatus,32,32,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I02",chk2_IOStatus,128,32,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I03",chk3_IOStatus,224,32,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I04",chk4_IOStatus,320,32,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I05",chk5_IOStatus,416,32,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I06",chk6_IOStatus,512,32,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I07",chk7_IOStatus,608,32,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I08",chk8_IOStatus,704,32,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I09",chk9_IOStatus,32,81,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I10",chk10_IOStatus,128,81,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I11",chk11_IOStatus,224,81,61,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I12",chk12_IOStatus,320,81,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I13",chk13_IOStatus,416,81,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I14",chk14_IOStatus,512,81,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I15",chk15_IOStatus,608,81,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I16",chk16_IOStatus,704,81,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I17",chk17_IOStatus,32,130,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I18",chk18_IOStatus,128,130,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I19",chk19_IOStatus,224,130,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I20",chk20_IOStatus,320,130,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I21",chk21_IOStatus,416,130,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I22",chk22_IOStatus,512,130,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I23",chk23_IOStatus,608,130,63,20,0,0x0,0 },
{ CHECKBOX_CreateIndirect,"I24",chk24_IOStatus,704,130,63,20,0,0x0,0 },
{ EDIT_CreateIndirect,"",pnlOutport_IOStatus,0,195,800,214,0,0x0,0 },
{ BUTTON_CreateIndirect,"O1",btn1_IOStatus,19,220,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O2",btn2_IOStatus,115,220,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O3",btn3_IOStatus,211,220,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O4",btn4_IOStatus,307,220,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O5",btn5_IOStatus,403,220,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O6",btn6_IOStatus,499,220,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O7",btn7_IOStatus,595,220,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O8",btn8_IOStatus,691,220,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O9",btn9_IOStatus,19,309,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O10",btn10_IOStatus,115,309,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O11",btn11_IOStatus,211,309,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O12",btn12_IOStatus,307,309,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O13",btn13_IOStatus,403,309,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O14",btn14_IOStatus,499,309,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O15",btn15_IOStatus,595,309,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"O16",btn16_IOStatus,691,309,89,73,0,0x0,0 },
{ BUTTON_CreateIndirect,"返回",btnBack_IOStatus,635,421,106,47,0,0x0,0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE14;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE18;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem,0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,pnlInport_IOStatus);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,chk1_IOStatus);
    CHECKBOX_SetText(hItem, "I01");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk2_IOStatus);
    CHECKBOX_SetText(hItem, "I02");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk3_IOStatus);
    CHECKBOX_SetText(hItem, "I03");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk4_IOStatus);
    CHECKBOX_SetText(hItem, "I04");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk5_IOStatus);
    CHECKBOX_SetText(hItem, "I05");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk6_IOStatus);
    CHECKBOX_SetText(hItem, "I06");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk7_IOStatus);
    CHECKBOX_SetText(hItem, "I07");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk8_IOStatus);
    CHECKBOX_SetText(hItem, "I08");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk9_IOStatus);
    CHECKBOX_SetText(hItem, "I09");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk10_IOStatus);
    CHECKBOX_SetText(hItem, "I10");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk11_IOStatus);
    CHECKBOX_SetText(hItem, "I11");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk12_IOStatus);
    CHECKBOX_SetText(hItem, "I12");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk13_IOStatus);
    CHECKBOX_SetText(hItem, "I13");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk14_IOStatus);
    CHECKBOX_SetText(hItem, "I14");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk15_IOStatus);
    CHECKBOX_SetText(hItem, "I15");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk16_IOStatus);
    CHECKBOX_SetText(hItem, "I16");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk17_IOStatus);
    CHECKBOX_SetText(hItem, "I17");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk18_IOStatus);
    CHECKBOX_SetText(hItem, "I18");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk19_IOStatus);
    CHECKBOX_SetText(hItem, "I19");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk20_IOStatus);
    CHECKBOX_SetText(hItem, "I20");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk21_IOStatus);
    CHECKBOX_SetText(hItem, "I21");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk22_IOStatus);
    CHECKBOX_SetText(hItem, "I22");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk23_IOStatus);
    CHECKBOX_SetText(hItem, "I23");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,chk24_IOStatus);
    CHECKBOX_SetText(hItem, "I24");
    CHECKBOX_SetFont(hItem, GUI_FONT_24_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,pnlOutport_IOStatus);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00F0F0F0);

    hItem = WM_GetDialogItem(pMsg->hWin,btn1_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn2_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn3_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn4_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn5_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn6_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn7_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn8_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn9_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn10_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn11_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn12_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn13_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn14_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn15_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn16_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnBack_IOStatus);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}


//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {		
		case btn1_IOStatus:
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
		case btn2_IOStatus:
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
		case btn3_IOStatus:
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
		case btn4_IOStatus:
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
		case btn5_IOStatus:
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
		case btn6_IOStatus:
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
		case btn7_IOStatus:
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
		case btn8_IOStatus:
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
		case btn9_IOStatus:
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
		case btn10_IOStatus:
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
		case btn11_IOStatus:
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
		case btn12_IOStatus:
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
		case btn13_IOStatus:
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
		case btn14_IOStatus:
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
		case btn15_IOStatus:
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
		case btn16_IOStatus:
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
		case btnBack_IOStatus:
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


WM_HWIN CreateIOStatus(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
