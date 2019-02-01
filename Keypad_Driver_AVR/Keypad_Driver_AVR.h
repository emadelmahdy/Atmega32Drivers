
#ifndef KEYPAD_DRIVER_AVR_H_
#define KEYPAD_DRIVER_AVR_H_


/*****************************/
/*user defined*/

#define delay(x) _delay_ms(x)

#define KPORT A
#define KPORT2 B
#define PA 0
#define PB 1
#define PC 2
#define PD 3

#define P1 0
#define P2 1
#define P3 2
#define P4 3
#define P5 4
#define P6 5

/**/
void Keypad_Intial();
unsigned char Kepad_Pressed();
int Keypad_Get_Num();

#endif /* KEYPAD_DRIVER_AVR_H_ */
