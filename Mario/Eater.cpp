#include "Eater.h"
#include "Mario.h"

CEater::CEater(float x, float y) :CGameObject(x, y)
{
	this->ox = x;
	this->oy = y;
	this->vx = 0;
	this->vy = -0.02f;
	time_start = -1;
	SetState(EATER_STATE_WALKING);
}

void CEater::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - EATER_BBOX_WIDTH / 2;
	top = y - EATER_BBOX_HEIGHT / 2;
	right = left + EATER_BBOX_WIDTH;
	bottom = top + EATER_BBOX_HEIGHT;
}

void CEater::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if ((state == EATER_STATE_WALKING) && (y < oy - 16.0f * 3.4)) {
		y = oy - 16.0f * 3.4;
		CMario* mario = mario->GetInstance(0, 0);
		if (mario->getY() < this->y) {
			CMario* mario = mario->GetInstance(0, 0);
			if (mario->getX() > this->x) {
				this->isFlipped = -1;
			}
			this->SetState(EATER_STATE_SHOOT_UP);
		}
		else
		{
			CMario* mario = mario->GetInstance(0, 0);
			if (mario->getX() > this->x) {
				this->isFlipped = -1;
			}
			this->SetState(EATER_STATE_SHOOT_DOWN);
		}
	}
	if ((state == EATER_STATE_DOWN) && (y > oy)) {
		y = oy;
	}
	if ((state == EATER_STATE_SHOOT_UP) && (GetTickCount64() - time_start > 3000))
	{
		this->SetState(EATER_STATE_DOWN);
	}
	if ((state == EATER_STATE_SHOOT_DOWN) && (GetTickCount64() - time_start > 3000))
	{
		this->SetState(EATER_STATE_DOWN);
	}
	if ((state == EATER_STATE_DOWN) && (GetTickCount64() - time_start > 5000))
	{
		this->SetState(EATER_STATE_WALKING);
	}

	y += vy * dt;
	CGameObject::Update(dt, coObjects);
}


void CEater::Render()
{
	int aniId = ID_ANI_EATER_WALKING;
	if (state == EATER_STATE_SHOOT_UP) { aniId = ID_ANI_EATER_SHOOT_UP; }
	if (state == EATER_STATE_SHOOT_DOWN) { aniId = ID_ANI_EATER_SHOOT_DOWN; }

	CAnimations::GetInstance()->Get(aniId)->setFlip(this->isFlipped);
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CEater::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case EATER_STATE_WALKING:
		isFlipped = 1;
		vy = -0.02f;
		break;
	case EATER_STATE_SHOOT_UP:
		time_start = GetTickCount64();
		vy = 0.0f;
		break;
	case EATER_STATE_SHOOT_DOWN:
		time_start = GetTickCount64();
		vy = 0.0f;
		break;
	case EATER_STATE_DOWN:
		isFlipped = 1;
		time_start = GetTickCount64();
		vy = 0.02f;
		break;
	}
}
