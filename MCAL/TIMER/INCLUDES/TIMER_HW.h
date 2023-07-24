/*
 * TIMER_HW.h
 *
 * Created: 10/28/2022 8:10:52 PM
 *  Author: Lenovo
 */ 


#ifndef TIMER_HW_H_
#define TIMER_HW_H_

#include "BIT_MATH.h"
#include "STD_Types.h"

#define TCCR0_REG	(*(volatile uint8 *)0x53)

#define WGM01_BIT		3
#define WGM00_BIT		6
#define COM00_BIT		4
#define COM01_BIT		5
#define FOC_BIT			7

typedef enum{
	NoPsc = 1,
	PSC8,
	PSC64,
	PSC256,
	PSC1024
}Timer_PSC;

typedef enum{
	Normal,
	Phase_Correct_PWM,
	CTC,
	Fast_PWM,
}TIMER_Mode;

typedef enum{
	Normal_OC0,
	ToggleCC,
	ClearOC,
	SetOC
}OC0_Mode;

#define NON_Inverted	0
#define Inverted		1


#define TCNT0_REG	(*(volatile uint8 *)0x52)

#define TIMSK_REG	(*(volatile uint8 *)0x59)

#define TOIE0_BIT	0
#define OCIE0_BIT	1

typedef enum{
	Polling,
	Interrupt
	}Interrupt_MASK;

#define TIFK_REG	(*(volatile uint8 *)0x58)

#define TOV0_BIT	0
#define OCV0_BIT	1

#define OCR0_REG	(*(volatile uint8 *)0x5C)

#endif /* TIMER_HW_H_ */