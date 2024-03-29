#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "Texture.h"
#include "Textures.h"

#include "AssetIDs.h"
#include "debug.h"

#define TEXTURES_DIR L"C:\\Code\\Mario\\Mario\\Resource"
#define TEXTURE_PATH_MARIO TEXTURES_DIR "\\mario_0.png"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.2f

#define MARIO_ACCEL_WALK_X	0.0005f
#define MARIO_ACCEL_RUN_X	0.0007f

#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_JUMP_RUN_SPEED_Y	0.6f

#define MARIO_GRAVITY			0.002f

#define MARIO_JUMP_DEFLECT_SPEED  0.4f

#define MARIO_STATE_DIE				0
#define MARIO_STATE_IDLE			-10
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200

#define MARIO_STATE_JUMP			300
#define MARIO_STATE_RELEASE_JUMP    301

#define MARIO_STATE_RUNNING_RIGHT	400
#define MARIO_STATE_RUNNING_LEFT	500

#define MARIO_STATE_SIT				600
#define MARIO_STATE_SIT_RELEASE		601

#define MARIO_STATE_SWIPE			700

#define MARIO_STATE_DOWN			800
#define MARIO_STATE_UP				801

#define MARIO_STATE_THROW			802

#pragma region ANIMATION_ID

#define ID_ANI_MARIO_IDLE_RIGHT 400
#define ID_ANI_MARIO_IDLE_LEFT 401

#define ID_ANI_MARIO_WALKING_RIGHT 500
#define ID_ANI_MARIO_WALKING_LEFT 501

#define ID_ANI_MARIO_RUNNING_RIGHT 600
#define ID_ANI_MARIO_RUNNING_LEFT 601

#define ID_ANI_MARIO_JUMP_WALK_RIGHT 700
#define ID_ANI_MARIO_JUMP_WALK_LEFT 701

#define ID_ANI_MARIO_JUMP_RUN_RIGHT 800
#define ID_ANI_MARIO_JUMP_RUN_LEFT 801

#define ID_ANI_MARIO_SIT_RIGHT 900
#define ID_ANI_MARIO_SIT_LEFT 901

#define ID_ANI_MARIO_BRACE_RIGHT 1000
#define ID_ANI_MARIO_BRACE_LEFT 1001

#define ID_ANI_MARIO_DIE 999

// SMALL MARIO
#define ID_ANI_MARIO_SMALL_IDLE_RIGHT 2100
#define ID_ANI_MARIO_SMALL_IDLE_LEFT 2102

#define ID_ANI_MARIO_SMALL_WALKING_RIGHT 2200
#define ID_ANI_MARIO_SMALL_WALKING_LEFT 2201

#define ID_ANI_MARIO_SMALL_RUNNING_RIGHT 2300
#define ID_ANI_MARIO_SMALL_RUNNING_LEFT 2301

#define ID_ANI_MARIO_SMALL_BRACE_RIGHT 2400
#define ID_ANI_MARIO_SMALL_BRACE_LEFT 2401

#define ID_ANI_MARIO_SMALL_JUMP_WALK_RIGHT 2500
#define ID_ANI_MARIO_SMALL_JUMP_WALK_LEFT 2501

#define ID_ANI_MARIO_SMALL_JUMP_RUN_RIGHT 2600
#define ID_ANI_MARIO_SMALL_JUMP_RUN_LEFT 2601

// TAIL MARIO
#define ID_ANI_MARIO_TAIL_IDLE_RIGHT 1100
#define ID_ANI_MARIO_TAIL_IDLE_LEFT 1101

#define ID_ANI_MARIO_TAIL_WALKING_RIGHT 1200
#define ID_ANI_MARIO_TAIL_WALKING_LEFT 1201

#define ID_ANI_MARIO_TAIL_RUNNING_RIGHT 1300
#define ID_ANI_MARIO_TAIL_RUNNING_LEFT 1301

#define ID_ANI_MARIO_TAIL_BRACE_RIGHT 1400
#define ID_ANI_MARIO_TAIL_BRACE_LEFT 1401

#define ID_ANI_MARIO_TAIL_JUMP_WALK_RIGHT 1500
#define ID_ANI_MARIO_TAIL_JUMP_WALK_LEFT 1501

#define ID_ANI_MARIO_TAIL_JUMP_RUN_RIGHT 1600
#define ID_ANI_MARIO_TAIL_JUMP_RUN_LEFT 1601

#define ID_ANI_MARIO_TAIL_SIT_RIGHT 902
#define ID_ANI_MARIO_TAIL_SIT_LEFT 903

#define ID_ANI_MARIO_TAIL_SWIPE_RIGHT 911
#define ID_ANI_MARIO_TAIL_SWIPE_LEFT 912

#define ID_ANI_MARIO_TAIL_TUNEL 950

#pragma endregion

#define GROUND_Y 160.0f




#define	MARIO_LEVEL_SMALL	1
#define	MARIO_LEVEL_BIG		2
#define	MARIO_LEVEL_TAIL	3

#define MARIO_BIG_BBOX_WIDTH  16
#define MARIO_BIG_BBOX_HEIGHT 28
#define MARIO_BIG_SITTING_BBOX_WIDTH  14
#define MARIO_BIG_SITTING_BBOX_HEIGHT 18

#define MARIO_TAIL_BBOX_WIDTH  21
#define MARIO_TAIL_BBOX_HEIGHT 28
#define	MARIO_TAIL_SITTING_BBOX_WIDTH 22
#define	MARIO_TAIL_SITTING_BBOX_HEIGHT 18

#define MARIO_SIT_HEIGHT_ADJUST ((MARIO_BIG_BBOX_HEIGHT-MARIO_BIG_SITTING_BBOX_HEIGHT)/2)

#define MARIO_SMALL_BBOX_WIDTH  13
#define MARIO_SMALL_BBOX_HEIGHT 12


#define MARIO_UNTOUCHABLE_TIME 2500

class CMario : public CGameObject
{
	BOOLEAN isSitting;
	float maxVx;
	float ax;				// acceleration on x 
	float ay;				// acceleration on y 

	int level;
	int untouchable;
	int go = 0;

	ULONGLONG untouchable_start;
	ULONGLONG tunel_time = -1;

	int coin;
	int gold;
	int life;
	int star;

	int GetAniIdBig();
	int GetAniIdSmall();
	int GetAniIdTail();

	ULONGLONG swipe_start;

	static CMario* __instance;
public:
	static CMario* GetInstance(float x, float y);

	BOOLEAN isOnPlatform;
	int air_lock;
	int hold;

	CMario(float x, float y);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void SetState(int state);
	int IsCollidable()
	{
		if (go > 0) return 0;
		return (state != MARIO_STATE_DIE);
	}

	int getX() { return x; }
	int getY() { return y; }

	int IsBlocking() { return (state != MARIO_STATE_DIE && untouchable == 0); }
	
	void OnNoCollision(DWORD dt);
	void OnCollisionWith(LPCOLLISIONEVENT e);

	void SetLevel(int l);
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount64(); }

	void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	void OnCollisionWithCoin(LPCOLLISIONEVENT e);
	void OnCollisionWithBox(LPCOLLISIONEVENT e);
	void OnCollisionWithGoomba(LPCOLLISIONEVENT e);
	void OnCollisionWithGTurtle(LPCOLLISIONEVENT e);
	void OnCollisionWithMushroom(LPCOLLISIONEVENT e);
	void OnCollisionWithGMushroom(LPCOLLISIONEVENT e);
	void OnCollisionWithLeaf(LPCOLLISIONEVENT e);
	void OnCollisionWithSewer(LPCOLLISIONEVENT e);
	void OnCollisionWithButton(LPCOLLISIONEVENT e);
	void OnCollisionWithStar(LPCOLLISIONEVENT e);

	void setGold(int x) { gold = x; }
	int getGold() { return gold; }
	int getCoin() { return coin; }
	int getLife() { return life; }
	int getGo() { return go; }
	int getStar() { return star; }

};