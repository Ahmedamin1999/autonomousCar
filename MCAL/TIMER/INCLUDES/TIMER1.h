/*
 * TIMER1.h
 *
 * Created: 11/18/2022 9:09:25 PM
 *  Author: Lenovo
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "BIT_MATH.h"
#include "STD_Types.h"

#define TCCR1A_REG	(*(volatile uint8 *)0x4F)
#define WGM10_BIT	0
#define WGM11_BIT	1
#define COM1A0_BIT	6
#define COM1A1_BIT	7

#define TCCR1B_REG	(*(volatile uint8 *)0x4E)
#define WGM12_BIT	3
#define WGM13_BIT	4
#define CS10_BIT	0
#define CS11_BIT	1
#define CS12_BIT	2

#define TCCNT1_REG	(*(volatile uint16 *)0x4C)
#define OCR1_REG	(*(volatile uint16 *)0x4A)
#define ICR1_REG	(*(volatile uint16 *)0x46)

void Timer1_Init(void);
void Set_OCR1(uint16 Data);

#endif /* TIMER1_H_ */