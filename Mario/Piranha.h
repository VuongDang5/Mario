#pragma once
#include "GameObject.h"

#define PIRANHA_BBOX_WIDTH 16
#define PIRANHA_BBOX_HEIGHT 30

#define PIRANHA_STATE_WALKING 100
#define PIRANHA_STATE_DOWN 200

#define ID_ANI_PIRANHA_WALKING 32001

class CPiranha : public CGameObject
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

public:
	CPiranha(float x, float y);
	virtual void SetState(int state);
};