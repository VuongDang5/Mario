#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_COIN 11000

#define	COIN_WIDTH 10
#define COIN_BBOX_WIDTH 10
#define COIN_BBOX_HEIGHT 16

class CCoin : public CGameObject {
public:
	float oy;
	CCoin(float x, float y) : CGameObject(x, y) { 
		oy = y;
		this->SetState(1); 
	}
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	int IsBlocking() { return 0; }

	virtual void OnNoCollision(DWORD dt);
	virtual void SetState(int state);
};