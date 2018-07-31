/*****************************************
*
* 肖应强设计的GUIBuilder生成的文件
* V2.03 (2018.07.17)
*
******************************************/

#include "DIALOG.h"
#include "MainTask.h"

#define WorkForm (GUI_ID_USER +0x00)
#define pnlCoords_WorkForm (GUI_ID_USER +0x01)
#define lbX_WorkForm (GUI_ID_USER +0x02)
#define txtX_WorkForm (GUI_ID_USER +0x03)
#define lbY1_WorkForm (GUI_ID_USER +0x04)
#define txtY1_WorkForm (GUI_ID_USER +0x05)
#define lbY2_WorkForm (GUI_ID_USER +0x06)
#define txtY2_WorkForm (GUI_ID_USER +0x07)
#define lbZ_WorkForm (GUI_ID_USER +0x08)
#define txtZ_WorkForm (GUI_ID_USER +0x09)
#define mEditMsg_WorkForm (GUI_ID_USER +0x0A)
#define label4_WorkForm (GUI_ID_USER +0x0B)
#define cmbFileSelect_WorkForm (GUI_ID_USER +0x0C)
#define label1_WorkForm (GUI_ID_USER +0x0D)
#define txtLSNum_WorkForm (GUI_ID_USER +0x0E)
#define label8_WorkForm (GUI_ID_USER +0x0F)
#define txtLSIndex_WorkForm (GUI_ID_USER +0x10)
#define label2_WorkForm (GUI_ID_USER +0x11)
#define txtTimeTotal_WorkForm (GUI_ID_USER +0x12)
#define label3_WorkForm (GUI_ID_USER +0x13)
#define txtTimeAVG_WorkForm (GUI_ID_USER +0x14)
#define label5_WorkForm (GUI_ID_USER +0x15)
#define txtJGTatol_WorkForm (GUI_ID_USER +0x16)
#define label6_WorkForm (GUI_ID_USER +0x17)
#define txtBHGNum_WorkForm (GUI_ID_USER +0x18)
#define label7_WorkForm (GUI_ID_USER +0x19)
#define txtRJGNum_WorkForm (GUI_ID_USER +0x1A)
#define btnWorkParaSet_WorkForm (GUI_ID_USER +0x1B)
#define btnIOStatusForm_WorkForm (GUI_ID_USER +0x1C)
#define label10_WorkForm (GUI_ID_USER +0x1D)
#define txtWorkSpeed_WorkForm (GUI_ID_USER +0x1E)
#define btnParaForm_WorkForm (GUI_ID_USER +0x1F)
#define btnReset_WorkForm (GUI_ID_USER +0x20)
#define btnRedo_WorkForm (GUI_ID_USER +0x21)
#define btnLeftStart_WorkForm (GUI_ID_USER +0x22)
#define btnRightStart_WorkForm (GUI_ID_USER +0x23)
#define btnStop_WorkForm (GUI_ID_USER +0x24)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"TK3000_自动点胶控制系统 V1.00",WorkForm,0,0,800,480,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",pnlCoords_WorkForm,12,12,309,165,0, 0x0, 0 },
{ TEXT_CreateIndirect,"X",lbX_WorkForm,54,24,27,27,0, 0x0, 0 },
{ EDIT_CreateIndirect,"0.001",txtX_WorkForm,98,19,179,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Y1",lbY1_WorkForm,54,61,41,27,0, 0x0, 0 },
{ EDIT_CreateIndirect,"0.001",txtY1_WorkForm,98,56,179,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Y2",lbY2_WorkForm,54,98,41,27,0, 0x0, 0 },
{ EDIT_CreateIndirect,"0.001",txtY2_WorkForm,98,93,179,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"Z",lbZ_WorkForm,54,134,27,27,0, 0x0, 0 },
{ EDIT_CreateIndirect,"0.001",txtZ_WorkForm,98,130,179,35,0, 0x0, 0 },
{ MULTIEDIT_CreateIndirect,"",mEditMsg_WorkForm,12,183,309,180,0, 0x0, 0 },
{ TEXT_CreateIndirect,"工作文件",label4_WorkForm,350,21,110,31,0, 0x0, 0 },
{ DROPDOWN_CreateIndirect,"",cmbFileSelect_WorkForm,458,17,313,39,0, 0x0, 0 },
{ TEXT_CreateIndirect,"总螺丝数",label1_WorkForm,349,68,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"1",txtLSNum_WorkForm,458,66,156,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"当前螺丝",label8_WorkForm,350,115,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"2",txtLSIndex_WorkForm,458,113,156,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"总计时长",label2_WorkForm,350,158,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"3",txtTimeTotal_WorkForm,458,156,156,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"平均时长",label3_WorkForm,350,201,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"4",txtTimeAVG_WorkForm,458,199,156,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"总加工数",label5_WorkForm,350,245,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"5",txtJGTatol_WorkForm,458,242,156,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"不合格数",label6_WorkForm,350,287,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"6",txtBHGNum_WorkForm,458,285,156,35,0, 0x0, 0 },
{ TEXT_CreateIndirect,"日加工数",label7_WorkForm,350,331,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"7",txtRJGNum_WorkForm,458,328,156,35,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"工作参数",btnWorkParaSet_WorkForm,649,128,122,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"IO状态",btnIOStatusForm_WorkForm,649,189,123,54,0, 0x0, 0 },
{ TEXT_CreateIndirect,"工作速度",label10_WorkForm,645,294,110,31,0, 0x0, 0 },
{ EDIT_CreateIndirect,"100%",txtWorkSpeed_WorkForm,649,328,122,35,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"设置",btnParaForm_WorkForm,12,382,115,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"复位",btnReset_WorkForm,163,382,106,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"重打",btnRedo_WorkForm,285,382,129,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"左启动",btnLeftStart_WorkForm,417,382,129,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"右启动",btnRightStart_WorkForm,549,382,122,54,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"停止",btnStop_WorkForm,674,382,106,54,0, 0x0, 0 },
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
    FRAMEWIN_SetClientColor(hItem,0x00C0C0C0);
    FRAMEWIN_SetTextColor(hItem, 0x00000000);
    FRAMEWIN_SetMoveable(hItem, 0);//窗体不可移动

    hItem = WM_GetDialogItem(pMsg->hWin,pnlCoords_WorkForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFocussable(hItem, 0);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0C0C0);

    hItem = WM_GetDialogItem(pMsg->hWin,lbX_WorkForm);
    TEXT_SetText(hItem,"X");
    TEXT_SetFont(hItem,GUI_FONT_24_ASCII);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

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
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

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
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

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
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtZ_WorkForm);
    EDIT_SetText(hItem, "0.001");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFC0C0);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,mEditMsg_WorkForm);
    MULTIEDIT_SetFont(hItem, &GUI_FontYAHE14);
    //MULTIEDIT_CI_READONLY:只读模式，MULTIEDIT_CI_EDIT：编辑模式
    MULTIEDIT_SetTextColor(hItem, MULTIEDIT_CI_READONLY, 0x00000000);  //设置文本颜色
    MULTIEDIT_SetBkColor(hItem, MULTIEDIT_CI_READONLY, 0x00C0E0FF); //设置背景色
    MULTIEDIT_SetAutoScrollV(hItem, 1); //使用能垂直滚动条
    MULTIEDIT_SetInsertMode(hItem, 0);//禁止插入模式
    MULTIEDIT_SetWrapWord(hItem); //启用换行模式
    MULTIEDIT_SetReadOnly(hItem, 1); //启用只读模式
    MULTIEDIT_SetBufferSize(hItem,1024);  //此长度限定方法好像没用
    //MULTIEDIT_SetMaxLen(hItem,200);       //此长度限定方法好像没用
    MULTIEDIT_AddText(hItem, "OneText");

    hItem = WM_GetDialogItem(pMsg->hWin,label4_WorkForm);
    TEXT_SetText(hItem,"工作文件");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,cmbFileSelect_WorkForm);
    DROPDOWN_SetFont(hItem, &GUI_FontYAHE18);
    DROPDOWN_SetAutoScroll(hItem, 1);//设置自动滚动条
    DROPDOWN_SetListHeight(hItem, 100);

    hItem = WM_GetDialogItem(pMsg->hWin,label1_WorkForm);
    TEXT_SetText(hItem,"总螺丝数");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtLSNum_WorkForm);
    EDIT_SetText(hItem, "1");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0E0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,label8_WorkForm);
    TEXT_SetText(hItem,"当前螺丝");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtLSIndex_WorkForm);
    EDIT_SetText(hItem, "2");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0E0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,label2_WorkForm);
    TEXT_SetText(hItem,"总计时长");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtTimeTotal_WorkForm);
    EDIT_SetText(hItem, "3");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0E0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,label3_WorkForm);
    TEXT_SetText(hItem,"平均时长");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtTimeAVG_WorkForm);
    EDIT_SetText(hItem, "4");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0E0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,label5_WorkForm);
    TEXT_SetText(hItem,"总加工数");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtJGTatol_WorkForm);
    EDIT_SetText(hItem, "5");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0E0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,label6_WorkForm);
    TEXT_SetText(hItem,"不合格数");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtBHGNum_WorkForm);
    EDIT_SetText(hItem, "6");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0E0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,label7_WorkForm);
    TEXT_SetText(hItem,"日加工数");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtRJGNum_WorkForm);
    EDIT_SetText(hItem, "7");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00C0E0FF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,btnWorkParaSet_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnIOStatusForm_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE18);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,label10_WorkForm);
    TEXT_SetText(hItem,"工作速度");
    TEXT_SetFont(hItem,&GUI_FontYAHE18);
    TEXT_SetTextAlign(hItem,GUI_TA_TOP|GUI_TA_LEFT);
    TEXT_SetWrapMode(hItem, GUI_WRAPMODE_CHAR);//自动换行
    TEXT_SetBkColor(hItem,0x00C0C0C0);
    TEXT_SetTextColor(hItem,0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,txtWorkSpeed_WorkForm);
    EDIT_SetText(hItem, "100%");
    EDIT_SetFont(hItem, GUI_FONT_24_ASCII);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_HCENTER);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFFFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 0); //光标不闪烁

    hItem = WM_GetDialogItem(pMsg->hWin,btnParaForm_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnReset_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnRedo_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnLeftStart_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnRightStart_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00C0C0C0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnStop_WorkForm);
    BUTTON_SetFont(hItem, &GUI_FontYAHE24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00FFFFFF);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x000000FF);
}


static WM_HWIN _txtXCoord=NULL;
static WM_HWIN _txtY1Coord=NULL;
static WM_HWIN _txtY2Coord=NULL;
static WM_HWIN _txtZCoord=NULL;
static WM_HWIN _txtTime=NULL;
static char* _coordFormat = "%.3f";//坐标格式化字符

//char _dateStr[15];
//char _timeStr[15];
char _timeStr[30];

static void ShowCurrCoord(LoopDataStruct loopData)
{
    MultiAxisCoordStruct coord = loopData.RealCoord;
    EDIT_SetText(_txtXCoord,ConvertFloatToAsciiFormat (coord.X1,_coordFormat));
    EDIT_SetText(_txtY1Coord,ConvertFloatToAsciiFormat(coord.Y1,_coordFormat));
    EDIT_SetText(_txtY2Coord,ConvertFloatToAsciiFormat(coord.Y2,_coordFormat));
    EDIT_SetText(_txtZCoord,ConvertFloatToAsciiFormat(coord.Z1,_coordFormat));
    
    DataTimeStruct dataTime=loopData.DataTime;
    //sprintf(_dateStr,"20%02d-%02d-%02d", dataTime.Year, dataTime.Mon,dataTime.Day);
	sprintf(_timeStr,"20%02d-%02d-%02d %0.2d:%0.2d:%0.2d",dataTime.Year, 
        dataTime.Mon,dataTime.Day, dataTime.Hour, dataTime.Min, dataTime.Sec);    
    MULTIEDIT_SetText(_txtTime,_timeStr);
}

//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    switch(Id)
    {		
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
		case txtBHGNum_WorkForm:
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
		case txtRJGNum_WorkForm:
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
		case btnWorkParaSet_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					GUI_EndDialog(pMsg->hWin,0);
					CreateFuncMenuSelect();
					break;
			}
			break;
		case btnIOStatusForm_WorkForm:
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
		case txtWorkSpeed_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					ShowNumKeyboard1(pMsg->hWin,EDIT_SetText,Id);
					break;
				case WM_NOTIFICATION_VALUE_CHANGED:
					//DO:控件的值已改变
					break;
			}
			break;
		case btnParaForm_WorkForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					GUI_EndDialog(pMsg->hWin,0);
					CreateFuncMenuSelect();
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
		case btnRedo_WorkForm:
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
    WM_HWIN hItem;
    switch (pMsg->MsgId)
	{
		case WM_INIT_DIALOG:
			InitForm(pMsg);
            FileListStruct* fileList=GetFileList();
            hItem=WM_GetDialogItem(pMsg->hWin,cmbFileSelect_WorkForm);
            for(int i=0;i<fileList->FileCount;i++)
            {
                DROPDOWN_AddString(hItem,fileList->FileList[i].FileName);
            }
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
    _txtTime=WM_GetDialogItem(hWin,mEditMsg_WorkForm);
    LoopDataReaded=ShowCurrCoord;
    return hWin;
}
 
