#include "GMushroom.h"

void CGMushroom::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(40005)->Render(x, y);

	RenderBoundingBox();
}

void CGMushroom::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - GMUSHROOM_BBOX_WIDTH / 2;
	t = y - GMUSHROOM_BBOX_HEIGHT / 2;
	r = l + GMUSHROOM_BBOX_WIDTH;
	b = t + GMUSHROOM_BBOX_HEIGHT;
}

void CGMushroom::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case 1:
		vx = 0;
		vy = -0.1f;
		ay = 0;
		ax = 0;
		break;
	case 2:
		vy = 0;
		ay = 0.02f;
		vx = 0.05f;
		break;
	}
}

void CGMushroom::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGMushroom::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CGMushroom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (y < oy - 17.0f) {
		y = oy - 16.0f;
		this->SetState(2);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
