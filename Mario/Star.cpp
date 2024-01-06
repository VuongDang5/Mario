#include "Star.h"

void CStar::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_STAR)->Render(x, y);

	RenderBoundingBox();
}

void CStar::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - STAR_BBOX_WIDTH / 2;
	t = y - STAR_BBOX_HEIGHT / 2;
	r = l + STAR_BBOX_WIDTH;
	b = t + STAR_BBOX_HEIGHT;
}

void CStar::SetState(int state)
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

void CStar::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CStar::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
