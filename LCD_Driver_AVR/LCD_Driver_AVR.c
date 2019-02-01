

#include <avr/io.h>
#include <avr/delay.h>
#include "GBIO_Drivers_AVR.h"
//#define F_CPU 4000000
#include "LCD_Driver_AVR.h"

#define Mode 8
void LCD_Intial()
{
	_delay_ms(15);
	PinDir(InsPort,RS,output);
	PinDir(InsPort,E,output);
	PinReset(InsPort,RS);
	PinReset(InsPort,E);
	if (Mode==8)
	{
		PortDir(DataPort,output);            //make dataport output
		PortReset(DataPort);            //make dataport intially zero
		LCD_Cmd(0x38);
		_delay_ms(10);
	}
	else if (Mode==4)
	{
		PinDir(DataPort,P0,output);
		PinDir(DataPort,P1,output);
		PinDir(DataPort,P2,output);
		PinDir(DataPort,P3,output);
		
		PinReset(DataPort,P0);
		PinReset(DataPort,P1);
		PinReset(DataPort,P2);
		PinReset(DataPort,P3);
		
		LCD_Cmd(0x33);
		LCD_Cmd(0x32);
		LCD_Cmd(0x28);
	}
	LCD_Cmd(0x0E);                         //set curser command
	_delay_ms(10);
	LCD_Cmd(0x01);
	//LCD_Cmd(0x80);                         //go to first line in first position
	_delay_us(4000);
	//LCD_Cmd(0x06);
}

void LCD_Cmd(unsigned char cmd)
{
	
	PinReset(InsPort,RS);                          //put RS=0 to send command
	if (Mode==8)
	{
		PortWrite(DataPort,cmd);
	}
	else if (Mode==4)
	{
		PinWrite(DataPort,P0, cmd & (1<<0));
		PinWrite(DataPort,P1, cmd & (1<<1));
		PinWrite(DataPort,P2, cmd & (1<<2));
		PinWrite(DataPort,P3, cmd & (1<<3));
		
		char cmd2=0x00;
		cmd2==(cmd>>4);
		
		PinSet(InsPort,E);
		_delay_ms(10);
		PinReset(InsPort,E);                  //high to low pulse
		
		PinWrite(DataPort,P0, cmd2 & (1<<0));
		PinWrite(DataPort,P1, cmd2 & (1<<1));
		PinWrite(DataPort,P2, cmd2 & (1<<2));
		PinWrite(DataPort,P3, cmd2 & (1<<3));
		
	}
	PinSet(InsPort,E);
	_delay_ms(10);
	PinReset(InsPort,E);                  //high to low pulse
	_delay_us(1000);                       //original delay is 100us delay
	
}

void LCD_Data(unsigned char data)
{
	
	if (Mode==8)
	{
		PortWrite(DataPort,data);
	}
	else if (Mode==4)
	{
		PinWrite(DataPort,P0, data & (1<<0));
		PinWrite(DataPort,P1, data & (1<<1));
		PinWrite(DataPort,P2, data & (1<<2));
		PinWrite(DataPort,P3, data & (1<<3));
		
		char data2=0x00;
		data2==(data>>4);
		
		PinSet(InsPort,E);
		_delay_ms(10);
		PinReset(InsPort,E);                  //high to low pulse
		_delay_us(1000);
		PinWrite(DataPort,P0, data2 & (1<<0));
		PinWrite(DataPort,P1, data2 & (1<<1));
		PinWrite(DataPort,P2, data2 & (1<<2));
		PinWrite(DataPort,P3, data2 & (1<<3));
		
	}
	PinSet(InsPort,RS);                          //put RS=1 to send data
	PinSet(InsPort,E);
	_delay_ms(10);
	PinReset(InsPort,E);                  //high to low pulse
	_delay_us(1000);                       //original delay is 100us delay
}
void LCD_Word(char * word)
{
	unsigned char i=0;
	while(word[i]!=0)
	{
		LCD_Data(word[i]);
		i++;
	}
}
