/*
 * Keypad_Driver_AVR.c
 *
 * Created: 8/12/2018 4:55:04 PM
 *  Author: em139
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "GBIO_Drivers_AVR.h"
#include "Keypad_Driver_AVR.h"

void Keypad_Intial()
{
	PinDir(KPORT,PA,output);
	PinDir(KPORT,PB,output);
	PinDir(KPORT,PC,output);
	PinDir(KPORT,PD,output);
	PinSet(KPORT,PA);
	PinSet(KPORT,PB);
	PinSet(KPORT,PC);
	PinSet(KPORT,PD);
	
	PinDir(KPORT,P1,input);
	PinDir(KPORT,P2,input);
	PinDir(KPORT,P3,input);
}

unsigned char Kepad_Pressed()
{
	
	
	unsigned char i;
					           };
	PinReset(KPORT,PA);
	PinReset(KPORT,PB);
	PinReset(KPORT,PC);
	PinReset(KPORT,PD);
	while(!(PinRead(KPORT,P1)&&PinRead(KPORT,P2)&&PinRead(KPORT,P3)));    //all keys open = 0
	
	while(1)
	{
		if (!(PinRead(KPORT,P1)&&PinRead(KPORT,P2)&&PinRead(KPORT,P3)))
		{
			delay(20);
			if (!(PinRead(KPORT,P1)&&PinRead(KPORT,P2)&&PinRead(KPORT,P3))) break;
		}
		
	}
	PinSet(KPORT,PB);
	PinSet(KPORT,PC);
	PinSet(KPORT,PD);
	
	
	PinReset(KPORT,PA);
	
		if (!PinRead(KPORT,P1))
		{
			return 1;
		}
		if (!PinRead(KPORT,P2))
		{
			return 2;
		}
		if (!PinRead(KPORT,P3))
		{
			return 3;
		}
		
	
	
	PinSet(KPORT,PA);
	
	
	PinReset(KPORT,PB);
	
		if (!PinRead(KPORT,P1))
		{
			
			return 4;
		}
		if (!PinRead(KPORT,P2))
		{
			
			return 5;
		}
		if (!PinRead(KPORT,P3))
		{
			
			return 6;
		}
		
	
	PinSet(KPORT,PB);
	PinReset(KPORT,PC);
	
	
		if (!PinRead(KPORT,P1))
		{
			
			return 7;
		}
		
		
		if (!PinRead(KPORT,P2))
		{
			
			return 8;
		}
		if (!PinRead(KPORT,P3))
		{
			
			return 9;
		}
		
		
	
	
	PinSet(KPORT,PC);
	
	PinReset(KPORT,PD);
	
		if (!PinRead(KPORT,P1))
		{
			
			return '*';
		}
		if (!PinRead(KPORT,P2))
		{
			
			return 0;
		}
		if (!PinRead(KPORT,P3))
		{
			
			return '#';
		}
		
		
	
	
	PinSet(KPORT,PD);
	
	
	
}

int Keypad_Get_Num()
{
	int n=0;
	int key=0;
	while(1)
	{
	//	Keypad_Intial();
		
		key=Kepad_Pressed();
		if (key!='#')
		{
			n=n*10+key;
		}
		else 
		{
			return n;
		}
	}
}
