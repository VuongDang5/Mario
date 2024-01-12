#include "Letter.h"

void Letter::Draw(float x, float y, const string& s)
{
	for (UINT i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			continue;
		}
		else if (s[i] == '!') {
			int left = NUM_OF_LETTER * TILE_CHAR_WIDTH;
			int right = left + NOTE_OF_EXCLAMATION_WIDTH;
			int top = TOP_LETTER;
			int bottom = top + TILE_CHAR_HEIGHT;
			LPSPRITE SpriteTile = new CSprite(i, left, top, right, bottom, texMisc);
			SpriteTile->Draw(x + i * SPACE_WIDTH, y);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			int index = s[i] - 'A';
			int left = index % NUM_OF_LETTER * TILE_CHAR_WIDTH;
			int right = left + TILE_CHAR_WIDTH;
			int top = TOP_LETTER;
			int bottom = top + TILE_CHAR_HEIGHT;
			LPSPRITE SpriteTile = new CSprite(index, left, top, right, bottom, texMisc);
			SpriteTile->Draw(x + i * SPACE_WIDTH, y);
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			int index = s[i] - '0';
			int left = index % NUM_OF_NUMBER * TILE_CHAR_WIDTH;
			int top = TILE_CHAR_NUMBER_HEIGHT;
			int right = left + TILE_CHAR_WIDTH;
			int bottom = top + TILE_CHAR_NUMBER_HEIGHT;
			LPSPRITE SpriteTile = new CSprite(index, left, top, right, bottom, texMisc);
			SpriteTile->Draw(x + i * SPACE_WIDTH, y);
		}
	}
}

Letter* Letter::__instance = NULL;
Letter* Letter::GetInstance()
{
	if (__instance == NULL) __instance = new Letter();
	return __instance;
}


Letter::Letter()
{
	CTextures* textures = CTextures::GetInstance();
	texMisc = textures->Get(ID_TEX_LETTER);
}
