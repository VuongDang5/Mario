#include "HUD.h"
#include "Mario.h"
#include "Animation.h"
#include "Animations.h"

void HUD::Render()
{
	CMario* mario = CMario::GetInstance(1, 1);

	CAnimations* animations = CAnimations::GetInstance();
	animations->Get(obj_ID)->Render(x, y);

	Letter* pen = Letter::GetInstance();
	pen->Draw(x - 86, y + 1, FillString(to_string(mario->getCoin()), 5));
	pen->Draw(x - 110, y + 1, FillString(to_string(mario->getLife()), 2));

	if (mario->getStar() == 1)
		animations->Get(40004)->Render(x + 30, y - 5);
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

