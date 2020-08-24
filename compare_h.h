/*
  Author: Nicholas Smith
  AlarmClock.c
  Created: 3/22/2012 
  Purpose:This is the header file for Compare function that has all the definitions and declaring statements for the compare.c file.
 */ 
typedef enum{on,off}AlarmOn;
#ifndef Compare_H_
#define Compare_H_
 #include <stdbool.h>
 
AlarmOn Alarm();

#endif /* Compare_H_ */