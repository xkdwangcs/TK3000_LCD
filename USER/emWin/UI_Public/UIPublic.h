#ifndef _UIPUBLIC_H_
#define _UIPUBLIC_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdbool.h"

//带一个字符串作为参数的函数指针
typedef void (*OneStrParaHandler)(char* para);
//设置控件录入字符的函数指针
typedef void (*SetCtrTextHandler1)(int ctrID,char* para);
typedef void (*SetCtrTextHandler2)(int ctrID,int colIndex,int rowIndex,char* para);
	
	
	#ifdef __cplusplus
}
#endif

#endif 
