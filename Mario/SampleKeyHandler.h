#pragma once

#include "KeyEventHandler.h"

class CSampleKeyHandler : public CKeyEventHandler
{
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	virtual void KeyState(BYTE* states);
};
