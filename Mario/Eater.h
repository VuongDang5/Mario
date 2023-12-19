#pragma once
#include "GameObject.h"

#define EATER_GRAVITY 0.002f
#define EATER_WALKING_SPEED 0.05f


#define EATER_BBOX_WIDTH 16
#define EATER_BBOX_HEIGHT 14
#define EATER_BBOX_HEIGHT_DIE 7

#define EATER_DIE_TIMEOUT 500

#define EATER_STATE_WALKING 100
#define EATER_STATE_DIE 200

#define ID_ANI_EATER_WALKING 8000
#define ID_ANI_EATER_DIE 8001

class CEater : public CGameObject
{
protected:
	float ax;
	float ay;
	float ox;
	float oy;

	ULONGLONG die_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	CEater(float x, float y);
	virtual void SetState(int state);
};