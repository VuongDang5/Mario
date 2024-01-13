#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define POINT_BBOX_WIDTH 0
#define POINT_BBOX_HEIGHT 0

class CPoint : public CGameObject {
public:
	float oy;
	int AniId;
	ULONGLONG start_time;

	CPoint(float x, float y) : CGameObject(x, y) {
		oy = y;
		this->SetState(1);
		AniId = 20051;
	}

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsBlocking() { return 0; }
	int IsCollidable() { return 0; }

	virtual void OnNoCollision(DWORD dt);
	virtual void SetState(int state);
};