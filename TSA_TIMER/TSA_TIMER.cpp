#include "TSA_TIMER.h";

bool TSA_TIMER :: setTime ()
{
	_start = true;
	_moment = millis ();
	return _start;
}

bool TSA_TIMER :: pauseTime (unsigned long pause)
{
	_enable = _start;
	if (_enable && (millis () >= (_moment + pause))) _timeout = true;
	else _timeout = false;
	return _timeout;
}
