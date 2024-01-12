#include "HUD.h"
#include "Mario.h"
#include "Animation.h"
#include "Animations.h"

void HUD::Render()
{
	CMario* mario = CMario::GetInstance(1,1);

	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(20048)->Render(x, y);

	Letter* pen = Letter::GetInstance();
	pen->Draw(x - 86,y + 1, FillString(to_string(mario->getCoin()),5));
}

void HUD::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	
}

string HUD::FillString(string s, int max)
{
	while (s.size() < max) {
		s = "0" + s;
	}
	return s;
}

