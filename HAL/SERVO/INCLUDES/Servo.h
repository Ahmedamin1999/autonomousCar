/*
 * Servo.h
 *
 * Created: 1/3/2023 7:11:14 PM
 *  Author: Lenovo
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "TIMER1.h"

void Servo_Init(void);
void Servo_Angle(uint8 Degree);

#endif /* SERVO_H_ */