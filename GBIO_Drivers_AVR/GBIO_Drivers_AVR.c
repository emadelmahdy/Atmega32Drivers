
#include "GBIO_Drivers_AVR.h"

void PortDir(char port ,char state)
{
	
	if (state==output)
	{
		(*(volatile unsigned char *)(port+1))=0xff;
	}
	else
	{
		(*(volatile unsigned char *)(port+1))=0x00;
	}
}
void PinDir(char port , char pin , char state)
{
	if (state==output)
	{
		(*(volatile unsigned char *)(port+1)) |=(1<<pin);
	}
	else
	{
		(*(volatile unsigned char *)(port+1)) &=~(1<<pin);
	}
}

void PortSet(char port)
{
	(*(volatile unsigned char *)(port+2))=0xff;
}
void PortReset(char port)
{
	(*(volatile unsigned char *)(port+2))=0x00;
}

void PinSet (char port , char pin)
{
	(*(volatile unsigned char *)(port+2)) |=(1<<pin);
}

void PinReset (char port , char pin)
{
	(*(volatile unsigned char *)(port+2)) &=~(1<<pin);
}
void PortWrite(char port,char value)
{
	(*(volatile unsigned char *)(port+2))=value;
}

char PortRead(char port)
{
	return (*(volatile unsigned char *)port);
}

void PinWrite(char port , char pin,char value )
{
	if (value==0)
	{
		(*(volatile unsigned char *)(port+2)) &=~(1<<pin);
	}
	else
	{
		(*(volatile unsigned char *)(port+2)) |=(1<<pin);
	}
}
char PinRead(char port,char pin)
{
	char result;
	result=(*(volatile unsigned char *)port) & (1<<pin);
	if (result==0)
	{
		return 0;
	}
	else
	return 1;
}
