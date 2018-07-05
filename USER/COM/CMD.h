#ifndef _CMD_H
#define _CMD_H

#ifdef __cplusplus
 extern "C" {
#endif 
	 
#include <stm32f4xx.h>
#include "PublicFunction.h"
#include "string.h"
#include "Protocol.h"
#include "Parameter.h"
#include "SysParameter.h"
#include "USBFunc_Ctr.h"	

typedef enum
{
	DeviceIniting,		//�豸��ʼ����
	TaskInitFail,		//�����ʼ��ʧ��
	RegWait,			//�ȴ�ע��
	DevReady,			//�豸׼������	
	DevWorking,			//�豸���ڹ�����	
	DevScram,			//��ͣ�У���ѯ����������
	USBInsert,			//USB�Ѳ��룬��ѯ����������	
	NoGetStatus,	//û�ж����豸״̬
}DeviceStatusEnum;	 	 
	 
//�豸״̬������
typedef struct
{
	DeviceStatusEnum DevStatus;  	//�豸״̬
	char StatusDescribe[100];	//״̬�����ַ���
} StatusParaStruct;
	 
//RDD�������Ĵ���
void RDDProcess(void);
//WRT�������Ĵ���
void WRTProcess(void);   
//SRQ�������Ĵ���
void SRQProcess(void);
   
//��ȡ�豸�ͺţ�Ҳ�����������֡�����ȡ������true
bool GetDevMode(char* devModeBuff);
//��ȡ��λ����ǰ״̬
StatusParaStruct GetCurrStatus(void);
//����λ����ȡ�����ļ�
void GetParameter();
//����λ����ȡϵͳ����
void GetSysParameter();
//��㶯����
void AxisPTRun(char* axisID,char* fx);
//��㶯ֹͣ
void AxisPTStop(char* axisID);
//���豸�Ͻ���ע��
void RegisterDevice(char* regNum);


	 
#ifdef __cplusplus
}
#endif

#endif
