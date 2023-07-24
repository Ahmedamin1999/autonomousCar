/*
 * EXT_INT.c
 *
 * Created: 10/20/2022 7:36:53 PM
 *  Author: Lenovo
 */ 

#include "EXT_INT.h"

void EXT_INT_Enable(EXTINT_Channels Channel)
{
	switch(Channel)
	{
		case EX_INT0 :
		SET_BIT(GICR_REG,INT0_BIT);
		break;
		case EX_INT1 :
		SET_BIT(GICR_REG,INT1_BIT);
		break;
		case EX_INT2 :
		SET_BIT(GICR_REG,INT2_BIT);
		break;
	}
}

void EXT_INI_Disable(EXTINT_Channels Channel)
{
	switch(Channel)
	{
		case EX_INT0 :
		CLEAR_BIT(GICR_REG,INT0_BIT);
		break;
		case EX_INT1 :
		CLEAR_BIT(GICR_REG,INT1_BIT);
		break;
		case EX_INT2 :
		CLEAR_BIT(GICR_REG,INT2_BIT);
		break;
	}
}

void EXT_INT_ModeSet(EXTINT_Channels Channel,EXTINTMODE Mode)
{
	switch(Channel)
	{
		case EX_INT0 :
		MCUCR_REG &= 0xFC;
		MCUCR_REG |= (Mode); 
		break;
		case EX_INT1 :
		MCUCR_REG &= 0xF3;
		MCUCR_REG |= (Mode<<2); 
		break;
		case EX_INT2 :
		switch(Mode)
		{
			case Falling :
			CLEAR_BIT(MCUCSR_REG,ISC2_BIT);
			break;
			case Risiing :
			SET_BIT(MCUCSR_REG,ISC2_BIT);
			break;
		}
		break;
	}
}

