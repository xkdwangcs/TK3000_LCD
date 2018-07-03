#include "Encrypt_XYQ.h"
#include "RTC_F4xx.h"
#include <stdlib.h>
#include <time.h>

const u8 _charLeng=16;
char _plainChars[_charLeng]={"0123456789ABCDEF"};//ԭ���ַ���
char _chiphChars1[_charLeng]={"PX9WK2HMD83FGY5A"};//�����ַ���1
char _chiphChars2[_charLeng]={"BQN4JTE6RUC7VLZS"};//�����ַ���2

//ָ��һ�������ַ�����ö�Ӧ�������ַ���
//������
char GetChiphChar(char plainChar)
{
	char* chiphChars=_chiphChars1;
	if(GetCurrDataTime()->Sec%2==0)//Ҫ��ms�ı仯���к�Ч��
		chiphChars=_chiphChars2;	
	//srand(time(NULL)); //�������У�Ҫ��ȡϵͳʱ�䣬��Linux/Uinux����
//	srand(GetCurrDataTime()->Sec);//Ч������һ��һ���ģ�Ҫ��ms�ı仯���к�Ч��
//	u16 randValue = rand()%100+1;
//	if(randValue%2==0)
//		chiphChars=_chiphChars2;
    for(u8 index=0;index<_charLeng;index++)
    {
        if(_plainChars[index]==plainChar)
            return chiphChars[index] ;
    }
    return 0;        
}

//ָ��һ�������ַ�����ö�Ӧ�������ַ�
char GetPlainChar(char chiphChar)
{
    for(u8 index=0;index<_charLeng;index++)
    {
        if(_chiphChars1[index]==chiphChar)
            return _plainChars[index];  
		if(_chiphChars2[index]==chiphChar)
            return _plainChars[index];  
    }
    return 0;    
}

//�������ݡ�plainStr:���ģ�ciphStr:����
void Encrypt_XYQ(char* plainStr, char* ciphStr)
{
    u8 leng=strlen(plainStr);
    for(u8 i=0;i<leng-1;)
    {
        ciphStr[i+1]=GetChiphChar(plainStr[i]);
        i=i+2;
    }
    for(u8 i=1;i<leng;)
    {
        ciphStr[i-1]=GetChiphChar(plainStr[i]);
        i=i+2;
    }
    if(leng%2 >0)
    {
        ciphStr[leng-1]=GetChiphChar(plainStr[leng-1]);
    }
}

//�������ݡ�ciphStr:����,plainStr:���ģ�
bool Decipher_XYQ(char* ciphStr,char* plainStr)
{
    u8 leng=strlen(ciphStr);
    for(u8 i=0;i<leng-1;)
    {
        char cc = GetPlainChar(ciphStr[i]);
        if(cc==0)
            return false;
        plainStr[i+1]=cc;
        i=i+2;
    }
    for(u8 i=1;i<leng;)
    {
        char cc = GetPlainChar(ciphStr[i]);
        if(cc==0)
            return false;
        plainStr[i-1]=GetPlainChar(ciphStr[i]);
        i=i+2;
    }  
    if(leng%2 >0)
    {
        char cc = GetPlainChar(ciphStr[leng-1]);
        if(cc==0)
            return false;
        plainStr[leng-1]=cc;
    }
    return true;
}