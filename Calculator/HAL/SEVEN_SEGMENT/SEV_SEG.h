
#ifndef SEV_SEG_H_
#define SEV_SEG_H_
#define F_CPU	8000000UL
#include "MemMap.h"
#include <util/delay.h>
#include "utils.h"
#include "stdTypes.h"
#define SEGPORT     PORTC
#define SEGDDR      DDRC

#define SEG_SIZE  10

void Seg_Display_num(uint8_t num);
void Seg_Display_All();
void Seg_Displa_hex();


#endif /* SEV_SEG_H_ */
