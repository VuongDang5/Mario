#include "Box.h"
#include "Coin.h"
#include "Brick.h"
#include "Mushroom.h"
#include "GMushroom.h"
#include "GameLoop.h"
#include "Point.h"

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
	if (oy < y) {
		y = oy;
		vy = 0;
		this->Delete();
		if (itemType == 2) {
			LPGAMEOBJECT m = new CMushroom(x, y);
			m->SetState(1);
			GameLoop::UpdateObj(m);
		}

		if (itemType == 3) {
			LPGAMEOBJECT m = new CGMushroom(x, y);
			m->SetState(1);
			GameLoop::UpdateObj(m);
		}

		LPGAMEOBJECT brick;
		brick = new CBrick(x, y, ID_ANI_BRICK + 10);
		GameLoop::UpdateObj(brick);
	}
	if (oy - y > 16.0f) {
		this->SetState(3);
		if (itemType == 1) {
			LPGAMEOBJECT coin = new CCoin(x, y);
			coin->SetState(2);
			GameLoop::UpdateObj(coin);

			LPGAMEOBJECT b = new CPoint(x, y);
			b->SetState(1);
			GameLoop::UpdateObj(b);
		}
	}
	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}