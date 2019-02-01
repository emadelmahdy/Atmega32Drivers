/*
 * Timer_Driver_AVR.c
 *
 * Created: 8/22/2018 4:35:15 PM
 *  Author: em139
 */ 

#include <avr/io.h>
#include "Timer_Driver_AVR.h"

void T0_Init(char Mode)
{
	SREG|=(1<<7);                        //Enable global interrupt
	if (Mode=='T0') TCCR1B=0b00000000;                            //No clock source (Timer/Counter stopped).
	else if (Mode==T1) TCCR0=0b00000001;                            //clkI/O/1 (No prescaling)
	else if (Mode==T8) TCCR0=0b00000010;                            //clkI/O/8 (From prescaler)
	else if (Mode==T64) TCCR0=0b00000011;                           //clkI/O/64 (From prescaler)
	else if (Mode==T256) TCCR0=0b00000100;                          //clkI/O/256 (From prescaler)
	else if (Mode==T1024) TCCR0=0b00000101;                         //clkI/O/1024 (From prescaler)
	else if (Mode==CF) TCCR0=0b00000110;                            //External clock source on T1 pin. Clock on falling edge.
	else if (Mode==CR) TCCR0=0b00000111;                            //External clock source on T1 pin. Clock on rising edge.
	
	
	TIMSK|=(1<<0);                                 //enable overflow interrupt
	
}
void T1_Init(char Mode)
{
	SREG|=(1<<7);                        //Enable global interrupt
	TIMSK|=(1<<2);                                 //enable overflow interrupt
	
	if (Mode=='T0') TCCR1B=0b00000000;                            //No clock source (Timer/Counter stopped).
	else if (Mode==T1) TCCR1B=0b00000001;                            //clkI/O/1 (No prescaling)
	else if (Mode==T8) TCCR1B=0b00000010;                            //clkI/O/8 (From prescaler)
	else if (Mode==T64) TCCR1B=0b00000011;                           //clkI/O/64 (From prescaler)
	else if (Mode==T256) TCCR1B=0b00000100;                          //clkI/O/256 (From prescaler)
	else if (Mode==T1024) TCCR1B=0b00000101;                         //clkI/O/1024 (From prescaler)
	else if (Mode==CF) TCCR1B=0b00000110;                            //External clock source on T1 pin. Clock on falling edge.
	else if (Mode==CR) TCCR1B=0b00000111;                            //External clock source on T1 pin. Clock on rising edge.

	
}
