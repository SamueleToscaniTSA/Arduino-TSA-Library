#ifndef TSA_READEVENT_H
#define TSA_READEVENT_H

#include "Arduino.h"

class TSA_READEVENT
{
	public:
		bool toggle (bool event);
		bool state (bool event);
		bool trig (bool event);
	private:
		unsigned long _now [3] = {0, 0, 0};
		bool _request [3] = {false, false, false};
		bool _app [3] = {false, false, false};
		bool _toggleRet = false;
		const int _pauseTime = 20;
};

#endif