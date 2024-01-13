#include "Impact.h"

void CImpact::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(impactAniId)->Render(x, y);

	RenderBoundingBox();
}

void CImpact::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - IMPACT_BBOX_WIDTH / 2;
	t = y - IMPACT_BBOX_HEIGHT / 2;
	r = l + IMPACT_BBOX_WIDTH;
	b = t + IMPACT_BBOX_HEIGHT;
}

void CImpact::SetState(int state)
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

void CImpact::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CImpact::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (GetTickCount64()-start_time > 280) {
		this->Delete();
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
