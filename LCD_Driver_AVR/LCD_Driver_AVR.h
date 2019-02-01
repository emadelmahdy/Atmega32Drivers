


#ifndef LCD_DRIVER_AVR_H_
#define LCD_DRIVER_AVR_H_


/********************************************/
/*user level*/
#define DataPort D
#define P0 0                                //0,1,2..etc are number of pin in microcontroller
#define P1 1                                //P0,P1..etc are number of bin in LCD
#define P2 2
#define P3 3
#define P4 4
#define P5 5
#define P6 6
#define P7 7
#define InsPort C
#define E 4
#define RS 2

/*************************************************/


void LCD_Intial();
void LCD_Cmd(unsigned char cmd);
void LCD_Data(unsigned char data);
void LCD_Word(char * word);


#endif /* LCD_DRIVER_AVR_H_ */
