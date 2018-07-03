#ifndef _CMD_H
#define _CMD_H

#ifdef __cplusplus
 extern "C" {
#endif 
	 
#include <stm32f4xx.h>
#include "PublicFunction.h"
#include "string.h"
#include "Protocol.h"
	 
	//ȡ�ϲ���
	typedef struct
	{
		u16 StatusID;  //״̬ID
		char StatusDescribe[100];//״̬�����ַ���
	} StatusParaStruct;
	 
//RDD�������Ĵ���
void RDDProcess(void);
//WRT�������Ĵ���
void WRTProcess(void);   
//SRQ�������Ĵ���
void SRQProcess(void);
//OUT�������Ĵ���
void OUTProcess(void);
   
void GetParameter();
void AxisPTRun(char* axisID,char* fx);
void AxisPTStop(char* axisID);
	 
//��ȡ�豸�ͺţ�Ҳ�����������֡�����ȡ������true
bool GetDevMode(char* devModeBuff);
//��ȡ��λ����ǰ״̬
StatusParaStruct GetCurrStatus(void);
	 
#ifdef __cplusplus
}
#endif

#endif
