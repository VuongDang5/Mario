#include "Eater.h"

CEater::CEater(float x, float y) :CGameObject(x, y)
{
	this->ox = x;
	this->oy = y;
	this->vx = 0;
	this->vy = -0.02f;
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

void CEater::OnCollisionWith(LPCOLLISIONEVENT e)
{

}

void CEater::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (y = 196.0f - 16.0f * 4.2) {
		vy = 0; }
	y += vy * dt;
	
	if ((state == EATER_STATE_DIE) && (GetTickCount64() - die_start > EATER_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	CGameObject::Update(dt, coObjects);
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
