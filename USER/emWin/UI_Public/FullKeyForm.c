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

#define FullKeyForm (GUI_ID_USER +0x00)
#define btn0_FullKeyForm (GUI_ID_USER +0x01)
#define btn1_FullKeyForm (GUI_ID_USER +0x02)
#define btn2_FullKeyForm (GUI_ID_USER +0x03)
#define btn3_FullKeyForm (GUI_ID_USER +0x04)
#define btn4_FullKeyForm (GUI_ID_USER +0x05)
#define btn5_FullKeyForm (GUI_ID_USER +0x06)
#define btn6_FullKeyForm (GUI_ID_USER +0x07)
#define btn7_FullKeyForm (GUI_ID_USER +0x08)
#define btn8_FullKeyForm (GUI_ID_USER +0x09)
#define btn9_FullKeyForm (GUI_ID_USER +0x0A)
#define btnA_FullKeyForm (GUI_ID_USER +0x0B)
#define btnB_FullKeyForm (GUI_ID_USER +0x0C)
#define btnC_FullKeyForm (GUI_ID_USER +0x0D)
#define btnD_FullKeyForm (GUI_ID_USER +0x0E)
#define btnE_FullKeyForm (GUI_ID_USER +0x0F)
#define btnF_FullKeyForm (GUI_ID_USER +0x10)
#define btnG_FullKeyForm (GUI_ID_USER +0x11)
#define btnH_FullKeyForm (GUI_ID_USER +0x12)
#define btnI_FullKeyForm (GUI_ID_USER +0x13)
#define btnJ_FullKeyForm (GUI_ID_USER +0x14)
#define btnK_FullKeyForm (GUI_ID_USER +0x15)
#define btnL_FullKeyForm (GUI_ID_USER +0x16)
#define btnM_FullKeyForm (GUI_ID_USER +0x17)
#define btnN_FullKeyForm (GUI_ID_USER +0x18)
#define btnO_FullKeyForm (GUI_ID_USER +0x19)
#define btnP_FullKeyForm (GUI_ID_USER +0x1A)
#define btnQ_FullKeyForm (GUI_ID_USER +0x1B)
#define btnR_FullKeyForm (GUI_ID_USER +0x1C)
#define btnS_FullKeyForm (GUI_ID_USER +0x1D)
#define btnT_FullKeyForm (GUI_ID_USER +0x1E)
#define btnU_FullKeyForm (GUI_ID_USER +0x1F)
#define btnV_FullKeyForm (GUI_ID_USER +0x20)
#define btnW_FullKeyForm (GUI_ID_USER +0x21)
#define btnX_FullKeyForm (GUI_ID_USER +0x22)
#define btnY_FullKeyForm (GUI_ID_USER +0x23)
#define btnZ_FullKeyForm (GUI_ID_USER +0x24)
#define btnSpace_FullKeyForm (GUI_ID_USER +0x25)
#define btnDH_FullKeyForm (GUI_ID_USER +0x26)
#define btnJH_FullKeyForm (GUI_ID_USER +0x27)
#define btnWH_FullKeyForm (GUI_ID_USER +0x28)
#define btnLeft_FullKeyForm (GUI_ID_USER +0x29)
#define btnRight_FullKeyForm (GUI_ID_USER +0x2A)
#define btnInputType_FullKeyForm (GUI_ID_USER +0x2B)
#define btnCaps_FullKeyForm (GUI_ID_USER +0x2C)
#define btnClear_FullKeyForm (GUI_ID_USER +0x2D)
#define btnBack_FullKeyForm (GUI_ID_USER +0x2E)
#define btnEnter_FullKeyForm (GUI_ID_USER +0x2F)
#define btnEsc_FullKeyForm (GUI_ID_USER +0x30)
#define txtInputData_FullKeyForm (GUI_ID_USER +0x31)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ WINDOW_CreateIndirect,"全键盘",FullKeyForm,0,0,754,329,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"0",btn0_FullKeyForm,587,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"1",btn1_FullKeyForm,2,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"2",btn2_FullKeyForm,67,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"3",btn3_FullKeyForm,132,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"4",btn4_FullKeyForm,197,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"5",btn5_FullKeyForm,262,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"6",btn6_FullKeyForm,327,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"7",btn7_FullKeyForm,392,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"8",btn8_FullKeyForm,457,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"9",btn9_FullKeyForm,522,67,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"A",btnA_FullKeyForm,54,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"B",btnB_FullKeyForm,363,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"C",btnC_FullKeyForm,235,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"D",btnD_FullKeyForm,184,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"E",btnE_FullKeyForm,227,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"F",btnF_FullKeyForm,249,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"G",btnG_FullKeyForm,314,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"H",btnH_FullKeyForm,379,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"I",btnI_FullKeyForm,552,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"J",btnJ_FullKeyForm,444,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"K",btnK_FullKeyForm,509,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"L",btnL_FullKeyForm,574,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"M",btnM_FullKeyForm,491,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"N",btnN_FullKeyForm,427,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"O",btnO_FullKeyForm,617,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"P",btnP_FullKeyForm,682,119,62,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Q",btnQ_FullKeyForm,97,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"R",btnR_FullKeyForm,292,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"S",btnS_FullKeyForm,119,171,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"T",btnT_FullKeyForm,357,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"U",btnU_FullKeyForm,487,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"V",btnV_FullKeyForm,299,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"W",btnW_FullKeyForm,162,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"X",btnX_FullKeyForm,171,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Y",btnY_FullKeyForm,422,119,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Z",btnZ_FullKeyForm,107,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"",btnSpace_FullKeyForm,259,276,378,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,",",btnDH_FullKeyForm,555,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,".",btnJH_FullKeyForm,619,224,63,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"?",btnWH_FullKeyForm,683,224,69,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"←",btnLeft_FullKeyForm,2,276,84,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"→",btnRight_FullKeyForm,87,276,84,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"En",btnInputType_FullKeyForm,172,276,84,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Caps",btnCaps_FullKeyForm,2,224,104,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Clear",btnClear_FullKeyForm,2,119,89,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Back",btnBack_FullKeyForm,652,67,100,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Enter",btnEnter_FullKeyForm,640,171,112,50,0, 0x0, 0 },
{ BUTTON_CreateIndirect,"Esc",btnEsc_FullKeyForm,640,276,112,50,0, 0x0, 0 },
{ EDIT_CreateIndirect,"",txtInputData_FullKeyForm,4,4,747,59,0, 0x0, 0 },
};

//初始化窗体相关控件
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    WINDOW_SetBkColor(hItem,0x0090EE90);

    hItem = WM_GetDialogItem(pMsg->hWin,btn0_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn1_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn2_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn3_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn4_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn5_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn6_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn7_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn8_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btn9_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnA_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnB_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnC_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnD_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnE_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnF_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnG_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnH_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnI_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnJ_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnK_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnL_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnM_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnN_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnO_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnP_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnQ_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnR_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnS_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnT_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnU_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnV_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnW_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnX_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnY_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnZ_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnSpace_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnDH_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnJH_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnWH_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnLeft_FullKeyForm);
    BUTTON_SetFont(hItem, &GUI_FontHZ40);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnRight_FullKeyForm);
    BUTTON_SetFont(hItem, &GUI_FontHZ40);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnInputType_FullKeyForm);
    BUTTON_SetFont(hItem, &GUI_FontHZ32);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00008000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnCaps_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00C000C0);

    hItem = WM_GetDialogItem(pMsg->hWin,btnClear_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x000040C0);

    hItem = WM_GetDialogItem(pMsg->hWin,btnBack_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnEnter_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00FF0000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnEsc_FullKeyForm);
    BUTTON_SetFont(hItem, GUI_FONT_32_ASCII);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00004000);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x000000FF);

    hItem = WM_GetDialogItem(pMsg->hWin,txtInputData_FullKeyForm);
    EDIT_SetText(hItem, "");
    EDIT_SetFont(hItem, &GUI_FontHZ32);
    EDIT_SetTextAlign(hItem, GUI_TA_VCENTER|GUI_TA_LEFT);
    EDIT_SetBkColor(hItem, EDIT_CI_ENABLED, 0x00FFFFFF);
    EDIT_SetTextColor(hItem, EDIT_CI_ENABLED, 0x00000000);
    EDIT_SetMaxLen(hItem, 50); //字符最大长度
    EDIT_EnableBlink(hItem, 500, 1); //光标闪烁
}

static WM_HWIN _thisForm;
static WM_HWIN _callForm=NULL;
static WM_HWIN _callCtrHandle=NULL;
static WM_HWIN _txtInputHandle=NULL;
static char _clickBuff[5];
static char _inputBuff[256];
static int _inputbuffIndex=0;
static int _inputCount=0;  //已录入字符的长度
static int _colIndex=0;
static int _rowIndex=0;

static OneStrParaHandler _inputedEvent=NULL;
static SetCtrTextHandler1 _setCtrTextEvent1=NULL;
static SetCtrTextHandler2 _setCtrTextEvent2=NULL;

static char _inputType=0; //0:En,1:Cn,2:123
static bool _isCaps=true;//是否为大写

static const char _keyUpper[] = {
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
'U', 'V', 'W', 'X', 'Y', 'Z', 0};

static const char _keyLow[] = {
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
'u', 'v', 'w', 'x', 'y', 'z', 0};

 static const char _keySign[] = {
'(', '~', '\'', '[','*',']', '{','}','&','<',
'(>', '`', '^', '!',':', ';','+','@',')','=',
 '#','_', '-','"','%', '|', 0};


//控件事件处理函数
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    WM_HWIN hItem=NULL;
    switch(Id)
    {
		case btn0_FullKeyForm:
		case btn1_FullKeyForm:
		case btn2_FullKeyForm:
		case btn3_FullKeyForm:
		case btn4_FullKeyForm:
		case btn5_FullKeyForm:
		case btn6_FullKeyForm:
		case btn7_FullKeyForm:
		case btn8_FullKeyForm:
		case btn9_FullKeyForm:
		case btnA_FullKeyForm:
		case btnB_FullKeyForm:
		case btnC_FullKeyForm:
		case btnD_FullKeyForm:
		case btnE_FullKeyForm:
		case btnF_FullKeyForm:
		case btnG_FullKeyForm:
		case btnH_FullKeyForm:
		case btnI_FullKeyForm:
		case btnJ_FullKeyForm:
		case btnK_FullKeyForm:
		case btnL_FullKeyForm:
		case btnM_FullKeyForm:
		case btnN_FullKeyForm:
		case btnO_FullKeyForm:
		case btnP_FullKeyForm:
		case btnQ_FullKeyForm:
		case btnR_FullKeyForm:
		case btnS_FullKeyForm:
		case btnT_FullKeyForm:
		case btnU_FullKeyForm:
		case btnV_FullKeyForm:
		case btnW_FullKeyForm:
		case btnX_FullKeyForm:
		case btnY_FullKeyForm:
		case btnZ_FullKeyForm:
		case btnSpace_FullKeyForm:
		case btnDH_FullKeyForm:
		case btnJH_FullKeyForm:
		case btnWH_FullKeyForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
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

		case btnLeft_FullKeyForm:
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
		case btnRight_FullKeyForm:
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
		case btnInputType_FullKeyForm: //123/En/Ch
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					hItem=WM_GetDialogItem(pMsg->hWin,btnInputType_FullKeyForm);
					int aID=btnA_FullKeyForm;
					char str[2];
					int i=0;
					if(_inputType==0)
                    {
                        _inputType=1; //跳到Cn模式
                        BUTTON_SetText(hItem,"汉字");
                        _isCaps=false;
                       for(i=0;i<26;i++)
                        {
                            hItem=WM_GetDialogItem(pMsg->hWin,aID+i);
                            str[0]=_keyLow[i];
                            str[1]=0;
                            BUTTON_SetText(hItem,str);
                        }
                    }
                    else if(_inputType==1)
                    {
                        _inputType=2;   //跳到”符号“模式
                        BUTTON_SetText(hItem,"符号");
                         for(i=0;i<26;i++)
                            {
                                hItem=WM_GetDialogItem(pMsg->hWin,aID+i);
                                str[0]=_keySign[i];
                                str[1]=0;
                                BUTTON_SetText(hItem,str);
                            }
                    }
                    else if(_inputType==2)
                    {
                        _inputType=0; //跳到En模式
                        BUTTON_SetText(hItem,"En");
                        _isCaps=true;
                        for(i=0;i<26;i++)
                        {
                            hItem=WM_GetDialogItem(pMsg->hWin,aID+i);
                            str[0]=_keyUpper[i];
                            str[1]=0;
                            BUTTON_SetText(hItem,str);
                        }
                    }
					break;
			}
			break;
		case btnCaps_FullKeyForm: //Caps
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					_isCaps=!_isCaps;
					int aID=btnA_FullKeyForm;
					char str[2];
					int i=0;
					if(_isCaps)
                    {
                        for(i=0;i<26;i++)
                        {
                            hItem=WM_GetDialogItem(pMsg->hWin,aID+i);
                            str[0]=_keyUpper[i];
                            str[1]=0;
                            BUTTON_SetText(hItem,str);
                        }
                    }
                    else
                    {
                       for(i=0;i<26;i++)
                        {
                            hItem=WM_GetDialogItem(pMsg->hWin,aID+i);
                            str[0]=_keyLow[i];
                            str[1]=0;
                            BUTTON_SetText(hItem,str);
                        }
                    }
					break;
			}
			break;
		case btnClear_FullKeyForm:
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
		case btnBack_FullKeyForm:
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
		case btnEnter_FullKeyForm:
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
		case btnEsc_FullKeyForm:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:按钮已被点击
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:按钮已被释放（弹起）
					WM_HideWin(pMsg->hWin);
                    //WM_DeleteWindow(pMsg->hWin);
//                    WM_ValidateWindow(WM_HBKWIN);
//                    GUI_Exec();
//                    GUI_SetBkColor(GUI_BLUE);
//                    GUI_Clear();
                    WM_ShowWindow(_callForm);
					break;
			}
			break;
		case txtInputData_FullKeyForm:
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

WM_HWIN CreateFullKeyForm(void)
{
    _thisForm = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    _txtInputHandle=WM_GetDialogItem(_thisForm,txtInputData_FullKeyForm);
    WM_HideWin(_thisForm);
    return _thisForm;
}


void ShowFullKeyboard(WM_HWIN callForm,OneStrParaHandler inputed)
{
    _setCtrTextEvent1=NULL;
    _setCtrTextEvent2=NULL;
    _inputedEvent=inputed;
    _callForm=callForm;
    //WM_AttachWindow(_keyBoardForm, callForm);
    WM_HideWindow(callForm);
    SetFormCenterScreen(_thisForm);
    WM_SetFocus(_txtInputHandle);
    WM_ShowWindow(_thisForm);
}

void ShowFullKeyboard1(WM_HWIN callForm,SetCtrTextHandler1 SetCtrTextFunc,int controlID)
{
    _inputedEvent=NULL;
    _setCtrTextEvent2=NULL;
    _setCtrTextEvent1=SetCtrTextFunc;
    _callForm=callForm;
    _callCtrHandle=WM_GetDialogItem(callForm,controlID);
    //WM_AttachWindow(_keyBoardForm, callForm);
    WM_HideWindow(callForm);
    SetFormCenterScreen(_thisForm);
    WM_SetFocus(_txtInputHandle);
    WM_ShowWindow(_thisForm);
}

void ShowFullKeyboard2(WM_HWIN callForm,SetCtrTextHandler2 SetCtrTextFunc,int controlID,int colIndex,int rowIndex)
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
    SetFormCenterScreen(_thisForm);
    WM_SetFocus(_txtInputHandle);
    WM_ShowWindow(_thisForm);
}
