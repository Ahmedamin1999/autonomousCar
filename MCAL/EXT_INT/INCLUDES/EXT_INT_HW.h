/*
 * EXT_INT_HW.h
 *
 * Created: 10/20/2022 7:36:05 PM
 *  Author: Lenovo
 */ 


#ifndef EXT_INT_HW_H_
#define EXT_INT_HW_H_

#include "BIT_MATH.h"
#include "STD_Types.h"
#include "DIO.h"

#define MCUCR_REG	(*(volatile uint8 *)0x55)
#define ISC00_BIT	0
#define ISC01_BIT	1
#define ISC10_BIT	2
#define ISC11_BIT	3

#define MCUCSR_REG		(*(volatile uint8 *)0x54)
#define ISC2_BIT	6

#define GICR_REG	(*(volatile uint8 *)0x5B)
#define INT0_BIT	6
#define INT1_BIT	7
#define INT2_BIT	5

#define GIFR_REG	(*(volatile uint8 *)0x5A)
#define INTF0_BIT	6
#define INTF1_BIT	7
#define INTF2_BIT	5

#endif /* EXT_INT_HW_H_ */