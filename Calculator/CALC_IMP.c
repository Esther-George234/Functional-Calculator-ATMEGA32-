/*
 * CALC_IMP.c
 *
 * Created: 8/9/2025 2:51:01 PM
 *  Author: Esther George
 */ 

#include "CALC_IMP.h"
 pos = 0; 
// logic used: str={1,2,3,4,*,6,9,7}  ---> take str and get first number until u meet an operand (get number)-->go to high preceed and check if there is *,/ or not
// go to low preceed after high preceed is done ---> lastly return value after checking all of the input string ****KEY FUNCTION ---> atof(char* str)****	
	
f16 Get_Number(const u8* str) {
	s8 numbuffer[32];
	s16 i = 0;

/*************CHECK SIGN OF NUMBER************/
	if (str[pos] == '+' || str[pos] == '-') {
		numbuffer[i] = str[pos];
		i++;
		pos++;
	}
	if (str[pos]=='/' || str[pos]=='*')   //handles inputs like -->  /89 , *7 at the beginning of the screen
	{
		LCD_CLEAR();
		LCD_GOTO(0,2);
		LCD_Print_String("Invalid Input.");
		return 0;
	}

	while ((str[pos] >= '0' && str[pos] <= '9')) {
		if (i < (s16)(sizeof(numbuffer) - 1)) {
			numbuffer[i] = str[pos];     //STORES NUMBER -123 ---> ['-','1','2','3']
			i++;
		}
		pos++;
	}
	numbuffer[i] = '\0';  // ends number before an operand gets inserted in numbuffer

	return atof(numbuffer);  //SIMILAR TO ATOI (from strings lecture) BUT RETURNS FLOAT AND NOT INTEGER  "-123" ---> -123 
}



f16 High_Preceed(const u8* str) {
	f16 value = Get_Number(str);

	while (1) {
		s8 op = str[pos];       //gets operator
		if (op != '*' && op != '/') break; //checks operator and jumps to returning left  if true

		pos++;
		f16 RHS = Get_Number(str);      //operates from left to right!

		if (op == '*') value *= RHS;
		else {
			if (RHS == 0.0f) {
				LCD_CLEAR();
				LCD_GOTO(0,4);
				LCD_Print_String("Math error");   
				return 0;
			}
			value /= RHS;
		}
	}

	return value;
}

f16 Low_Preceed(const u8* str) {
	f16 value = High_Preceed(str);

	while (1) {
		s8 op = str[pos];                   //similar to high preceed function from left to right
		if (op != '+' && op != '-') break;

		pos++;
		f16 RHS = High_Preceed(str);

		if (op == '+') value += RHS;
		else value -= RHS;
	}

	return value;
}

f16 calc(const u8* str) {
	pos = 0;  // reset global position before ending operation to avoid problems of garbage values ^_^
	return Low_Preceed(str);
}



