#ifndef TSA_DCMOTOR_H
#define TSA_DCMOTOR_H

#include "Arduino.h"

class TSA_DCMOTOR
{
	public:
		TSA_DCMOTOR (int maxVal, int velPWM, int enable, int forward, int back);
		
		void setFrequency (int _pin, int _prescaler);
		bool control (bool _start, bool _reverse);
		unsigned int setVel (unsigned int _vel);
		unsigned int absortion ();
		bool prealarm (unsigned int _thresholdPrealarm);
		bool alarm (unsigned int _thresholdAlarm, bool _resetAlarm);
	private:
		unsigned int _sense = 0, _velPWM, _forward, _back;
		unsigned long _moment, _sumVal;
		unsigned int _pauseSample = 0, _index = 0, _maxVal = 0, _mediaVal = 0;
		bool _alarm = false, _prealarm = false, _rightMaxVal = false;
};

#endif