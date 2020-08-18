#include "TSA_ENCODER.h";

TSA_ENCODER::TSA_ENCODER(int chA, int chB, int btn, bool typeReading)
{
	_chA = chA;
	_chB = chB;
	_btn = btn;
	_typeReading = typeReading;
}

int TSA_ENCODER::rotate()
{
	int _rotation = 0;
	bool _readingChA = _typeReading ? digitalRead(_chA) : not digitalRead(_chA);
	bool _readingChB = _typeReading ? digitalRead(_chB) : not digitalRead(_chB);
	
	if(_readingChA and not _appCh) {
		if(_readingChB) _rotation = -1;
		else _rotation = 1;
	}
	_appCh = _readingChA;
	
	return _rotation;
}

bool TSA_ENCODER::button()
{
	bool _trigRet = false;
	bool _event = _typeReading ? digitalRead(_btn) : not digitalRead(_btn);
	
	if (_event and !_request)
	{
		_now = millis ();
		_request = true;
	}
	if (_request and millis () >= _now + _pauseTime)
	{
		_trigRet = _event and !_app;
		_app = _event;
		_request = _event;
	}
	return _trigRet;
}