#include "Tail.h"
#include "Rock.h"
#include "Button.h"
#include "GameLoop.h"

Ctail::Ctail(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	this->ox = x;
	this->oy = y;
	time_start = GetTickCount64();
}

void Ctail::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x - TAIL_BBOX_WIDTH / 2;
	top = y - TAIL_BBOX_HEIGHT / 2;
	right = left + TAIL_BBOX_WIDTH;
	bottom = top + TAIL_BBOX_HEIGHT;
}

void Ctail::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (dynamic_cast<CRock*>(e->obj)) {
		CRock* r = dynamic_cast<CRock*>(e->obj);
		float rx = 0, ry = 0;
		r->GetPosition(rx, ry);
		r->Delete();
		if (r->getType() == 2)
		{
			LPGAMEOBJECT b = new CButton(rx, ry);
			GameLoop::UpdateObj(b);
		}
	}
}

void Ctail::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	x += vx * dt;
	y += vy * dt;
	
	if (x > ox + 10.0f) this->Delete();
	if (x < ox - 10.0f) this->Delete();

	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void Ctail::Render()
{
	CAnimations::GetInstance()->Get(ID_ANI_TAIL)->Render(x, y);
	RenderBoundingBox();
}
