#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Game.h"

#include "Collision.h"
#include "Coin.h"
#include "Box.h"
#include "Goomba.h"
#include "GreenTurtle.h"
#include "Mushroom.h"
#include "Leaf.h"

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

	if (GetTickCount64() - swipe_start < 190 && isOnPlatform == true && level == 3)
	{
		if (nx >= 0)
		{
			aniId = ID_ANI_MARIO_TAIL_SWIPE_RIGHT;
			ax = 0;
			vx = 0;
		}
		else
		{
			aniId = ID_ANI_MARIO_TAIL_SWIPE_LEFT;
			ax = 0;
			vx = 0;
		}
	}
	else if (state == MARIO_STATE_DIE)
		aniId = ID_ANI_MARIO_DIE;
	else if (level == MARIO_LEVEL_BIG)
		aniId = GetAniIdBig();
	else if (level == MARIO_LEVEL_SMALL)
		aniId = GetAniIdSmall();
	else if (level == MARIO_LEVEL_TAIL)
		aniId = GetAniIdTail();

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
	if (dynamic_cast<CLeaf*>(e->obj)) OnCollisionWithLeaf(e);


}

void CMario::OnCollisionWithLeaf(LPCOLLISIONEVENT e)
{
	CLeaf* leaf = dynamic_cast<CLeaf*>(e->obj);
	e->obj->Delete();
	if (level == 2)
		level = 3;
	coin += 100;
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
		turtle->SetState(GTURTLE_STATE_DIE_2);
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
			if (level > MARIO_LEVEL_SMALL)
			{
				level = MARIO_LEVEL_SMALL;
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
		goomba->SetState(GOOMBA_STATE_DIE_2);
	}
	else // hit by Goomba
	{
		if (untouchable == 0)
		{
			if (goomba->GetState() != GOOMBA_STATE_DIE)
			{
				if (level > MARIO_LEVEL_SMALL)
				{
					level = MARIO_LEVEL_SMALL;
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

void CMario::OnCollisionWithCoin(LPCOLLISIONEVENT e)
{
	e->obj->Delete();
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
		if ((isOnPlatform) || 1)
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
		if (isOnPlatform)
			swipe_start = GetTickCount64();
		break;
	}

	if (GetTickCount64() - swipe_start < 190 && isOnPlatform == true && level == 3)
	{
		state = MARIO_STATE_SWIPE;
		ax = 0;
		vx = 0;
	}

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

void LoadResource()
{
	CGame* game;
	game = CGame::GetInstance();
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_MARIO, TEXTURE_PATH_MARIO);

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texMario = textures->Get(ID_TEX_MARIO);

	// IDLE
	sprites->Add(ID_SPRITE_MARIO_BIG_IDLE_RIGHT + 1, 216, 243, 216 + 13, 243 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_IDLE_LEFT + 1, 176, 243, 176 + 13, 243 + 27, texMario);

	// WALKING LEFT
	sprites->Add(ID_SPRITE_MARIO_BIG_WALKING_LEFT + 2, 135, 243, 135 + 15, 243 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_WALKING_LEFT + 3, 95, 243, 95 + 15, 243 + 27, texMario);

	// WALKING RIGHT
	sprites->Add(ID_SPRITE_MARIO_BIG_WALKING_RIGHT + 2, 255, 243, 255 + 13, 243 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_WALKING_RIGHT + 3, 295, 243, 295 + 13, 243 + 27, texMario);

	// RUNNING RIGHT 
	sprites->Add(ID_SPRITE_MARIO_BIG_RUNNING_RIGHT + 1, 255, 243, 255 + 13, 243 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_RUNNING_RIGHT + 2, 295, 243, 295 + 13, 243 + 27, texMario);

	// RUNNING LEFT
	sprites->Add(ID_SPRITE_MARIO_BIG_RUNNING_LEFT + 1, 135, 243, 135 + 15, 243 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_RUNNING_LEFT + 2, 95, 243, 95 + 15, 243 + 27, texMario);

	// JUMP WALK RIGHT & LEFT 
	sprites->Add(ID_SPRITE_MARIO_BIG_JUMP_WALK_RIGHT + 1, 335, 244, 335 + 15, 244 + 25, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_JUMP_WALK_LEFT + 1, 55, 244, 55 + 15, 244 + 25, texMario);

	// JUMP RUN RIGHT & LEFT 
	sprites->Add(ID_SPRITE_MARIO_BIG_JUMP_RUN_RIGHT + 1, 333, 364, 333 + 18, 364 + 25, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_JUMP_RUN_LEFT + 1, 54, 364, 54 + 18, 364 + 25, texMario);

	// SIT RIGHT/LEFT
	sprites->Add(ID_SPRITE_MARIO_BIG_SIT_RIGHT + 1, 376, 248, 376 + 13, 248 + 17, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_SIT_LEFT + 1, 16, 248, 16 + 13, 248 + 17, texMario);

	// BRACING RIGHT/LEFT
	sprites->Add(ID_SPRITE_MARIO_BIG_BRACE_RIGHT + 1, 175, 283, 175 + 15, 283 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_BIG_BRACE_LEFT + 1, 215, 283, 215 + 15, 283 + 27, texMario);

	// MARIO DIE
	sprites->Add(ID_SPRITE_MARIO_DIE + 1, 375, 209, 375 + 15, 209 + 15, texMario);

	// SMALL MARIO 
	sprites->Add(ID_SPRITE_MARIO_SMALL_IDLE_RIGHT + 1, 217, 89, 217 + 11, 89 + 14, texMario);
	sprites->Add(ID_SPRITE_MARIO_SMALL_IDLE_LEFT + 1, 177, 89, 177 + 11, 89 + 14, texMario);

	sprites->Add(ID_SPRITE_MARIO_SMALL_WALKING_RIGHT + 2, 215, 169, 215 + 15, 169 + 15, texMario);
	sprites->Add(ID_SPRITE_MARIO_SMALL_WALKING_RIGHT + 3, 255, 169, 255 + 15, 169 + 15, texMario);

	sprites->Add(ID_SPRITE_MARIO_SMALL_WALKING_LEFT + 2, 175, 169, 175 + 15, 169 + 15, texMario);
	sprites->Add(ID_SPRITE_MARIO_SMALL_WALKING_LEFT + 3, 135, 169, 135 + 15, 169 + 15, texMario);

	sprites->Add(ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT + 1, 215, 169, 215 + 15, 169 + 15, texMario);
	sprites->Add(ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT + 2, 255, 169, 255 + 15, 169 + 15, texMario);

	sprites->Add(ID_SPRITE_MARIO_SMALL_RUNNING_LEFT + 1, 175, 169, 175 + 15, 169 + 15, texMario);
	sprites->Add(ID_SPRITE_MARIO_SMALL_RUNNING_LEFT + 2, 135, 169, 135 + 15, 169 + 15, texMario);

	sprites->Add(ID_SPRITE_MARIO_SMALL_BRACE_LEFT + 1, 176, 129, 176 + 13, 129 + 15, texMario);
	sprites->Add(ID_SPRITE_MARIO_SMALL_BRACE_RIGHT + 1, 216, 129, 216 + 13, 129 + 15, texMario);

	sprites->Add(ID_SPRITE_MARIO_SMALL_JUMP_WALK_LEFT + 1, 55, 89, 55 + 15, 89 + 15, texMario);
	sprites->Add(ID_SPRITE_MARIO_SMALL_JUMP_WALK_RIGHT + 1, 335, 89, 335 + 15, 89 + 15, texMario);

	sprites->Add(ID_SPRITE_MARIO_SMALL_JUMP_RUN_LEFT + 1, 175, 209, 175 + 15, 209 + 15, texMario);
	sprites->Add(ID_SPRITE_MARIO_SMALL_JUMP_RUN_RIGHT + 1, 215, 209, 215 + 15, 209 + 15, texMario);

	// TAIL MARIO 
	sprites->Add(ID_SPRITE_MARIO_TAIL_IDLE_RIGHT + 1, 212, 443, 212 + 20, 443 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_IDLE_LEFT + 1, 173, 443, 173 + 20, 443 + 27, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_WALKING_RIGHT + 2, 262, 443, 212 + 21, 443 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_WALKING_RIGHT + 3, 291, 443, 291 + 22, 443 + 27, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_WALKING_LEFT + 2, 122, 443, 122 + 21, 443 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_WALKING_LEFT + 3, 92, 443, 92 + 22, 443 + 27, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT + 1, 262, 443, 212 + 21, 443 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT + 2, 291, 443, 291 + 22, 443 + 27, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_RUNNING_LEFT + 1, 122, 443, 122 + 21, 443 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_RUNNING_LEFT + 2, 92, 443, 92 + 22, 443 + 27, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_BRACE_LEFT + 1, 175, 482, 175 + 15, 482 + 29, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_BRACE_RIGHT + 1, 215, 482, 215 + 15, 482 + 29, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_JUMP_WALK_LEFT + 1, 52, 443, 52 + 22, 443 + 26, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_JUMP_WALK_RIGHT + 1, 331, 443, 331 + 22, 443 + 26, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_JUMP_RUN_LEFT + 1, 11, 603, 11 + 23, 603 + 26, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_JUMP_RUN_RIGHT + 1, 371, 603, 371 + 23, 603 + 26, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_SIT_RIGHT + 1, 372, 448, 372 + 21, 448 + 17, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_SIT_LEFT + 1, 12, 448, 12 + 21, 448 + 17, texMario);

	sprites->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 1, 211, 523, 211 + 23 + 8, 523 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 2, 355, 483, 355 + 15, 483 + 27, texMario);
	sprites->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 3, 171 - 8, 523, 171 + 23, 523 + 27, texMario);
	LPANIMATION ani;

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_IDLE_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_IDLE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_IDLE_LEFT + 1);
	animations->Add(ID_ANI_MARIO_IDLE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_IDLE_RIGHT + 1);
	ani->Add(ID_SPRITE_MARIO_BIG_WALKING_RIGHT + 2);
	ani->Add(ID_SPRITE_MARIO_BIG_WALKING_RIGHT + 3);
	animations->Add(ID_ANI_MARIO_WALKING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_IDLE_LEFT + 1);
	ani->Add(ID_SPRITE_MARIO_BIG_WALKING_LEFT + 2);
	ani->Add(ID_SPRITE_MARIO_BIG_WALKING_LEFT + 3);
	animations->Add(ID_ANI_MARIO_WALKING_LEFT, ani);

	ani = new CAnimation(50);
	ani->Add(ID_SPRITE_MARIO_BIG_RUNNING_RIGHT + 1);
	ani->Add(ID_SPRITE_MARIO_BIG_RUNNING_RIGHT + 2);
	animations->Add(ID_ANI_MARIO_RUNNING_RIGHT, ani);

	// Mario runs faster hence animation speed should be faster
	ani = new CAnimation(50);
	ani->Add(ID_SPRITE_MARIO_BIG_RUNNING_LEFT + 1);
	ani->Add(ID_SPRITE_MARIO_BIG_RUNNING_LEFT + 2);
	animations->Add(ID_ANI_MARIO_RUNNING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_JUMP_WALK_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_JUMP_WALK_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_JUMP_WALK_LEFT + 1);
	animations->Add(ID_ANI_MARIO_JUMP_WALK_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_JUMP_RUN_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_JUMP_RUN_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_JUMP_RUN_LEFT + 1);
	animations->Add(ID_ANI_MARIO_JUMP_RUN_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_SIT_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_SIT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_SIT_LEFT + 1);
	animations->Add(ID_ANI_MARIO_SIT_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_BRACE_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_BRACE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_BIG_BRACE_LEFT + 1);
	animations->Add(ID_ANI_MARIO_BRACE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_DIE + 1);
	animations->Add(ID_ANI_MARIO_DIE, ani);

	//
	// SMALL MARIO 
	//
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_IDLE_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_SMALL_IDLE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_IDLE_RIGHT + 1);
	ani->Add(ID_SPRITE_MARIO_SMALL_WALKING_RIGHT + 2);
	ani->Add(ID_SPRITE_MARIO_SMALL_WALKING_RIGHT + 3);
	animations->Add(ID_ANI_MARIO_SMALL_WALKING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_IDLE_LEFT + 1);
	animations->Add(ID_ANI_MARIO_SMALL_IDLE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_IDLE_LEFT + 1);
	ani->Add(ID_SPRITE_MARIO_SMALL_WALKING_LEFT + 2);
	ani->Add(ID_SPRITE_MARIO_SMALL_WALKING_LEFT + 3);
	animations->Add(ID_ANI_MARIO_SMALL_WALKING_LEFT, ani);

	ani = new CAnimation(50);
	ani->Add(ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT + 1);
	ani->Add(ID_SPRITE_MARIO_SMALL_RUNNING_RIGHT + 2);
	animations->Add(ID_ANI_MARIO_SMALL_RUNNING_RIGHT, ani);

	ani = new CAnimation(50);
	ani->Add(ID_SPRITE_MARIO_SMALL_RUNNING_LEFT + 1);
	ani->Add(ID_SPRITE_MARIO_SMALL_RUNNING_LEFT + 2);
	animations->Add(ID_ANI_MARIO_SMALL_RUNNING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_BRACE_LEFT + 1);
	animations->Add(ID_ANI_MARIO_SMALL_BRACE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_BRACE_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_SMALL_BRACE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_JUMP_WALK_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_JUMP_WALK_LEFT + 1);
	animations->Add(ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_JUMP_RUN_LEFT + 1);
	animations->Add(ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_SMALL_JUMP_RUN_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT, ani);

	// TAIL MARIO 
	//
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_IDLE_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_IDLE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_IDLE_RIGHT + 1);
	ani->Add(ID_SPRITE_MARIO_TAIL_WALKING_RIGHT + 2);
	ani->Add(ID_SPRITE_MARIO_TAIL_WALKING_RIGHT + 3);
	animations->Add(ID_ANI_MARIO_TAIL_WALKING_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_IDLE_LEFT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_IDLE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_IDLE_LEFT + 1);
	ani->Add(ID_SPRITE_MARIO_TAIL_WALKING_LEFT + 2);
	ani->Add(ID_SPRITE_MARIO_TAIL_WALKING_LEFT + 3);
	animations->Add(ID_ANI_MARIO_TAIL_WALKING_LEFT, ani);

	ani = new CAnimation(50);
	ani->Add(ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT + 1);
	ani->Add(ID_SPRITE_MARIO_TAIL_RUNNING_RIGHT + 2);
	animations->Add(ID_ANI_MARIO_TAIL_RUNNING_RIGHT, ani);

	ani = new CAnimation(50);
	ani->Add(ID_SPRITE_MARIO_TAIL_RUNNING_LEFT + 1);
	ani->Add(ID_SPRITE_MARIO_TAIL_RUNNING_LEFT + 2);
	animations->Add(ID_ANI_MARIO_TAIL_RUNNING_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_BRACE_LEFT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_BRACE_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_BRACE_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_BRACE_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_JUMP_WALK_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_JUMP_WALK_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_JUMP_WALK_LEFT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_JUMP_WALK_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_JUMP_RUN_LEFT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_JUMP_RUN_LEFT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_JUMP_RUN_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_JUMP_RUN_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_SIT_RIGHT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_SIT_RIGHT, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_MARIO_TAIL_SIT_LEFT + 1);
	animations->Add(ID_ANI_MARIO_TAIL_SIT_LEFT, ani);

	ani = new CAnimation(50);
	ani->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 1);
	ani->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 2);
	ani->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 3);
	animations->Add(ID_ANI_MARIO_TAIL_SWIPE_RIGHT, ani);

	ani = new CAnimation(50);
	ani->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 3);
	ani->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 2);
	ani->Add(ID_SPRITE_MARIO_TAIL_SWIPE + 1);
	animations->Add(ID_ANI_MARIO_TAIL_SWIPE_LEFT, ani);
}

CMario::CMario(float x, float y) : CGameObject(x, y)
{
	isSitting = false;
	maxVx = 0.0f;
	ax = 0.0f;
	ay = MARIO_GRAVITY;

	level = MARIO_LEVEL_SMALL;
	untouchable = 0;
	untouchable_start = -1;
	swipe_start = -1;
	isOnPlatform = false;
	coin = 0;
	LoadResource();
}