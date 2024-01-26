#pragma once
#include "GameObject.h"

#define GEATER_BBOX_WIDTH 16
#define GEATER_BBOX_HEIGHT 30

#define GEATER_STATE_WALKING 100
#define GEATER_STATE_SHOOT_UP 200
#define GEATER_STATE_SHOOT_DOWN 201
#define GEATER_STATE_DOWN 300

#define ID_ANI_GEATER_WALKING 31001
#define ID_ANI_GEATER_SHOOT_UP 31003
#define ID_ANI_GEATER_SHOOT_DOWN 31002

class CGEater : public CGameObject
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
	CGEater(float x, float y);
	virtual void SetState(int state);
};