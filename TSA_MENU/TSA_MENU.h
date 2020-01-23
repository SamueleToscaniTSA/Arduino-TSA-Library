#ifndef TSA_MENU_H
#define TSA_MENU_H

#include "Arduino.h"

class TSA_MENU
{
	public:
		void setMenu (const unsigned int maxPages, const unsigned int secPages []);
		bool switchPages (bool ok, bool up, bool down, bool dx, bool sx);
		unsigned int level ();
		unsigned int mainPages ();
		unsigned int secondPages ();
		bool programming ();
		bool programModeBool (bool _dataBool);
		int programModeInt (int _dataInt, int _addInt);
		float programModeFloat (float _dataFloat, float _addFloat);
		
	private:
		bool _ok, _up, _down, _dx, _sx, _clear,
			_program = false;
		unsigned int _mainPages, *_secPages = NULL,
			_maxPages = 0, _level = 10, _mainNowPage = 1, _secNowPage = 1;
};

#endif