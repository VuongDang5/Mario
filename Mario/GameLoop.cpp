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

	texMisc = textures->Get(ID_TEX_MISC_1);

	LPANIMATION ani;
	sprites->Add(ID_SPRITE_BRICK + 3, 137, 18, 137 + 15, 18 + 15, texMisc);		//Bush 1
	sprites->Add(ID_SPRITE_BRICK + 4, 138, 1, 138 + 15, 1 + 15, texMisc);		//Bush 2
	sprites->Add(ID_SPRITE_BRICK + 5, 137, 52, 137 + 15, 52 + 15, texMisc);		//Bush 3

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