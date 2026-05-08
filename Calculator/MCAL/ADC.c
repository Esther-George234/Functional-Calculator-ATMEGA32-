/*
 * ADC.c
 *
 * Created: 8/10/2025 5:21:55 PM
 *  Author: Esther George
 */ 
#include "ADC.h"
void ADC_Init(){
	//1- set porta as input
	DDRA=0x00;
	//2- set Vref as 5V
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	//3- preScaler 8MHz/64 ---> 125KHz
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	// 4- left-adjust result --> ADMUX --> ADLAR BITS
	CLR_BIT(ADMUX,5);
	// 5- Turn on enable bit7 --> ADCSRA
	SET_BIT(ADCSRA,7);
}

u16 ADC_READ(u8 ch)
{
	// Variable to save ADC Reading
	u16 ADC=0;
	//1- Select Channel
	ADMUX &= 0xe0; // Bits( 5 ,6 ,7 ) should be initialized at ADC_INIT not in this function
	ADMUX |=ch;  // write channel number to bits (0,1,2)
	
	//2- Start Conversion
	SET_BIT(ADCSRA,6);   // start -->bit6 (1) -->when conversion ends bit6 (0);

	//3- wait for conversion to end
	while(GET_BIT(ADCSRA,6)) ; //busy wait

	//4- Save data to uint16_t variable
	
	ADC = ( ADCL | (ADCH <<8) );
	
	//5- Return value of ADC
	return ADC;
}

f16 ADC_VOLT(u16 x){
	f16 volt = (f16) ((x * 5.0) /1023.0);
	return volt;
}