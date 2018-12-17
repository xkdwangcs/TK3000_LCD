#ifndef _UIPUBLIC_H_
#define _UIPUBLIC_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdbool.h"
#include "CMD.h"

//��һ���ַ�����Ϊ�����ĺ���ָ��
typedef void (*OneStrParaHandler)(char* para);
//���ÿؼ�¼���ַ��ĺ���ָ��
typedef void (*SetCtrTextHandler1)(int ctrID,char* para);
typedef void (*SetCtrTextHandler2)(int ctrID,int colIndex,int rowIndex,char* para);
    
//��ȡ��һ��ѭ��������Ϊ�����ĺ���ָ��
typedef void (*LoopDataReadHandler)(LoopDataStruct loopData);
//��������ĺ������
typedef  WM_HWIN (*CreateFormHandler)(void);
	
	
	#ifdef __cplusplus
}
#endif

#endif 
