#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define GMUSHROOM_BBOX_WIDTH 16
#define GMUSHROOM_BBOX_HEIGHT 16

class CGMushroom : public CGameObject {
public:
	float ax;
	float ay;

	float oy;
	CGMushroom(float x, float y) : CGameObject(x, y) {
		oy = y;
		this->SetState(1);
	}
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

	virtual void OnNoCollision(DWORD dt);
	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

	virtual void SetState(int state);
};