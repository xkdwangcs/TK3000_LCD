
/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* 2018.05.16
*
******************************************/

#include  "DIALOG.h"
#include "XBFFont.h"
#include <string.h>

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


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] =
{
    { FRAMEWIN_CreateIndirect,"NumKeyForm",NumKeyForm,0,0,540,398,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"0",btn0_NumKeyForm,0,213,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"1",btn1_NumKeyForm,0,161,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"2",btn2_NumKeyForm,132,161,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"3",btn3_NumKeyForm,264,161,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"4",btn4_NumKeyForm,0,109,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"5",btn5_NumKeyForm,132,109,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"6",btn6_NumKeyForm,264,109,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"7",btn7_NumKeyForm,0,57,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"8",btn8_NumKeyForm,132,57,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"9",btn9_NumKeyForm,264,57,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"-",btnJH_NumKeyForm,132,213,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"+",btnJH2_NumKeyForm,264,213,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"*",btnCH_NumKeyForm,1,265,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,":",btnMH_NumKeyForm,132,265,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,".",btnJH1_NumKeyForm,264,265,129,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,",",btnDH_NumKeyForm,396,265,133,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect," ",btnSpac_NumKeyForm,264,317,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"%",btnBFH_NumKeyForm,396,317,133,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"←",btnLeft_NumKeyForm,0,317,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"→",btnRight_NumKeyForm,132,317,130,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"Back",btnBack_NumKeyForm,396,57,133,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"Clear",btnClear_NumKeyForm,396,109,133,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"ESC",btnEsc_NumKeyForm,396,161,133,50,0, 0x0, 0 },
    { BUTTON_CreateIndirect,"Enter",btnEnter_NumKeyForm,396,213,133,50,0, 0x0, 0 },
    { EDIT_CreateIndirect,"",txtData_NumKeyForm,1,1,527,55,0, 0x0, 0 },
};

//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
//GUI_FONT* numFont=GUI_FONT_32_ASCII;
//带一个字符串作为参数的函数指针
typedef void (*OneStrParaHandler)(char* para);
//设置控件录入字符的函数指针
typedef void (*SetCtrTextHandler1)(int ctrID,char* para);
typedef void (*SetCtrTextHandler2)(int ctrID,int colIndex,int rowIndex,char* para);

OneStrParaHandler _inputedEvent=NULL;
SetCtrTextHandler1 _setCtrTextEvent1=NULL;
SetCtrTextHandler2 _setCtrTextEvent2=NULL;

//初始化窗体相关控件
void InitDialog_NumKeyForm(WM_MESSAGE * pMsg)
{
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem,GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, GUI_FONT_20_ASCII);
    FRAMEWIN_SetTextColor(hItem, 0x008000FF);
	//FRAMEWIN_SetClientColor(hItem,
    //FRAMEWIN_SetTitleVis(hItem, 0); //不显示标题栏
    //FRAMEWIN_SetMoveable(hItem,1); //可拖动，但有重影

    hItem = WM_GetDialogItem(pMsg->hWin,btn0_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btn1_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btn2_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);	

    hItem = WM_GetDialogItem(pMsg->hWin,btn3_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btn4_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btn5_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btn6_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btn7_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btn8_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btn9_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnJH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnJH2_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnCH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnMH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnDH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnJH1_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnBFH_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnSpac_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnLeft_NumKeyForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);

    hItem = WM_GetDialogItem(pMsg->hWin,btnRight_NumKeyForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);

    hItem = WM_GetDialogItem(pMsg->hWin,btnBack_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnClear_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnEsc_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,btnEnter_NumKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin,txtData_NumKeyForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, GUI_FONT_32_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    EDIT_SetMaxLen(hItem,100);
    EDIT_EnableBlink(hItem,500,1); //光标闪烁
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

//控件事件处理函数
void DoEvent_NumKeyForm(WM_MESSAGE * pMsg)
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
        InitDialog_NumKeyForm(pMsg);
        break;
    case WM_NOTIFY_PARENT:
        DoEvent_NumKeyForm(pMsg);
        break;
    }
}

//设备键盘为居中
void SetKeyboardCenter(WM_HWIN callForm)
{
    int fW = WM_GetWindowSizeX(callForm);
    int kW = WM_GetWindowSizeX(_thisForm);
    int fH = WM_GetWindowSizeY(callForm);
    int kH = WM_GetWindowSizeY(_thisForm);
    int x0=(fW-kW)/2;
    int y0=(fH-kH)/2;
    WM_MoveTo(_thisForm, x0, y0);
}

void ShowNumKeyboard(WM_HWIN callForm,OneStrParaHandler inputed)
{
    _setCtrTextEvent1=NULL;
    _setCtrTextEvent2=NULL;
    _inputedEvent=inputed;
    _callForm=callForm;
    //WM_AttachWindow(_keyBoardForm, callForm);
    WM_HideWindow(callForm);
    SetKeyboardCenter(callForm);
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
    SetKeyboardCenter(callForm);
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
    SetKeyboardCenter(callForm);
    WM_SetFocus(_txtInputHandle);
    WM_ShowWindow(_thisForm);
}

WM_HWIN CreateNumKeyForm(void)
{
    _thisForm = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    _txtInputHandle=WM_GetDialogItem(_thisForm,txtData_NumKeyForm);
    WM_HideWin(_thisForm);
    return _thisForm;
}

