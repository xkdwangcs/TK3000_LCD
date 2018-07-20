/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"
#include "CMD.h"


#define Register (GUI_ID_USER +0x00)
#define lbDevCode_Register (GUI_ID_USER +0x01)
#define txtDevCode_Register (GUI_ID_USER +0x02)
#define lbRegCode_Register (GUI_ID_USER +0x03)
#define mEdtRegCode_Register (GUI_ID_USER +0x04)
#define lbMsg_Register (GUI_ID_USER +0x05)
#define btnReg_Register (GUI_ID_USER +0x06)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"请录入注册码",Register,200,200,639,441,0, 0x0, 0 },
{ TEXT_CreateIndirect,"机器码",lbDevCode_Register,84,66,114,41,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtDevCode_Register,201,64,337,44,0, 0x0, 0 },
{ TEXT_CreateIndirect,"注册码",lbRegCode_Register,84,141,114,41,0, 0x0, 0 },
{ MULTIEDIT_CreateIndirect,"ABC",mEdtRegCode_Register,201,137,337,111,0, 0x0, 0 },
{ TEXT_CreateIndirect,"*",lbMsg_Register,86,265,482,41,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"注册",btnReg_Register,391,322,111,40,0, 0x0, 0 },
};


extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE14;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE18;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;


//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontYAHE18);
    FRAMEWIN_SetClientColor(hItem,0x00F0F0F0);
    FRAMEWIN_SetTextColor(hItem, 0x00000000);
    FRAMEWIN_SetMoveable(hItem, 0);//窗体不可移动

    hItem = WM_GetDialogItem(pMsg->hWin,lbDevCode_Register);
    TEXT_SetText(hItem,"机器码");
    TEXT_SetFont(hItem,&GUI_FontYAHE24);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtDevCode_Register);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, &GUI_FontYAHE32);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00E1FFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,lbRegCode_Register);
    TEXT_SetText(hItem,"注册码");
    TEXT_SetFont(hItem,&GUI_FontYAHE24);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,mEdtRegCode_Register);
    MULTIEDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    //MULTIEDIT_CI_READONLY:只读模式，MULTIEDIT_CI_EDIT：编辑模式
    MULTIEDIT_SetTextColor(hItem, MULTIEDIT_CI_READONLY, 0x00000000);  //设置文本颜色
    MULTIEDIT_SetBkColor(hItem, MULTIEDIT_CI_READONLY, 0x00FFFFFF); //设置背景色
    MULTIEDIT_SetAutoScrollV(hItem, 1); //使用能垂直滚动条
    MULTIEDIT_SetInsertMode(hItem, 0);//禁止插入模式
    MULTIEDIT_SetWrapWord(hItem); //启用换行模式
    MULTIEDIT_SetReadOnly(hItem, 1); //启用只读模式
    MULTIEDIT_SetBufferSize(hItem,1024);  //此长度限定方法好像没用
    //MULTIEDIT_SetMaxLen(hItem,200);       //此长度限定方法好像没用
    MULTIEDIT_AddText(hItem, "*设备有效使用日期已过，请注册设备！");

    hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_Register);
    TEXT_SetText(hItem,"*");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_VCENTER|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00F0F0F0);
    TEXT_SetTextColor(hItem,0x000000FF);

    hItem = WM_GetDialogItem(pMsg->hWin,btnReg_Register);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}

//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
	WM_HWIN	hItem;
    switch(Id)
    {
		case txtDevCode_Register:
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
		case mEdtRegCode_Register:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					//ShowNumKeyboard1(pMsg->hWin,EDIT_SetText,Id);
					ShowFullKeyboard1(pMsg->hWin,EDIT_SetText,Id);
					break;
				case WM_NOTIFICATION_VALUE_CHANGED:
					//DO:控件的值已改变
					break;
			}
			break;
		case btnReg_Register:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					hItem = WM_GetDialogItem(pMsg->hWin,txtDevCode_Register);
					char regNum[20]={0};
					EDIT_GetText(hItem,regNum,20);
					RegisterDevice(regNum);					
					while(true)
					{
						StatusParaStruct status = GetCurrStatus();
						if(status.DevStatus==DevReady) //注册成功，跳转到主界面
						{
							GUI_EndDialog(pMsg->hWin, 0);
							CreateWorkForm();
							return;
						}
						else if(status.DevStatus!=NoGetStatus)
						{							
							char* msg=status.StatusDescribe;
							hItem = WM_GetDialogItem(pMsg->hWin,lbMsg_Register);
                            TEXT_SetText(hItem,msg);
						}
						GUI_Delay(500);
					}
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


WM_HWIN CreateRegister(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
	SetFormCenterScreen(hWin);
    return hWin;
}
 
