#include "Box.h"

void CBox::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_BOX)->Render(x, y);

	RenderBoundingBox();
}

void CBox::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CBox::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - BOX_BBOX_WIDTH / 2;
	t = y - BOX_BBOX_HEIGHT / 2;
	r = l + BOX_BBOX_WIDTH;
	b = t + BOX_BBOX_HEIGHT;
}

void CBox::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case 1:
		vx = 0;
		vy = 0;
		break;
	case 2:
		vy = -0.2f;
		break;
	case 3:
		vy = 0.2f;
		break;
	}
}

void CBox::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (oy > y) {
		y = oy;
		vy = 0;
	}
	if (oy != y) {
		this->SetState(3);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}