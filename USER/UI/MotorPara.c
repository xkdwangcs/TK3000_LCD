/*****************************************
*
* ФӦǿ��Ƶ�GUIBuilder���ɵ��ļ�
* V2.04 (2018.08.02)
*
******************************************/

#include "DIALOG.h"
#include "MainTask.h"
#include "CMD.h"

#define MotorPara (GUI_ID_USER +0x00)
#define gridPara_MotorPara (GUI_ID_USER +0x01)
#define btnSave_MotorPara (GUI_ID_USER +0x02)
#define btnWorkForm_MotorPara (GUI_ID_USER +0x03)
#define btnBack_MotorPara (GUI_ID_USER +0x04)


static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
{ FRAMEWIN_CreateIndirect,"���������",MotorPara,0,0,800,480,0,0x0,0 },
{ LISTVIEW_CreateIndirect,"",gridPara_MotorPara,0,0,790,385,0,0x0,0 },
{ BUTTON_CreateIndirect,"����",btnSave_MotorPara,358,392,106,42,0,0x0,0 },
{ BUTTON_CreateIndirect,"��������",btnWorkForm_MotorPara,506,392,122,42,0,0x0,0 },
{ BUTTON_CreateIndirect,"����",btnBack_MotorPara,634,392,106,42,0,0x0,0 },
};

void LoadMotorPara(WM_HWIN hItem)
{
   GetParameter();
  	for(int i=0;i<MotorPortNum;i++)
    {
      LISTVIEW_AddRow(hItem, NULL);
      LISTVIEW_SetItemText(hItem, 0, i, ConvertU32ToAscii(i+1));
      LISTVIEW_SetItemText(hItem, 1, i, ConvertFloatToAscii(Parameter.PulseK[i]));
      LISTVIEW_SetItemText(hItem, 2, i, ConvertFloatToAscii(Parameter.AxisLength[i]));
      LISTVIEW_SetItemText(hItem, 3, i, ConvertFloatToAscii(Parameter.RunSpeed[i]));
      LISTVIEW_SetItemText(hItem, 4, i, ConvertFloatToAscii(Parameter.AccSpeed[i]));
      if(Parameter.LimitMode[i]==0)
        LISTVIEW_SetItemText(hItem, 5, i, "Left");
      else if(Parameter.LimitMode[i]==1)
        LISTVIEW_SetItemText(hItem, 5, i, "Right");
    }
	
	int i=5;
	 LISTVIEW_AddRow(hItem, NULL);
     LISTVIEW_SetItemText(hItem, 0, i, "������");
     LISTVIEW_SetItemText(hItem, 1, i, ConvertFloatToAscii(Parameter.PulseK[0]));
     LISTVIEW_SetItemText(hItem, 2, i, ConvertFloatToAscii(Parameter.AxisLength[0]));
     LISTVIEW_SetItemText(hItem, 3, i, ConvertFloatToAscii(Parameter.RunSpeed[0]));
     LISTVIEW_SetItemText(hItem, 4, i, ConvertFloatToAscii(Parameter.AccSpeed[0]));
}

//��ʼ��������ؿؼ�
static void InitForm(WM_MESSAGE * pMsg){
    WM_HWIN hItem = pMsg->hWin;
    FRAMEWIN_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    FRAMEWIN_SetFont(hItem, &GUI_FontHZ24);
    FRAMEWIN_SetClientColor(hItem,0x00F0F0F0);
    FRAMEWIN_SetTextColor(hItem, 0x00000000);
    FRAMEWIN_SetMoveable(hItem, 0);//���岻���ƶ�

    hItem = WM_GetDialogItem(pMsg->hWin,gridPara_MotorPara);
    LISTVIEW_AddColumn(hItem, 100, "���", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 140, "���嵱��", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 140, "�г�[mm]", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 120, "�ٶ�", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 140, "���ٶ�", GUI_TA_HCENTER | GUI_TA_VCENTER);
    LISTVIEW_AddColumn(hItem, 160, "��λ", GUI_TA_HCENTER | GUI_TA_VCENTER);
    HEADER_Handle hHeader = LISTVIEW_GetHeader(hItem);
    HEADER_SetFont(hHeader, &GUI_FontHZ16);//������ͷ����
    LISTVIEW_SetFont(hItem, &GUI_FontHZ16);//����������
    LISTVIEW_SetRowHeight(hItem, 50);//�����и�
    LISTVIEW_SetHeaderHeight(hItem, 33);
    LISTVIEW_SetGridVis(hItem, 1);//�����߿ɼ�
    LISTVIEW_EnableCellSelect(hItem, 1);//ʹ�ܵ�Ԫ�����
    LoadMotorPara(hItem);

    hItem = WM_GetDialogItem(pMsg->hWin,btnSave_MotorPara);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnWorkForm_MotorPara);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);

    hItem = WM_GetDialogItem(pMsg->hWin,btnBack_MotorPara);
    BUTTON_SetFont(hItem, &GUI_FontHZ24);
    BUTTON_SetBkColor(hItem, BUTTON_CI_UNPRESSED, 0x00F0F0F0);
    BUTTON_SetTextColor(hItem, BUTTON_CI_UNPRESSED, 0x00000000);
}

//�ؼ��¼�������
static void DoEvent(WM_MESSAGE * pMsg)
{
    int Id = WM_GetId(pMsg->hWinSrc);
    int NCode = pMsg->Data.v;
    WM_HWIN hItem = pMsg->hWin;
    switch(Id)
    {
		case gridPara_MotorPara:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:��ť�ѱ����
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:��ť�ѱ��ͷţ�����
					hItem = WM_GetDialogItem(pMsg->hWin, gridPara_MotorPara);
					int rowIndex = LISTVIEW_GetSel(hItem);
					int colIndex = LISTVIEW_GetSelCol(hItem);
					//ShowNumKeyboard2(pMsg->hWin, LISTVIEW_SetItemText, gridPara_MotorPara, colIndex, rowIndex);
					break;
				case WM_NOTIFICATION_SEL_CHANGED:
					//DO:ѡ���ֵ�ѷ����ı�
					break;
			}
			break;
		case btnSave_MotorPara:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:��ť�ѱ����
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:��ť�ѱ��ͷţ�����
					break;
			}
			break;
		case btnWorkForm_MotorPara:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:��ť�ѱ����
					break;
				case WM_NOTIFICATION_RELEASED:
                    GUI_EndDialog(pMsg->hWin,0);
					CreateWorkForm();
					//DO:��ť�ѱ��ͷţ�����
					break;
			}
			break;
		case btnBack_MotorPara:
			switch(NCode)
			{
				case WM_NOTIFICATION_CLICKED:
					//DO:��ť�ѱ����
					break;
				case WM_NOTIFICATION_RELEASED:
					//DO:��ť�ѱ��ͷţ�����
                    GUI_EndDialog(pMsg->hWin,0);
					CreateFuncMenuSelect();
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


WM_HWIN CreateMotorPara(void) {
    WM_HWIN hWin;
    hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
    return hWin;
}
 
