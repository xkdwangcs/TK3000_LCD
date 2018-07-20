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
#include "DateTime.h"

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

typedef struct
{
	float X1;
    float X2;
	float Y1;
	float Y2;
	float Z1;
    float Z2;
}MultiAxisCoordStruct;//�������꣬��Ҫ����ʵʱ����

typedef struct
{
    MultiAxisCoordStruct RealCoord; //ʵʱ����
    DataTimeStruct DataTime;        //������ʱ��    
}LoopDataStruct;//ѭ����ȡ�����ݽṹ


typedef struct
{
	char FileName[32];	//�ļ�����	
	u16 CoordCount;		//��������
	u16 LeftCoordCount;	//��ƽ̨������
	u16 RightCoordCount;//��ƽ̨������
    int DateTime; //������
} CoordFileAttri;//�����ļ����Խṹ��

typedef struct
{
    u16 FileCount;
    CoordFileAttri FileList[20];    
}FileListStruct; //�ļ������������
	 
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
//��ȡҪѭ����ȡ������
LoopDataStruct GetLoopData();
//��ȡ�ļ��б�
FileListStruct* GetFileList();
	 
#ifdef __cplusplus
}
#endif

#endif
