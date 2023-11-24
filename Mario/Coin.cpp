#include "Coin.h"

void CCoin::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_COIN)->Render(x, y);

	RenderBoundingBox();
}

void CCoin::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - COIN_BBOX_WIDTH / 2;
	t = y - COIN_BBOX_HEIGHT / 2;
	r = l + COIN_BBOX_WIDTH;
	b = t + COIN_BBOX_HEIGHT;
}

void CCoin::SetState(int state)
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

void CCoin::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (oy - y > 16.0f) {
		this->Delete();
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
