#pragma once
#include "GameObject.h"

#define GTURTLE_GRAVITY 0.002f
#define GTURTLE_WALKING_SPEED 0.05f


#define GTURTLE_BBOX_WIDTH 16
#define GTURTLE_BBOX_HEIGHT 26
#define GTURTLE_BBOX_HEIGHT_SHELL 16

#define GTURTLE_DIE_TIMEOUT 1000

#define GTURTLE_STATE_WALKING 100
#define GTURTLE_STATE_FLYING 101
#define GTURTLE_STATE_SHELL 200
#define GTURTLE_STATE_DIE 201
#define GTURTLE_STATE_DIE_2 202

#define ID_ANI_GTURTLE_WALKING 7000
#define ID_ANI_GTURTLE_FLYING 7001
#define ID_ANI_GTURTLE_SHELL 7002
#define ID_ANI_GTURTLE_DIE 7003

class CGTurtle : public CGameObject
{
protected:
	float ax;
	float ay;
	float ox;
	float oy;
	int range = 2;

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
	void SetRange(int x) { range = x; }
};