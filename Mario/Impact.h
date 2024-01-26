#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define IMPACT_BBOX_WIDTH 16
#define IMPACT_BBOX_HEIGHT 16

class CImpact : public CGameObject {
public:
	float oy;
	int impactAniId;
	ULONGLONG start_time;

	CImpact(float x, float y) : CGameObject(x, y) {
		oy = y;
		this->SetState(1);
		impactAniId = 50001;
	}

	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsBlocking() { return 0; }
	int IsCollidable() { return 0; }

	virtual void OnNoCollision(DWORD dt);
	virtual void SetState(int state);

	void setImpactAniId(int aniId) { impactAniId = aniId; }
};