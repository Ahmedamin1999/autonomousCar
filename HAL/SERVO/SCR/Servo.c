/*
 * Servo.c
 *
 * Created: 1/3/2023 7:11:32 PM
 *  Author: Lenovo
 */ 

#include "Servo.h"
#include "util/delay.h"

void Servo_Init(void){
	Timer1_Init();
}

void Servo_Angle(uint8 Degree)
{
	uint16 Data = 1000 + ((200/9) * Degree);
	
	Set_OCR1(Data);
	
	_delay_ms(5000);
}