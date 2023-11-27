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
}


