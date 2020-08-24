/*
  Author: Nicholas Smith
  Compare.c
  Created: 3/22/2012 
  Purpose: This code will compare the time from the real time clock to the time that the alarm is supposed to go off. This program is responsible for telling the buzzer when to go off and when to shutup.
 */ 

 #include "buttons_h.h"
 #include "compare_h.h"

extern buttonheld trigger;
//bool Alarmon =false;
AlarmOn Alarm()
{
	int RTC_Min,RTC_hour;
	int AT_min,AT_hour;
	bool AT_Am_Pm, RTC_AM_PM;
	
	RTC_Min=CT_Min();//gets the real time min
	RTC_hour=CT_Hr();//gets the real time hour 	
	RTC_AM_PM=CT_AM_PM();//sees if the RTC is am or pm
	AT_min=AT_Min();//gets the alarm time min
	AT_hour=AT_Hr();//gets the alarm time hour
	AT_Am_Pm=AT_AM_PM();//gets to see if alarm time is am or pm
	
	if (trigger==active)
	{
	if (RTC_AM_PM==AT_Am_Pm)
	{
		if  (RTC_hour==AT_hour)
		{
			if (RTC_Min==AT_min)
			{
				return on;
			}
		}
	}
	}
	else
		return off;			
}

