/*
 * DIO_Interface.h
 *
 * Created: 8/6/2025 8:49:27 PM
 *  Author: Esther George
 */ 

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define F_CPU	8000000UL
#include <util/delay.h>
#include "MemMap.h"   //--> #include <avr/io.h>
#include "utils.h"
#include "stdTypes.h"


typedef enum
{
	OUTPUT,       
	INPUT,
	INPULL
	}DIO_Pin_State;
	
	
	typedef enum
	{
		LOW,
		HIGH		
	}DIO_volt;
	
	
typedef enum
{
	PA,
	PB,
	PC,
	PD
	
}DIO_Port;

// Function to detect state of pin ( DDRx)
// function name --> pinMode
// Function parameters (PORT , pin , State)

void pinMode(DIO_Port port_t ,uint8_t pin_num ,DIO_Pin_State state );


// Function to detect volt of pin ( PORTx)
// function name --> digitalWrite
// Function parameters (PORT , pin , volt)


void digitalWrite(DIO_Port port_t ,uint8_t pin_num ,DIO_volt  volt );
DIO_volt digitalRead(DIO_Port port_t ,uint8_t pin_num );
void pinModePort(DIO_Port port_t  ,DIO_Pin_State state );
void digitalWritePort(DIO_Port port_t  ,DIO_volt  volt );
void digitalWritePortnum(DIO_Port port_t  ,uint8_t num );



#endif /* DIO_INTERFACE_H_ */