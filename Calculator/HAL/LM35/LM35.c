/*
 * LM35.c
 *
 * Created: 8/11/2025 6:09:50 PM
 *  Author: BS
 */ 
#include "LM35.h"
f16 Temp_Read(f16 volt){
	// we need voltage value to get temperature 10mV=0.01v ---> 1 celsius (datasheet info)
	f16 temp= (f16) (volt/0.01) ;
	return temp;
	
}