/*
 * LCD.h
 *
 * Created: 8/7/2025 9:03:01 PM
 *  Author: Esther George
 */ 

#ifndef LCD_H_
#define LCD_H_

#include "DIO_Interface.h"

#define		_4bit   1
#define		_8bit   2

#define		LCD_Mode   _4bit


#define EN			0
#define RS			1
#define RSE_Port	PB
#define LCD_PORT	PD


void LCD_Init();
void LCD_CLEAR();
void LCD_Print_Char(u8 data);
void LCD_Print_String(u8 * str);
void LCD_Printnum(s16 num );
void LCD_GOTO(u8 ROW,u8 COL);
void LCD_CLRLOC( u8 ROW,u8 COL);
void LCD_Printfloat(f16 num);
void LCD_Cursor();

#endif /* LCD_H_ */