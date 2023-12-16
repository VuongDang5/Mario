#pragma once
#include "GameObject.h"

#define PIRANHA_GRAVITY 0.002f
#define PIRANHA_WALKING_SPEED 0.05f


#define PIRANHA_BBOX_WIDTH 16
#define PIRANHA_BBOX_HEIGHT 14
#define PIRANHA_BBOX_HEIGHT_DIE 7

#define PIRANHA_DIE_TIMEOUT 500

#define PIRANHA_STATE_WALKING 100
#define PIRANHA_STATE_DIE 200

#define ID_ANI_PIRANHA_WALKING 10000
#define ID_ANI_PIRANHA_DIE 10001

class CPiranha : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CPiranha(float x, float y);
	virtual void SetState(int state);
};