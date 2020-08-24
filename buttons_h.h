#ifndef Buttons_H_
#define Buttons_H_
#include <avr/io.h>
#include <stdbool.h>


typedef enum{high ,low, bouncy}debounce;
typedef enum{active,inactive}buttonheld;	
	
#define NUMSTATES 4
#define inactive 10
#define pressed 11
#define held 12
#define released 13

debounce votesetmin();
debounce votesethr();
debounce voteRTC();
debounce voteAT();
debounce voteAlarmOn();

void buttons();

#endif