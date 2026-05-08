/*
 * KEYPAD.h
 *
 * Created: 8/8/2025 2:37:41 PM
 *  Author: Esther George
 */ 
#include "DIO_Interface.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_


#define COL	4

#define ROW	4

#define NO_KEY  0
#define FIRST_OUTPUT  0
#define FIRST_INPUT   0

static u8 Key_array [ROW][COL]={
	{'7','8' ,'9' ,'/' },
	{'4','5' ,'6' ,'*' },
	{'1','2' ,'3' ,'-'},
	{'c','0' ,'=' ,'+' },
};

void Kepad_init();
u8 Keypad_getkey();






#endif /* KEYPAD_H_ */