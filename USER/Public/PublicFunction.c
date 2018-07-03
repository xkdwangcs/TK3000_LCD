/*
* Public.c
*
*  Created on: 2014��7��8��
*      Author: Administrator
*/
#include "PublicFunction.h"
#include "MemoryAlloc.h"

char _charArr[20]; //ת��Ϊ�ַ�ָ���ȫ�ֱ���
Dictionary _dic[dicLeng] __at(DicBuffAddr); //�ֵ�ȫ�ֱ���
const u8 _listLeng = 10; //�б�Ԫ�ص�������
LIST _list[_listLeng]; //�б�ȫ���ֵ�
floatBytesTypedef _floatData;

//����һ���ַ���������һ���ֵ䡣�ַ���ʽ��"MID|Y" OR "MID|X,DIR|FFX,SPD|-12"
Dictionary* ConvertToDic(char *tpara, u8 *itemCount)
{
    int index = 0;
    char *split = "|,";
    char* tp=strtok(tpara,split);
    int dicIndex = 0;
    while (tp != NULL)
    {
        if (index % 2 == 0)
        {
            strcpy(_dic[dicIndex].key, tp);
        }
        else
        {
            strcpy(_dic[dicIndex].value, tp);
            dicIndex++;
        }
        tp = strtok(NULL, split);
        index++;
    }
    *itemCount = dicIndex;
    return _dic;
}

//ָ���ֵ䣬�ֵ�Ԫ�ظ�����һ��key����ѯ������value���˺�����<GetValue>��ȫ
char *GetValue_n(Dictionary *dic, u8 itemCount, char *key)
{
    for (int i = 0; i < itemCount; i++)
    {
        if (StrCMP(dic[i].key, key))
        {
            return dic[i].value;
        }
    }
    return NULL;
}

//ָ���ֵ䣬һ��value,���ض�Ӧ��key
char* GetKey(Dictionary* dic, u8 itemCount, char* value)
{
    for (int i = 0; i < itemCount; i++)
    {
        if (StrCMP(dic[i].value, value))
        {
            return dic[i].key;
        }
    }
    return NULL;
}

//ָ���ֵ䣬һ��key����ѯ������value
char* GetValue(Dictionary *dic, char *key)
{
    return GetValue_n(dic, dicLeng, key);
}

//�ֽ�һ���ַ���������һ���б��ַ���ʽ��"AA/BB/CC"
LIST* SplitString(char *tpara,char* split, u8* itemCount)
{
    int index = 0;
    char para[strlen(tpara)];
    strcpy(para, tpara);
    char *tp = strtok(para, split); //para����Ϊ���飬�������
    while (tp != NULL)
    {
        strcpy(_list[index].item, tp);
        tp = strtok(NULL, split);
        index++;
    }
    *itemCount = index;
    return _list;
}

//����һ���ַ���������һ���б��ַ���ʽ��"1.0��1.3��1.6"
LIST* GetLIST(char *tpara, u8 *itemCount)
{
    return SplitString(tpara,",",itemCount);
}

char _arrTostrBuff[50];
//����һ����������õ�һ���ַ�����Ԫ�ؼ��ö��Ÿ���
char* ConvertFloatArrToStr(float* datas,u8 count)
{
    memset(_arrTostrBuff,0,sizeof(_arrTostrBuff));
    for(u8 i=0; i<count; i++)
    {
        u8 leng=strlen(_arrTostrBuff);
        sprintf(_arrTostrBuff+leng,"%g,",datas[i]);
    }
    u8 leng=strlen(_arrTostrBuff);
    _arrTostrBuff[leng-1]=0x00;
    return _arrTostrBuff;
}

//�Ƚ������ַ���Ҫ��'\0'��β���������򷵻�1,���򷵻�0
bool StrCMP(const char *s1, const char *s2)
{
    if (strcmp(s1, s2) == 0)
        return true;
    return false;
}

//�Ƚ������ַ�,ָ�����ȣ��������򷵻�1,���򷵻�0
bool StrCMP_n(const char *s1, const char *s2,u8 length)
{
    if (strncmp(s1, s2,length)==0)
        return true;
    return false;
}

//�Ƴ��ı���Ļ��з�
void TrimTail(char* str)
{
    u8 leng;
    do
    {
        leng=strlen(str);
        if(str[leng-2]==0x0D && str[leng-1]==0x0A)
        {
            str[leng-2]=0;
            str[leng-1]=0;
        }
        else
        {
            break;
        }
    } while(leng>0);
}

//ת��Ϊu32
u32 ConvertAsciiTou32(char *s)
{
    int v = atoi(s);
    return v;
}

//ascii�ֽ�ת��Ϊ������
float ConvertAsciiToFloat(char *s)
{
    float v = atof(s);
    return v;
}

//������תASCII��
char* ConvertFloatToAscii(float f)
{
    sprintf(_charArr, "%g", f); //%f���Ȳ���
    return _charArr;
}

//������תASCII��,����ʽ��
char* ConvertFloatToAsciiFormat(float f, char* formatStr)
{
    sprintf(_charArr, formatStr, f);
    return _charArr;
}

//u32��תASCII��
char* ConvertU32ToAscii(u32 d)
{
    //char a[20];//����ֲ������ǲ��еģ���Ϊ���غ�ͱ��ͷ���
    sprintf(_charArr, "%d", d);
    return _charArr;
}

//���ֽ�ת��Ϊ������
float Convert4ByteToFloat(char *s)
{
    float fv;
    unsigned char i;
    u8 *pf = (u8*) &fv;
    for (i = 0; i < 4; i++)
    {
        *(pf + i) = *(s + i);
    }
    return fv;
}

//���ֽ�ת��Ϊ������
float Convert4ByteToFloat_offset(char *s, int startIndex)
{
    s = s + startIndex;
    return Convert4ByteToFloat(s);
    /*float fv;
    unsigned char i;
    u8 *pf = (u8*) &fv;
    for (i = startIndex; i < startIndex + 4; i++)
    {
    *(pf + i) = *(s + i);
    }
    return fv;*/
}

//������תΪ4�ֽ�char
char* ConvertFloatTo4Byte(float data)
{
    _floatData.f = data;
    return (char*) _floatData.c4; //����Ҫע������
}

//��data��β�����ָ�����ַ�����destStrArrҪ������
void AppendStr(char *destStrArr, char *tailStr)
{
    strcat(destStrArr, tailStr);

    /*u16 leng = strlen(destStr);//���������ܱȽ�Σ��
    u16 addLeng = strlen(tailStr);
    u16 i = 0;
    for (i = 0; i < addLeng; i++)
    {
    destStr[leng + i] = *tailStr++;
    }
    destStr[leng + i] = '\0';*/
}

//��destStr��β�����ָ�����ַ���,�������ַ����в���ָ�����ַ�
void AppendStrAddSplit(char *destStrArr, char *split, char *tailStr)
{
    AppendStr(destStrArr, split);
    AppendStr(destStrArr, tailStr);
}

//���������ַ���
void LinkThreeStr(char* destStrArr,char* str1, char* str2, char* str3)
{
    sprintf(destStrArr,"%s%s%s",str1,str2,str3);
}

//��destArr��β�����ָ�����ַ�����destArrҪ�����顣
//destOffset:destArr��ʼ���Ƶ�������tailCount:Ҫ���Ƶĸ���
void CopyBytes(u8* destArr, int destOffset, u8* sourceArr, int copyCount)
{
    for (int i = 0; i < copyCount; i++)
    {
        destArr[destOffset + i] = sourceArr[i];
    }
}

//��destArr��β�����ָ�����ַ�����destArrҪ�����顣
//destOffset:destArr��ʼ���Ƶ�������tailCount:Ҫ���Ƶĸ���
void CopyBytes1(u8* destArr, int destOffset, u8* sourceArr,int sourceOffset, int copyCount)
{
    for (int i = 0; i < copyCount; i++)
    {
        destArr[destOffset + i] = sourceArr[sourceOffset+i];
    }
}

//���ļ�����������Ƚ���
int comp_strdes(const void* a,const void* b)
{
    return strcmp(b, a);
}

//���ļ�����������Ƚ���
int comp_strasc(const void* a,const void* b)
{
    return strcmp(a, b);
}

//��ά�ַ����齵������
//strArray:ָ���ά�ַ������ָ��,��str[3][10]��itemCount:��������(Ԫ�ظ���);itemByteNum��Ԫ���ֽ���(һ�ж����ֽ�)
void StringArrayShortDES(char* strArray,u8 itemCount,u8 itemByteNum)
{
    qsort(strArray,itemCount,itemByteNum,comp_strdes);
}

//��ά�ַ�������������
//strArray:ָ���ά�ַ������ָ��,��str[3][10]��itemCount:��������(Ԫ�ظ���);itemByteNum��Ԫ���ֽ���(һ�ж����ֽ�)
void StringArrayShortASC(char* strArray,u8 itemCount,u8 itemByteNum)
{
    qsort(strArray,itemCount,itemByteNum,comp_strasc);
}

//ȡָ��ֵ�ķ���
s8 Sign(float v)
{
    if(v>0)
        return 1;
    if(v<0)
        return -1;
    return 0;
}

/*�ַ��Ҷ���, �������ָ���ַ���, ��߲��ո�*/
void charRightAlign(char *str, u32 alignLen)
{
    int i;
    int len;

    len = strlen(str);
    if (len < alignLen)
    {
        for (i = 0; i < len; i++)
            str[alignLen - 1 - i] = str[len - 1 - i]; //�ַ�����

        for (i = 0; i < alignLen - len; i++)
            str[i] = ' ';   //��߲��ո�

        str[alignLen] = 0;
    }
    else if (len > alignLen)
    {
        for (i = alignLen; i < len; i++)
            str[i] = 0;
    }
}

/*�ַ������, �������ָ���ַ���, �ұ߲߱��ո�*/
void charLeftAlign(char *str, u32 alignLen)
{
    int i;
    int len;

    len = strlen(str);
    if (len < alignLen)
    {
        for (i = len; i < alignLen; i++)
            str[i] = ' ';

        str[alignLen] = 0;
    }
    else if (len > alignLen)
    {
        for (i = alignLen; i < len; i++)
            str[i] = 0;
    }
}

/*���ַ����������ַ�����*/
int intCharNum(char *str)
{
    int i;
    int len;
    int intCharnum = 0;
    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            intCharnum++;
        else if (str[i] == '.')
            break;
    }
    return intCharnum;
}

bool isValidIntStr(char *str)
{
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            break;
    }
    if (i == len)
        return true;
    else
        return false;
}

/*�ַ����Ƿ���һ����Ч�ĸ������ַ���*/
bool isValidFloatStr(char *str, int strMaxLen)
{
    int len;
    int i;
    int point;

    len = strlen(str);
    if (len > strMaxLen || len == 0)
        return false;

    /*���С�������*/
    point = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == '.')
            point++;
    }
    if (point > 1)
        return false;

    /*����Ƿ��������ַ�*/
    for (i = 0; i < len; i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
            return false;
    }
    /*��һ���ַ�����ΪС����*/
    if (str[0] == '.')
        return false;

    if (len == strMaxLen && len > 0 && str[len - 1] == '.')
        return false;
    return true;
}

bool isValidwithSymFloatStr(char *str, int strMaxLen)
{
    bool ret = false;

    if (str[0] == '-' || str[0] == '+') //��һλ�Ƿ���λ���ӵڶ�λ��ʼ
        ret = isValidFloatStr(&str[1], strMaxLen - 1);
    else
        ret = isValidFloatStr(str, strMaxLen);
    return ret;
}

bool isValidSoftVerStr(char *str, int strMaxLen)
{
    int len;
    int i;

    len = strlen(str);
    if (len > strMaxLen || len == 0)
        return false;

    /*���ַ�������С����*/
    if (str[0] == '.')
        return false;

    /*����Ƿ��������ַ�*/
    for (i = 0; i < len; i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
            return false;
    }

    /*����������������С����*/
    for (i = 0; i < len - 1; i++)
    {
        if (str[i] == '.' && str[i + 1] == '.')
            return false;
    }

    if (len == strMaxLen && len > 0 && str[len - 1] == '.')
        return false;

    return true;
}

bool isValidZeroPointInput(char *str, int strMaxLen)
{
    bool ret = false;

    if (str[0] == '-' || str[0] == '+') //��һλ�Ƿ���λ���ӵڶ�λ��ʼ
        ret = isValidFloatStr(&str[1], strMaxLen - 1);
    else
        ret = isValidFloatStr(str, strMaxLen);

    return ret;
}

bool isValidDateStr(char *str)
{
    int len;
    int i;
    char tmp[8];
    int year, month, day;
    int leapyear = 0;

    len = strlen(str);
    if (len != 8)
        return false;

    for (i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }

    memset(tmp, 0, sizeof(tmp));
    for (i = 0; i < 4; i++)
        tmp[i] = str[i];
    year = atoi(tmp);

    memset(tmp, 0, sizeof(tmp));
    for (i = 4; i < 6; i++)
        tmp[i - 4] = str[i];
    month = atoi(tmp);

    memset(tmp, 0, sizeof(tmp));
    for (i = 6; i < 8; i++)
        tmp[i - 6] = str[i];
    day = atoi(tmp);

    if ((year % 4) == 0 && (year % 100) != 0)
        leapyear = 1;

    if (month < 1 || month > 12)
        return false;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day < 1 || day > 31)
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day < 1 || day > 30)
            return false;
    }
    else
    {
        if (leapyear)
        {
            if (day < 1 || day > 29)
                return false;
        }
        else
        {
            if (day < 1 || day > 28)
                return false;
        }
    }

    return true;

}

bool addPercentCharAfterDigitChar(char *str)
{
    int i;
    int len;
    bool ret = false;
    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ')
            break;
    }
    if (i < len)
    {
        str[i] = '%';
        ret = true;
    }
    return ret;
}
