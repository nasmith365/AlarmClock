/*
 * buttonstest.c
 *
 * Created: 3/27/2012 11:53:40 PM
 *  Author: Nicholas
 */ 
#include "buttons_h.h"

buttonheld trigger=inactive;
extern int tick;
void buttons(){
	static States;	
	static int action =0;
if (((tick%1024)==0))//a power of 2 so its faster
{
	voteRTC();
	voteAT();
	votesetmin();
	votesethr();
	voteAlarmOn();
}				
if (voteRTC()==high)
{	
	if (votesetmin()==high)
	{
	switch (States){
		case inactive: 
			States = pressed;   break;	
		case pressed:
			States= held; RTC_incMin();  break;	
		case held:
			States = released; break;	
		case released:
			States = inactive; break;	
		default:
				States=inactive; break;
		}//end of switch
	}
	if (votesethr()==high)
	{
		switch (States){
		case inactive: 
			States = pressed;   break;	
		case pressed:
			States= held; RTC_incHr();  break;	
		case held:
			States = released; break;	
		case released:
			States = inactive; break;	
		default:
				States=inactive; break;
		}//end of switch
	}				
}

if(voteAT()==high)
{
	if (votesetmin()==high)
	{
	switch (States){
		case inactive: 
			States = pressed;   break;	
		case pressed:
			States= held; AT_incMin();  break;	
		case held:
			States = released; break;	
		case released:
			States = inactive; break;	
		default:
				States=inactive; break;
		}//end of switch
	}
	if (votesethr()==high)
	{
		switch (States){
		case inactive: 
			States = pressed;   break;	
		case pressed:
			States= held; AT_incHr();  break;	
		case held:
			States = released;break;	
		case released:
			States = inactive; break;	
		default:
				States=inactive; break;
		}//end of switch
	}				
}
//if(voteAlarmOn()==high)
if(!(PIND&1<<PD4))
{
	switch (States){
		case inactive: 
			States = pressed;   break;	
		case pressed:
			States= held; 
			if (trigger==inactive)
			trigger=active;
			else
			trigger=inactive;
			break;	
		case held:
			States = released; break;	
		case released:
			States = inactive; break;	
		default:
				States=inactive; break;
		}//end of switch
}
}//end of Buttons

//-------------------Debouncing Code-------------

debounce votesetmin()
{
	static char tracemin;
	if(!(PIND&1<<PD0))
	{
		tracemin=tracemin<<1;
	}
	else
	{
		tracemin=(tracemin<<1)|1;
	}
	if ((tracemin& 0x0F)==0x0F)//4 consective yes votes
	{
		tracemin=0x00;
		return low;
	}
	else if ((tracemin& 0x0F)==0x00)//4 consective no votes
	{
		tracemin=0x0F;
		return high;
	}
	return bouncy;	
}
debounce votesethr()
{
	static char tracehr;
	if(!(PIND&1<<PD1))
	{
		tracehr=tracehr<<1;
	}
	else
	{
		tracehr=(tracehr<<1)|1;
	}
	if ((tracehr& 0x0F)==0x0F)//4 consective yes votes
	{
		tracehr=0x00;
		return low;
	}
	else if ((tracehr& 0x0F)==0x00)//4 consective no votes
	{
		tracehr=0x0F;
		return high;
	}
	return bouncy;	
}
debounce voteRTC()
{
	static char tracertc;
	if(!(PIND&1<<PD2))
	{
		tracertc=tracertc<<1;
	}
	else
	{
		tracertc=(tracertc<<1)|1;
	}
	if ((tracertc& 0x0F)==0x0F)//4 consective yes votes
	{
		tracertc=0x00;
		return low;
	}
	else if ((tracertc& 0x0F)==0x00)//4 consective no votes
	{
		tracertc=0x0F;
		return high;
	}
	return bouncy;			
}
debounce voteAT()
{
	static char traceat;
	if(!(PIND&1<<PD3))
	{
		traceat=traceat<<1;
	}
	else
	{
		traceat=(traceat<<1)|1;
	}
	if ((traceat& 0x0F)==0x0F)//4 consective yes votes
	{
		traceat=0x00;
		return low;
	}
	else if ((traceat& 0x0F)==0x00)//4 consective no votes
	{
		traceat=0x0F;//dont need because it already is but i like it
		return high;
	}	
	return bouncy;	
}
debounce voteAlarmOn()
{
	static char tracealarm;
	if(!(PIND&1<<PD4))
	{
		tracealarm=tracealarm<<1;
	}
	else
	{
		tracealarm=(tracealarm<<1)|1;
	}
	if ((tracealarm& 0x0F)==0x0F)//4 consective yes votes
	{
		tracealarm=0x00;
		return low;
	}
	else if ((tracealarm& 0x0F)==0x00)//4 consective no votes
	{
		tracealarm=0x0F;
		return high;
	}	
	return bouncy;		
}
