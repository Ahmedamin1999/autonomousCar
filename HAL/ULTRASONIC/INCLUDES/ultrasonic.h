#ifndef _ULTRA_H_
#define _ULTRA_H_

#include "CLK.h"
#include <avr/interrupt.h>
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include<string.h>
#include <stdlib.h>
#include <util/delay.h>
#include "TIMER.h"
#include "EXT_INT.h"
#include "Car.h"

#if F_CPU == 8000000
#define ultrasonic_Constant		466
#elif F_CPU == 16000000	
#define ultrasonic_Constant		933
#endif

#define   TRIGER_DDR    DDRD_REG
#define   ECHO_DDR      DDRD_REG
#define   TRIGER_PORT   PORTD_REG
#define   ECHO_PULLUP   PORTD_REG
#define   TRIGER        DIO_ChannelD0
#define   ECHO          DIO_ChannelD3

void ultrasonic_init(void);
void ultrasonic_triger(void);
void Display_Distance(uint32 distance);

#endif
