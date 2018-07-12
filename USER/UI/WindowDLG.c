#include "DIALOG.h"
#include "FileOperate.h"

#define ID_WINDOW_0    (GUI_ID_USER + 0x00)
#define ID_IMAGE_0    (GUI_ID_USER + 0x01)
#define ID_TEXT_0    (GUI_ID_USER + 0x02)
#define ID_TEXT_1    (GUI_ID_USER + 0x03)
#define ID_TEXT_2    (GUI_ID_USER + 0x04)

static const GUI_WIDGET_CREATE_INFO _aDialogCreate[] = {
  { WINDOW_CreateIndirect, "Window", ID_WINDOW_0, 0, 0, 800, 480, 0, 0x0, 0 },
  { IMAGE_CreateIndirect, "Image", ID_IMAGE_0, 0, 0, 800, 480, 0, 0, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_0, 213, 74, 253, 49, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_1, 220, 319, 255, 39, 0, 0x64, 0 },
  { TEXT_CreateIndirect, "Text", ID_TEXT_2, 258, 372, 236, 34, 0, 0x64, 0 },
};

extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE36;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE40;

static void _cbDialog(WM_MESSAGE * pMsg) 
{
  WM_HWIN      hItem;
  switch (pMsg->MsgId) {
  case WM_INIT_DIALOG:
      hItem = WM_GetDialogItem(pMsg->hWin, ID_IMAGE_0);
      char* picFileName="0:/Pic/Welcome.jpg";
      int fileSize=GetFileSize(picFileName);     
      GUI_HMEM hMem = GUI_ALLOC_AllocZero(fileSize);
      // 将申请到内存的句柄转换成指针类型 
      u8* fileBuffer = GUI_ALLOC_h2p(hMem);
      bool isReadOk =ReadFile(picFileName,fileBuffer);
      if(isReadOk)
      {
          IMAGE_SetJPEG(hItem, fileBuffer, fileSize);
      }      
      //GUI_ALLOC_Free(hMem);							//在此不能释放内存
      
    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_0);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, &GUI_FontYAHE32);
    TEXT_SetText(hItem, "鑷姩鐐硅兌鎺у埗绯荤粺");

    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
    TEXT_SetText(hItem, "tk");
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_32_ASCII);

    hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
    TEXT_SetText(hItem, "http://www.tkrobot.net");
    TEXT_SetTextAlign(hItem, GUI_TA_LEFT | GUI_TA_VCENTER);
    TEXT_SetFont(hItem, GUI_FONT_24_ASCII);

    //GUI_ALLOC_Free(hMem);							//在此释放内存可以
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

WM_HWIN CreateWindow(void) {
  WM_HWIN hWin;
  hWin = GUI_CreateDialogBox(_aDialogCreate, GUI_COUNTOF(_aDialogCreate), _cbDialog, WM_HBKWIN, 0, 0);
  return hWin;
}

