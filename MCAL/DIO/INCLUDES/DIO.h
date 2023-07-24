/*
 * DIO.h
 *
 * Created: 10/8/2022 1:48:56 PM
 *  Author: Lenovo
 */ 

#ifndef DIO_H_
#define DIO_H_

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_WriteChannel(DIO_ChannelTypes WhichPin,STD_LevelTypes Write);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes WhichPin);
void DIO_WritePort(DIO_PortTypes WhichPort,uint8 PortValue);
uint8 DIO_ReadPort(DIO_PortTypes WhichPort);
void DIO_ToggleChannel(DIO_ChannelTypes WhichPin);

#endif
