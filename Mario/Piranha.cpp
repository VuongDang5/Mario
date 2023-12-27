#include "Piranha.h"

CPiranha::CPiranha(float x, float y) :CGameObject(x, y)
{
	this->ox = x;
	this->oy = y;
	this->vx = 0;
	this->vy = -0.02f;
	time_start = -1;
	SetState(PIRANHA_STATE_WALKING);
}

void CPiranha::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - PIRANHA_BBOX_WIDTH / 2;
	top = y - PIRANHA_BBOX_HEIGHT / 2;
	right = left + PIRANHA_BBOX_WIDTH;
	bottom = top + PIRANHA_BBOX_HEIGHT;
}

void CPiranha::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if ((state == PIRANHA_STATE_WALKING) && (y < oy - 16.0f * 3.4)) {
		this->SetState(PIRANHA_STATE_DOWN);
	}

	if ((state == PIRANHA_STATE_DOWN) && (GetTickCount64() - time_start > 5000))
	{
		this->SetState(PIRANHA_STATE_WALKING);
	}
	if ((state == PIRANHA_STATE_DOWN) && (y > oy)) {
		y = oy;
	}
	y += vy * dt;
	CGameObject::Update(dt, coObjects);
}


void CPiranha::Render()
{
	CAnimations::GetInstance()->Get(ID_ANI_PIRANHA_WALKING)->Render(x, y);
	RenderBoundingBox();
}

void CPiranha::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PIRANHA_STATE_WALKING:
		vy = -0.02f;
		break;
	case PIRANHA_STATE_DOWN:
		time_start = GetTickCount64();
		vy = 0.02f;
		break;
	}
}