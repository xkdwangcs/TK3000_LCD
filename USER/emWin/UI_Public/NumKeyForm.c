/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"
#include "MainTask.h"
#include <string.h>
#include "UIPublic.h"


#define NumKeyForm (GUI_ID_USER +0x00)
#define btn0_NumKeyForm (GUI_ID_USER +0x01)
#define btn1_NumKeyForm (GUI_ID_USER +0x02)
#define btn2_NumKeyForm (GUI_ID_USER +0x03)
#define btn3_NumKeyForm (GUI_ID_USER +0x04)
#define btn4_NumKeyForm (GUI_ID_USER +0x05)
#define btn5_NumKeyForm (GUI_ID_USER +0x06)
#define btn6_NumKeyForm (GUI_ID_USER +0x07)
#define btn7_NumKeyForm (GUI_ID_USER +0x08)
#define btn8_NumKeyForm (GUI_ID_USER +0x09)
#define btn9_NumKeyForm (GUI_ID_USER +0x0A)
#define btnJH_NumKeyForm (GUI_ID_USER +0x0B)
#define btnJH2_NumKeyForm (GUI_ID_USER +0x0C)
#define btnCH_NumKeyForm (GUI_ID_USER +0x0D)
#define btnMH_NumKeyForm (GUI_ID_USER +0x0E)
#define btnJH1_NumKeyForm (GUI_ID_USER +0x0F)
#define btnDH_NumKeyForm (GUI_ID_USER +0x10)
#define btnSpac_NumKeyForm (GUI_ID_USER +0x11)
#define btnBFH_NumKeyForm (GUI_ID_USER +0x12)
#define btnLeft_NumKeyForm (GUI_ID_USER +0x13)
#define btnRight_NumKeyForm (GUI_ID_USER +0x14)
#define btnBack_NumKeyForm (GUI_ID_USER +0x15)
#define btnClear_NumKeyForm (GUI_ID_USER +0x16)
#define btnEsc_NumKeyForm (GUI_ID_USER +0x17)
#define btnEnter_NumKeyForm (GUI_ID_USER +0x18)
#define txtData_NumKeyForm (GUI_ID_USER +0x19)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"数字键盘",NumKeyForm,0,0,532,374,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"0",btn0_NumKeyForm,1,217,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"1",btn1_NumKeyForm,1,165,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"2",btn2_NumKeyForm,133,165,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"3",btn3_NumKeyForm,265,165,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"4",btn4_NumKeyForm,1,113,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"5",btn5_NumKeyForm,133,113,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"6",btn6_NumKeyForm,265,113,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"7",btn7_NumKeyForm,1,61,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"8",btn8_NumKeyForm,133,61,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"9",btn9_NumKeyForm,265,61,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"-",btnJH_NumKeyForm,133,217,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"+",btnJH2_NumKeyForm,265,217,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"*",btnCH_NumKeyForm,2,269,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,":",btnMH_NumKeyForm,133,269,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,".",btnJH1_NumKeyForm,265,269,129,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,",",btnDH_NumKeyForm,397,269,133,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect," ",btnSpac_NumKeyForm,265,321,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"%",btnBFH_NumKeyForm,397,321,133,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"←",btnLeft_NumKeyForm,1,321,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"→",btnRight_NumKeyForm,133,321,130,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Back",btnBack_NumKeyForm,397,61,133,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Clear",btnClear_NumKeyForm,397,113,133,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"ESC",btnEsc_NumKeyForm,397,165,133,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Enter",btnEnter_NumKeyForm,397,217,133,50,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtData_NumKeyForm,2,2,527,57,0, 0x0, 0 },
};

//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem,0x0090EE90);

    hItem = WM_GetDialogItem(pMsg->hWin,btn0_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn1_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn2_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn3_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn4_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn5_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn6_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn7_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn8_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn9_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnJH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnJH2_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnCH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnMH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnJH1_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnDH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnSpac_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnBFH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnLeft_NumKeyForm);
    BUTTON_SetFont(hItem, &GUI_FontHZ40);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnRight_NumKeyForm);
    BUTTON_SetFont(hItem, &GUI_FontHZ40);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnBack_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnClear_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnEsc_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x000080FF);

    hItem = WM_GetDialogItem(pMsg->hWin,btnEnter_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x0090EE90);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00FF0000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtData_NumKeyForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFFFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 1); //光标闪烁
}


static WM_HWIN _thisForm;
static WM_HWIN _callForm=NULL;
WM_HWIN _callCtrHandle=NULL;
WM_HWIN _txtInputHandle=NULL;
char _clickBuff[5];
char _inputBuff[256];
int _inputbuffIndex=0;
int _inputCount=0;  //已录入字符的长度
int _colIndex=0;
int _rowIndex=0;

OneStrParaHandler _inputedEvent=NULL;
SetCtrTextHandler1 _setCtrTextEvent1=NULL;
SetCtrTextHandler2 _setCtrTextEvent2=NULL;


//控件事件处理函数
void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {
    case btnEnter_NumKeyForm:
        switch(NCode)
        {
        case WM_NOTIFICATION_CLICKED:
            //DO:按钮已被点击
            break;
        case WM_NOTIFICATION_RELEASED:
            //DO:按钮已被释放（弹起）
            WM_HideWin(pMsg->hWin);
            WM_ShowWindow(_callForm);
            if(_inputedEvent!=NULL)
            {
                _inputedEvent(_inputBuff);
            }
            else if(_setCtrTextEvent1!=NULL)
            {
                _setCtrTextEvent1(_callCtrHandle,_inputBuff);
            }
            else if(_setCtrTextEvent2!=NULL)
            {
                _setCtrTextEvent2(_callCtrHandle,_colIndex,_rowIndex,_inputBuff);
            }
            break;
        }
        break;
    case btnEsc_NumKeyForm:
        switch(NCode)
        {
        case WM_NOTIFICATION_CLICKED:
            //DO:按钮已被点击
            break;
        case WM_NOTIFICATION_RELEASED:
            //DO:按钮已被释放（弹起）
            WM_HideWin(pMsg->hWin);
            WM_ShowWindow(_callForm);
            break;
        }
        break;
    case btnBack_NumKeyForm:
        switch(NCode)
        {
        case WM_NOTIFICATION_CLICKED:
            //DO:按钮已被点击
            break;
        case WM_NOTIFICATION_RELEASED:
            //DO:按钮已被释放（弹起）
            _inputbuffIndex=EDIT_GetCursorCharPos(_txtInputHandle);
            if(_inputbuffIndex>0)
            {
                if(_inputbuffIndex>=_inputCount-1)//从后面删除字符
                {
                    _inputBuff[--_inputbuffIndex]='\0';
                }
                else//从中间删除字符
                {
                    int i=_inputbuffIndex;
                    for(; i<_inputCount; i++)
                    {
                        _inputBuff[i-1]=_inputBuff[i];
                    }
                    _inputBuff[_inputCount-1]='\0';
                    _inputbuffIndex--;
                }
                _inputCount--;
                EDIT_SetText(_txtInputHandle, _inputBuff);
            }
            EDIT_SetCursorAtChar(_txtInputHandle,_inputbuffIndex);
            WM_SetFocus(_txtInputHandle);
            break;
        }
        break;
    case btnClear_NumKeyForm:
        switch(NCode)
        {
        case WM_NOTIFICATION_CLICKED:
            //DO:按钮已被点击
            break;
        case WM_NOTIFICATION_RELEASED:
            //DO:按钮已被释放（弹起）
            memset(_inputBuff,0,sizeof(_inputBuff));
            _inputbuffIndex=0;
            _inputCount=0;
            EDIT_SetText(_txtInputHandle, _inputBuff);
            WM_SetFocus(_txtInputHandle);
            break;
        }
        break;
    case btnLeft_NumKeyForm:
        switch(NCode)
        {
        case WM_NOTIFICATION_CLICKED:
            //DO:按钮已被点击
            break;
        case WM_NOTIFICATION_RELEASED:
            //DO:按钮已被释放（弹起）
            _inputbuffIndex=EDIT_GetCursorCharPos(_txtInputHandle);
            if(_inputbuffIndex>0)
            {
                _inputbuffIndex--;
            }
            EDIT_SetCursorAtChar(_txtInputHandle,_inputbuffIndex);
            WM_SetFocus(_txtInputHandle);
            break;
        }
        break;
    case btnRight_NumKeyForm:
        switch(NCode)
        {
        case WM_NOTIFICATION_CLICKED:
            //DO:按钮已被点击
            break;
        case WM_NOTIFICATION_RELEASED:
            //DO:按钮已被释放（弹起）
            _inputbuffIndex=EDIT_GetCursorCharPos(_txtInputHandle);
            if(_inputbuffIndex<_inputCount)
            {
                _inputbuffIndex++;
            }
            EDIT_SetCursorAtChar(_txtInputHandle,_inputbuffIndex);
            WM_SetFocus(_txtInputHandle);
            break;
        }
        break;
    case btn0_NumKeyForm:
    case btn1_NumKeyForm:
    case btn2_NumKeyForm:
    case btn3_NumKeyForm:
    case btn4_NumKeyForm:
    case btn5_NumKeyForm:
    case btn6_NumKeyForm:
    case btn7_NumKeyForm:
    case btn8_NumKeyForm:
    case btn9_NumKeyForm:
    case btnJH_NumKeyForm:      //-
    case btnJH1_NumKeyForm:     //.
    case btnJH2_NumKeyForm:     //+
    case btnMH_NumKeyForm:      //:
    case btnDH_NumKeyForm:      //,
    case btnSpac_NumKeyForm:    //空格
    case btnCH_NumKeyForm:      //*
    case btnBFH_NumKeyForm:     //%
        switch(NCode)
        {
        case WM_NOTIFICATION_CLICKED:
            //DO:按钮已被点击
            break;
        case WM_NOTIFICATION_RELEASED:
            if(_inputbuffIndex<0)
                _inputbuffIndex=0;
            BUTTON_GetText(pMsg->hWinSrc, &_clickBuff[0], sizeof(_clickBuff));
            _inputbuffIndex=EDIT_GetCursorCharPos(_txtInputHandle);
            if(_inputbuffIndex>=_inputCount) //在后面添加字符
            {
                _inputBuff[_inputbuffIndex++]=_clickBuff[0];
            }
            else //在中间插入字符
            {
                int i=_inputCount;
                for(; i>_inputbuffIndex; i--)
                {
                    _inputBuff[i]=_inputBuff[i-1];
                }
                _inputBuff[_inputbuffIndex++]=_clickBuff[0];
            }
            _inputCount++;
            EDIT_SetText(_txtInputHandle, _inputBuff);
            EDIT_SetCursorAtChar(_txtInputHandle,_inputbuffIndex);
            WM_SetFocus(_txtInputHandle);
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

WM_HWIN CreateNumKeyForm(void)
{
    _thisForm = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    _txtInputHandle=WM_GetDialogItem(_thisForm,txtData_NumKeyForm);
    WM_HideWin(_thisForm);
    return _thisForm;
}

void ShowNumKeyboard(WM_HWIN callForm,OneStrParaHandler inputed)
{
    _setCtrTextEvent1=NULL;
    _setCtrTextEvent2=NULL;
    _inputedEvent=inputed;
    _callForm=callForm;
    //WM_AttachWindow(_keyBoardForm, callForm);
    WM_HideWindow(callForm);
    SetFormCenterPrent(callForm,_thisForm);
    WM_SetFocus(_txtInputHandle);
    WM_ShowWindow(_thisForm);
}

void ShowNumKeyboard1(WM_HWIN callForm,SetCtrTextHandler1 SetCtrTextFunc,int controlID)
{
    _inputedEvent=NULL;
    _setCtrTextEvent2=NULL;
    _setCtrTextEvent1=SetCtrTextFunc;
    _callForm=callForm;
    _callCtrHandle=WM_GetDialogItem(callForm,controlID);
    //WM_AttachWindow(_keyBoardForm, callForm);
    WM_HideWindow(callForm);
    SetFormCenterPrent(callForm,_thisForm);
    WM_SetFocus(_txtInputHandle);
    WM_ShowWindow(_thisForm);
}

void ShowNumKeyboard2(WM_HWIN callForm,SetCtrTextHandler2 SetCtrTextFunc,int controlID,int colIndex,int rowIndex)
{
    _inputedEvent=NULL;
    _setCtrTextEvent1=NULL;
    _setCtrTextEvent2=SetCtrTextFunc;
    _callForm=callForm;
    _callCtrHandle=WM_GetDialogItem(callForm,controlID);
    _colIndex=colIndex;
    _rowIndex=rowIndex;
    //WM_AttachWindow(_keyBoardForm, callForm);
    WM_HideWindow(callForm);
    SetFormCenterPrent(callForm,_thisForm);
    WM_SetFocus(_txtInputHandle);
    WM_ShowWindow(_thisForm);
}
