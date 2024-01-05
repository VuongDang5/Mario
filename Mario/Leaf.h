#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define LEAF_BBOX_WIDTH 16
#define LEAF_BBOX_HEIGHT 16

class CLeaf : public CGameObject {
public:
	float ax;
	float ay;

	float oy;
	float ox;

	CLeaf(float x, float y) : CGameObject(x, y) {
		oy = y;
		ox = x;
		this->SetState(1);
	}
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual int IsCollidable() { return 0; };
	virtual int IsBlocking() { return 0; }

	virtual void OnNoCollision(DWORD dt);

	virtual void SetState(int state);
};