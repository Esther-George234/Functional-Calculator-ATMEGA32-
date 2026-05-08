#include "LCD.h"
#include <stdlib.h>

#if LCD_Mode == _8bit

static void LCD_CMD(u8 command)     //Rs = 0
{
	digitalWrite(RSE_Port,RS,LOW);
	digitalWritePortnum(LCD_PORT,command);
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,HIGH);
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,LOW);
	_delay_ms(1);
}
void LCD_Print_Char(u8 data)  //Rs = 1
{
	digitalWrite(RSE_Port,RS,HIGH);
	digitalWritePortnum(LCD_PORT,data);
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,HIGH);
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,LOW);
	_delay_ms(1);
	
}


void LCD_Init()
{
	pinModePort(LCD_PORT,OUTPUT);
	pinModePort(RSE_Port,OUTPUT);
	_delay_ms(50);
	LCD_CMD(0x38);   //Function Set
	LCD_CMD(0x0c);   //Display ON / OFF
	LCD_CLEAR();
	LCD_CMD(0x06);   //Entry Mode Set
}

#elif LCD_Mode == _4bit

static void LCD_CMD(u8 command)     //Rs = 0
{
	digitalWrite(RSE_Port,RS,LOW);
	digitalWrite(LCD_PORT,7, GET_BIT(command,7)  );  // HIGHER Bits
	digitalWrite(LCD_PORT,6,   GET_BIT(command,6) );
	digitalWrite(LCD_PORT,5,   GET_BIT(command,5) );
	digitalWrite(LCD_PORT,4, GET_BIT(command,4)   );
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,HIGH);
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,LOW);
	_delay_ms(1);
	digitalWrite(LCD_PORT,7, GET_BIT(command,3)   );    // LOWER bits
	digitalWrite(LCD_PORT,6,   GET_BIT(command,2) );
	digitalWrite(LCD_PORT,5,   GET_BIT(command,1) );
	digitalWrite(LCD_PORT,4,   GET_BIT(command,0) );
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,HIGH);
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,LOW);
	_delay_ms(1);
}
void LCD_Print_Char(u8 data)  //Rs = 1
{
	digitalWrite(RSE_Port,RS,HIGH);
	digitalWrite(LCD_PORT,7, GET_BIT(data,7)  );  // HIGHER Bits
	digitalWrite(LCD_PORT,6,   GET_BIT(data,6) );
	digitalWrite(LCD_PORT,5,   GET_BIT(data,5) );
	digitalWrite(LCD_PORT,4, GET_BIT(data,4)   );
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,HIGH);
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,LOW);
	_delay_ms(1);
	digitalWrite(LCD_PORT,7, GET_BIT(data,3)   );    // LOWER bits
	digitalWrite(LCD_PORT,6,   GET_BIT(data,2) );
	digitalWrite(LCD_PORT,5,   GET_BIT(data,1) );
	digitalWrite(LCD_PORT,4,   GET_BIT(data,0) );
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,HIGH);
	_delay_ms(1);
	digitalWrite(RSE_Port,EN,LOW);
	_delay_ms(1);
	
}


void LCD_Init()
{
	pinModePort(LCD_PORT,OUTPUT);
	pinModePort(RSE_Port,OUTPUT);
	_delay_ms(50);
	LCD_CMD(0x02);
	LCD_CMD(0x28);   //Function Set
	LCD_CMD(0x0c);   //Display ON / OFF
	LCD_CLEAR();
	LCD_CMD(0x06);   //Entry Mode Set
}

#endif


void LCD_Print_String(u8 * str)
{
	while(*str != '\0')
	{
		LCD_Print_Char(*str);
		str++;
	}
}



void LCD_Printnum(s16 num )
{
	char buffer[17];
	itoa(num,buffer,10);
	LCD_Print_String(buffer);
}
void LCD_Printfloat(f16 num){
	char buffer[17];
	dtostrf(num,6,2,buffer);
	LCD_Print_String(buffer);
}
void LCD_GOTO(u8 ROW,u8 COL)
{
	if (ROW == 0)
	{
		LCD_CMD(0x80+COL);    //Line 0
	}
	
	else if(ROW == 1)
	{
		LCD_CMD(0x80+0x40+COL);
	}
	
	
	
}


void LCD_CLRLOC( u8 ROW,u8 COL)
{
	LCD_GOTO(ROW,COL);
	for(int i=0;i<4;i++)
	{
		LCD_Print_Char(' ');
	}
	LCD_GOTO(ROW,COL);
}


void LCD_CLEAR()
{
	LCD_CMD(0x01);
	_delay_ms(1);
}

void LCD_Cursor(){
	LCD_CMD(0x0f);
	_delay_ms(1);
}