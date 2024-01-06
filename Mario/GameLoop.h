#pragma once
#include <Windows.h>
#include <d3d10.h>
#include <d3dx10.h>

#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "Animation.h"
#include "Animations.h"
#include "Sprite.h"
#include "Sprites.h"

#include "Mario.h"
#include "Brick.h"

#include "SampleKeyHandler.h"

class GameLoop
{
public:
    GameLoop(HWND hWnd);
    ~GameLoop();

    static void UpdateObj(LPGAMEOBJECT& o);
    static void GoMap(int x);

    void InitLoop();

    //ham dung de ve sau khi update
    void Render();

    //ham update cua game
    void Update(DWORD dt);
};
