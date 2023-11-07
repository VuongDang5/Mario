#include "GameLoop.h"

#include <windows.h>
#include <d3d10.h>
#include <d3dx10.h>
#include <list>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"
#include "Animation.h"
#include "Animations.h"

#include "Mario.h"
#include "Brick.h"

#include "SampleKeyHandler.h"

#include "AssetIDs.h"

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"04 - Collision"
#define WINDOW_ICON_PATH L"mario.ico"

#define BACKGROUND_COLOR D3DXCOLOR(145.0f/255, 255.0f/255, 255.0f/255, 0.0f)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define TEXTURES_DIR L"C:\\Code\\Mario\\Mario\\Resource"
#define TEXTURE_PATH_MISC TEXTURES_DIR "\\tiles.png"
#define TEXTURE_PATH_1_MISC TEXTURES_DIR "\\tiles_transparent.png"
#define TEXTURE_PATH_ENEMY TEXTURES_DIR "\\enemies_transparent.png"
#define TEXTURE_PATH_BBOX TEXTURES_DIR "\\bbox.png"

#define MARIO_START_X 20.0f
#define MARIO_START_Y 10.0f

#define BRICK_X 0.0f
#define BRICK_Y GROUND_Y + 36.0f

CGame* game;
CMario* mario;

list<LPGAMEOBJECT> objects;

CSampleKeyHandler* keyHandler;


GameLoop::GameLoop(HWND hWnd)
{
	game = CGame::GetInstance();
	CTextures* textures = CTextures::GetInstance();

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	textures->Add(ID_TEX_ENEMY, TEXTURE_PATH_ENEMY);
	textures->Add(ID_TEX_MISC, TEXTURE_PATH_MISC);
	textures->Add(ID_TEX_MISC_1, TEXTURE_PATH_1_MISC);
	textures->Add(ID_TEX_BBOX, TEXTURE_PATH_BBOX);

	LPTEXTURE texMisc = textures->Get(ID_TEX_MISC);
	sprites->Add(ID_SPRITE_BRICK + 1, 239, 222, 239 + 15, 222 + 15, texMisc);	//Floor
	sprites->Add(ID_SPRITE_BRICK + 2, 290, 171, 290 + 15, 171 + 15, texMisc);	//Ground

	sprites->Add(ID_SPRITE_BRICK + 11, 1, 52, 1 + 15, 52 + 15, texMisc);	//PinkBlock
	sprites->Add(ID_SPRITE_BRICK + 12, 1, 69, 1 + 15, 69 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 13, 1, 86, 1 + 15, 86 + 15, texMisc);	

	sprites->Add(ID_SPRITE_BRICK + 14, 18, 52, 18 + 15, 52 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 15, 18, 69, 18 + 15, 69 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 16, 18, 86, 18 + 15, 86 + 15, texMisc);	

	sprites->Add(ID_SPRITE_BRICK + 17, 35, 52, 35 + 15, 52 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 18, 35, 69, 35 + 15, 69 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 19, 35, 86, 35 + 15, 86 + 15, texMisc);	

	sprites->Add(ID_SPRITE_BRICK + 20, 52, 52, 52 + 15, 52 + 15, texMisc);	//BlueBlock
	sprites->Add(ID_SPRITE_BRICK + 21, 52, 69, 52 + 15, 69 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 22, 52, 86, 52 + 15, 86 + 15, texMisc);	

	sprites->Add(ID_SPRITE_BRICK + 23, 69, 52, 69 + 15, 52 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 24, 69, 69, 69 + 15, 69 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 25, 69, 86, 69 + 15, 86 + 15, texMisc);	

	sprites->Add(ID_SPRITE_BRICK + 26, 86, 52, 86 + 15, 52 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 27, 86, 69, 86 + 15, 69 + 15, texMisc);	
	sprites->Add(ID_SPRITE_BRICK + 28, 86, 86, 86 + 15, 86 + 15, texMisc);	

	texMisc = textures->Get(ID_TEX_MISC_1);

	sprites->Add(ID_SPRITE_BRICK + 3, 137, 18, 137 + 15, 18 + 15, texMisc);		//Bush 1
	sprites->Add(ID_SPRITE_BRICK + 4, 138, 1, 138 + 15, 1 + 15, texMisc);		//Bush 2
	sprites->Add(ID_SPRITE_BRICK + 5, 137, 52, 137 + 15, 52 + 15, texMisc);		//Bush 3
	sprites->Add(ID_SPRITE_BRICK + 6, 154, 35, 154 + 15, 35 + 15, texMisc);		//Bush 4
	sprites->Add(ID_SPRITE_BRICK + 7, 137, 35, 137 + 15, 35 + 15, texMisc);		//Bush 5
	sprites->Add(ID_SPRITE_BRICK + 8, 154, 18, 154 + 15, 18 + 15, texMisc);		//Bush 6
	sprites->Add(ID_SPRITE_BRICK + 9, 154, 1, 154 + 15, 1 + 15, texMisc);		//Bush 7
	sprites->Add(ID_SPRITE_BRICK + 10, 222, 205, 222 + 15, 205 + 15, texMisc);	//Grass

	sprites->Add(ID_SPRITE_BRICK + 29, 69, 103, 69 + 15, 103 + 15, texMisc);		//Shadow
	sprites->Add(ID_SPRITE_BRICK + 30, 86, 103, 86 + 15, 103 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 31, 103, 103, 103 + 15, 103 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 32, 103, 86, 103 + 15, 86 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 33, 103, 69, 103 + 15, 69 + 15, texMisc);


	//-----------------------------------------------
	LPANIMATION ani;

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 1);
	animations->Add(ID_ANI_BRICK + 1, ani);		//Floor
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 2);
	animations->Add(ID_ANI_BRICK + 2, ani);		//Ground

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 3);
	animations->Add(ID_ANI_BG + 1, ani);		//Bush 1
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 4);
	animations->Add(ID_ANI_BG + 2, ani);		//Bush 2
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 5);
	animations->Add(ID_ANI_BG + 3, ani);		//Bush 3
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 6);
	animations->Add(ID_ANI_BG + 4, ani);		//Bush 4
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 7);
	animations->Add(ID_ANI_BG + 5, ani);		//Bush 5
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 8);
	animations->Add(ID_ANI_BG + 6, ani);		//Bush 6
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 9);
	animations->Add(ID_ANI_BG + 7, ani);		//Bush 7

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 10);
	animations->Add(ID_ANI_BG + 8, ani);		//Grass

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 11);
	animations->Add(ID_ANI_TOP_BRICK + 1, ani);		//Pink 1
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 12);
	animations->Add(ID_ANI_BG + 9, ani);			//Pink 2
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 13);
	animations->Add(ID_ANI_BG + 10, ani);			//Pink 3
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 14);
	animations->Add(ID_ANI_TOP_BRICK + 2, ani);		//Pink 4
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 15);
	animations->Add(ID_ANI_BG + 11, ani);			//Pink 5
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 16);
	animations->Add(ID_ANI_BG + 12, ani);			//Pink 6
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 17);
	animations->Add(ID_ANI_TOP_BRICK + 3, ani);		//Pink 7
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 18);
	animations->Add(ID_ANI_BG + 13, ani);			//Pink 8
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 19);
	animations->Add(ID_ANI_BG + 14, ani);			//Pink 9

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 20);
	animations->Add(ID_ANI_TOP_BRICK + 4, ani);		//Pink 1
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 21);
	animations->Add(ID_ANI_BG + 15, ani);			//Pink 2
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 22);
	animations->Add(ID_ANI_BG + 16, ani);			//Pink 3
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 23);
	animations->Add(ID_ANI_TOP_BRICK + 5, ani);		//Pink 4
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 24);
	animations->Add(ID_ANI_BG + 17, ani);			//Pink 5
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 25);
	animations->Add(ID_ANI_BG + 18, ani);			//Pink 6
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 26);
	animations->Add(ID_ANI_TOP_BRICK + 6, ani);		//Pink 7
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 27);
	animations->Add(ID_ANI_BG + 19, ani);			//Pink 8
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 28);
	animations->Add(ID_ANI_BG + 20, ani);			//Pink 9

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 29);
	animations->Add(ID_ANI_BG + 21, ani);			//Shadow 1
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 30);
	animations->Add(ID_ANI_BG + 22, ani);			//Shadow 2
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 31);
	animations->Add(ID_ANI_BG + 23, ani);			//Shadow 3
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 32);
	animations->Add(ID_ANI_BG + 24, ani);			//Shadow 4
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 33);
	animations->Add(ID_ANI_BG + 25, ani);			//Shadow 5
	list<LPGAMEOBJECT>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++)
	{
		delete (*it);
	}
	objects.clear();

	// Main floor
	for (int i = 0; i < 50; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 40; i++)
	{
		CBrick* b = new CBrick((i + 50) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 2);
		objects.push_back(b);
	}
	for (int i = 0; i < 40; i++)
	{
		CBrick* b = new CBrick((i + 50) * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 24; i++)
	{
		CBrick* b = new CBrick((i + 93) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 5; i++)
	{
		CBrick* b = new CBrick((i + 119) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 35; i++)
	{
		CBrick* b = new CBrick((i + 126) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 40; i++)
	{
		CBrick* b = new CBrick((i + 162) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	//Bush
	CBrick* bush = new CBrick(2 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 1);
	objects.push_back(bush);

	bush = new CBrick(2 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f*2, ID_ANI_BG + 1);
	objects.push_back(bush);

	bush = new CBrick(2 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(bush);

	bush = new CBrick(3 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(bush);

	bush = new CBrick(3 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(bush);

	bush = new CBrick(3 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 5);
	objects.push_back(bush);

	bush = new CBrick(3 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 2);
	objects.push_back(bush);

	bush = new CBrick(4 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(bush);

	bush = new CBrick(4 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 5);
	objects.push_back(bush);

	bush = new CBrick(4 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 6);
	objects.push_back(bush);

	bush = new CBrick(4 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 7);
	objects.push_back(bush);

	bush = new CBrick(5 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(bush);

	bush = new CBrick(5 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 3);
	objects.push_back(bush);

	bush = new CBrick(5 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(bush);

	bush = new CBrick(6 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 4);
	objects.push_back(bush);

	bush = new CBrick(6 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 6);
	objects.push_back(bush);

	bush = new CBrick(6 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(bush);

	bush = new CBrick(7 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 5);
	objects.push_back(bush);

	bush = new CBrick(7 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(bush);

	bush = new CBrick(7 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(bush);

	bush = new CBrick(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(bush);

	bush = new CBrick(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(bush);

	bush = new CBrick(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(bush);

	bush = new CBrick(9 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 6);
	objects.push_back(bush);

	bush = new CBrick(9 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 7);
	objects.push_back(bush);
	
	//Grass
	bush = new CBrick(12 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(bush);
	bush = new CBrick(13 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(bush);
	bush = new CBrick(14 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(bush);

	//Pink block
	
	bush = new CBrick(17 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 1);
	objects.push_back(bush);
	bush = new CBrick(17 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 9);
	objects.push_back(bush);
	bush = new CBrick(17 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 10);
	objects.push_back(bush);

	bush = new CBrick(18 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 2);
	objects.push_back(bush);
	bush = new CBrick(18 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 11);
	objects.push_back(bush);
	bush = new CBrick(18 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 12);
	objects.push_back(bush);

	bush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 3);
	objects.push_back(bush);
	bush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 13);
	objects.push_back(bush);
	bush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 14);
	objects.push_back(bush);

	//Blue block

	bush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 4);
	objects.push_back(bush);
	bush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 15);
	objects.push_back(bush);

	bush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 5);
	objects.push_back(bush);
	bush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 17);
	objects.push_back(bush);
	bush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 17);
	objects.push_back(bush);
	bush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 17);
	objects.push_back(bush);
	bush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 18);
	objects.push_back(bush);

	bush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 6);
	objects.push_back(bush);
	bush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 19);
	objects.push_back(bush);
	bush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 19);
	objects.push_back(bush);
	bush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 19);
	objects.push_back(bush);
	bush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 20);
	objects.push_back(bush);

	//Shadow for pink block

	bush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 25);
	objects.push_back(bush);
	bush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(bush);
	bush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(bush);

	//Shadow for blue block

	bush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 25);
	objects.push_back(bush);
	bush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 24);
	objects.push_back(bush);
	bush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 24);
	objects.push_back(bush);
	bush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(bush);
	bush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(bush);

	mario = new CMario(MARIO_START_X, MARIO_START_Y);
	objects.push_back(mario);

	InitLoop();

}

GameLoop::~GameLoop()
{

}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
bool IsGameObjectDeleted(const LPGAMEOBJECT& o) { return o == NULL; }
void GameLoop::Update(DWORD dt)
{
	vector<LPGAMEOBJECT> coObjects;
	list<LPGAMEOBJECT>::iterator i;
	for (i = objects.begin(); i != objects.end(); ++i)
	{
		coObjects.push_back(*i);
	}

	for (i = objects.begin(); i != objects.end(); ++i)
	{
		(*i)->Update(dt, &coObjects);
	}

	list<LPGAMEOBJECT>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++)
	{
		LPGAMEOBJECT o = *it;
		if (o->IsDeleted())
		{
			delete o;
			*it = NULL;
		}
	}
	objects.erase(
		std::remove_if(objects.begin(), objects.end(), IsGameObjectDeleted),
		objects.end());

	// Update camera to follow mario
	float cx, cy;
	mario->GetPosition(cx, cy);

	cx -= SCREEN_WIDTH / 2;
	cy -= SCREEN_HEIGHT / 2;

	if (cx < 0) cx = 0;
	if (cy > 0) cy = 0;
	CGame::GetInstance()->SetCamPos(cx, cy);
}

/*
	Render a frame
*/
void GameLoop::Render()
{
	CGame* g = CGame::GetInstance();

	ID3D10Device* pD3DDevice = g->GetDirect3DDevice();
	IDXGISwapChain* pSwapChain = g->GetSwapChain();
	ID3D10RenderTargetView* pRenderTargetView = g->GetRenderTargetView();
	ID3DX10Sprite* spriteHandler = g->GetSpriteHandler();

	pD3DDevice->ClearRenderTargetView(pRenderTargetView, BACKGROUND_COLOR);

	spriteHandler->Begin(D3DX10_SPRITE_SORT_TEXTURE);

	FLOAT NewBlendFactor[4] = { 0,0,0,0 };
	pD3DDevice->OMSetBlendState(g->GetAlphaBlending(), NewBlendFactor, 0xffffffff);

	list<LPGAMEOBJECT>::iterator i;
	for (i = objects.begin(); i != objects.end(); ++i)
	{
		(*i)->Render();
	}

	spriteHandler->End();
	pSwapChain->Present(0, 0);
}

void GameLoop::InitLoop()
{
	MSG msg;
	int done = 0;
	ULONGLONG frameStart = GetTickCount64();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		ULONGLONG now = GetTickCount64();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = (DWORD)(now - frameStart);

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			game->ProcessKeyboard();
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}
}