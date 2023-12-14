#include "Eater.h"

CEater::CEater(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = EATER_GRAVITY;
	die_start = -1;
	SetState(EATER_STATE_WALKING);
}

void CEater::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == EATER_STATE_DIE)
	{
		left = x - EATER_BBOX_WIDTH / 2;
		top = y - EATER_BBOX_HEIGHT_DIE / 2;
		right = left + EATER_BBOX_WIDTH;
		bottom = top + EATER_BBOX_HEIGHT_DIE;
	}
	else
	{
		left = x - EATER_BBOX_WIDTH / 2;
		top = y - EATER_BBOX_HEIGHT / 2;
		right = left + EATER_BBOX_WIDTH;
		bottom = top + EATER_BBOX_HEIGHT;
	}
}

void CEater::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CEater::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CEater*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CEater::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if ((state == EATER_STATE_DIE) && (GetTickCount64() - die_start > EATER_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CEater::Render()
{
	int aniId = ID_ANI_EATER_WALKING;
	if (state == EATER_STATE_DIE)
	{
		aniId = ID_ANI_EATER_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CEater::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case EATER_STATE_DIE:
		die_start = GetTickCount64();
		y += (EATER_BBOX_HEIGHT - EATER_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case EATER_STATE_WALKING:
		vx = -EATER_WALKING_SPEED;
		break;
	}
}