#include "Rock.h"
#include "Coin.h"
#include "Mario.h"
#include "GameLoop.h"
#include "Impact.h"

void CRock::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_ROCK)->Render(x, y);

	RenderBoundingBox();
}

void CRock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - ROCK_BBOX_WIDTH / 2;
	t = y - ROCK_BBOX_HEIGHT / 2;
	r = l + ROCK_BBOX_WIDTH;
	b = t + ROCK_BBOX_HEIGHT;
}

void CRock::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case 1:
		vx = 0;
		vy = 0;
		break;
	case 2:
		vy = -0.05f;
		break;
	case 3:
		vx = 0;
		vy = 0;
		break;
	}
}

void CRock::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CRock::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (state == 3)
	{
		LPGAMEOBJECT m = new CImpact(x, y);
		GameLoop::UpdateObj(m);
		this->Delete();
	}
	CMario* gold = CMario::GetInstance(1, 1);
	if (gold->getGold() == 1)
	{
		LPGAMEOBJECT m = new CImpact(x, y);
		GameLoop::UpdateObj(m);

		LPGAMEOBJECT b = new CCoin(x, y);
		GameLoop::UpdateObj(b);
		this->Delete();

	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
