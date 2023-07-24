/*
 * DIO_CFG.c
 *
 * Created: 10/8/2022 1:52:20 PM
 *  Author: Lenovo
 */
 
#include "DIO.h"

DIO_pincfg pinCfg[] ={
	
	//portA
	{Output,STD_High},	//0
	{Output,STD_High},	//1
	{Output,STD_High},	//2
    {Output,STD_Low},	//3
	{Output,STD_High},	//4
	{Output,STD_High},	//5
	{Output,STD_High},	//6
	{Output,STD_High},	//7
				
	//portB		
	{Output,STD_High},		//0
	{Output,STD_High},		//1
	{Output,STD_High},		//2
	{Output,STD_High},		//3
	{Output,STD_High},		//4
	{Output,STD_Low},		//5
	{Input,STD_Low},		//6
	{Output,STD_Low},		//7
	
	//portC
	{Output,STD_Low},	//0
	{Output,STD_Low},	//1
	{Output,STD_Low},	//2
	{Output,STD_Low},	//3
	{Input,STD_Low},	//4
	{Input,STD_Low},	//5
	{Input,STD_Low},	//6
	{Input,STD_Low},	//7
	
	//portD
	{Output,STD_High},	//0
	{Output,STD_High},	//1
	{Output,STD_High},	//2
	{Input,STD_Low},	//3
	{Output,STD_Low},	//4
	{Output,STD_Low},	//5
	{Output,STD_Low},	//6
	{Output,STD_Low},	//7
};

void DIO_Init(void)
{
	DIO_ChannelTypes count = DIO_ChannelA0;
	DIO_ChannelTypes BitNO;
	DIO_PortTypes Portx;
	
	for(count = DIO_ChannelA0; count < PINCOUNT;count++)
	{
		Portx = count/8;
		BitNO = count%8;
		
		switch(Portx)
		{
			case DIO_PortA:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRA_REG,BitNO);
			else
			CLEAR_BIT(DDRA_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTA_REG,BitNO);
			else
			CLEAR_BIT(PORTA_REG,BitNO);
			break;
			
			case DIO_PortB:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRB_REG,BitNO);
			else
			CLEAR_BIT(DDRB_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTB_REG,BitNO);
			else
			CLEAR_BIT(PORTB_REG,BitNO);
			break;
			
			case DIO_PortC:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRC_REG,BitNO);
			else
			CLEAR_BIT(DDRC_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTC_REG,BitNO);
			else
			CLEAR_BIT(PORTC_REG,BitNO);
			break;
			
			case DIO_PortD:
			if (pinCfg[count].pinDir == Output)
			SET_BIT(DDRD_REG,BitNO);
			else
			CLEAR_BIT(DDRD_REG,BitNO);
			
			if (pinCfg[count].Level == STD_High)
			SET_BIT(PORTD_REG,BitNO);
			else
			CLEAR_BIT(PORTD_REG,BitNO);
			break;
			
		}
		
	}
	
}


