/*
 * EXT_INT.h
 *
 * Created: 10/20/2022 7:36:28 PM
 *  Author: Lenovo
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "EXT_INT_HW.h"

typedef enum{
	EX_INT0,
	EX_INT1,
	EX_INT2
}EXTINT_Channels;
	
typedef enum{
	LOW_Level,
	Logical,
	Falling,
	Risiing
	}EXTINTMODE;

void EXT_INT_Enable(EXTINT_Channels Channel);
void EXT_INI_Disable(EXTINT_Channels Channel);
void EXT_INT_ModeSet(EXTINT_Channels Channel,EXTINTMODE Mode);

#endif /* EXT_INT_H_ */