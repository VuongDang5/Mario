#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BUTTON 10014

#define	BUTTON_WIDTH 10
#define BUTTON_BBOX_WIDTH 16
#define BUTTON_BBOX_HEIGHT 16

class CButton : public CGameObject {
public:
	float oy;
	CButton(float x, float y) : CGameObject(x, y) {
		oy = y;
		this->SetState(1);
	}
	void Render();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	int IsBlocking() { return 1; }

	virtual void OnNoCollision(DWORD dt);
	virtual void SetState(int state);
};