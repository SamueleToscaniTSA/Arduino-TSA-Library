#ifndef TSA_TRIGGER_H
#define TSA_TRIGGER_H

#include "Arduino.h"

class TSA_TRIGGER
{
	public:
		bool trig(bool event);
	private:
		bool _app = false;
};

#endif