#pragma once
#include <Windows.h>
#include <d3d10.h>
#include <d3dx10.h>

#include "Game.h"
#include "GameObject.h"

#include "Mario.h"
#include "Textures.h"

class GameLoop
{
public:
    GameLoop(HWND hWnd);
    ~GameLoop();

protected:
    void InitLoop();

    //ham dung de ve sau khi update
    void Render();

    //ham update cua game
    void Update(DWORD dt);
};
