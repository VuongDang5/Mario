#include "GreenTurtle.h"
#include "Mario.h"

CGTurtle::CGTurtle(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	this->ox = x;
	this->oy = y;
	this ->vx = -GTURTLE_WALKING_SPEED;
	die_start = -1;
}

void CGTurtle::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == GTURTLE_STATE_SHELL || state == GTURTLE_STATE_DIE)
	{
		left = x - GTURTLE_BBOX_WIDTH / 2;
		top = y - GTURTLE_BBOX_HEIGHT_SHELL / 2;
		right = left + GTURTLE_BBOX_WIDTH;
		bottom = top + GTURTLE_BBOX_HEIGHT_SHELL;
	}
	else
	{
		left = x - GTURTLE_BBOX_WIDTH / 2;
		top = y - GTURTLE_BBOX_HEIGHT / 2;
		right = left + GTURTLE_BBOX_WIDTH;
		bottom = top + GTURTLE_BBOX_HEIGHT;
	}
}

void CGTurtle::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGTurtle::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CGTurtle*>(e->obj)) return;
	if (dynamic_cast<CMario*>(e->obj)) return;

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
		isFlipped = -isFlipped;
	}
}

void CGTurtle::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (state != GTURTLE_STATE_DIE)
	{
		if (x > ox + 16.0f * range)
		{
			x = ox + 16.0f * range;
			isFlipped = -isFlipped;
			vx = -vx;
		}
		if (x < ox - 16.0f * range)
		{
			x = ox - 16.0f * range;
			isFlipped = -isFlipped;
			vx = -vx;
		}
	}

	if (state == GTURTLE_STATE_FLYING) 
	{
		if (y > oy + 10.0f)
		{
			y = oy + 10.0f;
			vy = -0.05f;
		}
		if (y < oy - 10.0f)
		{
			y = oy - 10.0f;
			vy = 0.05f;
		}
	}
	if ((state == GTURTLE_STATE_DIE) && (GetTickCount64() - die_start > GTURTLE_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CGTurtle::Render()
{
	int aniId = ID_ANI_GTURTLE_FLYING;
	if (state == GTURTLE_STATE_WALKING)
	{
		aniId = ID_ANI_GTURTLE_WALKING;
	}
	if (state == GTURTLE_STATE_SHELL)
	{
		aniId = ID_ANI_GTURTLE_SHELL;
	}
	
	if (state == GTURTLE_STATE_DIE)
	{
		aniId = ID_ANI_GTURTLE_DIE;
	}

	CAnimations::GetInstance()->Get(aniId)->setFlip(this->isFlipped);
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CGTurtle::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GTURTLE_STATE_FLYING:
		vy = -0.05f;
		break;
	case GTURTLE_STATE_SHELL:
		y += (GTURTLE_BBOX_HEIGHT - GTURTLE_BBOX_HEIGHT_SHELL) / 2;
		vx = 0;
		vy = 0;
		ay = 0;
		ax = 0;
		break;
	case GTURTLE_STATE_WALKING:
		vy = 0;
		ay = 0.02f;
		break;
	case GTURTLE_STATE_DIE:
		die_start = GetTickCount64();
		vx = 0.3f;
		y -= 0.1f;
		break;
	}
}
