/*
 * insession.c
 *
 * Created: 8/6/2025 5:33:15 PM
 * Author : Esther George
 */ 


#include "LCD.h"
#include "KEYPAD.h"
#include "CALC_IMP.h"

int main(void)
{
	LCD_Init();
	Kepad_init();
	u8 x=0;
	u8 it=0;
	u8 str[64]={0};
		
while (1)
{
	x=Keypad_getkey();
	if (x=='c')
	{
	  LCD_Cursor();
	  break;  
	}
}
		

	while(1)
	{
		x = Keypad_getkey();
		if (x=='c'){
			LCD_CLEAR();
			str[0] = '\0'; //reset str
			it=0;
		}
		else if(x=='='){
			 str[it] = '\0'; //stops str from taking digits
			LCD_GOTO(1,0);
			LCD_Printfloat(calc(str));
			  it = 0; //reassign
			  str[0] = '\0'; //reassign
		}
	else if(x != NO_KEY && it < sizeof(str) - 1)   // checks if key pressed AND if it exceeded string size
	{
		str[it] = x;
		it++;
		LCD_Print_Char(x);
	}

	}	            
		
	

}

	