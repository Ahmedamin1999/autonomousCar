/*
 * LM298.c
 *
 * Created: 1/3/2023 8:07:10 PM
 *  Author: Lenovo
 */ 

#include "LM298.h"

void Forward(void)
{
	DIO_WriteChannel(Motor1_F,STD_High);
	DIO_WriteChannel(Motor1_B,STD_Low);
	DIO_WriteChannel(Motor2_F,STD_High);
	DIO_WriteChannel(Motor2_B,STD_Low);	
}

void Backword(void)
{
	DIO_WriteChannel(Motor1_F,STD_Low);
	DIO_WriteChannel(Motor1_B,STD_High);
	DIO_WriteChannel(Motor2_F,STD_Low);
	DIO_WriteChannel(Motor2_B,STD_High);
}

void Left(void)
{
	DIO_WriteChannel(Motor1_F,STD_High);
	DIO_WriteChannel(Motor1_B,STD_Low);
	DIO_WriteChannel(Motor2_F,STD_Low);
	DIO_WriteChannel(Motor2_B,STD_High);
}

void Right(void)
{
	DIO_WriteChannel(Motor1_F,STD_Low);
	DIO_WriteChannel(Motor1_B,STD_High);
	DIO_WriteChannel(Motor2_F,STD_High);
	DIO_WriteChannel(Motor2_B,STD_Low);
}

void Stop(void)
{
	DIO_WriteChannel(Motor1_F,STD_Low);
	DIO_WriteChannel(Motor1_B,STD_Low);
	DIO_WriteChannel(Motor2_F,STD_Low);
	DIO_WriteChannel(Motor2_B,STD_Low);
}
