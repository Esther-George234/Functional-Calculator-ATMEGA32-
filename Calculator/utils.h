/*
 * utils.h
 *
 * Created: 8/6/2025 1:46:53 PM
 *  Author: Esther George
 */ 

// i changed var into reg,because in the next lectures we are dealing with registers,not variables.

#ifndef UTILS_H_
#define UTILS_H_
//SET BIT
#define SET_BIT(reg, BitNo) ((reg)|=(1U<<(BitNo)))
//CLEAR
#define CLR_BIT(reg, BitNo) ((reg)&= ~(1U<<(BitNo)))
//TOGGLE
#define TOG_BIT(reg, BitNo) ((reg)^=(1U<<(BitNo)))
//GET BIT
#define GET_BIT(reg,BitNo) (((reg)>>(BitNo)) & 1U)



#endif /* UTILS_H_ */