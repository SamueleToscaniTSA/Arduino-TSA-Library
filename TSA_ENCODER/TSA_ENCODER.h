#ifndef TSA_ENCODER_H
#define TSA_ENCODER_H

#include "Arduino.h"

#define PULLUP false
#define PULLDOWN true

class TSA_ENCODER
{
	public:
		TSA_ENCODER(int chA, int chB, int btn, bool typeReading);
		int rotate();
		bool button();
	private:
		int _chA, _chB, _btn;
		bool _typeReading;
		bool _appCh = false;
		unsigned long _now;
		bool _request = false;
		bool _app = false;
		const int _pauseTime = 50;
};

#endif