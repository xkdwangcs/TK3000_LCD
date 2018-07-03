/******************** (C) COPYRIGHT 2009 www.armjishu.com ************************
* File Name          : date.c
* Author             : www.armjishu.com Team
* Version            : V1.0
* Date               : 12/1/2009
* Description        : ������غ���
*******************************************************************************/
#include "RTC_F4xx.h"
#include "stm32f4xx.h"
#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Delay.h"

NVIC_InitTypeDef   NVIC_InitStructure;
RTC_TimeTypeDef RTC_Time;
RTC_DateTypeDef RTC_Date;
DataTimeStruct _currDateTime;

//RTCʱ������
//hour,min,sec:Сʱ,����,����
//����ֵ:SUCEE(1),�ɹ�
//       ERROR(0),�����ʼ��ģʽʧ�� 
ErrorStatus RTC_Set_Time(u8 hour,u8 min,u8 sec)
{
	RTC_Time.RTC_Hours=hour;
	RTC_Time.RTC_Minutes=min;
	RTC_Time.RTC_Seconds=sec;
	if(hour<=12)
		RTC_Time.RTC_H12=RTC_H12_AM;
	else
		RTC_Time.RTC_H12=RTC_H12_PM;	
	return RTC_SetTime(RTC_Format_BIN,&RTC_Time);
	
}
//RTC��������
//year,month,date:��(0~99),��(1~12),��(0~31)
//week:����(1~7,0,�Ƿ�!)
//����ֵ:SUCEE(1),�ɹ�
//       ERROR(0),�����ʼ��ģʽʧ�� 
ErrorStatus RTC_Set_Date(u8 year,u8 month,u8 date)
{	
	RTC_DateTypeDef RTC_Time;
	RTC_Time.RTC_Date=date;
	RTC_Time.RTC_Month=month;
	RTC_Time.RTC_WeekDay=3;//������ҲҪ���ã�������ݻ��������������������ò���Ӱ�����
	RTC_Time.RTC_Year=year;
	return RTC_SetDate(RTC_Format_BIN,&RTC_Time);
}

//ʵʱʱ�ӳ�ʼ��
u8 IniRTC(void)
{	
	RTC_InitTypeDef RTC_InitStructure;
	u16 retry=0X1FFF; 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);//ʹ��PWRʱ��
	PWR_BackupAccessCmd(ENABLE);	//ʹ�ܺ󱸼Ĵ������� 
	if(RTC_ReadBackupRegister(RTC_BKP_DR0)!=0x5050)		//�Ƿ��һ������?
	{
		RCC_LSEConfig(RCC_LSE_ON);//LSE ����    
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)	//���ָ����RCC��־λ�������,�ȴ����پ������
		{
			retry++;
			Delay_ms(10);
		}
		if(retry==0)
			return 1;		//LSE ����ʧ��. 
			
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);		//����RTCʱ��(RTCCLK),ѡ��LSE��ΪRTCʱ��    
		RCC_RTCCLKCmd(ENABLE);	//ʹ��RTCʱ�� 

		RTC_InitStructure.RTC_AsynchPrediv = 0x7F;//RTC�첽��Ƶϵ��(1~0X7F)
		RTC_InitStructure.RTC_SynchPrediv  = 0xFF;//RTCͬ����Ƶϵ��(0~7FFF)
		RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;//RTC����Ϊ,24Сʱ��ʽ
		RTC_Init(&RTC_InitStructure);
 
		RTC_Set_Time(6,0,0);	//����ʱ��
		RTC_Set_Date(16,6,6);	//��������
	 
		RTC_WriteBackupRegister(RTC_BKP_DR0,0x5050);	//����Ѿ���ʼ������
	}  
	return 0;
}

//��ȡ��ǰ���ڼ�ʱ��,���ؽṹ����ʽ
DataTimeStruct* GetCurrDataTime(void)
{
	RTC_GetTime(RTC_Format_BIN,&RTC_Time);
	RTC_GetDate(RTC_Format_BIN, &RTC_Date);
	_currDateTime.Year=RTC_Date.RTC_Year;
	_currDateTime.Mon=RTC_Date.RTC_Month;
	_currDateTime.Day=RTC_Date.RTC_Date;
	_currDateTime.WDay=RTC_Date.RTC_WeekDay;
	_currDateTime.Hour=RTC_Time.RTC_Hours;
	_currDateTime.Min=RTC_Time.RTC_Minutes;
	_currDateTime.Sec=RTC_Time.RTC_Seconds;
	return &_currDateTime;
}

char _currDataTimeStr[40];
//��ȡ��ǰ���ڼ�ʱ���ַ���
char* GetCurrDataTimeStr()
{
	GetCurrDataTime();
    memset(_currDataTimeStr,0,sizeof(_currDataTimeStr));
	sprintf(_currDataTimeStr,"20%02d-%02d-%02d %0.2d:%0.2d:%0.2d", RTC_Date.RTC_Year, RTC_Date.RTC_Month, 
		RTC_Date.RTC_Date, RTC_Time.RTC_Hours, RTC_Time.RTC_Minutes, RTC_Time.RTC_Seconds);
	return _currDataTimeStr;
}

//��ȡ��ǰ���ڵ��ַ�������ʽΪ��2016-07-23
char* GetCurrDateStr(void)
{
    GetCurrDataTime();
    memset(_currDataTimeStr,0,sizeof(_currDataTimeStr));
	sprintf(_currDataTimeStr,"20%02d-%02d-%02d", RTC_Date.RTC_Year, RTC_Date.RTC_Month,RTC_Date.RTC_Date);
	return _currDataTimeStr;
}

//��ȡ��ǰʱ����ַ�������ʽΪ��11:20:26
char* GetCurrTimeStr(void)
{
    GetCurrDataTime();
    memset(_currDataTimeStr,0,sizeof(_currDataTimeStr));
	sprintf(_currDataTimeStr,"%0.2d:%0.2d:%0.2d", RTC_Time.RTC_Hours, RTC_Time.RTC_Minutes, RTC_Time.RTC_Seconds);
	return _currDataTimeStr;
}

//ʱ��У׼��Ҫ���õ���ʱ�䣬���굽�����У�6��Ԫ��
bool TimeAdjust(char* setDateTime)
{
	DataTimeStruct dts;
	ConvertToDateTime(setDateTime,&dts);
	dts.Year-=2000;
	if(dts.Year<16 || dts.Year>50)
		return false;
	if(dts.Mon<1 || dts.Mon>12)
		return false;
	if(dts.Day<1 || dts.Mon>31)
		return false;
	if(dts.Hour<0 || dts.Hour>24)
		return false;
	if(dts.Min<0 || dts.Min>60)
		return false;
	if(dts.Sec<0 || dts.Sec>60)
		return false;
	RTC_Set_Time(dts.Hour,dts.Min,dts.Sec);	//����ʱ��
	RTC_Set_Date(dts.Year,dts.Mon,dts.Day);		//��������
	return true;
}
