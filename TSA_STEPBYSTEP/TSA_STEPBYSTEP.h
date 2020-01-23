#ifndef TSA_STEPBYSTEP_H
#define TSA_STEPBYSTEP_H

#include "Arduino.h"

class TSA_STEPBYSTEP
{
	public:
		TSA_STEPBYSTEP (int pin0, int pin1, int pin2, int pin3);
		
		void setVel (int vel);
		int setStep (int step, bool enStep, bool dirMan);
		void resetStep (int resetPos);
		void stepping (bool dir, int step, bool dirMan);
	private:
		int _pin [4];
		unsigned long _moment;
		bool _direction = false, _dirMan = false;
		bool _enStep;
		int _counterStep;
		int _set = 0;
		int _pause;
		int _step;
};

#endif