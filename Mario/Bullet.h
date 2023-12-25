#pragma once
#include "GameObject.h"

#define BULLET_BBOX_WIDTH 8
#define BULLET_BBOX_HEIGHT 8

#define ID_SPRITE_EATER 
#define ID_ANI_BULLET 11001

class CBullet : public CGameObject
{
protected:
	float ax;
	float ay;

	ULONGLONG time_start;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; }

public:
	CBullet(float x, float y);
};