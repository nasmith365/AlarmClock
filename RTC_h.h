/*
 * RTC_h.h
 *
 * Created: 3/23/2012 6:49:10 PM
 *  Author: linderd
 * Purpose: To define the functions for the Real Time Clock
 */ 


#ifndef RTC_h
#define RTC_h
#include <stdbool.h>

int CT_Hr();//CT=Current Time
int CT_Min();
bool CT_AM_PM();
void RTC_incHr();//Setting the real time clock
void RTC_incMin();

#endif /* RTC_h */