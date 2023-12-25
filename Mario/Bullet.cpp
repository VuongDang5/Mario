#include "Bullet.h"

CBullet::CBullet(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	time_start = GetTickCount64();
}

void CBullet::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - BULLET_BBOX_WIDTH / 2;
	top = y - BULLET_BBOX_HEIGHT / 2;
	right = left + BULLET_BBOX_WIDTH;
	bottom = top + BULLET_BBOX_HEIGHT;
}


void CBullet::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	x += vx * dt;
	y += vy * dt;
	if (GetTickCount64() - time_start > 3500) this->Delete();
}


void CBullet::Render()
{
	CAnimations::GetInstance()->Get(ID_ANI_BULLET)->Render(x, y);
	RenderBoundingBox();
}
