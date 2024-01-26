#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Tail.h"
#include "Game.h"
#include "PlayScene.h"

#include "Collision.h"
#include "Coin.h"
#include "Box.h"
#include "Goomba.h"
#include "GreenTurtle.h"
#include "Mushroom.h"
#include "GMushroom.h"
#include "Leaf.h"
#include "Sewer.h"
#include "Button.h"
#include "Eater.h"
#include "GreenEater.h"
#include "Bullet.h"
#include "Piranha.h"
#include "Star.h"
#include "Point.h"

CMario* CMario::__instance = NULL;
CMario* CMario::GetInstance(float x, float y)
{
	if (__instance == NULL) __instance = new CMario(x, y);
	return __instance;
}

void CMario::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	vy += ay * dt;
	vx += ax * dt;

	if (abs(vx) > abs(maxVx)) vx = maxVx;

	// reset untouchable timer if untouchable time has passed
	if (GetTickCount64() - untouchable_start > MARIO_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	isOnPlatform = false;
	
	if (GetTickCount64() - tunel_time > 3000 && go == 1)
	{
		CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
		go = 0;
		this->SetState(MARIO_STATE_IDLE);
		ay = MARIO_GRAVITY;
		scene->GoMap(2);
	}

	if (GetTickCount64() - tunel_time > 3000 && go == 2)
	{
		CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
		go = 0;
		this->SetState(MARIO_STATE_IDLE);
		ay = MARIO_GRAVITY;
		scene->GoMap(1);
	}
	CCollision::GetInstance()->Process(this, dt, coObjects);
}

void CMario::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

//
// Get animation ID for small Mario
//
int CMario::GetAniIdSmall()
{
	int aniId = -1;
	if (!isOnPlatform)
	{
		if (abs(ax) == MARIO_ACCEL_RUN_X)
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT;
		}
	}
	else
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;
			else
				aniId = ID_ANI_MARIO_SMALL_IDLE_LEFT;
		}
		else
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_SMALL_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_SMALL_BRACE_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_SMALL_RUNNING_RIGHT;
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_SMALL_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_SMALL_BRACE_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_SMALL_RUNNING_LEFT;
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_SMALL_WALKING_LEFT;
			}

	if (aniId == -1) aniId = ID_ANI_MARIO_SMALL_IDLE_RIGHT;
	return aniId;
}

int CMario::GetAniIdTail()
{
	if (state == MARIO_STATE_SWIPE) return 0;
	int aniId = -1;
	if (isSitting) {
		ax = 0;
		vx = 0;
	};

	if (!isOnPlatform)
	{
		if (abs(ax) == MARIO_ACCEL_RUN_X)
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_TAIL_JUMP_RUN_RIGHT;
			else
				aniId = ID_ANI_MARIO_TAIL_JUMP_RUN_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_TAIL_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_TAIL_JUMP_WALK_LEFT;
		}
	}
	else
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_TAIL_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_TAIL_SIT_LEFT;
		}
		else
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_TAIL_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_TAIL_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_TAIL_BRACE_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_TAIL_RUNNING_RIGHT;
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_TAIL_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_TAIL_BRACE_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_TAIL_RUNNING_LEFT;
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_TAIL_WALKING_LEFT;
			}

	if (aniId == -1) aniId = ID_ANI_MARIO_TAIL_IDLE_RIGHT;

	return aniId;
}

//
// Get animdation ID for big Mario
//
int CMario::GetAniIdBig()
{
	int aniId = -1;
	if (isSitting) {
		ax = 0;
		vx = 0;
	};
	if (!isOnPlatform)
	{
		if (abs(ax) == MARIO_ACCEL_RUN_X)
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_JUMP_RUN_RIGHT;
			else
				aniId = ID_ANI_MARIO_JUMP_RUN_LEFT;
		}
		else
		{
			if (nx >= 0)
				aniId = ID_ANI_MARIO_JUMP_WALK_RIGHT;
			else
				aniId = ID_ANI_MARIO_JUMP_WALK_LEFT;
		}
	}
	else
		if (isSitting)
		{
			if (nx > 0)
				aniId = ID_ANI_MARIO_SIT_RIGHT;
			else
				aniId = ID_ANI_MARIO_SIT_LEFT;
		}
		else
			if (vx == 0)
			{
				if (nx > 0) aniId = ID_ANI_MARIO_IDLE_RIGHT;
				else aniId = ID_ANI_MARIO_IDLE_LEFT;
			}
			else if (vx > 0)
			{
				if (ax < 0)
					aniId = ID_ANI_MARIO_BRACE_RIGHT;
				else if (ax == MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_RUNNING_RIGHT;
				else if (ax == MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_WALKING_RIGHT;
			}
			else // vx < 0
			{
				if (ax > 0)
					aniId = ID_ANI_MARIO_BRACE_LEFT;
				else if (ax == -MARIO_ACCEL_RUN_X)
					aniId = ID_ANI_MARIO_RUNNING_LEFT;
				else if (ax == -MARIO_ACCEL_WALK_X)
					aniId = ID_ANI_MARIO_WALKING_LEFT;
			}

	if (aniId == -1) aniId = ID_ANI_MARIO_IDLE_RIGHT;

	return aniId;
}

void CMario::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	if (GetTickCount64() - tunel_time < 3000)
	{
		aniId = ID_ANI_MARIO_TAIL_TUNEL;
	}
	else if (state == MARIO_STATE_DIE)
		aniId = ID_ANI_MARIO_DIE;
	else if (level == MARIO_LEVEL_BIG)
		aniId = GetAniIdBig();
	else if (level == MARIO_LEVEL_SMALL)
		aniId = GetAniIdSmall();
	else if (level == MARIO_LEVEL_TAIL)
		aniId = GetAniIdTail();

	if (state == MARIO_STATE_SWIPE)
	{
		if (nx > 0)	aniId = ID_ANI_MARIO_TAIL_SWIPE_RIGHT;
		if (nx < 0)	aniId = ID_ANI_MARIO_TAIL_SWIPE_LEFT;
	}

	animations->Get(aniId)->Render(x, y);

	RenderBoundingBox();

	DebugOutTitle(L"Coins: %d", coin);
}

void CMario::OnCollisionWith(LPCOLLISIONEVENT e)
{

	if (e->ny != 0 && e->obj->IsBlocking())
	{
		vy = 0;
		if (e->ny < 0) isOnPlatform = true;
	}
	else
		if (e->nx != 0 && e->obj->IsBlocking())
		{
			vx = 0;
		}

	if (dynamic_cast<CCoin*>(e->obj)) OnCollisionWithCoin(e);
	if (dynamic_cast<CBox*>(e->obj) && e->ny > 0) OnCollisionWithBox(e);
	if (dynamic_cast<CGoomba*>(e->obj)) OnCollisionWithGoomba(e);
	if (dynamic_cast<CGTurtle*>(e->obj)) OnCollisionWithGTurtle(e);
	if (dynamic_cast<CMushroom*>(e->obj)) OnCollisionWithMushroom(e);	
	if (dynamic_cast<CGMushroom*>(e->obj)) OnCollisionWithGMushroom(e);
	if (dynamic_cast<CLeaf*>(e->obj)) OnCollisionWithLeaf(e);
	if (dynamic_cast<CSewer*>(e->obj)) OnCollisionWithSewer(e);
	if (dynamic_cast<CButton*>(e->obj)) OnCollisionWithButton(e);
	if (dynamic_cast<CStar*>(e->obj)) OnCollisionWithStar(e);

	if (dynamic_cast<CEater*>(e->obj)) {
		if (untouchable == 0)
		{
			if (level > 1)
			{
				level -= 1;
				StartUntouchable();
			}
			else
			{
				SetState(MARIO_STATE_DIE);
			}
		}
	}
	if (dynamic_cast<CGEater*>(e->obj)) {
		if (untouchable == 0)
		{
			if (level > 1)
			{
				level -= 1;
				StartUntouchable();
			}
			else
			{
				SetState(MARIO_STATE_DIE);
			}
		}
	}
	
	if (dynamic_cast<CPiranha*>(e->obj)) {
		if (untouchable == 0)
		{
			if (level > 1)
			{
				level -= 1;
				StartUntouchable();
			}
			else
			{
				SetState(MARIO_STATE_DIE);
			}
		}
	}

	if (dynamic_cast<CBullet*>(e->obj))
	{
		if (untouchable == 0)
		{
			if (level > 1)
			{
				level -= 1;
				StartUntouchable();
			}
			else
			{
				SetState(MARIO_STATE_DIE);
			}
		}
	}
}

void CMario::OnCollisionWithButton(LPCOLLISIONEVENT e)
{
	CButton* s = dynamic_cast<CButton*>(e->obj);
	if (e->ny < 0)
	{
		this->gold = 1;
		s->Delete();
	}
}


void CMario::OnCollisionWithSewer(LPCOLLISIONEVENT e)
{
	CSewer* s = dynamic_cast<CSewer*>(e->obj);
	if (isSitting == true && s->getType() == 1) {
		tunel_time = GetTickCount64();
		this->SetState(MARIO_STATE_DOWN);
		float sx, sy;
		s->GetPosition(sx, sy);
		this->x = sx;
	}
	if (s->getType() == 2 && go == 0) {
		tunel_time = GetTickCount64();
		this->SetState(MARIO_STATE_UP);
		float sx, sy;
		s->GetPosition(sx, sy);
		this->x = sx;
	}
}

void CMario::OnCollisionWithLeaf(LPCOLLISIONEVENT e)
{
	CLeaf* leaf = dynamic_cast<CLeaf*>(e->obj);
	e->obj->Delete();
	if (level == 2)
		level = 3;
	coin += 100;
}

void CMario::OnCollisionWithGMushroom(LPCOLLISIONEVENT e)
{
	CGMushroom* m = dynamic_cast<CGMushroom*>(e->obj);
	e->obj->Delete();
	life += 1;
}

void CMario::OnCollisionWithMushroom(LPCOLLISIONEVENT e)
{
	CMushroom* m = dynamic_cast<CMushroom*>(e->obj);
	e->obj->Delete();
	if (level == 1)
		level = 2;
	y -= 10.0f;
	coin += 100;
}

void CMario::OnCollisionWithGTurtle(LPCOLLISIONEVENT e)
{
	CGTurtle* turtle = dynamic_cast<CGTurtle*>(e->obj);

	// jump on top >> kill Turtle and deflect a bit 
	if (e->ny < 0)
	{
		if (turtle->GetState() == GTURTLE_STATE_SHELL)
		{
			turtle->SetState(GTURTLE_STATE_DIE);
			e->obj->SetSpeed(0.5, 0);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
		if (turtle->GetState() == GTURTLE_STATE_WALKING)
		{
			turtle->SetState(GTURTLE_STATE_SHELL);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
		if (turtle->GetState() == GTURTLE_STATE_FLYING)
		{
			turtle->SetState(GTURTLE_STATE_WALKING);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
	} else if (state == MARIO_STATE_SWIPE)
	{
		return;
		//turtle->SetState(GTURTLE_STATE_DIE_2);
	}
	else if (e->obj->GetState() == GTURTLE_STATE_SHELL)
	{
		e->obj->SetState(GTURTLE_STATE_DIE);
		if (e->nx < 0) e->obj->SetSpeed(0.5,0);
		else e->obj->SetSpeed(-0.5, 0);
	}
	else // hit by Turtle
	{
		if (untouchable == 0)
		{
			if (level > 1)
			{
				level -= 1;
				StartUntouchable();
			} 
			else
			{
				SetState(MARIO_STATE_DIE);
			}
		}
	}
}

void CMario::OnCollisionWithGoomba(LPCOLLISIONEVENT e)
{
	CGoomba* goomba = dynamic_cast<CGoomba*>(e->obj);

	// jump on top >> kill Goomba and deflect a bit 
	if (e->ny < 0)
	{
		if (goomba->GetState() == GOOMBA_STATE_WALKING)
		{
			goomba->SetState(GOOMBA_STATE_DIE);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
		if (goomba->GetState() == GOOMBA_STATE_FLYING)
		{
			goomba->SetState(GOOMBA_STATE_WALKING);
			vy = -MARIO_JUMP_DEFLECT_SPEED;
		}
	}
	else if (state == MARIO_STATE_SWIPE)
	{
		return;
		//goomba->SetState(GOOMBA_STATE_DIE_2);
	}
	else // hit by Goomba
	{
		if (untouchable == 0)
		{
			if (goomba->GetState() != GOOMBA_STATE_DIE)
			{
				if (level > 1)
				{
					level -= 1;
					StartUntouchable();
				}
				else
				{
					SetState(MARIO_STATE_DIE);
				}
			}
		}
	}
}

void CMario::OnCollisionWithStar(LPCOLLISIONEVENT e)
{
	e->obj->Delete();
	star += 1;
	coin += 1000;
}

void CMario::OnCollisionWithCoin(LPCOLLISIONEVENT e)
{
	float  cx, cy;
	e->obj->GetPosition(cx, cy);
	e->obj->Delete();
	LPGAMEOBJECT b = new CPoint(cx, cy);
	b->SetState(1);
	
	CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
	scene->objects.push_back(b);

	coin += 100;
}

void CMario::OnCollisionWithBox(LPCOLLISIONEVENT e)
{
	e->obj->SetState(2);
	coin += 100;
}

void CMario::SetState(int state)
{
	// DIE is the end state, cannot be changed! 
	if (this->state == MARIO_STATE_DIE) return;

	switch (state)
	{
	case MARIO_STATE_RUNNING_RIGHT:
		if (isSitting) break;
		maxVx = MARIO_RUNNING_SPEED;
		ax = MARIO_ACCEL_RUN_X;
		nx = 1;
		break;
	case MARIO_STATE_RUNNING_LEFT:
		if (isSitting) break;
		maxVx = -MARIO_RUNNING_SPEED;
		ax = -MARIO_ACCEL_RUN_X;
		nx = -1;
		break;
	case MARIO_STATE_WALKING_RIGHT:
		if (isSitting) break;
		maxVx = MARIO_WALKING_SPEED;
		ax = MARIO_ACCEL_WALK_X;
		nx = 1;
		break;
	case MARIO_STATE_WALKING_LEFT:
		if (isSitting) break;
		maxVx = -MARIO_WALKING_SPEED;
		ax = -MARIO_ACCEL_WALK_X;
		nx = -1;
		break;
	case MARIO_STATE_JUMP:
		if (isSitting) break;
		if (isOnPlatform || (level == 3 && abs(this->vx) == MARIO_RUNNING_SPEED))
		{
			if (abs(this->vx) == MARIO_RUNNING_SPEED)
				vy = -MARIO_JUMP_RUN_SPEED_Y;
			else
				vy = -MARIO_JUMP_SPEED_Y;
		}
		break;

	case MARIO_STATE_RELEASE_JUMP:
		if (vy < 0) vy += MARIO_JUMP_SPEED_Y / 2;
		break;

	case MARIO_STATE_SIT:
		if (isOnPlatform && level != 0)
		{
			state = MARIO_STATE_IDLE;
			isSitting = true;
			vx = 0; vy = 0.0f;
			if (level != 1)
				y += MARIO_SIT_HEIGHT_ADJUST;
		}
		break;

	case MARIO_STATE_SIT_RELEASE:
		if (isSitting)
		{
			isSitting = false;
			state = MARIO_STATE_IDLE;
			y -= MARIO_SIT_HEIGHT_ADJUST;
		}
		break;

	case MARIO_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		break;

	case MARIO_STATE_DIE:
		vy = -MARIO_JUMP_DEFLECT_SPEED;
		vx = 0;
		ax = 0;
		break;
	case MARIO_STATE_SWIPE:
		swipe_start = GetTickCount64();
		break;
	case MARIO_STATE_UP:
		go = 2;
		vy = -0.4f;
		break;
	case MARIO_STATE_DOWN:
		go = 1;
		vy = 0.02f;
		break;
	}

	if (GetTickCount64() - swipe_start < 290 && level == 3)
	{
		state = MARIO_STATE_SWIPE;
		ax = 0;
		ay = 0;
		vx = 0;
		vy = 0;
		LPGAMEOBJECT b = new Ctail(x, y + 8.0f);
		if (nx >= 0) b->SetSpeed(0.05, 0);
		else b->SetSpeed(-0.05, 0);

		CPlayScene* scene = (CPlayScene*)CGame::GetInstance()->GetCurrentScene();
		scene->objects.push_back(b);
	}
	else ay = MARIO_GRAVITY;

	if (go != 0) ay = 0;
	CGameObject::SetState(state);
}

void CMario::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (level == MARIO_LEVEL_BIG)
	{
		if (isSitting)
		{
			left = x - MARIO_BIG_SITTING_BBOX_WIDTH / 2;
			top = y - MARIO_BIG_SITTING_BBOX_HEIGHT / 2;
			right = left + MARIO_BIG_SITTING_BBOX_WIDTH;
			bottom = top + MARIO_BIG_SITTING_BBOX_HEIGHT;
		}
		else
		{
			left = x - MARIO_BIG_BBOX_WIDTH / 2;
			top = y - MARIO_BIG_BBOX_HEIGHT / 2;
			right = left + MARIO_BIG_BBOX_WIDTH;
			bottom = top + MARIO_BIG_BBOX_HEIGHT;
		}
	}

	if (level == MARIO_LEVEL_SMALL)
	{
		left = x - MARIO_SMALL_BBOX_WIDTH / 2;
		top = y - MARIO_SMALL_BBOX_HEIGHT / 2;
		right = left + MARIO_SMALL_BBOX_WIDTH;
		bottom = top + MARIO_SMALL_BBOX_HEIGHT;
	}

	if (level == MARIO_LEVEL_TAIL)
	{
		if (isSitting)
		{
			left = x - MARIO_TAIL_SITTING_BBOX_WIDTH / 2;
			top = y - MARIO_TAIL_SITTING_BBOX_HEIGHT / 2;
			right = left + MARIO_TAIL_SITTING_BBOX_WIDTH;
			bottom = top + MARIO_TAIL_SITTING_BBOX_HEIGHT;
		}
		else {
			if (state == MARIO_STATE_WALKING_RIGHT ||
				state == MARIO_STATE_RUNNING_RIGHT ||
				(state == MARIO_STATE_IDLE and nx > 0))
				{
					left = x - (MARIO_TAIL_BBOX_WIDTH) / 2;
					top = y - MARIO_TAIL_BBOX_HEIGHT / 2;
					right = x + (MARIO_TAIL_BBOX_WIDTH) / 2;
					bottom = top + MARIO_TAIL_BBOX_HEIGHT;
				}
			else if (state == MARIO_STATE_WALKING_LEFT ||
					 state == MARIO_STATE_RUNNING_LEFT ||
					(state == MARIO_STATE_IDLE and nx < 0))
					{
						left = x - (MARIO_TAIL_BBOX_WIDTH) / 2;
						top = y - MARIO_TAIL_BBOX_HEIGHT / 2;
						right = x + (MARIO_TAIL_BBOX_WIDTH) / 2;
						bottom = top + MARIO_TAIL_BBOX_HEIGHT;
					}
			else if (state == MARIO_STATE_SWIPE)
			{
				left = x - 32.0f / 2;
				top = y - MARIO_TAIL_BBOX_HEIGHT / 2;
				right = x + 32.0f / 2;
				bottom = top + MARIO_TAIL_BBOX_HEIGHT;
			}
			else
			{
				left = x - (MARIO_TAIL_BBOX_WIDTH) / 2;
				top = y - MARIO_TAIL_BBOX_HEIGHT / 2;
				right = x + (MARIO_TAIL_BBOX_WIDTH) / 2;
				bottom = top + MARIO_TAIL_BBOX_HEIGHT;
			}
		}
	}
}

void CMario::SetLevel(int l)
{
	// Adjust position to avoid falling off platform
	if (this->level == MARIO_LEVEL_SMALL)
	{
		y -= (MARIO_BIG_BBOX_HEIGHT - MARIO_SMALL_BBOX_HEIGHT) / 2;
	}
	level = l;
}

CMario::CMario(float x, float y) : CGameObject(x, y)
{
	star = 0;
	gold = 0;
	isSitting = false;
	maxVx = 0.0f;
	ax = 0.0f;
	ay = MARIO_GRAVITY;

	level = 3;
	untouchable = 0;
	tunel_time = -1;

	untouchable_start = -1;
	swipe_start = -1;
	isOnPlatform = false;
	coin = 0;
	life = 0;
}