#ifndef __DATETIME_H
#define __DATETIME_H

#ifdef __cplusplus
 extern "C" {
#endif 
	 
#include "stm32f4xx.h"
#include "DateTime.h"


//ʵʱʱ�ӳ�ʼ��
u8 IniRTC(void);
//ʱ��У׼��Ҫ���õ���ʱ�䣬���굽�����У�6��Ԫ��
bool TimeAdjust(char* setDateTime);
//��ȡ��ǰ���ڼ�ʱ��,���ؽṹ����ʽ
DataTimeStruct* GetCurrDataTime(void);
//��ȡ��ǰ���ڵ��ַ�������ʽΪ��2016-07-23
char* GetCurrDateStr(void);
//��ȡ��ǰʱ����ַ�������ʽΪ��11:20:26
char* GetCurrTimeStr(void);
//��ȡ��ǰ���ڼ�ʱ���ַ���
char* GetCurrDataTimeStr(void);

#ifdef __cplusplus
}
#endif

#endif
