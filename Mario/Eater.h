#pragma once
#include "GameObject.h"

#define EATER_BBOX_WIDTH 16
#define EATER_BBOX_HEIGHT 30

#define EATER_DIE_TIMEOUT 500

#define EATER_STATE_WALKING 100
#define EATER_STATE_SHOOT 200
#define EATER_STATE_DOWN 300

#define ID_ANI_EATER_WALKING 8000
#define ID_ANI_EATER_SHOOT 8001
#define ID_ANI_EATER_SHOOT_UP 8002

class CEater : public CGameObject
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
	CEater(float x, float y);
	virtual void SetState(int state);
};