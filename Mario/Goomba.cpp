#include "Goomba.h"
#include "Mario.h"

CGoomba::CGoomba(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	this->ox = x;
	this->oy = y;
	vx = -GOOMBA_WALKING_SPEED;
	die_start = -1;
}

void CGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == GOOMBA_STATE_DIE)
	{
		left = x - GOOMBA_BBOX_WIDTH / 2;
		top = y - GOOMBA_BBOX_HEIGHT_DIE / 2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT_DIE;
	}
	if (state == GOOMBA_STATE_WALKING)
	{
		left = x - GOOMBA_BBOX_WIDTH / 2;
		top = y - GOOMBA_BBOX_HEIGHT / 2;
		right = left + GOOMBA_BBOX_WIDTH;
		bottom = top + GOOMBA_BBOX_HEIGHT;
	}
	if (state == GOOMBA_STATE_FLYING)
	{
		left = x - GOOMBA_BBOX_WIDTH_FLY / 2;
		top = y - GOOMBA_BBOX_HEIGHT_FLY / 2;
		right = left + GOOMBA_BBOX_WIDTH_FLY;
		bottom = top + GOOMBA_BBOX_HEIGHT_FLY - 2.0f;
	}
}

void CGoomba::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGoomba::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CGoomba*>(e->obj)) return;
	if (dynamic_cast<CMario*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
	}
}

void CGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (state != GOOMBA_STATE_DIE)
	{
		if (x > ox + 16.0f * range)
		{
			x = ox + 16.0f * range;
			vx = -vx;
		}
		if (x < ox - 16.0f * range)
		{
			x = ox - 16.0f * range;
			vx = -vx;
		}
	}

	if ((state == GOOMBA_STATE_FLYING) && (GetTickCount64() - jump_start > 2000))
	{
		jump_start = GetTickCount64();
		vy = -0.4f;
	}

	if ((state == GOOMBA_STATE_DIE) && (GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	if ((state == GOOMBA_STATE_DIE_2) && (GetTickCount64() - die_start > GOOMBA_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CGoomba::Render()
{
	int aniId = ID_ANI_GOOMBA_WALKING;
	if (state == GOOMBA_STATE_DIE)
	{
		aniId = ID_ANI_GOOMBA_DIE;
	}
	if (state == GOOMBA_STATE_FLYING)
	{
		aniId = ID_ANI_GOOMBA_FLYING;
	}

	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GOOMBA_STATE_DIE_2:
		die_start = GetTickCount64();
		vx = 0;
		vy = -0.5f;
		ay = GOOMBA_GRAVITY;
		break;
	case GOOMBA_STATE_DIE:
		die_start = GetTickCount64();
		y += (GOOMBA_BBOX_HEIGHT - GOOMBA_BBOX_HEIGHT_DIE) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		break;
	case GOOMBA_STATE_WALKING:
		ay = GOOMBA_GRAVITY;
		break;
	case GOOMBA_STATE_FLYING:
		jump_start = GetTickCount64();
		ay = GOOMBA_GRAVITY;
		break;
	}
}
