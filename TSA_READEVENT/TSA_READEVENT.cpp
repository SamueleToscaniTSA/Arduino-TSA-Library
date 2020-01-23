#include "TSA_READEVENT.h";

bool TSA_READEVENT :: trig (bool event)
{
	bool _event = event;
	bool _trigRet = false;
	
	if (_event and !_request [0])
	{
		_now [0] = millis ();
		_request [0] = true;
	}
	if (_request [0] and millis () >= _now [0] + _pauseTime)
	{
		_trigRet = _event and !_app [0];
		_app [0] = _event;
		_request [0] = _event;
	}
	return _trigRet;
}

bool TSA_READEVENT :: state (bool event)
{
	bool _event = event;
	bool _stateRet = false;

	if (_event and !_request [1])
	{
		_now [1] = millis ();
		_request [1] = true;
	}
	if (_request [1] and millis () >= _now [1] + _pauseTime)
	{
		_stateRet = _event;
		_request [1] = _event;
	}
	return _stateRet;
}

bool TSA_READEVENT :: toggle (bool event)
{
	bool _event = event;
	bool _trigRet = false;

	if (_event and !_request [2])
	{
		_now [2] = millis ();
		_request [2] = true;
	}
	if (_request [2] and millis () >= _now [2] + _pauseTime)
	{
		_trigRet = _event and !_app [2];
		_app [2] = _event;
		if (_trigRet) _toggleRet = !_toggleRet;
		_request [2] = _event;
	}
	return _toggleRet;
}