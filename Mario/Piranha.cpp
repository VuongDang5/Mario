#include "Piranha.h"

CPiranha::CPiranha(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = PIRANHA_GRAVITY;
	die_start = -1;
	SetState(PIRANHA_STATE_WALKING);
}

void CPiranha::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == PIRANHA_STATE_DIE)
	{
		left = x - PIRANHA_BBOX_WIDTH / 2;
		top = y - PIRANHA_BBOX_HEIGHT_DIE / 2;
		right = left + PIRANHA_BBOX_WIDTH;
		bottom = top + PIRANHA_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - PIRANHA_BBOX_WIDTH / 2;
		top = y - PIRANHA_BBOX_HEIGHT / 2;
		right = left + PIRANHA_BBOX_WIDTH;
		bottom = top + PIRANHA_BBOX_HEIGHT;
	}
}

void CPiranha::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CPiranha::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CPiranha*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CPiranha::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ((state == PIRANHA_STATE_DIE) && (GetTickCount64() - die_start > PIRANHA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CPiranha::Render()
{
	int aniId = ID_ANI_PIRANHA_WALKING;
	if (state == PIRANHA_STATE_DIE)
	{
		aniId = ID_ANI_PIRANHA_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CPiranha::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PIRANHA_STATE_DIE:
		die_start = GetTickCount64();
		y += (PIRANHA_BBOX_HEIGHT - PIRANHA_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case PIRANHA_STATE_WALKING:
		vx = -PIRANHA_WALKING_SPEED;
		break;
	}
}
