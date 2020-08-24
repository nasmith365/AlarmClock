/*
 * RTC_c.c
 *
 * Created: 3/23/2012 6:49:10 PM
 *  Author: linderd
 *	Purpose: Set the Real Time clock by calling functions to increment the hour and minute
 */ 
 #include "RTC_h.h"
 #include <stdbool.h>
 //int onemin=0, tensmin=0;
 //int onehour=2, tenshour=1;
 int RTChour = 12;//set the starting hour to 12, the following are set as global variables so each function can see them and the values are not reset
 int RTCmin = 0;//set the starting minutes to 0
 bool RTCAM = false, timechange=true;//set to start at AM
 extern int tick;
void RTC_incHr()
{	
	timechange=true;
	RTChour++;//increment the hour by 1 when the inchour button is pressed
	if(RTChour>12)
	{
		RTChour=1;//when the hour exceeds 12, restart at 1
	}
	else if(RTChour>11)
	{
		RTCAM = !RTCAM;//when the hour goes past 11 change the AM/PM to its opposite value
	}
	/*onehour++;	
	if ((onehour>9)&&(tenshour==0))
	{	
		onehour=0;
		tenshour++;
		if (tenshour>1)
		{
			tenshour=0;
		}		
	}	
	else if ((onehour>2)&&(tenshour==1))
	{		
		onehour=1;
		tenshour=0;	
	}*/	
}
void RTC_incMin()
{
	/*onemin++;
	if (onemin>9)
	{
		onemin=0;
		tensmin++;
		
		if (tensmin>5)
		{	RTC_incHr();
			tensmin=0;
		}
	}*/
	timechange=true;
	RTCmin++;//increment the minute by 1 when the incmin button is pressed
	if(RTCmin>59)
	{
		RTCmin=0;//when the the time exceeds 59, restart at 0
	}
	
}
int CT_Hr()
{
	return RTChour;//when CT_Hr is called it will return the current Hour
}
int CT_Min()
{
	return RTCmin;//when CT_Min is called it will return the current Minute
}
bool CT_AM_PM()
{
	return RTCAM;//when CT_AM_PM is called it will return the current AM/PM
}
