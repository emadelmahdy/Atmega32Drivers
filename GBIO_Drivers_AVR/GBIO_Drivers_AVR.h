/*
 * GBIO_Drivers_AVR.h
 *
 * Created: 7/24/2018 6:06:12 PM
 *  Author: em139
 */ 


#ifndef GBIO_DRIVERS_AVR_H_
#define GBIO_DRIVERS_AVR_H_

#define A 0x39
#define B 0x36
#define C 0x33
#define D 0x30

#define input 0
#define output 1

void PortDir(char port ,char state);
void PinDir(char port , char pin , char state);
void PortSet(char port);
void PortReset(char port);
void PinSet (char port , char pin);
void PinReset (char port , char pin);
void PortWrite(char port,char value);
char PortRead(char port);
void PinWrite(char port , char pin,char value );
char PinRead(char port,char pin);





#endif /* GBIO_DRIVERS_AVR_H_ */
