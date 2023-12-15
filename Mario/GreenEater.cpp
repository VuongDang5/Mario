#include "GreenEater.h"

CGEater::CGEater(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = GEATER_GRAVITY;
	die_start = -1;
	SetState(GEATER_STATE_WALKING);
}

void CGEater::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == GEATER_STATE_DIE)
	{
		left = x - GEATER_BBOX_WIDTH / 2;
		top = y - GEATER_BBOX_HEIGHT_DIE / 2;
		right = left + GEATER_BBOX_WIDTH;
		bottom = top + GEATER_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - GEATER_BBOX_WIDTH / 2;
		top = y - GEATER_BBOX_HEIGHT / 2;
		right = left + GEATER_BBOX_WIDTH;
		bottom = top + GEATER_BBOX_HEIGHT;
	}
}

void CGEater::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGEater::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CGEater*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CGEater::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ((state == GEATER_STATE_DIE) && (GetTickCount64() - die_start > GEATER_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CGEater::Render()
{
	int aniId = ID_ANI_GEATER_WALKING;
	if (state == GEATER_STATE_DIE)
	{
		aniId = ID_ANI_GEATER_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CGEater::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GEATER_STATE_DIE:
		die_start = GetTickCount64();
		y += (GEATER_BBOX_HEIGHT - GEATER_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case GEATER_STATE_WALKING:
		vx = -GEATER_WALKING_SPEED;
		break;
	}
}
