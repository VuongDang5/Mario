#pragma once
#include "GameObject.h"

#define TAIL_BBOX_WIDTH 8
#define TAIL_BBOX_HEIGHT 8

#define ID_ANI_TAIL 40006

class Ctail : public CGameObject
{
protected:
	float ax;
	float ay;
	float ox;
	float oy;
	ULONGLONG time_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

	virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	Ctail(float x, float y);
};