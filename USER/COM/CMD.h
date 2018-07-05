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
	DeviceIniting,		//设备初始化中
	TaskInitFail,		//任务初始化失败
	RegWait,			//等待注册
	DevReady,			//设备准备就绪	
	DevWorking,			//设备正在工作中	
	DevScram,			//急停中，查询与主动上送
	USBInsert,			//USB已插入，查询与主动上送	
	NoGetStatus,	//没有读到设备状态
}DeviceStatusEnum;	 	 
	 
//设备状态机参数
typedef struct
{
	DeviceStatusEnum DevStatus;  	//设备状态
	char StatusDescribe[100];	//状态描述字符串
} StatusParaStruct;
	 
//RDD相关命令的处理
void RDDProcess(void);
//WRT相关命令的处理
void WRTProcess(void);   
//SRQ相关命令的处理
void SRQProcess(void);
   
//读取设备型号，也用作联机握手。当读取到返回true
bool GetDevMode(char* devModeBuff);
//获取下位机当前状态
StatusParaStruct GetCurrStatus(void);
//从下位机读取参数文件
void GetParameter();
//从下位机读取系统参数
void GetSysParameter();
//轴点动运行
void AxisPTRun(char* axisID,char* fx);
//轴点动停止
void AxisPTStop(char* axisID);
//在设备上进行注册
void RegisterDevice(char* regNum);


	 
#ifdef __cplusplus
}
#endif

#endif
