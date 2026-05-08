/*
 * KEYPAD.c
 *
 * Created: 8/8/2025 2:37:26 PM
 *  Author: Hassan-Hetta
 */ 


#include "KEYPAD.h"

void Kepad_init()
{

	for(uint8_t i =0;i<4;i++)
	{
		pinMode(PD,FIRST_OUTPUT+i,OUTPUT);
		pinMode(PC,FIRST_INPUT+i,INPULL);
	}
	
}
uint8_t Keypad_getkey()
{
	uint8_t r,c,key=0; 
	
	for(uint8_t i = 0;i<ROW;i++)
	{
		digitalWrite(PD,FIRST_OUTPUT+i,HIGH);
	}
	
	for(r = 0;r<ROW;r++) // looping rows
	{
		digitalWrite(PD,FIRST_OUTPUT+r,LOW);
		for(c=0;c<COL;c++)
		{
			if(digitalRead(PC,FIRST_INPUT+c)==LOW)
			{
				key = Key_array[r][c];
				while(digitalRead(PC,FIRST_INPUT+c)==LOW);
			}
		}
		digitalWrite(PD,FIRST_OUTPUT+r,HIGH);
	}
	
	return key;
}

