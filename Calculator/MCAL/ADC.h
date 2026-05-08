/*
 * ADC.h
 *
 * Created: 8/10/2025 5:21:41 PM
 *  Author: BS
 */ 


#ifndef ADC_H_
#define ADC_H_

#define F_CPU	8000000UL
#include <util/delay.h>
#include "MemMap.h"
#include "utils.h"
#include "stdTypes.h"


void ADC_Init();

u16 ADC_READ(u8 ch);
f16 ADC_VOLT(u16 x);




#endif /* ADC_H_ */