#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdbool.h"
#include "string.h"
#include <stdint.h>
    
//�������ݡ�plainStr:���ģ�ciphStr:����
void Encrypt_XYQ(char* plainStr, char* ciphStr);
//�������ݡ�plainStr:���ģ�ciphStr:����
bool Decipher_XYQ(char* ciphStr,char* plainStr);    
    
#ifdef __cplusplus
}
#endif

#endif 
