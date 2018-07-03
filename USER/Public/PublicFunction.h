#ifndef _Public_H
#define _Public_H

#ifdef __cplusplus
 extern "C" {
#endif 
	 
#include "stm32f4xx.h"
#include "string.h"
#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"

#define	 dicLeng  10 //�ֵ�Ԫ�ص�������

//�ֵ�Ԫ�ؽṹ
typedef struct
{
	char key[40];
	char value[100];
} Dictionary;

//�б�Ԫ�ؽṹ���Ƿ���� *char[40]�ķ�ʽ
typedef struct
{
	char item[100];
} LIST;

typedef union
{
	float f;
	unsigned char c4[4];
} floatBytesTypedef;

typedef union
{
	int val32;
	unsigned char c4[4];
} intBytesTypedef;

typedef union
{
	s16 val16;
	unsigned char c2[2];
} s16BytesTypedef;

typedef union
{
	u16 val16;
	unsigned char c2[2];
} u16BytesTypedef;

typedef union
{
	u32 u32Data;
	u8 u8Ary4[4];
} u32BytesType;

extern Dictionary _dic[dicLeng];

//����һ���ַ���������һ���ֵ䡣�ַ���ʽ��"MID|Y" OR "MID|X,DIR|FFX,SPD|-12"
Dictionary* ConvertToDic(char *tpara, u8 *itemCount);
//�ֽ�һ���ַ���������һ���б��ַ���ʽ��"AA/BB/CC"
LIST* SplitString(char *tpara,char* split, u8* itemCount); 
//����һ���ַ���������һ���б��ַ���ʽ��"1.0��1.3��1.6"
LIST* GetLIST(char *tpara, u8 *itemCount);
//����һ����������õ�һ���ַ�����Ԫ�ؼ��ö��Ÿ���
char* ConvertFloatArrToStr(float* datas,u8 count);
//ָ���ֵ䣬һ��key����ѯ������value
char *GetValue(Dictionary *dic, char *key);
//ָ���ֵ䣬�ֵ�Ԫ�ظ�����һ��key����ѯ������value���˺�����<GetValue>��ȫ
char *GetValue_n(Dictionary *dic, u8 itemCount, char *key);
//ָ���ֵ䣬һ��value,���ض�Ӧ��key
char* GetKey(Dictionary* dic, u8 itemCount, char* value);
//�Ƚ������ַ���Ҫ��'\0'��β���������򷵻�1,���򷵻�0
bool StrCMP(const char *s1, const char *s2);
//�Ƚ������ַ�,ָ�����ȣ��������򷵻�1,���򷵻�0
bool StrCMP_n(const char *s1, const char *s2,u8 length);
//ɾ������Ŀո�
void TrimTail(char s[]);
//ת��Ϊu32
u32 ConvertAsciiTou32(char *s);
//ascii�ֽ�ת��Ϊ������
float ConvertAsciiToFloat(char *s);
//������תASCII��
char* ConvertFloatToAscii(float f);
//������תASCII��,����ʽ��
char* ConvertFloatToAsciiFormat(float f, char* formatStr);
//u32��תASCII��
char* ConvertU32ToAscii(u32 d);
//������תΪ4�ֽ�char
char* ConvertFloatTo4Byte(float data);
//���ֽ�ת��Ϊ������
float Convert4ByteToFloat(char *s);
//���ֽ�ת��Ϊ������
float Convert4ByteToFloat_offset(char *s, int startIndex);
//��destStr��β�����ָ�����ַ���
void AppendStr(char *destStrArr, char *tailStr);
//��destStr��β�����ָ�����ַ���,�������ַ����в���ָ�����ַ�
void AppendStrAddSplit(char *destStrArr, char *split, char *tailStr);
//���������ַ���
void LinkThreeStr(char* destStrArr,char* str1, char* str2, char* str3);
//��destArr��β�����ָ�����ַ�����destArrҪ�����顣
//destOffset:destArr��ʼ���Ƶ�������tailCount:Ҫ���Ƶĸ���
void CopyBytes(u8* destArr, int destOffset, u8* sourceArr, int copyCount);
//��destArr��β�����ָ�����ַ�����destArrҪ�����顣
//destOffset:destArr��ʼ���Ƶ�������tailCount:Ҫ���Ƶĸ���
void CopyBytes1(u8* destArr, int destOffset, u8* sourceArr,int sourceOffset, int copyCount);
//��ά�ַ����齵������
//strArray:ָ���ά�ַ������ָ��,��str[3][10]��itemCount:��������(Ԫ�ظ���);itemByteNum��Ԫ���ֽ���(һ�ж����ֽ�)
void StringArrayShortDES(char* strArray,u8 itemCount,u8 itemByteNum);
//��ά�ַ�������������
//strArray:ָ���ά�ַ������ָ��,��str[3][10]��itemCount:��������(Ԫ�ظ���);itemByteNum��Ԫ���ֽ���(һ�ж����ֽ�)
void StringArrayShortASC(char* strArray,u8 itemCount,u8 itemByteNum);
//ȡָ��ֵ�ķ���
s8 Sign(float v);


void charRightAlign(char *str, u32 alignLen);
void charLeftAlign(char *str, u32 alignLen);
bool addPercentCharAfterDigitChar(char *str);
bool isValidIntStr(char *str);
bool isValidFloatStr(char *str, int strMaxLen);
bool isValidwithSymFloatStr(char *str, int strMaxLen);

#ifdef __cplusplus
}
#endif

#endif
