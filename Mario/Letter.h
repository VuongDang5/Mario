#pragma once
#include "GameObject.h"
#include "Sprites.h"
#include "Textures.h"
#include "Game.h"
#include "AssetIDs.h"
#include <string>

#define ID_TEXT_CHAR 110
#define NUM_OF_LETTER 26
#define NUM_OF_NUMBER 10
#define TILE_CHAR_WIDTH 8
#define	TILE_CHAR_HEIGHT 8
#define TILE_CHAR_NUMBER_HEIGHT 8
#define SPACE_WIDTH 8
#define NOTE_OF_EXCLAMATION_WIDTH 6
#define TOP_LETTER 0

class Letter
{
public:
	void Draw(float x, float y, const string& s);
	Letter();

	LPTEXTURE texMisc;

	static Letter* __instance;
	static Letter* GetInstance();
};

