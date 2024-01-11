#pragma once
#include "Mario.h"
#include "GameObject.h"

class HUD : public CGameObject
{
public:
	HUD(float x, float y) : CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
	};
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

