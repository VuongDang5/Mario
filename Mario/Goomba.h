#pragma once
#include "GameObject.h"

#define GOOMBA_GRAVITY 0.002f
#define GOOMBA_WALKING_SPEED 0.05f


#define GOOMBA_BBOX_WIDTH 16
#define GOOMBA_BBOX_HEIGHT 14

#define GOOMBA_BBOX_WIDTH_FLY 18
#define GOOMBA_BBOX_HEIGHT_FLY 22

#define GOOMBA_BBOX_HEIGHT_DIE 8

#define GOOMBA_DIE_TIMEOUT 500

#define GOOMBA_STATE_WALKING 100
#define GOOMBA_STATE_DIE 200
#define GOOMBA_STATE_DIE_2 201
#define GOOMBA_STATE_FLYING 300

#define ID_ANI_GOOMBA_WALKING 26001
#define ID_ANI_GOOMBA_FLYING 26003
#define ID_ANI_GOOMBA_DIE 26002

class CGoomba : public CGameObject
{
protected:
	float ax;
	float ay;
	float ox;
	float oy;
	int range = 2;

	ULONGLONG die_start;
	ULONGLONG jump_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }
	virtual void OnNoCollision(DWORD dt);

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CGoomba(float x, float y);
	virtual void SetState(int state);
	void SetRange(int x) { range = x; }
};