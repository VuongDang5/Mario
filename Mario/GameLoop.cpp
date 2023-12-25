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
#include "Bullet.h"

#include "SampleKeyHandler.h"

#include "AssetIDs.h"

#include "Map.h"
#include "Map1.h"
#include "Map2.h"

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"04 - Collision"
#define WINDOW_ICON_PATH L"mario.ico"

#define BACKGROUND_COLOR D3DXCOLOR(64.0f/255, 144.0f/255, 192.0f/255, 0.0f)
#define BACKGROUND_COLOR1 D3DXCOLOR(0.0f/255, 0.0f/255, 0.0f/255, 0.0f)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define TEXTURES_DIR L"C:\\Code\\Mario\\Mario\\Resource"
#define TEXTURE_PATH_MISC TEXTURES_DIR "\\tiles.png"
#define TEXTURE_PATH_1_MISC TEXTURES_DIR "\\tiles_transparent.png"
#define TEXTURE_PATH_ENEMY TEXTURES_DIR "\\enemies_transparent.png"
#define TEXTURE_PATH_ENEMY_0 TEXTURES_DIR "\\enemies_0.png"
#define TEXTURE_PATH_2_MISC TEXTURES_DIR "\\misc_transparent.png"
#define TEXTURE_PATH_BBOX TEXTURES_DIR "\\bbox.png"

#define MARIO_START_X 20.0f
#define MARIO_START_Y 10.0f

#define GOOMBA_X 200.0f


CGame* game;
CMario* mario;

list<LPGAMEOBJECT> objects;

CSampleKeyHandler* keyHandler;

void LoadAssetsBullet()
{
	CTextures* textures = CTextures::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texEnemy = textures->Get(ID_TEX_ENEMY_0);

	sprites->Add(ID_SPRITE_BULLET + 1, 164, 180, 164 + 7, 180 + 7, texEnemy);
	sprites->Add(ID_SPRITE_BULLET + 2, 180, 180, 180 + 7, 180 + 7, texEnemy);
	sprites->Add(ID_SPRITE_BULLET + 3, 164, 197, 164 + 7, 197 + 7, texEnemy);
	sprites->Add(ID_SPRITE_BULLET + 4, 180, 196, 180 + 7, 196 + 7, texEnemy);


	LPANIMATION ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BULLET + 1);
	ani->Add(ID_SPRITE_BULLET + 2);
	ani->Add(ID_SPRITE_BULLET + 3);
	ani->Add(ID_SPRITE_BULLET + 4);
	animations->Add(ID_ANI_BULLET, ani);
}

void LoadAssetsEater()
{
	CTextures* textures = CTextures::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texEnemy = textures->Get(ID_TEX_ENEMY_0);

	sprites->Add(ID_SPRITE_EATER + 1, 96, 145, 96 + 15, 145 + 30, texEnemy);
	sprites->Add(ID_SPRITE_EATER + 2, 112, 145, 112 + 15, 145 + 30, texEnemy);
	sprites->Add(ID_SPRITE_EATER + 3, 128, 145, 128 + 15, 145 + 30, texEnemy);
	sprites->Add(ID_SPRITE_EATER + 4, 144, 145, 144 + 15, 145 + 30, texEnemy);
	sprites->Add(ID_SPRITE_EATER + 5, 160, 145, 160 + 15, 145 + 30, texEnemy);
	sprites->Add(ID_SPRITE_EATER + 6, 176, 145, 176 + 15, 145 + 30, texEnemy);

	LPANIMATION ani = new CAnimation(100);
	ani->Add(ID_SPRITE_EATER + 1);
	ani->Add(ID_SPRITE_EATER + 2);
	animations->Add(ID_ANI_EATER_WALKING, ani);
	
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_EATER + 3);
	ani->Add(ID_SPRITE_EATER + 4,5000);
	animations->Add(ID_ANI_EATER_SHOOT_DOWN, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_EATER + 5);
	ani->Add(ID_SPRITE_EATER + 6, 5000);
	animations->Add(ID_ANI_EATER_SHOOT_UP, ani);

}

void LoadAssetsGoomba()
{
	CTextures* textures = CTextures::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texEnemy = textures->Get(ID_TEX_ENEMY);

	sprites->Add(ID_SPRITE_GOOMBA_WALK + 1, 4, 13, 22, 30, texEnemy);
	sprites->Add(ID_SPRITE_GOOMBA_WALK + 2, 24, 13, 42, 30, texEnemy);

	sprites->Add(ID_SPRITE_GOOMBA_DIE + 1, 44, 19, 62, 30, texEnemy);

	LPANIMATION ani = new CAnimation(100);
	ani->Add(ID_SPRITE_GOOMBA_WALK + 1);
	ani->Add(ID_SPRITE_GOOMBA_WALK + 2);
	animations->Add(ID_ANI_GOOMBA_WALKING, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_GOOMBA_DIE + 1);
	animations->Add(ID_ANI_GOOMBA_DIE, ani);

}

void LoadAssetsTurtle()
{
	CTextures* textures = CTextures::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	LPTEXTURE texEnemy = textures->Get(ID_TEX_ENEMY);

	sprites->Add(ID_SPRITE_TURTLE_WALK + 1, 6, 129, 6 + 16, 129 + 27, texEnemy);
	sprites->Add(ID_SPRITE_TURTLE_WALK + 2, 28, 129, 28 + 16, 129 + 27, texEnemy);

	sprites->Add(ID_SPRITE_TURTLE_DIE + 1, 71, 139, 71 + 18, 139 + 16, texEnemy);

	LPANIMATION ani = new CAnimation(100);
	ani->Add(ID_SPRITE_TURTLE_WALK + 1);
	ani->Add(ID_SPRITE_TURTLE_WALK + 2);
	animations->Add(ID_ANI_TURTLE_WALKING, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_TURTLE_DIE + 1);
	animations->Add(ID_ANI_TURTLE_DIE, ani);
}

GameLoop::GameLoop(HWND hWnd)
{
	game = CGame::GetInstance();
	CTextures* textures = CTextures::GetInstance();

	CSprites* sprites = CSprites::GetInstance();
	CAnimations* animations = CAnimations::GetInstance();

	textures->Add(ID_TEX_ENEMY, TEXTURE_PATH_ENEMY);
	textures->Add(ID_TEX_ENEMY_0, TEXTURE_PATH_ENEMY_0);
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

	sprites->Add(ID_SPRITE_BRICK + 78, 290, 188, 290 + 15, 188 + 15, texMisc);		//Blue Brick

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
	LPANIMATION ani;
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 69);
	animations->Add(ID_ANI_BRICK + 100, ani);		//Blocker

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
	animations->Add(ID_ANI_TOP_BRICK + 4, ani);		//Blue 1
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 21);
	animations->Add(ID_ANI_BG + 15, ani);			//Blue 2
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 22);
	animations->Add(ID_ANI_BG + 16, ani);			//Blue 3
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 23);
	animations->Add(ID_ANI_TOP_BRICK + 5, ani);		//Blue 4
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 24);
	animations->Add(ID_ANI_BG + 17, ani);			//Blue 5
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 25);
	animations->Add(ID_ANI_BG + 18, ani);			//Blue 6
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 26);
	animations->Add(ID_ANI_TOP_BRICK + 6, ani);		//Blue 7
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 27);
	animations->Add(ID_ANI_BG + 19, ani);			//Blue 8
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 28);
	animations->Add(ID_ANI_BG + 20, ani);			//Blue 9

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

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 34);
	animations->Add(ID_ANI_BRICK + 3, ani);			//Sewer 1
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 35);
	animations->Add(ID_ANI_BRICK + 4, ani);			//Sewer 2
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 36);
	animations->Add(ID_ANI_BRICK + 5, ani);			//Sewer 3
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 37);
	animations->Add(ID_ANI_BRICK + 6, ani);			//Sewer 4

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 38);
	animations->Add(ID_ANI_TOP_BRICK + 7, ani);		//Green 1
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 39);
	animations->Add(ID_ANI_BG + 26, ani);			//Green 2
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 40);
	animations->Add(ID_ANI_BG + 27, ani);			//Green 3
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 41);
	animations->Add(ID_ANI_TOP_BRICK + 8, ani);		//Green 4
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 42);
	animations->Add(ID_ANI_BG + 28, ani);			//Green 5
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 43);
	animations->Add(ID_ANI_BG + 29, ani);			//Green 6
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 44);
	animations->Add(ID_ANI_TOP_BRICK + 9, ani);		//Green 7
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 45);
	animations->Add(ID_ANI_BG + 30, ani);			//Green 8
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 46);
	animations->Add(ID_ANI_BG + 31, ani);			//Green 9

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 47);
	animations->Add(ID_ANI_TOP_BRICK + 10, ani);		//White 1
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 48);
	animations->Add(ID_ANI_BG + 32, ani);			//White 2
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 49);
	animations->Add(ID_ANI_BG + 33, ani);			//White 3
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 50);
	animations->Add(ID_ANI_TOP_BRICK + 11, ani);		//White 4
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 51);
	animations->Add(ID_ANI_BG + 34, ani);			//White 5
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 52);
	animations->Add(ID_ANI_BG + 35, ani);			//White 6
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 53);
	animations->Add(ID_ANI_TOP_BRICK + 12, ani);		//White 7
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 54);
	animations->Add(ID_ANI_BG + 36, ani);			//White 8
	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 55);
	animations->Add(ID_ANI_BG + 37, ani);			//White 9

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 56);
	animations->Add(ID_ANI_BRICK + 7, ani);			//Brick 1

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 57);
	animations->Add(ID_ANI_BRICK + 8, ani);			//Brick 2

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 58);
	animations->Add(ID_ANI_BRICK + 9, ani);			//Cloud

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 59);
	animations->Add(ID_ANI_BG + 38, ani);			//Black BG

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 60);
	animations->Add(ID_ANI_BG + 39, ani);			//Black BG

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 61);
	animations->Add(ID_ANI_BG + 40, ani);			//Black Tree

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 62);
	animations->Add(ID_ANI_BG + 41, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 63);
	animations->Add(ID_ANI_BG + 42, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 64);
	animations->Add(ID_ANI_BG + 43, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 65);
	animations->Add(ID_ANI_BG + 44, ani);			//Black Square

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 66);
	animations->Add(ID_ANI_BG + 45, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 67);
	animations->Add(ID_ANI_BG + 46, ani);

	ani = new CAnimation(100);
	ani->Add(ID_SPRITE_BRICK + 68);
	animations->Add(ID_ANI_BG + 47, ani);

	ani = new CAnimation(100);						//Coin
	ani->Add(ID_SPRITE_BRICK + 70);
	animations->Add(ID_ANI_COIN, ani);
	ani->Add(ID_SPRITE_BRICK + 71);
	animations->Add(ID_ANI_COIN, ani);
	ani->Add(ID_SPRITE_BRICK + 72);
	animations->Add(ID_ANI_COIN, ani);

	ani = new CAnimation(100);						//Box
	ani->Add(ID_SPRITE_BRICK + 73);
	animations->Add(ID_ANI_BOX, ani);
	ani->Add(ID_SPRITE_BRICK + 74);
	animations->Add(ID_ANI_BOX, ani);
	ani->Add(ID_SPRITE_BRICK + 75);
	animations->Add(ID_ANI_BOX, ani);
	ani->Add(ID_SPRITE_BRICK + 76);
	animations->Add(ID_ANI_BOX, ani);
	ani->Add(ID_SPRITE_BRICK + 73);
	animations->Add(ID_ANI_BOX, ani);

	ani = new CAnimation(100);						//Normal Box
	ani->Add(ID_SPRITE_BRICK + 77);
	animations->Add(ID_ANI_BRICK + 10, ani);

	ani = new CAnimation(100);						//Blue Brick
	ani->Add(ID_SPRITE_BRICK + 78);
	animations->Add(ID_ANI_BRICK + 11, ani);
	//------------------------------------
	list<LPGAMEOBJECT>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++)
	{
		delete (*it);
	}
	objects.clear();

	//------------------------------------
	LoadAssetsGoomba();
	LoadAssetsTurtle();
	LoadAssetsEater();
	LoadAssetsBullet();

	//------------------------------------
	CMap* map = new CMap1(1, 1);
	objects = map->objects;

	mario = mario->GetInstance(MARIO_START_X, MARIO_START_Y);
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