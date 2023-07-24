/*
 * TIMER.h
 *
 * Created: 10/28/2022 8:11:06 PM
 *  Author: Lenovo
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "TIMER_HW.h"

typedef struct{
	Timer_PSC PSC;
	TIMER_Mode Mode;
	Interrupt_MASK	Mask;
	OC0_Mode	OC0Mode;
	uint8 Invert_Mode;
	}TimerConfStruct;

void Timer_INIT(TimerConfStruct * ptr);
void Timer_Start(void);
void Timer_Stop(void);
void Timer_OVF(void);
void PWM_SetDuty(uint8 Duty);

#endif /* TIMER_H_ */