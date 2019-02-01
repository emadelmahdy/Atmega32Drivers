/*
 * Timer_Driver_AVR.h
 *
 * Created: 8/22/2018 4:35:32 PM
 *  Author: em139
 */ 


#ifndef TIMER_DRIVER_AVR_H_
#define TIMER_DRIVER_AVR_H_

#define T0 0
#define T1 1
#define T8 2
#define T64 3
#define T256 4
#define T1024 5
#define CF 6
#define CR 7


void T0_Init(char Mode);
void T1_Init(char Mode);


#endif /* TIMER_DRIVER_AVR_H_ */
