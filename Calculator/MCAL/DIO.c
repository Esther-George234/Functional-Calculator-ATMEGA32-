/*
 * DIO.c
 *
 * Created: 8/6/2025 8:49:02 PM
 *  Author: Esther George
 */ 


#include "DIO_Interface.h"

// Function to detect state of pin ( DDRx)
// function name --> pinMode
// Function parameters (PORT , pin , State)
void pinMode(DIO_Port port_t ,uint8_t pin_num ,DIO_Pin_State state )
{
	switch(state)
	{
		case OUTPUT:
		switch(port_t)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		
		break;
		
		case INPUT:
		switch(port_t)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			break;
		}
		
		break;
		case INPULL:
		switch(port_t)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		
		break;
	}
}


void digitalWrite(DIO_Port port_t ,uint8_t pin_num ,DIO_volt  volt )
{
	switch(volt)
	{
		case HIGH:
						switch(port_t)
						{
							case PA:
							SET_BIT(PORTA,pin_num);
							break;
							case PB:
							SET_BIT(PORTB,pin_num);
							break;
							case PC:
							SET_BIT(PORTC,pin_num);
							break;
							case PD:
							SET_BIT(PORTD,pin_num);
							break;
						}
		break;
		
		
		case LOW:
					switch(port_t)
					{
						case PA:
						CLR_BIT(PORTA,pin_num);
						break;
						case PB:
						CLR_BIT(PORTB,pin_num);
						break;
						case PC:
						CLR_BIT(PORTC,pin_num);
						break;
						case PD:
						CLR_BIT(PORTD,pin_num);
						break;
					}
		
		break;
	}
}



DIO_volt digitalRead(DIO_Port port_t ,uint8_t pin_num )
{
	DIO_volt volt = LOW;
	switch(port_t)
	{
		case PA:
		volt = GET_BIT(PINA,pin_num);
		break;
		case PB:
		volt = GET_BIT(PINB,pin_num);
		break;
		case PC:
		volt = GET_BIT(PINC,pin_num);
		break;
		case PD:
		volt = GET_BIT(PIND,pin_num);
		break;
	}
	return volt;
}
void pinModePort(DIO_Port port_t  ,DIO_Pin_State state )
{
	switch(state)
	{
		case OUTPUT:
		switch(port_t)
		{
			case PA:
			 DDRA = 0xff;
			 PORTA = 0x00;
			break;
			case PB:
			DDRB = 0xff;
			PORTB = 0x00;
			break;
			case PC:
			DDRC = 0xff;
			PORTC = 0x00;
			break;
			case PD:
			DDRD = 0xff;
			PORTD = 0x00;
			break;
		}
		
		break;
		
		case INPUT:
		switch(port_t)
		{
			case PA:
			DDRA = 0x00;
			break;
			case PB:
			DDRB = 0x00;
			break;
			case PC:
			DDRC = 0x00;
			break;
			case PD:
			DDRD = 0x00;
			break;
		}
		
		break;
		case INPULL:
		switch(port_t)
		{
			case PA:
			DDRA = 0x00;
			PORTA = 0xff;
			break;
			case PB:
			DDRB = 0x00;
			PORTB = 0xff;
			break;
			case PC:
			DDRC = 0x00;
			PORTC = 0xff;
			break;
			case PD:
			DDRD = 0x00;
			PORTD = 0xff;
			break;
		}
		
		break;
	}
}

void digitalWritePort(DIO_Port port_t  ,DIO_volt  volt )
{
	
	switch(volt)
	{
		case HIGH:
		switch(port_t)
		{
			case PA:
			PORTA = 0xff;
			break;
			case PB:
			PORTB = 0xff;
			break;
			case PC:
			PORTC = 0xff;
			break;
			case PD:
			PORTD = 0xff;
			break;
		}
		break;
		
		
		case LOW:
		switch(port_t)
		{
			case PA:
			PORTA = 0x00;
			break;
			case PB:
			PORTB = 0x00;
			break;
			case PC:
			PORTC = 0x00;
			break;
			case PD: 0x00;
			break;
		}
		
		break;
	}
}

void digitalWritePortnum(DIO_Port port_t  ,uint8_t num )
{
	
	switch(port_t)
	{
		case PA:
		PORTA = num;
		break;
		case PB:
		PORTB = num;
		break;
		case PC:
		PORTC = num;
		break;
		case PD:num;
		break;
	}
	
}
