#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

class CMap {
public:
	list<LPGAMEOBJECT> objects;
	CMap(float x, float y);
};