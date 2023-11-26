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
#include "Coin.h"
#include "Box.h"

#include "SampleKeyHandler.h"

#include "AssetIDs.h"

#include "Map.h"

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
#define TEXTURE_PATH_2_MISC TEXTURES_DIR "\\misc_transparent.png"
#define TEXTURE_PATH_BBOX TEXTURES_DIR "\\bbox.png"

#define MARIO_START_X 20.0f
#define MARIO_START_Y 10.0f

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
	textures->Add(ID_TEX_MISC_2, TEXTURE_PATH_2_MISC);
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

	sprites->Add(ID_SPRITE_BRICK + 38, 52, 1, 52 + 15, 1 + 15, texMisc);	//GreenBlock
	sprites->Add(ID_SPRITE_BRICK + 39, 52, 18, 52 + 15, 18 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 40, 52, 35, 52 + 15, 35 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 41, 69, 1, 69 + 15, 1 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 42, 69, 18, 69 + 15, 18 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 43, 69, 35, 69 + 15, 35 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 44, 86, 1, 86 + 15, 1 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 45, 86, 18, 86 + 15, 18 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 46, 86, 35, 86 + 15, 35 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 47, 1, 1, 1 + 15, 1 + 15, texMisc);	//WhiteBlock
	sprites->Add(ID_SPRITE_BRICK + 48, 1, 18, 1 + 15, 18 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 49, 1, 35, 1 + 15, 35 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 50, 18, 1, 18 + 15, 1 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 51, 18, 18, 18 + 15, 18 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 52, 18, 35, 18 + 15, 35 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 53, 35, 1, 35 + 15, 1 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 54, 35, 18, 35 + 15, 18 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 55, 35, 35, 35 + 15, 35 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 56, 324, 171, 324 + 15, 171 + 15, texMisc);		//Brick 1
	sprites->Add(ID_SPRITE_BRICK + 57, 273, 154, 273 + 15, 154 + 15, texMisc);		//Brick 2

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

	sprites->Add(ID_SPRITE_BRICK + 34, 324, 52, 324 + 15, 52 + 15, texMisc);	//Sewer
	sprites->Add(ID_SPRITE_BRICK + 35, 341, 52, 341 + 15, 52 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 36, 324, 69, 324 + 15, 69 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 37, 341, 69, 341 + 15, 69 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 58, 222, 188, 222 + 15, 188 + 15, texMisc);		//Cloud

	sprites->Add(ID_SPRITE_BRICK + 59, 103, 52, 103 + 15, 52 + 15, texMisc);		//Black bg
	sprites->Add(ID_SPRITE_BRICK + 60, 120, 52, 120 + 15, 52 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 61, 103, 1, 103 + 15, 1 + 15, texMisc);		//Black obj
	sprites->Add(ID_SPRITE_BRICK + 62, 103, 18, 103 + 15, 18 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 63, 120, 1, 120 + 15, 1 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 64, 120, 18, 120 + 15, 18 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 65, 137, 86, 137 + 15, 86 + 15, texMisc);		//Black spuare
	sprites->Add(ID_SPRITE_BRICK + 66, 137, 103, 137 + 15, 103 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 67, 154, 86, 154 + 15, 86 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 68, 154, 103, 154 + 15, 103 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 69, 460, 256, 460 + 15, 256 + 15, texMisc);		//Blocker

	texMisc = textures->Get(ID_TEX_MISC_2);

	sprites->Add(ID_SPRITE_BRICK + 70, 303, 99, 303 + 10, 99 + 15, texMisc);		//Coin
	sprites->Add(ID_SPRITE_BRICK + 71, 321, 99, 321 + 10, 99 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 72, 339, 99, 339 + 10, 99 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 73, 300, 117, 300 + 15, 117 + 15, texMisc);		//Box
	sprites->Add(ID_SPRITE_BRICK + 74, 318, 117, 318 + 15, 117 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 75, 336, 117, 336 + 15, 117 + 15, texMisc);
	sprites->Add(ID_SPRITE_BRICK + 76, 354, 117, 354 + 15, 117 + 15, texMisc);

	sprites->Add(ID_SPRITE_BRICK + 77, 372, 117, 372 + 15, 117 + 15, texMisc);

	//-----------------------------------------------
	CMap* map = new CMap(1,1);
	objects = map->objects;
	//------------------------------------
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

void GameLoop::UpdateObj(LPGAMEOBJECT& o)
{
	objects.push_back(o);
}

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