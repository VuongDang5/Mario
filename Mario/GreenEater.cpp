#include "GreenEater.h"
#include "Mario.h"
#include "Bullet.h"
#include "GameLoop.h"

CGEater::CGEater(float x, float y) :CGameObject(x, y)
{
	this->ox = x;
	this->oy = y;
	this->vx = 0;
	this->vy = -0.02f;
	time_start = -1;
	SetState(GEATER_STATE_WALKING);
}

void CGEater::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - GEATER_BBOX_WIDTH / 2;
	top = y - GEATER_BBOX_HEIGHT / 2;
	right = left + GEATER_BBOX_WIDTH;
	bottom = top + GEATER_BBOX_HEIGHT;
}

void CGEater::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if ((state == GEATER_STATE_WALKING) && (y < oy - 16.0f * 3.4)) {
		y = oy - 16.0f * 3.4;
		CMario* mario = mario->GetInstance(0, 0);
		if (mario->getY() < this->y) {
			CMario* mario = mario->GetInstance(0, 0);
			if (mario->getX() > this->x) {
				this->isFlipped = -1;
			}
			this->SetState(GEATER_STATE_SHOOT_UP);
			LPGAMEOBJECT b = new CBullet(x, y - 8.0f);
			b->SetSpeed(-0.03 * isFlipped, -0.03);
			GameLoop::UpdateObj(b);
		}
		else
		{
			CMario* mario = mario->GetInstance(0, 0);
			if (mario->getX() > this->x) {
				this->isFlipped = -1;
			}
			this->SetState(GEATER_STATE_SHOOT_DOWN);
			LPGAMEOBJECT b = new CBullet(x, y - 8.0f);
			b->SetSpeed(-0.03 * isFlipped, 0.03);
			GameLoop::UpdateObj(b);
		}
	}
	if ((state == GEATER_STATE_DOWN) && (y > oy)) {
		y = oy;
	}
	if ((state == GEATER_STATE_SHOOT_UP) && (GetTickCount64() - time_start > 3000))
	{
		this->SetState(GEATER_STATE_DOWN);
	}
	if ((state == GEATER_STATE_SHOOT_DOWN) && (GetTickCount64() - time_start > 3000))
	{
		this->SetState(GEATER_STATE_DOWN);
	}
	if ((state == GEATER_STATE_DOWN) && (GetTickCount64() - time_start > 5000))
	{
		this->SetState(GEATER_STATE_WALKING);
	}

	y += vy * dt;
	CGameObject::Update(dt, coObjects);
}


void CGEater::Render()
{
	int aniId = ID_ANI_GEATER_WALKING;
	if (state == GEATER_STATE_SHOOT_UP) { aniId = ID_ANI_GEATER_SHOOT_UP; }
	if (state == GEATER_STATE_SHOOT_DOWN) { aniId = ID_ANI_GEATER_SHOOT_DOWN; }

	CAnimations::GetInstance()->Get(aniId)->setFlip(this->isFlipped);
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CGEater::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GEATER_STATE_WALKING:
		isFlipped = 1;
		vy = -0.02f;
		break;
	case GEATER_STATE_SHOOT_UP:
		time_start = GetTickCount64();
		vy = 0.0f;
		break;
	case GEATER_STATE_SHOOT_DOWN:
		time_start = GetTickCount64();
		vy = 0.0f;
		break;
	case GEATER_STATE_DOWN:
		isFlipped = 1;
		time_start = GetTickCount64();
		vy = 0.02f;
		break;
	}
}
