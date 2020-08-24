/*
 * ISR_c.c
 *
 * Created: 3/23/2012 6:49:10 PM
 *  Author: Nicholas
 *	Purpose: To set the ISR to count ticks, which will increment the time
 */ 

 #include <avr/io.h>
 int tickAlarm = 0;
 ISR(TIMER0_COMP_vect)
	{
		int min = CT_Min();
		static long tick = 0;
		tick++;
		bool AlarmOn = Alarm();
		if (AlarmOn == true)
		{
			tickAlarm++;//Add one to the Alarm counter while the alarm is on	
		}
		else tickAlarm = 0;
		if(tick = 60000)//ticks=60seconds
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
		OCR0 = 3;
		TIMSK =TIMSK |(1<<OCIE0);
		DDRA=0xFF
		DDRB=0xFF
		DDRC=0xFF
		DDRD=0xFF
		sei();// enable ISR
	while(1){
		
	}	
