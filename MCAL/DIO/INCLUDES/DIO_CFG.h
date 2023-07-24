/*
 * DIO_CFG.h
 *
 * Created: 10/8/2022 1:35:07 PM
 *  Author: Lenovo
 */ 

#ifndef DIO_CFG_h_
#define DIO_CFG_h_

#include "DIO.h"

typedef struct
{
	DIO_DirTypes pinDir;
	STD_LevelTypes Level;
	
	}DIO_pincfg;
	
#define PINCOUNT	32

void DIO_Init(void);

#endif
