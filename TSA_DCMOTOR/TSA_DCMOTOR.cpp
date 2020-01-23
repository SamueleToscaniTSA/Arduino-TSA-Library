#include "TSA_DCMOTOR.h";

TSA_DCMOTOR :: TSA_DCMOTOR (int maxVal, int sense, int velPWM, int forward, int back)
{
	_sense = sense;
	_velPWM = velPWM;
	_forward = forward;
	_back = back;
	if (_sense != 0) pinMode (_sense, INPUT);
	pinMode (velPWM, OUTPUT);
	if (_forward != 0) pinMode (_forward, OUTPUT);
	if (_back != 0) pinMode (_back, OUTPUT);
	_maxVal = maxVal;
	_rightMaxVal = (_maxVal == 1 or _maxVal == 2 or _maxVal == 5 or
				    _maxVal == 10 or _maxVal == 20 or _maxVal == 50);
	if (_maxVal != 0 and _rightMaxVal) _pauseSample = 1000 / _maxVal;
}

void TSA_DCMOTOR :: setFrequency (int _pin, int _prescaler)
{
	byte mode;
	if (_pin == 5 || _pin == 6 || _pin == 9 || _pin == 10) 
	{
		switch (_prescaler) 
		{
		  case 1: mode = 0x01; break;
		  case 8: mode = 0x02; break;
		  case 64: mode = 0x03; break;
		  case 256: mode = 0x04; break;
		  case 1024: mode = 0x05; break;
		  default: return;
		}
		if (_pin == 5 || _pin == 6) TCCR0B = TCCR0B & 0b11111000 | mode;
		else TCCR1B = TCCR1B & 0b11111000 | mode;
	} 
	else if (_pin == 3 || _pin == 11) 
	{
		switch (_prescaler) {
		  case 1: mode = 0x01; break;
		  case 8: mode = 0x02; break;
		  case 32: mode = 0x03; break;
		  case 64: mode = 0x04; break;
		  case 128: mode = 0x05; break;
		  case 256: mode = 0x06; break;
		  case 1024: mode = 0x7; break;
		  default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

bool TSA_DCMOTOR :: control (bool _start, bool _reverse)
{
	digitalWrite (_forward, _start and !_reverse and !_alarm);
	digitalWrite (_back, _start and _reverse and !_alarm);
	return _start;
}

unsigned int TSA_DCMOTOR :: setVel (unsigned int _vel)
{
	bool rangeVel = _vel >= 0 and _vel <= 255;
	if (rangeVel) analogWrite (_velPWM, _vel);
	return (rangeVel ? map (_vel, 0, 255, 0, 100) : 999);
}

unsigned int TSA_DCMOTOR :: absortion ()
{
	if (_rightMaxVal)
	{
		if (millis () >= _moment + _pauseSample)
		{
			_moment = millis ();
			_sumVal += analogRead (_sense);
			if (_index < _maxVal - 1) _index ++;
			else _index = 0;
			if (_index == _maxVal-1)
			{
				_mediaVal = _sumVal / _maxVal;
				_sumVal = 0;
				return _mediaVal;
			}
		}
	}
	else return 999;
}

bool TSA_DCMOTOR :: prealarm (unsigned int _thresholdPrealarm)
{
	_prealarm = (_mediaVal >= _thresholdPrealarm ? true : false);
	return _prealarm;
}

bool TSA_DCMOTOR :: alarm (unsigned int _thresholdAlarm, bool _resetAlarm)
{
	if (_mediaVal >= _thresholdAlarm) _alarm = true;
	if (_resetAlarm) _alarm = false;
	return _alarm;
}