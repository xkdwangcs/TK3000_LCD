
#ifndef __XBFFONT_H
#define __XBFFONT_H

#include "GUI.h"
#include "ff.h"


/*
*********************************************************************************************************
*	                                  定义XBF格式字体
*********************************************************************************************************
*/

extern char* _xbfLibName;

extern GUI_FONT GUI_FontYAHE16;
extern GUI_FONT GUI_FontYAHE20;
extern GUI_FONT GUI_FontYAHE24;
extern GUI_FONT GUI_FontYAHE32;
extern GUI_FONT GUI_FontYAHE36;
extern GUI_FONT GUI_FontYAHE40;

//extern GUI_FONT     XBF_Font24;
//extern GUI_FONT     XBF_Font32;
//extern GUI_FONT  XBF_Font;

//void GUI_SetXBF(void);

////使用XBF字体
void UseXBF(void);

#endif


