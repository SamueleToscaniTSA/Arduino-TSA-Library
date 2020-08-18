#include "TSA_TRIGGER.h";

bool TSA_TRIGGER::trig(bool event)
{
	bool _trigRet = event and not _app;
	_app = event;
	return _trigRet;
}