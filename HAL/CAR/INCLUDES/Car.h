/*
 * Car.h
 *
 * Created: 1/3/2023 9:13:54 PM
 *  Author: Lenovo
 */ 


#ifndef CAR_H_
#define CAR_H_

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "Servo.h"
#include "LM298.h"
#include "LCD.h"

#define Min_Dist	90
#define M_Servo		90
#define L_Servo		180
#define R_Servo		0

 static uint8 Servo_flag,Motion_flag,Rotation_flag;
 static uint32 Dist_L = 0,Dist_R = 0,Car_Deminsion = 20;

void Car_Init();
void Move_Stright(uint32 Distance);
void Decision(uint32 Distance);
void Rotation(uint32 Distance);

#endif /* CAR_H_ */