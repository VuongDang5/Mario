#pragma once

#include "Map.h"

class CMap1 : public CMap {
public:
	CMap1(float x, float y) : CMap(x, y) {
		LoadMap(x, y);
	};
	void LoadMap(float x, float y);
};