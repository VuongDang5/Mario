#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_SEWER 100141

#define SEWER_BBOX_WIDTH 16
#define SEWER_BBOX_HEIGHT 16

class CSewer : public CGameObject {
public:
	float oy;
	float ox;
	int type = 1;

	int getType() { return type; }
	void setType(int x) { type = x; }

	CSewer(float x, float y, int att) : CGameObject(x, y, obj_ID) {
		oy = y;
		ox = x;
		this->type = att;
	}
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }

	virtual void OnNoCollision(DWORD dt);
	virtual void SetState(int state);
};