#ifndef _HANDLERS_H_
#define _HANDLERS_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdbool.h"

//��һ���ַ�����Ϊ�����ĺ���ָ��
typedef void (*OneStrParameterHandler)(char* para);  	
//��һ��������Ϊ�����ĺ���ָ��
typedef void (*OneIntParameterHandler)(int para);  
//�޲����ĺ���ָ��
typedef void (*EventHandlerNoPara)(void);
//�����¼�����ָ��
typedef void (*PCLICK)(u16 keyCode);
//¼���ȷ������ָ��
typedef void (*PInputBoxEnter)(u16 keyCode, char* text);    
    
#ifdef __cplusplus
}
#endif

#endif 
