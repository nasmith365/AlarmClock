/*
 * Alert_Time.c
 *
 * Created: 3/25/2012 4:51:33 PM
 *  Author: Devin Leas
 */ 

#include <stdbool.h>
#include "Alert Time.h"


int min=1;
int hour=12;
bool am=false,timechangeat=true;

void AT_incHr(){
	timechangeat=true;
	hour = hour + 1;
	if(hour>12){
		hour = 1;
	}
	if(hour==12){
		am = !am;
	}
}
	
void AT_incMin(){
	timechangeat=true;
	min = min + 1;
	if (min>59){
		min = 0;
	}	
}

int AT_Hr(){
	return hour;
}
int AT_Min(){
	return min;
}

bool AT_AM_PM(){
	return am;
}

