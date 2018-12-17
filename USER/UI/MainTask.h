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

//��ȡ��ѭ�����ݺ�����
extern LoopDataReadHandler LoopDataReaded;

/*
************************************************************************
*						emWin����
************************************************************************
*/
extern GUI_CONST_STORAGE  GUI_FONT GUI_FontHZ16;
extern GUI_CONST_STORAGE  GUI_FONT GUI_FontHZ24;
extern GUI_CONST_STORAGE  GUI_FONT GUI_FontHZ32;
extern GUI_CONST_STORAGE  GUI_FONT GUI_FontHZ40;

//XBF���壬�����ֿ�̫�󣬲��ܴ���SPI flash ֱ�Ӷ�ȡ,
//����Nand Flash��ֻ�����ļ�ϵͳ�ķ�ʽ��ȡ���������ٶȽ�����
//���´����л����٣���������GBK�ֿ����SPIFlash���ֿ�оƬ
//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE14;
//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE18;
//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE24;
//extern GUI_CONST_STORAGE GUI_FONT GUI_FontYAHE32;


#endif

