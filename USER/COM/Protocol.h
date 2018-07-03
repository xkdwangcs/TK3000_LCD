#ifndef __ProtocolBASE_H
#define __ProtocolBASE_H

#ifdef __cplusplus
 extern "C" {
#endif 

#include <stm32f4xx.h>
#include "string.h"

#define CMDBuffLeng 2000   			//���������󳤶�
	 
#define _srq "SRQ"
#define _rdd "RDD"
#define _wrt "WRT"
#define _cdr "CDR"
#define _cdw "CDW"
#define _err "ERR"
#define _out "OUT"

//�����
typedef enum
{
	RMR,	//run motor ���õ��ֱ��ִ��
	SMR, //SetMotor
	RUN, //����set motor ����,ִ��
	SPD,  //set speed max
	SPT,	//set point speed
	RPM,	//run point ��+����
	OUT_NULL = 0xFF
} MOT_ET;

typedef enum
{
	RS232,
	WIFI,
}CommChannelEnum;//ͨ��ͨ������

#pragma pack(1)  
typedef struct
{
	u8 Head;					      //ͷ�ֽ�
	u16 Length;					    //�����ĳ��ȣ����ְ�ͷ����β
	u8 DestAddr;				    //Ŀ�ĵ�ַ
	u8 SourAddr;				    //Դ��ַ
  u8 PackNum;             //�ְ�����Ϊ0ʱ��ʾû�ְ�
	u8 PackID;					    //����
	char FunCode[3];			  //������
	char CmdName[20];			  //���������̶����ȣ�������0����
	u8 CmdData[CMDBuffLeng];	//�������ݾݣ�����ʱ������CRC��β
  u16 DataLeng;            //������ʵ�ʳ���
  u16 RecvOK;
} ProtocolBuffStruct;//ͨ�Ż���ṹ
#pragma pack()  

//������ջ���
extern ProtocolBuffStruct _cmdRecvBuff;
//����ͻ���
extern ProtocolBuffStruct _cmdSendBuff;
extern char *_cmdERR;
extern char *_crcERR;
extern char *_tailERR;
extern char *_funcERR;

//����CRC16
u16 CRC16ByPoly(u8 *data, u16 startIndex, u16 length);
//�����������ð��İ���
u16 Package(char* func,char* cmdName,u8* cmdData,u16 dataLeng);
//COM1�Ľ��
void DisPackage(void);

//�������,recvPack�����յ���commChannel����ǰ���յ�ͨ��ͨ��
void CMDAnalysis(void);
//��ΪӦ������ݷ���
void ResponseSendData(char *func, u16 cmdDataLeng);
//��ָ���Ĵ��ڷ�������������
void SendBytes_Pack(char* func,char* cmdName, u8* cmdData,u16 cmdLeng);
//��ָ���Ĵ��ڷ�������������
void SendChars_Pack(char* func,char* cmdName, char* cmdData);

#ifdef __cplusplus
}
#endif
#endif
