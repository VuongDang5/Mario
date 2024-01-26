#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BOX 25001

#define	BOX_WIDTH 16
#define BOX_BBOX_WIDTH 16
#define BOX_BBOX_HEIGHT 16

class CBox : public CGameObject {
public:
	float oy;
	int itemType = 1;

	CBox(float x, float y) : CGameObject(x, y) { oy = y; }
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	virtual void OnNoCollision(DWORD dt);
	virtual void SetState(int state);
	void setItem(int x) { itemType = x; };
};