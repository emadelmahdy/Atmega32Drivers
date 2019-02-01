/*
 * Keypad_Driver_AVR.h
 *
 * Created: 8/12/2018 4:55:38 PM
 *  Author: em139
 */ 


#ifndef KEYPAD_DRIVER_AVR_H_
#define KEYPAD_DRIVER_AVR_H_


/*****************************/
/*user defined*/

#define delay(x) _delay_ms(x)

#define KPORT A
#define PA 1
#define PB 2
#define PC 3
#define PD 4

#define P1 5
#define P2 6
#define P3 7

/**/
void Keypad_Intial();
unsigned char Kepad_Pressed();
int Keypad_Get_Num();

#endif /* KEYPAD_DRIVER_AVR_H_ */
