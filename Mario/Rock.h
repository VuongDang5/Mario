#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_ROCK 10008

#define ROCK_BBOX_WIDTH 16
#define ROCK_BBOX_HEIGHT 16

class CRock : public CGameObject {
public:
	float oy;
	float ox;
	int type = 1;

	CRock(float x, float y) : CGameObject(x, y) {
		oy = y;
		ox = x;
		this->SetState(1);
	}
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsBlocking() { return 1; }

	virtual void OnNoCollision(DWORD dt);
	virtual void SetState(int state);

	int getType() { return type; }
	void setType(int x) { type = x; }
};