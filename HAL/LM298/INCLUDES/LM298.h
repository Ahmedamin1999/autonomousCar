/*
 * LM298.h
 *
 * Created: 1/3/2023 8:06:57 PM
 *  Author: Lenovo
 */ 


#ifndef LM298_H_
#define LM298_H_

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO.h"

#define Motor1_F	DIO_ChannelC0
#define Motor1_B	DIO_ChannelC1
#define Motor2_F	DIO_ChannelC2
#define Motor2_B	DIO_ChannelC3

void Forward(void);
void Backword(void);
void Left(void);
void Right(void);
void Stop(void);

#endif /* LM298_H_ */