#include "GameLoop.h"

CMario* mario;
#define MARIO_START_X 10.0f
#define MARIO_START_Y 100.0f
#define MARIO_START_VX 0.1f
#define MARIO_START_VY 0.1f


CBrick* brick;
#define BRICK_X 10.0f
#define BRICK_Y 120.0f

LPTEXTURE texMario = NULL;
LPTEXTURE texBrick = NULL;
LPTEXTURE texMisc = NULL;

#define BACKGROUND_COLOR D3DXCOLOR(0.5f, 0.5f, 0.5f, 0.0f)

#define TEXTURE_PATH_BRICK L"C:\\Code\\Mario\\Mario\\Resource\\brick.png"
#define TEXTURE_PATH_MARIO L"C:\\Code\\Mario\\Mario\\Resource\\mario.png"

#define TEXTURE_PATH_MISC L"C:\\Code\\Mario\\Mario\\Resource\\misc.png"

/*
	Constructor load all game resources. Then create game loop
*/

GameLoop::GameLoop(HWND hWnd)
{
	CGame* game = CGame::GetInstance();
	game->Init(hWnd);

	texBrick = game->LoadTexture(TEXTURE_PATH_BRICK);
	texMario = game->LoadTexture(TEXTURE_PATH_MARIO);
	texMisc = game->LoadTexture(TEXTURE_PATH_MISC);

	// Load a sprite sheet as a texture to try drawing a portion of a texture. See function Render 
	//texMisc = game->LoadTexture(MISC_TEXTURE_PATH);

	mario = new CMario(MARIO_START_X, MARIO_START_Y, MARIO_START_VX, MARIO_START_VY, texMario);
	brick = new CBrick(BRICK_X, BRICK_Y, texBrick);

	InitLoop();

}

GameLoop::~GameLoop()
{

}

/*
	Update world status for this frame
	dt: time period between beginning of last frame and beginning of this frame
*/
void GameLoop::Update(DWORD dt)
{
	mario->Update(dt);
	brick->Update(dt);
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

	if (pD3DDevice != NULL)
	{
		// clear the background 
		pD3DDevice->ClearRenderTargetView(pRenderTargetView, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DX10_SPRITE_SORT_TEXTURE);

		// Use Alpha blending for transparent sprites
		FLOAT NewBlendFactor[4] = { 0,0,0,0 };
		pD3DDevice->OMSetBlendState(g->GetAlphaBlending(), NewBlendFactor, 0xffffffff);

		brick->Render();
		mario->Render();

		// Uncomment this line to see how to draw a porttion of a texture  
		//g->Draw(10, 10, texMisc, 300, 117, 317, 134);
		//g->Draw(10, 10, texMario, 215, 120, 234, 137);

		spriteHandler->End();
		pSwapChain->Present(0, 0);
	}
}

void GameLoop::InitLoop()
{
	MSG msg;
	int done = 0;
	ULONGLONG frameStart = GetTickCount64();
	ULONGLONG tickPerFrame = 1000 / MAX_FRAME_RATE;

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
		ULONGLONG dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;
			Update((DWORD)dt);
			Render();
		}
		else
			Sleep((DWORD)(tickPerFrame - dt));
	}

}