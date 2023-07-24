/*
 * GccApplication1.c
 *
 * Created: 10/7/2022 3:14:38 PM
 * Author : Ahmed Medhat
 * Email  : ahmed1998medhate@gmail.com
 */ 

#include <avr/interrupt.h>
#include <stdlib.h>

#include "CLK.h"
#include "DIO.h"

#include "LCD.h"

#include "EXT_INT.h"

#include "TIMER.h"
#include "TIMER1.h"
#include "ultrasonic.h"
#include "Servo.h"
#include "LM298.h"

int main(void)

{
 	sei();
	DIO_Init();
 	LCD_Init();
 	LCD_PrintString("Distance ");
	_delay_ms(10);
 	Servo_Init();
 	Car_Init();
	ultrasonic_init();	
	
		while(1){
    		ultra_triger();
    		_delay_ms(10);

	}
}