/*
 * Car.c
 *
 * Created: 1/3/2023 9:14:06 PM
 *  Author: Lenovo
 */ 

#include "Car.h"

void Car_Init()
{
	Stop();
	/*Lcd*/
	LCD_MoveCursor(1,0);
	LCD_PrintString("                ");
	LCD_MoveCursor(1,6);
	LCD_PrintString("Stop");
	Servo_Angle(M_Servo);
	Servo_flag = 'M';
	Motion_flag = 'S';
	Rotation_flag = 'N';
}

void Move_Stright(uint32 Distance)
{
	if (Servo_flag == 'M' && Rotation_flag == 'N')
	{
	if(Distance <= Min_Dist && Motion_flag == 'F' && Motion_flag != 'S')
	{
		Stop();
		
		/*Lcd*/
		LCD_MoveCursor(1,0);
		LCD_PrintString("                ");
		LCD_MoveCursor(1,6);
		LCD_PrintString("Stop");
		Motion_flag = 'S';
	}
	else if(Distance > Min_Dist && Motion_flag != 'F'  )
	{
		Forward();
		/*Lcd*/
		LCD_MoveCursor(1,0);
		LCD_PrintString("                ");
		LCD_MoveCursor(1,5);
		LCD_PrintString("Forward");
		Motion_flag = 'F';
	}
	}
}

void Decision(uint32 Distance)
{
	if(Motion_flag == 'S' && Rotation_flag == 'N')
	{
	if(Servo_flag == 'M')
	{
		Servo_Angle(L_Servo);
		Servo_flag = 'L';
	}
	else if (Servo_flag == 'L')
	{
		Dist_L = Distance;
		Servo_Angle(R_Servo);
		Servo_flag = 'R';
	}
	else if (Servo_flag == 'R')
	{
		Dist_R = Distance;
		Rotation_flag = Dist_R >= Dist_L ?	'R':'L';
		Servo_Angle(M_Servo);
		Servo_flag = 'M';
	}
}
}

void Rotation(uint32 Distance)
{
	if (Motion_flag == 'S' && Servo_flag == 'M')
	{
		if (Rotation_flag == 'R')
		{
			/*Lcd*/
			LCD_MoveCursor(1,0);
			LCD_PrintString("                ");
			LCD_MoveCursor(1,6);
			LCD_PrintString("Right");
			Right();
			Motion_flag = 'R';
		}
		else if (Rotation_flag == 'L')
		{
			/*Lcd*/
			LCD_MoveCursor(1,0);
			LCD_PrintString("                ");
			LCD_MoveCursor(1,6);
			LCD_PrintString("Left");
			Left();
			Motion_flag = 'L';
		} 
	}
	else if ((Motion_flag == 'R' && (Dist_R - Car_Deminsion) <= Distance) 
			||
			 (Motion_flag == 'L' && (Dist_L - Car_Deminsion) <= Distance))
	{
		Stop();
		Motion_flag = 'S';
		Rotation_flag = 'N';
	}
}