#include "SEV_SEG.h"

static const uint8_t seg[SEG_SIZE] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};


void Seg_Display_num(uint8_t num)
{
		SEGDDR = 0x7f;
		SEGPORT = seg[num];
}

void Seg_Display_All()
{
	SEGDDR = 0x7f;
	for(int i =0;i<SEG_SIZE;i++)
	{
		SEGPORT = seg[i];
		_delay_ms(500);
	}
	
}
