#include "TSA_MENU.h";

void TSA_MENU :: setMenu (const unsigned int mainPages, const unsigned int secPages [])
{
	_mainPages = mainPages;
	_secPages = new unsigned int [_mainPages];
	for (int i = 0; i < _mainPages; i ++) _secPages [i] = secPages [i];
	_maxPages = _mainPages;
}

bool TSA_MENU :: switchPages (bool ok, bool up, bool down, bool dx, bool sx)
{
	_ok = ok;
	_up = up;
	_down = down;
	_dx = dx;
	_sx = sx;
	
	_clear = (_ok or _up or _down or _dx or _sx);
	return _clear;
}

unsigned int TSA_MENU :: level ()
{
	if (_sx && !_program) 
	{
		if (_level == 20)
		{
			_level = 10;
			_secNowPage = 1;
		}
		if (_level == 30) _level = 20;
	}
	if (_dx && !_program)
	{
		if (_level == 20) _level = 30;
		if (_level == 10) _level = 20;
	}
	if (_level == 10) _maxPages = _mainPages;
	if (_level == 20) _maxPages = _secPages [_mainNowPage-1];
	return _level;
}

unsigned int TSA_MENU :: mainPages ()
{
	if (_level == 10 && !_program)
	{
		if (_up) _mainNowPage ++;
		if (_down) _mainNowPage --;
		if (_mainNowPage > _maxPages) _mainNowPage = 1;
		if (_mainNowPage < 1) _mainNowPage = _maxPages;
	}
	return _mainNowPage;
}

unsigned int TSA_MENU :: secondPages ()
{
	if (_level == 20 && !_program)
	{
		if (_up) _secNowPage ++;
		if (_down) _secNowPage --;
		if (_secNowPage > _maxPages) _secNowPage = 1;
		if (_secNowPage < 1) _secNowPage = _maxPages;
	}
	return _secNowPage;
}

bool TSA_MENU :: programming ()
{
	if (_ok) _program = !_program;
	return _program;
}

bool TSA_MENU :: programModeBool (bool _dataBool)
{
	if (_program and (_up or _down)) _dataBool = !_dataBool;
	return _dataBool;
}

int TSA_MENU :: programModeInt (int _dataInt, int _addInt)
{
	if (_program)
	{
		if (_up) _dataInt += _addInt;
		if (_down) _dataInt -= _addInt;
	}
	return _dataInt;
}

float TSA_MENU :: programModeFloat (float _dataFloat, float _addFloat)
{
	if (_program)
	{
		if (_up) _dataFloat += _addFloat;
		if (_down) _dataFloat -= _addFloat;
	}
	return _dataFloat;
}
