/*
 * CALC_IMP.h
 *
 * Created: 8/9/2025 2:50:38 PM
 *  Author: Esther George
 */ 


#ifndef CALC_IMP_H_
#define CALC_IMP_H_

#include "stdTypes.h"
#include <stdlib.h>
#include <string.h>
#include "LCD.h"

s16 pos;
f16 Get_Number(const u8* str);
f16 calc(const u8* str);
f16 High_Preceed(const u8* str);
f16 Low_Preceed(const u8* str);
#endif /* CALC_IMP_H_ */