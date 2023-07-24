/*
 * LCD.c
 *
 * Created: 10/14/2022 1:40:28 PM
 *  Author: Lenovo
 */ 

#include "CLK.h"
#include "util/delay.h"
#include "LCD.h"

#ifdef LCD_8
/*
// 
// void LCD_EN_Trigger(void)
// {
// 	SET_BIT(PORTB_REG,EN);
// 	_delay_ms(4);
// 	CLEAR_BIT(PORTB_REG,EN);
// 	_delay_ms(4);
// }
// 
// void LCD_Clear(void)
// {
// 	LCD_SendCmd(0x01);
// 	_delay_ms(20);
// }
// 
// void LCD_SendCmd(uint8 cmd)
// {
//  	CLEAR_BIT(PORTB_REG,RS);
//  	PORTA_REG = cmd;
//  	LCD_EN_Trigger();	
// }
// 
// void LCD_MoveCursor(uint8 row,uint8 col)
// {
// 	if(row == 0)
// 	LCD_SendCmd(0x80 + col);
// 	else if(row == 1)
// 	LCD_SendCmd(0xc0 + col);
// }
// 
// void LCD_PrintChar(uint8 Data)
// {
// 	PORTA_REG = Data;
// 	SET_BIT(PORTB_REG,RS);
// 	LCD_EN_Trigger();
// }
// 
// void LCD_PrintString(uint8 *ptr)
// {
// 	uint32 i;
// 	for (i = 0;;i++)
// 	{
// 		if(ptr[i] != '\0')
// 		LCD_PrintChar(ptr[i]);
// 		else if(ptr[i] == '\0')
// 		break;
// 	}
// / *
// // 	while(ptr[i] != '\0')
// // 	LCD_PrintChar(ptr[i]);
// // 	i++;
// * /
// }
// 
// void LCD_Init(void)
// {
// 	DDRA_REG = 0xFF;
// 	DDRB_REG |= 0x0E;
// 	CLEAR_BIT(PORTB_REG,RW);
// 	LCD_SendCmd(0x38);
// 	LCD_SendCmd(0x0F);
// 	LCD_SendCmd(0x01);
// 	_delay_ms(20);
// }
*/

#elif defined LCD_4

void LCD_EN_Trigger(void)
{
	DIO_WriteChannel(LCD_EN,STD_Low);
	_delay_us(100);
	DIO_WriteChannel(LCD_EN,STD_High);
	_delay_ms(5);
}

void LCD_Clear(void)
{
	LCD_SendCmd(0x01);
	_delay_ms(20);
}

void LCD_SendCmd(uint8 cmd)
{
	DIO_WriteChannel(LCD_RS,STD_Low);
	LCD_DataPort &= 0x0F;
	LCD_DataPort |= cmd & 0xf0;
	
	LCD_EN_Trigger();
	
	LCD_DataPort &= 0x0F;
	LCD_DataPort |= (cmd << 4);
	
	LCD_EN_Trigger();
}

void LCD_MoveCursor(uint8 row,uint8 col)
{
	if(row == 0)
	LCD_SendCmd(0x80 + col);
	else if(row == 1)
	LCD_SendCmd(0xc0 + col);
}

void LCD_PrintChar(uint8 Data)
{
	DIO_WriteChannel(LCD_RS,STD_High);//Select Data Register
	LCD_DataPort &= 0x0F;
	LCD_DataPort |= Data & 0xf0;
	
	LCD_EN_Trigger();
	
	LCD_DataPort &= 0x0F;
	LCD_DataPort |= (Data << 4);
	
	LCD_EN_Trigger();
}

void LCD_PrintString(uint8 *ptr)
{
	uint32 i = 0;

	while(ptr[i] != '\0')
	{
	LCD_PrintChar(ptr[i]);
	i++;
	}
}

void LCD_Init(void)
{
	DIO_WriteChannel(LCD_RW,STD_Low);
	
	_delay_ms(20);
	
  	LCD_SendCmd(0x33);//Function set to 8-bit mode
  	_delay_ms(2);
 	LCD_SendCmd(0x32);// Function set to 8-bit mode again

	LCD_SendCmd(0x28);//Set Function 4-Bit & 2Line & 5*8 Dots
	LCD_SendCmd(0x0f);//Turn display on, cursor on and blink cursor.
	LCD_SendCmd(0x01);//Clear LCD
	LCD_SendCmd(0x06);//Entry Mode move to right and no shift
	LCD_SendCmd(0x02);//send the cursor to the home position
}

#endif