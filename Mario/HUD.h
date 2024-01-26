#pragma once
#include "Letter.h"
#include "GameObject.h"

class HUD : public CGameObject
{
public:
	HUD(float x, float y, int obj_ID) : CGameObject(x, y, obj_ID) {}
	void Render();
	string FillString(string s, int max);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

