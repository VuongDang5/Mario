#include "Leaf.h"

void CLeaf::Render()
{
	CAnimations* animations = CAnimations::GetInstance();

	animations->Get(10000 + 13)->setFlip(this->isFlipped);
	animations->Get(10000 + 13)->Render(x, y);

	RenderBoundingBox();
}

void CLeaf::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - LEAF_BBOX_WIDTH / 2;
	t = y - LEAF_BBOX_HEIGHT / 2;
	r = l + LEAF_BBOX_WIDTH;
	b = t + LEAF_BBOX_HEIGHT;
}

void CLeaf::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case 1:
		vx = 0;
		vy = -0.5f;
		ay = 0;
		ax = 0;
		break;
	case 2:
		vy = 0.02;
		vx = 0.02;
		break;
	}
}

void CLeaf::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CLeaf::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (state == 2)
	{
		if (x > ox + 16.0f*2)
		{
			x = ox + 16.0f * 2;
			vx = -vx;
			this->isFlipped = -this->isFlipped;
		}
		if (x < ox)
		{
			x = ox;
			vx = -vx;
			this->isFlipped = -this->isFlipped;
		}
	}
	if (y < oy - 16.0f * 3) {
		y = oy - 16.0f * 3;
		this->SetState(2);
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
