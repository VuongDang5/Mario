#include "Map2.h"

#include "Mario.h"
#include "Brick.h"
#include "Coin.h"
#include "Box.h"

#include "AssetIDs.h"

#define BRICK_X 0.0f
#define BRICK_Y GROUND_Y + 36.0f

void CMap2::LoadMap(float x, float y)
{
	// Main floor
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}

	for (int i = 0; i < 15; i++)
	{
		CBrick* b = new CBrick(BRICK_WIDTH, BRICK_Y - 16.0f * i, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 0; i < 15; i++)
	{
		CBrick* b = new CBrick(BRICK_WIDTH - 16.0f, BRICK_Y - 16.0f * i, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}

	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 12, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 13, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 14, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 15, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 16, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 17, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 18, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}

	for (int i = 9; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 1, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 10; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 2, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 11; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 3, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 12; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 4, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 13; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 5, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}
	for (int i = 14; i < 20; i++)
	{
		CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * 6, ID_ANI_BRICK + 11);
		objects.push_back(b);
	}

	for (int i = 17; i < 20; i++)
	{
		for (int j = 7; j < 12; j++)
		{
			CBrick* b = new CBrick(i * BRICK_WIDTH, BRICK_Y - 16.0f * j, ID_ANI_BRICK + 11);
			objects.push_back(b);
		}
	}

	//Coin
	CCoin* coin;
	coin = new CCoin(6 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 9);
	objects.push_back(coin);
	coin = new CCoin(7 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10);
	objects.push_back(coin);
	coin = new CCoin(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 10);
	objects.push_back(coin);
	coin = new CCoin(9 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 9);
	objects.push_back(coin);
	coin = new CCoin(9 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 8 + 2.0f);
	objects.push_back(coin);
	coin = new CCoin(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 7);
	objects.push_back(coin);
	coin = new CCoin(9 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 6);
	objects.push_back(coin);
	coin = new CCoin(9 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5 + 2.0f);
	objects.push_back(coin);
	coin = new CCoin(8 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4);
	objects.push_back(coin);
	coin = new CCoin(7 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 4);
	objects.push_back(coin);
	coin = new CCoin(6 * BRICK_WIDTH * 1.0f, BRICK_Y - 16.0f * 5);
	objects.push_back(coin);
}


