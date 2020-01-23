#include "TSA_STEPBYSTEP.h";

TSA_STEPBYSTEP :: TSA_STEPBYSTEP (int pin0, int pin1, int pin2, int pin3)
{
	_pin [0] = pin0;
	_pin [1] = pin1;
	_pin [2] = pin2;
	_pin [3] = pin3;
	pinMode (_pin [0], OUTPUT);
	pinMode (_pin [1], OUTPUT);
	pinMode (_pin [2], OUTPUT);
	pinMode (_pin [3], OUTPUT);
	_moment = millis ();
}

void TSA_STEPBYSTEP :: setVel (int vel)
{
	_pause = vel;
}

void TSA_STEPBYSTEP :: resetStep (int resetPos)
{
	_counterStep = resetPos;
}

int TSA_STEPBYSTEP :: setStep (int step, bool enStep, bool dirMan)
{
	_enStep = enStep;
	_dirMan = dirMan;
	_step = step;
	
	if (_enStep)
	{
		if (_counterStep > _step) _direction = false;
		else _direction = true;
		if (_counterStep == _step) _enStep = false;
		else stepping (_direction, _step, _dirMan); 
	}
	else stepping (_direction, step, _dirMan);
	return _counterStep;
}

void TSA_STEPBYSTEP :: stepping (bool dir, int step, bool dirMan)
{
	_direction = dir;
	_dirMan = dirMan;
	_step = step;
	
	if (_enStep)
	{
		digitalWrite (_pin [_set], true);
		if (millis () >= _moment + _pause)
		{
			_moment = millis ();
			if (_direction) _counterStep ++;
			else _counterStep --;
			digitalWrite (_pin [_set], false);
			if (_direction)
				if (_set > 0) _set --;
				else _set = 3;
			else
				if (_set < 3) _set ++;
					else _set = 0;
		}
	}
	else
	{
		digitalWrite (_pin [_set], true);
		if (millis () >= _moment + _pause)
		{
			_moment = millis ();
			if (_dirMan) _counterStep ++;
			else _counterStep --;
			digitalWrite (_pin [_set], false);
			if (_dirMan)
				if (_set > 0) _set --;
				else _set = 3;
			else
				if (_set < 3) _set ++;
					else _set = 0;
		}
	}
 
}