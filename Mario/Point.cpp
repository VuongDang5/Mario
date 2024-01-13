#include "Point.h"

void CPoint::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(AniId)->Render(x, y);

	RenderBoundingBox();
}

void CPoint::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - POINT_BBOX_WIDTH / 2;
	t = y - POINT_BBOX_HEIGHT / 2;
	r = l + POINT_BBOX_WIDTH;
	b = t + POINT_BBOX_HEIGHT;
}

void CPoint::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case 1:
		start_time = GetTickCount64();
		vx = 0;
		vy = 0;
		break;
	}
}

void CPoint::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CPoint::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (GetTickCount64() - start_time > 280) {
		this->Delete();
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
