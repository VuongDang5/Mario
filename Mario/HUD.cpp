#include "HUD.h"
#include "Animation.h"
#include "Animations.h"

void HUD::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(20048)->Render(x, y);
}

void HUD::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	
}


