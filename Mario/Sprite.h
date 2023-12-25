#pragma once

#include "Texture.h"
#include "Game.h"

class CSprite
{
	int id;				// Sprite ID in the sprite database

	int left;
	int top;
	int right;
	int bottom;

	LPTEXTURE texture;
	D3DX10_SPRITE sprite;
	D3DXMATRIX matScaling;

	int flip = 1;
public:
	CSprite(int id, int left, int top, int right, int bottom, LPTEXTURE tex);

	void Draw(float x, float y);
	void isFlipped(int isFlipped);
};

typedef CSprite* LPSPRITE;