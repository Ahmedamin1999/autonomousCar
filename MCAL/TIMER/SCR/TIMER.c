/*
 * TIMER.c
 *
 * Created: 10/28/2022 8:11:22 PM
 *  Author: Lenovo
 */ 

#include "TIMER.h"
#include "TIMER1.h"

static TimerConfStruct InitStruct;

void Timer_INIT(TimerConfStruct * ptr)
{
	InitStruct.Mask = ptr->Mask;
	InitStruct.Mode = ptr->Mode;
	InitStruct.OC0Mode = ptr->OC0Mode;
	InitStruct.PSC = ptr->PSC;
	InitStruct.Invert_Mode = ptr->Invert_Mode;
	
	/*Specifing Timer Mode*/
	
	if (InitStruct.Mode == Normal)
	{
	CLEAR_BIT(TCCR0_REG,WGM01_BIT);
	
	/*Specify Interrupt Mode*/
	if (InitStruct.Mask == Interrupt)
	{
		SET_BIT(TIMSK_REG,TOIE0_BIT);
	}
	else if (InitStruct.Mask == Polling)
	{
		CLEAR_BIT(TIMSK_REG,TOIE0_BIT);
	}
	
	}
	else if(InitStruct.Mode == CTC)
	{
		SET_BIT(TCCR0_REG,WGM01_BIT);
	
	/*IF using CTC Mode == specify OC0*/
	TCCR0_REG &= 0xCF;
	TCCR0_REG |= (InitStruct.OC0Mode << 4);
	
	/*Specify Interrupt Mode*/
	if (InitStruct.Mask == Interrupt)
	{
		SET_BIT(TIMSK_REG,OCIE0_BIT);
	}
	else if (InitStruct.Mask == Polling)
	{
		CLEAR_BIT(TIMSK_REG,OCIE0_BIT);
	}
	}
	else if (InitStruct.Mode == Fast_PWM)
	{
		/*Set mode to fast_pwm*/
		TCCR0_REG &= 0xB7;
		SET_BIT(TCCR0_REG,WGM01_BIT);
		SET_BIT(TCCR0_REG,WGM00_BIT);
		
		/*Choose Inverted mode OR NonInverted mode*/
		if (InitStruct.Invert_Mode == NON_Inverted)
		{
			CLEAR_BIT(TCCR0_REG,COM00_BIT);
			SET_BIT(TCCR0_REG,COM01_BIT);
		}
		else if (InitStruct.Invert_Mode == Inverted)
		{
			SET_BIT(TCCR0_REG,COM00_BIT);
			SET_BIT(TCCR0_REG,COM01_BIT);
		}
	}
	else if (InitStruct.Mode == Phase_Correct_PWM)
	{
		/*Set mode to Phase_Correct_pwm*/
		TCCR0_REG &= 0xB7;
		CLEAR_BIT(TCCR0_REG,WGM01_BIT);
		SET_BIT(TCCR0_REG,WGM00_BIT);
		
		/*Choose Inverted mode OR NonInverted mode*/
			if (InitStruct.Invert_Mode == NON_Inverted)
			{
				CLEAR_BIT(TCCR0_REG,COM00_BIT);
				SET_BIT(TCCR0_REG,COM01_BIT);
			}
			else if (InitStruct.Invert_Mode == Inverted)
			{
				SET_BIT(TCCR0_REG,COM00_BIT);
				SET_BIT(TCCR0_REG,COM01_BIT);
			}
	}
		
}

void Timer_Start(void)
{
	TCCR0_REG &= 0xF8;
	TCCR0_REG |= InitStruct.PSC;
	
}

void Timer_Stop(void)
{
	CLEAR_BIT(TIMSK_REG,TOIE0_BIT);
}

void Timer_OVF(void)
{
	while(READ_BIT(TIFK_REG,TOV0_BIT) == 0);
	SET_BIT(TIFK_REG,TOV0_BIT);
}

void PWM_SetDuty(uint8 Duty)
{
	OCR0_REG = (255 * Duty) / 100;
}

void Timer1_Init(void)
{
	/*choose mode of operation using WGM1X bits*/
	CLEAR_BIT(TCCR1A_REG,WGM10_BIT);
	SET_BIT(TCCR1A_REG,WGM11_BIT);
	SET_BIT(TCCR1B_REG,WGM12_BIT);
	SET_BIT(TCCR1B_REG,WGM13_BIT);
	/*choose in inverted or normal mode using COMAX Bits*/
	CLEAR_BIT(TCCR1A_REG,COM1A0_BIT);
	SET_BIT(TCCR1A_REG,COM1A1_BIT);
	/*set ICR value to 40000*/
	ICR1_REG = 40000;
	/*SET OCR value to 2000*/
	OCR1_REG = 2000;
	/*set clock prescalaer*/
	CLEAR_BIT(TCCR1B_REG,CS10_BIT);
	SET_BIT(TCCR1B_REG,CS11_BIT);
	CLEAR_BIT(TCCR1B_REG,CS12_BIT);
}

void Set_OCR1(uint16 Data)
{
	OCR1_REG = Data;
}