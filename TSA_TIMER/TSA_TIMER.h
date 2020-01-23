#ifndef TSA_TIMER_H
#define TSA_TIMER_H

#include "Arduino.h"

class TSA_TIMER
{
	public:
		bool setTime ();
		bool pauseTime (unsigned long pause);
	private:
		unsigned long _moment;
		bool _start;
		
		bool _enable;
		bool _timeout;
};

#endif