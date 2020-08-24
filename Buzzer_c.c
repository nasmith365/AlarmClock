/*
 * Buzzer_c.c
 *
 * Created: 3/23/2012 6:49:10 PM
 *  Author: linderd
 *	Purpose: Have the alarm go off when the Alarm function is true
 */ 
 #include "compare_h.h"
 #include "Buzzer_h.h"
 #include <avr/io.h>
 
 long tickAlarm=0;
 void Buzz();
void Buzz(){ 
	//calls alarm function
	if(Alarm() == on)
	{
		if(tickAlarm>=2)//Adjust for pitch of Alarm
		{
			tickAlarm-=2;
			PORTD = PORTD^(1<<PD6);//sound the alarm	
		}
	}	
	else
	{
		tickAlarm = 0;
		PORTD = (PORTD&~(1<<PD6))|(1<<PD6);//keep alarm off	
	}
}