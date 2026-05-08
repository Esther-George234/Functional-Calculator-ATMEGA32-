/*
 * memMap.h
 *
 * Created: 8/6/2025 9:26:42 PM
 *  Author: BS
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_
#include "stdTypes.h"
// PORTA
#define PORTA			( *(volatile u8 *) (0x3b) )
#define DDRA			( *(volatile u8 *) (0x3a) )
#define PINA			( *(volatile u8 *) (0x39) )

// PORTB
#define PORTB			( *(volatile u8 *) (0x38) )
#define DDRB			( *(volatile u8 *) (0x37) )
#define PINB			( *(volatile uint8_t *) (0x36) )


// PORTC
#define PORTC			( *(volatile u8 *) (0x35) )
#define DDRC			( *(volatile u8 *) (0x34) )
#define PINC			( *(volatile u8 *) (0x33) )

// PORTD
#define PORTD			( *(volatile u8 *) (0x32) )
#define DDRD			( *(volatile u8 *) (0x31) )
#define PIND			( *(volatile u8 *) (0x30) )

/***********************ADC*************************/

#define ADMUX			( *(volatile uint8_t *) (0x27) )

#define ADCSRA			( *(volatile uint8_t *) (0x26) )

#define ADCH			( *(volatile uint8_t *) (0x25) )

#define ADCL			( *(volatile uint8_t *) (0x24) )


#endif /* MEMMAP_H_ */