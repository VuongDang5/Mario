#include "Map.h"

#include "Mario.h"
#include "Brick.h"
#include "Coin.h"
#include "Box.h"

#include "AssetIDs.h"

#define BRICK_X 0.0f
#define BRICK_Y GROUND_Y + 36.0f

CMap::CMap(float x, float y)
{
	CAnimations* animations = CAnimations::GetInstance();

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
	//------------------------------------
	list<LPGAMEOBJECT>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++)
	{
		delete (*it);
	}
	objects.clear();
	//Blocker
	for (int i = 0; i < 25; i++)
	{
		CBrick* b = new CBrick(0 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * i, ID_ANI_BRICK + 100);
		objects.push_back(b);
	}

	for (int i = 0; i < 300; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 25, ID_ANI_BRICK + 100);
		objects.push_back(b);
	}

	// Main floor
	for (int i = 0; i < 45; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 32; i++)
	{
		CBrick* b = new CBrick((i + 45) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 2);
		objects.push_back(b);
	}
	for (int i = 0; i < 32; i++)
	{
		CBrick* b = new CBrick((i + 45) * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 27; i++)
	{
		CBrick* b = new CBrick((i + 81) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 6; i++)
	{
		CBrick* b = new CBrick((i + 110) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 39; i++)
	{
		CBrick* b = new CBrick((i + 119) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	for (int i = 0; i < 100; i++)
	{
		CBrick* b = new CBrick((i + 159) * BRICK_WIDTH * 1.0f, BRICK_Y, ID_ANI_BRICK + 1);
		objects.push_back(b);
	}

	//Draw map 1-1
	CBrick* brush;

	//Bush 1
	brush = new CBrick(2 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(2 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(2 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(3 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(3 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(3 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(3 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(4 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(4 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(4 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(4 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(5 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(5 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(5 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(6 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(6 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(6 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(7 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(7 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(7 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(9 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(9 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 7);
	objects.push_back(brush);

	//Grass 1
	brush = new CBrick(12 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(13 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(14 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);

	//Pink block

	brush = new CBrick(17 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 1);
	objects.push_back(brush);
	brush = new CBrick(17 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 9);
	objects.push_back(brush);
	brush = new CBrick(17 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 10);
	objects.push_back(brush);

	brush = new CBrick(18 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(18 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(18 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 12);
	objects.push_back(brush);

	brush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 13);
	objects.push_back(brush);
	brush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 14);
	objects.push_back(brush);

	//Blue block

	brush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 4);
	objects.push_back(brush);
	brush = new CBrick(19 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 15);
	objects.push_back(brush);

	brush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 18);
	objects.push_back(brush);

	brush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 19);
	objects.push_back(brush);
	brush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 19);
	objects.push_back(brush);
	brush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 19);
	objects.push_back(brush);
	brush = new CBrick(21 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 20);
	objects.push_back(brush);

	//Shadow block 1

	brush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(20 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	brush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(22 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	//Sewer

	brush = new CBrick(25 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(25 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(25 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(26 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 4);
	objects.push_back(brush);
	brush = new CBrick(26 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(26 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 6);
	objects.push_back(brush);

	//Green block

	brush = new CBrick(29 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(29 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 26);
	objects.push_back(brush);
	brush = new CBrick(29 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 27);
	objects.push_back(brush);

	brush = new CBrick(30 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(30 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(30 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(31 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(31 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(31 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(32 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 9);
	objects.push_back(brush);
	brush = new CBrick(32 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(32 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 31);
	objects.push_back(brush);

	//Pink block

	brush = new CBrick(32 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 1);
	objects.push_back(brush);
	brush = new CBrick(32 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 9);
	objects.push_back(brush);

	brush = new CBrick(33 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(33 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(33 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(33 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(33 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 12);
	objects.push_back(brush);

	brush = new CBrick(34 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 1);
	objects.push_back(brush);
	brush = new CBrick(34 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 9);
	objects.push_back(brush);

	brush = new CBrick(34 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(34 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(34 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(34 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(34 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 12);
	objects.push_back(brush);

	brush = new CBrick(35 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_TOP_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(35 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 13);
	objects.push_back(brush);
	brush = new CBrick(35 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 13);
	objects.push_back(brush);

	//Green block

	brush = new CBrick(35 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(35 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 27);
	objects.push_back(brush);

	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(37 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(37 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(38 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(38 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(39 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(39 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(40 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(40 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(41 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 9);
	objects.push_back(brush);
	brush = new CBrick(41 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 31);
	objects.push_back(brush);

	//White block

	brush = new CBrick(35 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_TOP_BRICK + 10);
	objects.push_back(brush);
	brush = new CBrick(35 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 32);
	objects.push_back(brush);

	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_TOP_BRICK + 11);
	objects.push_back(brush);
	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 34);
	objects.push_back(brush);
	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 34);
	objects.push_back(brush);
	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 34);
	objects.push_back(brush);
	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 34);
	objects.push_back(brush);

	brush = new CBrick(37 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_TOP_BRICK + 11);
	objects.push_back(brush);
	brush = new CBrick(37 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 34);
	objects.push_back(brush);
	brush = new CBrick(37 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 34);
	objects.push_back(brush);
	brush = new CBrick(37 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 34);
	objects.push_back(brush);
	brush = new CBrick(37 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 34);
	objects.push_back(brush);

	brush = new CBrick(38 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_TOP_BRICK + 12);
	objects.push_back(brush);
	brush = new CBrick(38 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 36);
	objects.push_back(brush);
	brush = new CBrick(38 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 36);
	objects.push_back(brush);
	brush = new CBrick(38 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 36);
	objects.push_back(brush);
	brush = new CBrick(38 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 36);
	objects.push_back(brush);

	//Shadow block 2

	brush = new CBrick(33 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(33 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(33 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(36 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 24);
	objects.push_back(brush);

	brush = new CBrick(39 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(39 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(39 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(39 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(39 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 24);
	objects.push_back(brush);

	brush = new CBrick(42 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(42 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	//Grass 2
	brush = new CBrick(49 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(50 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(51 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(52 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(53 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(54 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);

	//Bush 2

	brush = new CBrick(58 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(58 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(58 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(59 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(59 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(59 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(59 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 12.0f - 16.0f * 4, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(60 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(60 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(60 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(60 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 4, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(61 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(61 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(61 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(62 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(62 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(62 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(63 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(63 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(63 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(64 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(64 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(64 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(65 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(65 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(66 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(67 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(67 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(67 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(68 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(68 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(68 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(69 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(69 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 2, ID_ANI_BG + 7);
	objects.push_back(brush);

	//Grass 3

	brush = new CBrick(73 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(74 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);

	//Grass 4

	brush = new CBrick(83 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(84 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(85 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);

	//Green block

	brush = new CBrick(88 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(88 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 27);
	objects.push_back(brush);

	brush = new CBrick(89 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(89 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(90 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(90 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(91 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(91 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_TOP_BRICK + 9);
	objects.push_back(brush);
	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 31);
	objects.push_back(brush);

	//Pink block

	brush = new CBrick(90 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_TOP_BRICK + 1);
	objects.push_back(brush);
	brush = new CBrick(90 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 9);
	objects.push_back(brush);

	brush = new CBrick(91 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(91 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 11);
	objects.push_back(brush);

	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 11);
	objects.push_back(brush);

	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 11);
	objects.push_back(brush);

	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 11);
	objects.push_back(brush);

	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 12);
	objects.push_back(brush);

	brush = new CBrick(96 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(96 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(96 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(96 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 12);
	objects.push_back(brush);

	brush = new CBrick(97 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_TOP_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(97 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 13);
	objects.push_back(brush);
	brush = new CBrick(97 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 13);
	objects.push_back(brush);
	brush = new CBrick(97 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 14);
	objects.push_back(brush);

	//Blue block

	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 4);
	objects.push_back(brush);
	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 15);
	objects.push_back(brush);

	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 17);
	objects.push_back(brush);

	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 17);
	objects.push_back(brush);

	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 17);
	objects.push_back(brush);

	brush = new CBrick(96 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(96 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 17);
	objects.push_back(brush);

	brush = new CBrick(97 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(97 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 17);
	objects.push_back(brush);

	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 18);
	objects.push_back(brush);

	brush = new CBrick(99 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(99 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(99 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(99 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(99 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 17);
	objects.push_back(brush);
	brush = new CBrick(99 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 18);
	objects.push_back(brush);

	brush = new CBrick(100 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_TOP_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(100 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 19);
	objects.push_back(brush);
	brush = new CBrick(100 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 19);
	objects.push_back(brush);
	brush = new CBrick(100 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 19);
	objects.push_back(brush);
	brush = new CBrick(100 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 19);
	objects.push_back(brush);
	brush = new CBrick(100 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 20);
	objects.push_back(brush);

	//Shadow block 2

	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	brush = new CBrick(101 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(101 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(101 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(101 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(101 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(101 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	//Brick 1
	brush = new CBrick(108 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(109 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BRICK + 7);
	objects.push_back(brush);

	//Brick 1
	brush = new CBrick(113 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 7);
	objects.push_back(brush);

	brush = new CBrick(114 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(114 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 7);
	objects.push_back(brush);

	brush = new CBrick(115 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(115 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(115 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 7);
	objects.push_back(brush);

	//Brick 1
	brush = new CBrick(121 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 7);
	objects.push_back(brush);

	brush = new CBrick(120 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(120 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 7);
	objects.push_back(brush);

	brush = new CBrick(119 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(119 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(119 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 7);
	objects.push_back(brush);

	//Grass 5
	brush = new CBrick(124 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(125 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);
	brush = new CBrick(126 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 8);
	objects.push_back(brush);

	//Sewer
	brush = new CBrick(129 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(129 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 5);
	objects.push_back(brush);

	brush = new CBrick(130 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 4);
	objects.push_back(brush);
	brush = new CBrick(130 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 6);
	objects.push_back(brush);

	//Sewer
	brush = new CBrick(135 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(135 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(135 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 5);
	objects.push_back(brush);

	brush = new CBrick(136 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 4);
	objects.push_back(brush);
	brush = new CBrick(136 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(136 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 6);
	objects.push_back(brush);

	//Bush 3
	brush = new CBrick(137 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(138 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(138 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(138 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(139 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(139 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(139 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(140 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(140 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 7);
	objects.push_back(brush);

	//Brick 2
	brush = new CBrick(141 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 8);
	objects.push_back(brush);

	brush = new CBrick(142 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(142 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 8);
	objects.push_back(brush);

	brush = new CBrick(143 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(143 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(143 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 8);
	objects.push_back(brush);

	brush = new CBrick(144 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(144 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(144 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 8);
	objects.push_back(brush);

	brush = new CBrick(145 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(145 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(145 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 8);
	objects.push_back(brush);

	brush = new CBrick(146 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 8);
	objects.push_back(brush);

	brush = new CBrick(149 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(149 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 8);
	objects.push_back(brush);

	brush = new CBrick(150 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 8);
	objects.push_back(brush);

	//Pink block

	brush = new CBrick(152 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 1);
	objects.push_back(brush);
	brush = new CBrick(152 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 9);
	objects.push_back(brush);
	brush = new CBrick(152 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 10);
	objects.push_back(brush);

	brush = new CBrick(153 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(153 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 11);
	objects.push_back(brush);
	brush = new CBrick(153 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 12);
	objects.push_back(brush);

	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_TOP_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 13);
	objects.push_back(brush);
	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 14);
	objects.push_back(brush);

	//Green block

	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10, ID_ANI_TOP_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 9, ID_ANI_BG + 26);
	objects.push_back(brush);
	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 8, ID_ANI_BG + 26);
	objects.push_back(brush);
	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_BG + 26);
	objects.push_back(brush);
	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 26);
	objects.push_back(brush);
	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 26);
	objects.push_back(brush);
	brush = new CBrick(154 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 26);
	objects.push_back(brush);

	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10, ID_ANI_TOP_BRICK + 8);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 9, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 8, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 28);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 29);
	objects.push_back(brush);

	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10, ID_ANI_TOP_BRICK + 9);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 9, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 8, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 30);
	objects.push_back(brush);
	brush = new CBrick(156 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 31);
	objects.push_back(brush);

	//Shadow block 3

	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(155 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 9, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 8, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(157 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 24);
	objects.push_back(brush);

	//Sewer
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 18, ID_ANI_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 17, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 16, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 15, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 14, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 13, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 12, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 11, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 9, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 8, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 5);
	objects.push_back(brush);
	brush = new CBrick(159 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 5);
	objects.push_back(brush);

	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 18, ID_ANI_BRICK + 4);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 17, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 16, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 15, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 14, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 13, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 12, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 11, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 9, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 8, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 7);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 6);
	objects.push_back(brush);
	brush = new CBrick(160 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 6);
	objects.push_back(brush);

	//Sewer
	brush = new CBrick(163 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(163 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 5);
	objects.push_back(brush);

	brush = new CBrick(164 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 4);
	objects.push_back(brush);
	brush = new CBrick(164 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BRICK + 6);
	objects.push_back(brush);

	//Bush 4
	brush = new CBrick(166 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(166 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(166 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(167 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(167 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(167 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(167 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(168 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(168 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(168 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(168 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(169 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(169 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(169 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(170 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(170 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(170 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(171 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 5);
	objects.push_back(brush);
	brush = new CBrick(171 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 1);
	objects.push_back(brush);
	brush = new CBrick(171 * BRICK_WIDTH * 1.0f + 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 2);
	objects.push_back(brush);

	brush = new CBrick(172 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 3);
	objects.push_back(brush);
	brush = new CBrick(172 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 4);
	objects.push_back(brush);
	brush = new CBrick(172 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 7);
	objects.push_back(brush);

	brush = new CBrick(173 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 6);
	objects.push_back(brush);
	brush = new CBrick(173 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 7);
	objects.push_back(brush);

	//Airial obljects
	//Pink block

	brush = new CBrick(91 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 17, ID_ANI_TOP_BRICK + 1);
	objects.push_back(brush);
	brush = new CBrick(91 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 16, ID_ANI_BG + 10);
	objects.push_back(brush);

	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 17, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 16, ID_ANI_BG + 12);
	objects.push_back(brush);

	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 17, ID_ANI_TOP_BRICK + 2);
	objects.push_back(brush);
	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 16, ID_ANI_BG + 12);
	objects.push_back(brush);

	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 17, ID_ANI_TOP_BRICK + 3);
	objects.push_back(brush);
	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 16, ID_ANI_BG + 14);
	objects.push_back(brush);

	//Shadow 
	brush = new CBrick(91 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 15, ID_ANI_BG + 21);
	objects.push_back(brush);

	brush = new CBrick(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 15, ID_ANI_BG + 22);
	objects.push_back(brush);

	brush = new CBrick(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 15, ID_ANI_BG + 22);
	objects.push_back(brush);

	brush = new CBrick(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 15, ID_ANI_BG + 22);
	objects.push_back(brush);

	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 17, ID_ANI_BG + 25);
	objects.push_back(brush);
	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 16, ID_ANI_BG + 24);
	objects.push_back(brush);
	brush = new CBrick(95 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 15, ID_ANI_BG + 23);
	objects.push_back(brush);

	//Cloud
	for (int i = 0; i < 4; i++)
	{
		CBrick* b = new CBrick((i + 97) * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 14, ID_ANI_BRICK + 9);
		objects.push_back(b);
	}

	for (int i = 0; i < 12; i++)
	{
		CBrick* b = new CBrick((i + 102) * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 15, ID_ANI_BRICK + 9);
		objects.push_back(b);
	}

	// Black BG

	for (int i = 1; i < 40; i++)
	{
		CBrick* b = new CBrick(175 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * i, ID_ANI_BG + 38);
		objects.push_back(b);
	}

	for (int i = 1; i < 40; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			CBrick* b = new CBrick((176 + j) * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * i, ID_ANI_BG + 39);
			objects.push_back(b);
		}
	}

	//Black tree
	brush = new CBrick(180 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 40);
	objects.push_back(brush);

	brush = new CBrick(181 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 40);
	objects.push_back(brush);
	brush = new CBrick(181 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 41);
	objects.push_back(brush);
	brush = new CBrick(181 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 41);
	objects.push_back(brush);
	brush = new CBrick(181 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 41);
	objects.push_back(brush);
	brush = new CBrick(181 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 41);
	objects.push_back(brush);
	brush = new CBrick(181 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 42);
	objects.push_back(brush);

	brush = new CBrick(182 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 42);
	objects.push_back(brush);
	brush = new CBrick(182 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 43);
	objects.push_back(brush);
	brush = new CBrick(182 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 40);
	objects.push_back(brush);

	brush = new CBrick(183 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4, ID_ANI_BG + 42);
	objects.push_back(brush);
	brush = new CBrick(183 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 43);
	objects.push_back(brush);
	brush = new CBrick(183 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 40);
	objects.push_back(brush);

	brush = new CBrick(184 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 42);
	objects.push_back(brush);
	brush = new CBrick(184 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 43);
	objects.push_back(brush);

	//Black square

	brush = new CBrick(188 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 44);
	objects.push_back(brush);
	brush = new CBrick(188 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 45);
	objects.push_back(brush);

	brush = new CBrick(189 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6, ID_ANI_BG + 46);
	objects.push_back(brush);
	brush = new CBrick(189 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5, ID_ANI_BG + 47);
	objects.push_back(brush);

	//Black Tree

	brush = new CBrick(193 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 40);
	objects.push_back(brush);

	brush = new CBrick(194 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 40);
	objects.push_back(brush);
	brush = new CBrick(194 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 41);
	objects.push_back(brush);
	brush = new CBrick(194 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 42);
	objects.push_back(brush);

	brush = new CBrick(195 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3, ID_ANI_BG + 42);
	objects.push_back(brush);
	brush = new CBrick(195 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 2, ID_ANI_BG + 43);
	objects.push_back(brush);
	brush = new CBrick(195 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f, ID_ANI_BG + 43);
	objects.push_back(brush);

	//Coins
	CCoin* coin;
	coin = new CCoin(76 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6);
	objects.push_back(coin);
	coin = new CCoin(78 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 8);
	objects.push_back(coin);
	coin = new CCoin(80 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10);
	objects.push_back(coin);
	coin = new CCoin(82 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 12);
	objects.push_back(coin);
	coin = new CCoin(84 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 14);
	objects.push_back(coin);

	coin = new CCoin(92 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 22);
	objects.push_back(coin);
	coin = new CCoin(93 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 22);
	objects.push_back(coin);
	coin = new CCoin(94 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 22);
	objects.push_back(coin);

	coin = new CCoin(100 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 20);
	objects.push_back(coin);
	coin = new CCoin(101 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 20);
	objects.push_back(coin);

	coin = new CCoin(104 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 19);
	objects.push_back(coin);
	coin = new CCoin(105 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 19);
	objects.push_back(coin);
	coin = new CCoin(106 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 19);
	objects.push_back(coin);
	coin = new CCoin(107 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 19);
	objects.push_back(coin);

	coin = new CCoin(109 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 20);
	objects.push_back(coin);
	coin = new CCoin(110 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 20);
	objects.push_back(coin);
	coin = new CCoin(111 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 20);
	objects.push_back(coin);
	coin = new CCoin(112 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 20);
	objects.push_back(coin);

	coin = new CCoin(114 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 18);
	objects.push_back(coin);

	coin = new CCoin(116 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 20);
	objects.push_back(coin);

	coin = new CCoin(118 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 19);
	objects.push_back(coin);

	coin = new CCoin(121 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 21);
	objects.push_back(coin);

	coin = new CCoin(123 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 20);
	objects.push_back(coin);

	//Box
	CBox* box;
	box = new CBox(12 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4);
	objects.push_back(box);
	box = new CBox(13 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4);
	objects.push_back(box);

	box = new CBox(15 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7);
	objects.push_back(box);
	box = new CBox(16 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7);
	objects.push_back(box);

	box = new CBox(30 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6);
	objects.push_back(box);

	box = new CBox(48 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f);
	objects.push_back(box);
	box = new CBox(51 * BRICK_WIDTH * 1.0f, BRICK_Y - 12.0f - 16.0f * 3);
	objects.push_back(box);

	box = new CBox(98 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 19);
	objects.push_back(box);

	box = new CBox(105 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 3);
	objects.push_back(box);
}


