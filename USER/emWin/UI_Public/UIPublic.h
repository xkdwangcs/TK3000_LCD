#ifndef _UIPUBLIC_H_
#define _UIPUBLIC_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdbool.h"

//��һ���ַ�����Ϊ�����ĺ���ָ��
typedef void (*OneStrParaHandler)(char* para);
//���ÿؼ�¼���ַ��ĺ���ָ��
typedef void (*SetCtrTextHandler1)(int ctrID,char* para);
typedef void (*SetCtrTextHandler2)(int ctrID,int colIndex,int rowIndex,char* para);
	
	
	#ifdef __cplusplus
}
#endif

#endif 
