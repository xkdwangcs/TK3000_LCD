#ifndef __LCDPARAM_H
#define __LCDPARAM_H

#include "stm32f4xx.h"
#include "stdbool.h"


//LCD��ز����Ľṹ��
typedef struct
{      
    u8 ucBackLight;				//LCD��������
    u8 TouchDirection;			//��Ļ���� 0-3  0��ʾ������1��ʾ����180�� 2��ʾ���� 3��ʾ����180��
    u8 XYChange;				//X, Y �Ƿ񽻻��� 1��ʾi�л���0��ʾ���л�
	
    u16 usAdcX1;				//���Ͻ�
    u16 usAdcY1;
    u16 usAdcX2;				//���½�
    u16 usAdcY2;
    u16 usAdcX3;				//���½�
    u16 usAdcY3;
    u16 usAdcX4;				//���Ͻ�
    u16 usAdcY4;

	//У׼ʱ����Ļ����
    u16 usLcdX1;		
    u16 usLcdY1;
    u16 usLcdX2;
    u16 usLcdY2;
    u16 usLcdX3;
    u16 usLcdY3;
    u16 usLcdX4;
    u16 usLcdY4;	
	
	char ParaVer[7];			//�����汾�������Զ������������� 
	
} LcdParaStruct;

extern bool _isTouchCalibration;
//LCD����ʵ��
extern LcdParaStruct g_tParam;

//��Flash�ж�ȡLCD���У׼�������ڴ�
void LoadLcdPara(void);
//��LCD���У׼�������浽Flash
void SaveLcdPara(void);

#endif
