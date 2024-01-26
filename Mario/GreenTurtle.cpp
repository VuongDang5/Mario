#include "GreenTurtle.h"
#include "Mario.h"
#include "Box.h"
#include "Brick.h"
#include "Leaf.h"
#include "PlayScene.h"
#include "Impact.h"

CGTurtle::CGTurtle(float x, float y) :CGameObject(x, y)
{
	this->ax = 0;
	this->ay = 0;
	this->ox = x;
	this->oy = y;
	this ->vx = -GTURTLE_WALKING_SPEED;
	die_start = -1;
}

void CGTurtle::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == GTURTLE_STATE_SHELL || state == GTURTLE_STATE_DIE)
	{
		left = x - GTURTLE_BBOX_WIDTH / 2;
		top = y - GTURTLE_BBOX_HEIGHT_SHELL / 2;
		right = left + GTURTLE_BBOX_WIDTH;
		bottom = top + GTURTLE_BBOX_HEIGHT_SHELL;
	}
	else
	{
		left = x - GTURTLE_BBOX_WIDTH / 2;
		top = y - GTURTLE_BBOX_HEIGHT / 2;
		right = left + GTURTLE_BBOX_WIDTH;
		bottom = top + GTURTLE_BBOX_HEIGHT;
	}

	if (state == GTURTLE_STATE_DIE_2)
	{
		left = x;
		top = y;
		right = x;
		bottom = y;
	}
}

void CGTurtle::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
};

void CGTurtle::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking()) return;
	if (dynamic_cast<CGTurtle*>(e->obj)) return;
	if (dynamic_cast<CBrick*>(e->obj) && state == GTURTLE_STATE_FLYING) return;
	if (dynamic_cast<CMario*>(e->obj)) return;
	if (dynamic_cast<CBox*>(e->obj)) {
		float bx = 0, by = 0;
		e->obj->GetPosition(bx, by);

		e->obj->Delete();

		CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();

		LPGAMEOBJECT brick;
		brick = new CBrick(bx, by, 25002);
		scene->objects.push_back(brick);

		LPGAMEOBJECT leaf;
		leaf = new CLeaf(bx, by);
		leaf->SetState(1);
		scene->objects.push_back(leaf);
	}

	if (e->ny != 0)
	{
		vy = 0;
	}
	else if (e->nx != 0)
	{
		vx = -vx;
		isFlipped = -isFlipped;
	}

	y -= 1.0f;
}

void CGTurtle::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (state != GTURTLE_STATE_DIE)
	{
		if (x > ox + 16.0f * range)
		{
			x = ox + 16.0f * range;
			isFlipped = -isFlipped;
			vx = -vx;
		}
		if (x < ox - 16.0f * range)
		{
			x = ox - 16.0f * range;
			isFlipped = -isFlipped;
			vx = -vx;
		}
	}

	if (state == GTURTLE_STATE_FLYING) 
	{
		if (y > oy + 10.0f)
		{
			y = oy + 10.0f;
			vy = -0.05f;
		}
		if (y < oy - 10.0f)
		{
			y = oy - 10.0f;
			vy = 0.05f;
		}
	}
	if ((state == GTURTLE_STATE_DIE) && (GetTickCount64() - die_start > GTURTLE_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	if ((state == GTURTLE_STATE_DIE_2) && (GetTickCount64() - die_start > GTURTLE_DIE_TIMEOUT))
	{
		isDeleted = true;
		return;
	}

	if ((state == GTURTLE_STATE_SHELL) && (GetTickCount64() - shell_start > 5000))
	{
		y -= 5.0f;
		this->SetState(GTURTLE_STATE_WALKING);
		return;
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}


void CGTurtle::Render()
{
	int aniId = ID_ANI_GTURTLE_FLYING;
	if (state == GTURTLE_STATE_WALKING)
	{
		aniId = ID_ANI_GTURTLE_WALKING;
	}
	if (state == GTURTLE_STATE_SHELL)
	{
		aniId = ID_ANI_GTURTLE_SHELL;
	}
	
	if (state == GTURTLE_STATE_DIE)
	{
		aniId = ID_ANI_GTURTLE_DIE;
	}

	if (state == GTURTLE_STATE_DIE_2)
	{
		aniId = ID_ANI_GTURTLE_SHELL;
	}

	CAnimations::GetInstance()->Get(aniId)->setFlip(this->isFlipped);
	CAnimations::GetInstance()->Get(aniId)->Render(x, y);
	RenderBoundingBox();
}

void CGTurtle::SetState(int state)
{
	CGameObject::SetState(state);

	if (state == GTURTLE_STATE_DIE_2)
	{
		CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
		LPGAMEOBJECT m = new CImpact(x, y);
		scene->objects.push_back(m);
	}

	switch (state)
	{
	case GTURTLE_STATE_FLYING:
		vy = -0.05f;
		break;
	case GTURTLE_STATE_SHELL:
		y += (GTURTLE_BBOX_HEIGHT - GTURTLE_BBOX_HEIGHT_SHELL) / 2;
		vx = 0;
		vy = 0;
		ax = 0;
		shell_start = GetTickCount64();
		break;
	case GTURTLE_STATE_WALKING:
		if (nx > 0 )vx = -GTURTLE_WALKING_SPEED;
		else vx = GTURTLE_WALKING_SPEED;
		vy = 0;
		ay = 0.02f;
		break;
	case GTURTLE_STATE_DIE:
		die_start = GetTickCount64();
		y -= 0.1f;
		break;
	case GTURTLE_STATE_DIE_2:
		die_start = GetTickCount64();
		y += (GTURTLE_BBOX_HEIGHT - GTURTLE_BBOX_HEIGHT_SHELL) / 2;
		vy = -0.3f;
		ay = 0.002f;
		vx = 0;
		ax = 0;
		break;
	}
}
