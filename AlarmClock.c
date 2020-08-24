/*
 * AlarmClock.c
 *
 * Created: 3/23/2012 6:49:10 PM
 *  Author: linderd
 *	Purpose: To set the ISR to count ticks, which will increment the time
 */ 

 #include <avr/interrupt.h>
 #include <stdbool.h>
 extern long tickAlarm;
 long tick = 0;
 extern int COLHR;
 ISR(TIMER0_COMP_vect)
	{
		COLHR = COLHR + 1; //Increment the cycle

		int min = CT_Min();		
		tick++;
		tickAlarm++;//Add one to the Alarm counter while the alarm is on	
		if(tick == 10992)//ticks=60seconds
		{
			tick = 0;//when the seconds equal 60, reset at 0
			RTC_incMin();//increment the minutes by 1
			min = min + 1;
			if(min > 59)
			{
				RTC_incHr();//increment the hour by 1
			}			
		}
	}
	
int main(void)
{	
		TCCR0 = (1<<WGM01)|(0<<CS02)|(1<<CS01)|(1<<CS00);
		OCR0 = 12;
		TIMSK =TIMSK |(1<<OCIE0);
		DDRA=0xFF;
		DDRB=0xFF;
		DDRC=0xFF;
		DDRD=0xC0;
		sei();// enable ISR
	while(1)
	{		
		if(!(PIND&1<<PD3))//tells what it is supposed to display, if this was debouncing code it will cause interference
		AlertTime_D();
		else
		RealTimeClock_D();//call the display to display the realtime clock with it will display until the setalarm button is held		
		buttons();
		Buzz();
	}	
}	