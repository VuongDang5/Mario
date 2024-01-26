#include "Coin.h"
#include "Rock.h"
#include "Mario.h"
#include "PlayScene.h"

void CCoin::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(ID_ANI_COIN)->Render(x, y);

	RenderBoundingBox();
}

void CCoin::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - COIN_BBOX_WIDTH / 2;
	t = y - COIN_BBOX_HEIGHT / 2;
	r = l + COIN_BBOX_WIDTH;
	b = t + COIN_BBOX_HEIGHT;
}

void CCoin::SetState(int state)
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
		break;;
	}
}

void CCoin::OnNoCollision(DWORD dt)
{
	y += vy * dt;
};

void CCoin::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (oy - y > 16.0f) {
		this->Delete();
	}

	if (state == 3 && GetTickCount64() - start_time > 2000)
	{
		this->Delete();

		CMario* m = CMario::GetInstance(1, 1);
		m->setGold(0);

		LPGAMEOBJECT r = new CRock(ox, oy);
		CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
		scene->objects.push_back(r);
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
