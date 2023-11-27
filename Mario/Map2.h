#pragma once

#include "Map.h"

class CMap2 : public CMap {
public:
	CMap2(float x, float y) : CMap(x, y) {
		LoadMap(x, y);
	};
	void LoadMap(float x, float y);
};