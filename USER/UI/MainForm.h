#ifndef _MINFORMS_H
#define _MINFORMS_H

#ifdef __cplusplus
 extern "C" {
#endif 

#include "WorkControl.h"	 
	 
	 
//��ʾ��ӭ����
void ShowDateTimeSetForm(u16 keyCode);
//��ʾ��½���塣showOkForm����½�ɹ�ʱ��ʾ�Ĵ�������showBackForm�����ذ�ťʱ�Ĵ�����
void ShowLoginForm(PermissionTypeEnum destPer,PCLICK showOkForm,PCLICK showBackForm);
//�ް�ť����Ϣ��ʾ����
void ShowMessgeForm_NoButton(char* msg);
//�а�ť����Ϣ��ʾ����
void ShowMessgeForm(char* msg,PCLICK okClickFunc,PCLICK backClickFunc);
//��ʾ������
void ShowMainForm();
 //��ʾ���������е���Ϣ
void ShowWorkMsg(char* msg);
//��ʾ������Ϣ
void ShowDebugMsg(char* msg);
//��ʾ�ӹ������е��������
void ShowWorkData(void);
//��ʾʵʱ����
void ShowCurrCoord(MultiAxisCoordStruct* realCoord);	 
	 
#ifdef __cplusplus
}
#endif

#endif
