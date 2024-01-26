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
#include "Goomba.h"
#include "Turtle.h"
#include "Eater.h"
#include "GreenEater.h"
#include "GreenTurtle.h"
#include "Piranha.h"
#include "Bullet.h"
#include "Button.h"
#include "Star.h"

#include "SampleKeyHandler.h"

#include "AssetIDs.h"

#include "HUD.h"
#include "Map.h"
#include "Map1.h"
#include "Map2.h"

#define BRICK_Y 160.0f + 36.0f

#define WINDOW_ICON_PATH L"mario.ico"

#define BACKGROUND_COLOR D3DXCOLOR(100.0f/255, 144.0f/255, 192.0f/255, 0.0f)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 320

CGame* game;
int cameraStatus = 0;

GameLoop::GameLoop(HWND hWnd)
{
	game = CGame::GetInstance();
	CTextures* textures = CTextures::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	game->Load(L"mario-sample.txt");

	InitLoop();

}

GameLoop::~GameLoop()
{

}

void GameLoop::Update(DWORD dt)
{
	CGame::GetInstance()->GetCurrentScene()->Update(dt);
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

	CGame::GetInstance()->GetCurrentScene()->Render();

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
			CMario* mario = CMario::GetInstance(1,1);
			if (mario->getGo() == 0) game->ProcessKeyboard();
			Update(dt);
			Render();

			CGame::GetInstance()->SwitchScene();
		}
		else
			Sleep(tickPerFrame - dt);
	}
}