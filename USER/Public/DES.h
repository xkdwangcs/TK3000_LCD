#ifndef _DES_H_
#define _DES_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include "stm32f4xx.h"
#include "stdbool.h"
#include "string.h"
#include <stdint.h>

//�������ݡ�plainStr:���ģ�key:���ܻ���ܵļ���ciphStr:����
void Encrypt_DES(u8* plainStr, u8* key, u8* ciphStr);
//�������ݡ�plainStr:���ģ�key:���ܻ���ܵļ���ciphStr:����
void Decipher_DES(u8* plainStr, u8* key, u8* ciphStr);
    
#ifdef __cplusplus
}
#endif

#endif 
