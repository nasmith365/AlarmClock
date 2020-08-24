/*
 * Alert_Time.c
 *
 * Created: 3/25/2012 4:51:33 PM
 *  Author: Devin Leas
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include "Display.h"
//extern int onemin, tensmin, onehour, tenshour;
extern bool RTCAM,am,timechange,timechangeat;
int  COLHR=0, cathodehr,oldmin,oldhr;
void AlertTime_D(){
	int hr = AT_Hr();
	int minute = AT_Min();
	//bool a_m = AT_AM_PM();
//	char LEDAM;
	static int onesdigithr, tensdigithr, onesdigitmin, tensdigitmin;
	static int anodehr, anodemin, cathodemin;
	
	if (timechangeat==true)
	{
	onesdigithr=hr%10;
	tensdigithr=(hr/10)%10;
	
	onesdigitmin=minute%10;
	tensdigitmin=(minute/10)%10;		
	timechangeat=false;
	}
				
	anodehr = digits[tensdigithr][COLHR]<<4|digits[onesdigithr][COLHR]<<0;
	cathodehr = ~(1<<COLHR);
	
	anodemin = digits[tensdigitmin][COLHR]<<4|digits[onesdigitmin][COLHR]<<0;
	if (COLHR>4)	// As soon as it hits 6 it will return to 0
		{ 
			COLHR=-1;  // this code resets it back to 0
		}
	PORTD = (PORTD&~(1<<PD7))|(am<<PD7);

	PORTC = 0xFF; // Block current flow out of all LEDs	
	PORTA = anodehr;
	PORTB = anodemin;
	PORTC = cathodehr; // Permit current flow out of one column.
	//PORTD = cathodemin;
}
// This function shows the real time value on the LED matrix.

void RealTimeClock_D(){
	// Call three functions from RTC to get current correct time.	
	int hrr = CT_Hr();
	int minn = CT_Min();
	
	static int onedigithr, tendigithr, onedigitmin, tendigitmin;
	static int anodeshr, anodesmin, cathodesmin;
//	char LEDAM;

	if (timechange==true)
	{
	onedigithr=hrr%10;
	tendigithr=(hrr/10)%10;
	
	onedigitmin=minn%10;
	tendigitmin=(minn/10)%10;
	timechange=false;
	}	

	anodesmin = digits[tendigitmin][COLHR]<<4|digits[onedigitmin][COLHR]<<0;
	
	anodeshr = digits[tendigithr][COLHR]<<4|digits[onedigithr][COLHR]<<0;
	cathodehr = ~(1<<COLHR);
		if (COLHR>4)	// As soon as it hits 6 it will return to 0
		{ 
			COLHR=-1;  // this code resets it back to 0
		}	
	PORTD = (PORTD&~(1<<PD7))|(RTCAM<<PD7);
	
	PORTC = 0xFF; // Block current flow out of all LEDs	
	PORTA = anodeshr;
	PORTB = anodesmin;
	PORTC = cathodehr;
	//PORTD = cathodesmin;
}//end of REalTimeClock_D