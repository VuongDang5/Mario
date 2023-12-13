#pragma once
#include "GameObject.h"

#define GTURTLE_GRAVITY 0.002f
#define GTURTLE_WALKING_SPEED 0.05f


#define GTURTLE_BBOX_WIDTH 16
#define GTURTLE_BBOX_HEIGHT 27
#define GTURTLE_BBOX_HEIGHT_DIE 16

#define GTURTLE_DIE_TIMEOUT 500

#define GTURTLE_STATE_WALKING 100
#define GTURTLE_STATE_DIE 200

#define ID_ANI_GTURTLE_WALKING 7000
#define ID_ANI_GTURTLE_DIE 7001

class CGTurtle : public CGameObject
{
protected:
	float ax;
	float ay;
	float time;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CGTurtle(float x, float y);
	virtual void SetState(int state);
};