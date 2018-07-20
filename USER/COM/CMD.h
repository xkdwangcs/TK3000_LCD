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

typedef struct
{
	float X1;
    float X2;
	float Y1;
	float Y2;
	float Z1;
    float Z2;
}MultiAxisCoordStruct;//多轴坐标，主要用于实时坐标

typedef struct
{
    MultiAxisCoordStruct RealCoord; //实时坐标
    DataTimeStruct DataTime;        //控制器时间    
}LoopDataStruct;//循环读取的数据结构


typedef struct
{
	char FileName[32];	//文件名称	
	u16 CoordCount;		//坐标总数
	u16 LeftCoordCount;	//左平台坐标数
	u16 RightCoordCount;//右平台坐标数
    int DateTime; //排序用
} CoordFileAttri;//坐标文件属性结构体

typedef struct
{
    u16 FileCount;
    CoordFileAttri FileList[20];    
}FileListStruct; //文件管理相关数据
	 
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
//获取要循环读取的数据
LoopDataStruct GetLoopData();
//获取文件列表
FileListStruct* GetFileList();
	 
#ifdef __cplusplus
}
#endif

#endif
