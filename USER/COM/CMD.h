#ifndef _CMD_H
#define _CMD_H

#ifdef __cplusplus
 extern "C" {
#endif 
	 
#include <stm32f4xx.h>
#include "PublicFunction.h"
#include "string.h"
#include "Protocol.h"
	 
	//取料参数
	typedef struct
	{
		u16 StatusID;  //状态ID
		char StatusDescribe[100];//状态描述字符串
	} StatusParaStruct;
	 
//RDD相关命令的处理
void RDDProcess(void);
//WRT相关命令的处理
void WRTProcess(void);   
//SRQ相关命令的处理
void SRQProcess(void);
//OUT相关命令的处理
void OUTProcess(void);
   
void GetParameter();
void AxisPTRun(char* axisID,char* fx);
void AxisPTStop(char* axisID);
	 
//读取设备型号，也用作联机握手。当读取到返回true
bool GetDevMode(char* devModeBuff);
//获取下位机当前状态
StatusParaStruct GetCurrStatus(void);
	 
#ifdef __cplusplus
}
#endif

#endif
