
/*this is keypad driver, it contain function for handling keypad 


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
	
	PinDir(KPORT2,P1,input);
	PinDir(KPORT2,P2,input);
	PinDir(KPORT2,P3,input);
	PinDir(KPORT2,P4,input);
	PinDir(KPORT2,P5,input);
	PinDir(KPORT2,P6,input);
}

unsigned char Kepad_Pressed()
{
	
	
	PinReset(KPORT,PA);
	PinReset(KPORT,PB);
	PinReset(KPORT,PC);
	PinReset(KPORT,PD);
	while( !(PinRead(KPORT2,P1)&&PinRead(KPORT2,P2)&&PinRead(KPORT2,P3)&&PinRead(KPORT2,P4)&&PinRead(KPORT2,P5)&&PinRead(KPORT2,P6)) );    //all keys open = 0
	
	while(1)
	{
		if (!(PinRead(KPORT2,P1)&&PinRead(KPORT2,P2)&&PinRead(KPORT2,P3)&&PinRead(KPORT2,P4)&&PinRead(KPORT2,P5)&&PinRead(KPORT2,P6)))
		{
			delay(20);
			if (!(PinRead(KPORT2,P1)&&PinRead(KPORT2,P2)&&PinRead(KPORT2,P3)&&PinRead(KPORT2,P4)&&PinRead(KPORT2,P5)&&PinRead(KPORT2,P6))) break;
		}
		
	}
	PinSet(KPORT,PB);
	PinSet(KPORT,PC);
	PinSet(KPORT,PD);
	
	
	PinReset(KPORT,PA);
	
		if (!PinRead(KPORT2,P1))
		{
			return 'R';
		}
		if (!PinRead(KPORT2,P2))
		{
			return 7;
		}
		if (!PinRead(KPORT2,P3))
		{
			return 8;
		}
		if (!PinRead(KPORT2,P4))
		{
			return 9;
		}
		if (!PinRead(KPORT2,P5))
		{
			return '*';
		}
		if (!PinRead(KPORT2,P6))
		{
			return '/';
		}
		
	
	
	PinSet(KPORT,PA);
	
	
	PinReset(KPORT,PB);
	
		if (!PinRead(KPORT2,P1))
		{
			return 0;
		}
		if (!PinRead(KPORT2,P2))
		{
			return 4;
		}
		if (!PinRead(KPORT2,P3))
		{
			return 5;
		}
		if (!PinRead(KPORT2,P4))
		{
			return 6;
		}
		if (!PinRead(KPORT2,P5))
		{
			return '-';
		}
		if (!PinRead(KPORT2,P6))
		{
			return 0;
		}
		
	
	PinSet(KPORT,PB);
	PinReset(KPORT,PC);
	
	
		if (!PinRead(KPORT2,P1))
		{
			return '%';
		}
		if (!PinRead(KPORT2,P2))
		{
			return 1;
		}
		if (!PinRead(KPORT2,P3))
		{
			return 2;
		}
		if (!PinRead(KPORT2,P4))
		{
			return 3;
		}
		if (!PinRead(KPORT2,P5))
		{
			return '+';
		}
		if (!PinRead(KPORT2,P6))
		{
			return 0;
		}
		
		
	
	
	PinSet(KPORT,PC);
	
	PinReset(KPORT,PD);
	
		if (!PinRead(KPORT2,P1))
		{
			return '^';
		}
		if (!PinRead(KPORT2,P2))
		{
			return 0;
		}
		if (!PinRead(KPORT2,P3))
		{
			return '.';
		}
		if (!PinRead(KPORT2,P4))
		{
			return '=';
		}
		if (!PinRead(KPORT2,P5))
		{
			return '+';
		}
		if (!PinRead(KPORT2,P6))
		{
			return 0;
		}
		
		
	
	
	PinSet(KPORT,PD);
	
	
	
}

int Keypad_Get_Num()
{
	int n=0;
	int key=0;
	while(1)
	{
	
		
		key=Kepad_Pressed();
		if (key!='=')
		{
			n=n*10+key;
		}
		else 
		{
			return n;
		}
	}
}
