#pragma once
#include "GameObject.h"

#define GEATER_GRAVITY 0.002f
#define GEATER_WALKING_SPEED 0.05f


#define GEATER_BBOX_WIDTH 16
#define GEATER_BBOX_HEIGHT 14
#define GEATER_BBOX_HEIGHT_DIE 7

#define GEATER_DIE_TIMEOUT 500

#define GEATER_STATE_WALKING 100
#define GEATER_STATE_DIE 200

#define ID_ANI_GEATER_WALKING 9000
#define ID_ANI_GEATER_DIE 9001

class CGEater : public CGameObject
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
	CGEater(float x, float y);
	virtual void SetState(int state);
};