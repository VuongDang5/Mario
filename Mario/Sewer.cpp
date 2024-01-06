#include "Sewer.h"

void CSewer::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_SEWER)->Render(x, y);

	RenderBoundingBox();
}

void CSewer::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - SEWER_BBOX_WIDTH / 2;
	t = y - SEWER_BBOX_HEIGHT / 2;
	r = l + SEWER_BBOX_WIDTH;
	b = t + SEWER_BBOX_HEIGHT;
}

void CSewer::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case 1:
		vx = 0;
		vy = 0;
		break;
	case 2:
		vy = -0.05f;
		break;
	}
}

void CSewer::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CSewer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (oy - y > 16.0f) {
		this->Delete();
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
