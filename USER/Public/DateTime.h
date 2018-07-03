#ifndef _DATETIME_H_
#define _DATETIME_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdio.h"
#include "string.h"
#include <stdint.h>
#include "PublicFunction.h"
//#include "time.h"
	
typedef struct 
{
	u8 Sec;
	u8 Min;
	u8 Hour;
	u8 Day;
	u8 Mon;
	u16 Year;
	u8 WDay;//����
}DataTimeStruct;//����ʱ��ṹ��    
	
typedef enum
{
	Equal=0, //���
	Greater, //����
	Less,    //С��
}CMPValueEnum;//�����Ƚ�ֵ��ö��    

//�Ƚ��������ڣ����԰���ʱ�䣨Ҳ����û�У���Ҫ���������ڵĸ�ʽ��һ�µ�
CMPValueEnum DateTimeCMP(char* dateTime1,char* dateTime2);
//����ʽ��"20160802"�ĸ�ʽת��Ϊ2016-08-02
char* DateFormat(char* dateStr);
//���ַ����ֽ������,���ֽ�ʱ��,��ʽ:2016-08-11
void ConvertToDate(char* dateStr,DataTimeStruct* dateTime);
//���ַ����ֽ�����ڼ�ʱ�䣬��ʽ:2016-08-11 21:13:15
void ConvertToDateTime(char* dateTimeStr,DataTimeStruct* dateTime);
//���������ڵ����������date1-date2,������
int CalcDateDiff_Struct(DataTimeStruct date1,DataTimeStruct date2);
//���������ڵ����������date1-date2,������
int CalcDateDiff_String(char* date1,char* date2);
//ָ��һ�����ڣ����������������µ�����
char* DateAddDay(char* oldDate,int days);
    
#ifdef __cplusplus
}
#endif

#endif 
