/*
 * LCD.h
 *
 * Created: 10/14/2022 1:40:07 PM
 *  Author: Lenovo
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"

#define	LCD_RS			DIO_ChannelB1
#define LCD_RW			DIO_ChannelB2
#define LCD_EN			DIO_ChannelB3
#define LCD_DataPort	PORTA_REG
#define LCD_4

void LCD_EN_Trigger(void);
void LCD_Clear(void);
void LCD_SendCmd(uint8 cmd);
void LCD_MoveCursor(uint8 row,uint8 col);
void LCD_PrintChar(uint8 Data);
void LCD_PrintString(uint8 *ptr);
void LCD_Init(void);
 
#endif /* LCD_H_ */