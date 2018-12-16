#ifndef __MainTask_H
#define __MainTask_H

#include "GUI.h"
#include "DIALOG.h"
#include "WM.h"
#include "BUTTON.h"
#include "CHECKBOX.h"
#include "DROPDOWN.h"
#include "EDIT.h"
#include "FRAMEWIN.h"
#include "LISTBOX.h"
#include "MULTIEDIT.h"
#include "RADIO.h"
#include "SLIDER.h"
#include "TEXT.h"
#include "PROGBAR.h"
#include "SCROLLBAR.h"
#include "LISTVIEW.h"
#include "GRAPH.h"
#include "MENU.h"
#include "MULTIPAGE.h"
#include "ICONVIEW.h"
#include "TREEVIEW.h"
#include "UIPublic.h"
//#include "XBFFont.h"

//读取到循环数据后引发
extern LoopDataReadHandler LoopDataReaded;

/*
************************************************************************
*						emWin字体
************************************************************************
*/
extern GUI_CONST_STORAGE  GUI_FONT GUI_FontHZ16;
extern GUI_CONST_STORAGE  GUI_FONT GUI_FontHZ24;
extern GUI_CONST_STORAGE  GUI_FONT GUI_FontHZ32;
extern GUI_CONST_STORAGE  GUI_FONT GUI_FontHZ40;

//XBF字体，由于字库太大，不能存入SPI flash 直接读取,
//放入Nand Flash又只能用文件系统的方式读取，这样又速度较慢，
//导致窗体切换卡顿，所以先用GBK字库存入SPIFlash或字库芯片
//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE14;
//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE18;
//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;


#endif

