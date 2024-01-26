#include <iostream>
#include <fstream>
#include "AssetIDs.h"

#include "PlayScene.h"
#include "Utils.h"
#include "Textures.h"
#include "Sprites.h"
#include "Coin.h"
#include "Brick.h"
#include "Box.h"
#include "Rock.h"
#include "Sewer.h"

#include "GreenTurtle.h"
#include "Eater.h"
#include "GreenEater.h"
#include "Piranha.h"

#include "HUD.h"

#include "SampleKeyHandler.h"

using namespace std;

CPlayScene::CPlayScene(int id, LPCWSTR filePath) : CScene(id, filePath)
{
	player = NULL;
	key_handler = new CSampleKeyHandler(this);
	cameraStatus = 0;
}


#define SCENE_SECTION_UNKNOWN -1
#define SCENE_SECTION_ASSETS	1
#define SCENE_SECTION_OBJECTS	2

#define ASSETS_SECTION_UNKNOWN -1
#define ASSETS_SECTION_SPRITES 1
#define ASSETS_SECTION_ANIMATIONS 2

#define MAX_SCENE_LINE 1024

void CPlayScene::_ParseSection_SPRITES(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 6) return; // skip invalid lines

	int ID = atoi(tokens[0].c_str());
	int l = atoi(tokens[1].c_str());
	int t = atoi(tokens[2].c_str());
	int r = atoi(tokens[3].c_str());
	int b = atoi(tokens[4].c_str());
	int texID = atoi(tokens[5].c_str());

	LPTEXTURE tex = CTextures::GetInstance()->Get(texID);
	if (tex == NULL)
	{
		DebugOut(L"[ERROR] Texture ID %d not found!\n", texID);
		return;
	}

	CSprites::GetInstance()->Add(ID, l, t, r, b, tex);
}

void CPlayScene::_ParseSection_ASSETS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 1) return;

	wstring path = ToWSTR(tokens[0]);

	LoadAssets(path.c_str());
}

void CPlayScene::_ParseSection_ANIMATIONS(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 3) return; // skip invalid lines - an animation must at least has 1 frame and 1 frame time

	//DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	LPANIMATION ani = new CAnimation();

	int ani_id = atoi(tokens[0].c_str());
	for (int i = 1; i < tokens.size(); i += 2)	// why i+=2 ?  sprite_id | frame_time  
	{
		int sprite_id = atoi(tokens[i].c_str());
		int frame_time = atoi(tokens[i + 1].c_str());
		ani->Add(sprite_id, frame_time);
	}

	CAnimations::GetInstance()->Add(ani_id, ani);
 }

/*
	Parse a line in section [OBJECTS]
*/
void CPlayScene::DrawRoom(int att) {
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f, att);
		objects.push_back(b);
	}

	for (int i = 0; i < 15; i++)
	{
		CBrick* b = new CBrick(BRICK_WIDTH * 209, 196.0f - 16.0f * i, att);
		objects.push_back(b);
	}
	for (int i = 0; i < 15; i++)
	{
		CBrick* b = new CBrick(BRICK_WIDTH * 209 - 16.0f, 196.0f - 16.0f * i, att);
		objects.push_back(b);
	}

	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 12, att);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 13, att);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 14, att);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 15, att);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 16, att);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 17, att);
		objects.push_back(b);
	}
	for (int i = 0; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 18, att);
		objects.push_back(b);
	}

	for (int i = 9; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 1, att);
		objects.push_back(b);
	}
	for (int i = 10; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 2, att);
		objects.push_back(b);
	}
	for (int i = 11; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 3, att);
		objects.push_back(b);
	}
	for (int i = 12; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 4, att);
		objects.push_back(b);
	}
	for (int i = 13; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 5, att);
		objects.push_back(b);
	}
	for (int i = 14; i < 20; i++)
	{
		CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * 6, att);
		objects.push_back(b);
	}

	for (int i = 17; i < 20; i++)
	{
		for (int j = 7; j < 12; j++)
		{
			CBrick* b = new CBrick((i + 209) * BRICK_WIDTH, 196.0f - 16.0f * j, att);
			objects.push_back(b);
		}
	}
	CCoin* coin;
	coin = new CCoin((6 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 9);
	objects.push_back(coin);
	coin = new CCoin((7 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 10);
	objects.push_back(coin);
	coin = new CCoin((8 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 10);
	objects.push_back(coin);
	coin = new CCoin((9 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 9);
	objects.push_back(coin);
	coin = new CCoin((9 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 8 + 2.0f);
	objects.push_back(coin);
	coin = new CCoin((8 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 7);
	objects.push_back(coin);
	coin = new CCoin((9 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 6);
	objects.push_back(coin);
	coin = new CCoin((9 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 5 + 2.0f);
	objects.push_back(coin);
	coin = new CCoin((8 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 4);
	objects.push_back(coin);
	coin = new CCoin((7 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 4);
	objects.push_back(coin);
	coin = new CCoin((6 + 209) * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 5);
	objects.push_back(coin);
}

void CPlayScene::_ParseSection_OBJECTS(string line)
{
	vector<string> tokens = split(line);

	// skip invalid lines - an object set must have at least id, x, y
	if (tokens.size() < 2) return;

	int object_type = atoi(tokens[0].c_str());
	float x = (float)atof(tokens[1].c_str());
	float y = (float)atof(tokens[2].c_str());
	int att = 0;
	if (tokens.size() > 3)
	{
		att = (float)atof(tokens[3].c_str());
	}
	CGameObject* obj = NULL;
	CBox* box = NULL;
	CGoomba* goomba = NULL;
	CGTurtle* turtle = NULL;
	CRock* rock = NULL;

	switch (object_type)
	{
	case OBJECT_TYPE_MARIO:
		if (player != NULL)
		{
			DebugOut(L"[ERROR] MARIO object was created before!\n");
			return;
		}
		obj = CMario::GetInstance(x, y);
		player = (CMario*)obj;

		DebugOut(L"[INFO] Player object has been created!\n");
		break;
	case OBJECT_TYPE_BRICK: obj = new CBrick(x, y, att); break;
	case OBJECT_TYPE_COIN: obj = new CCoin(x, y); break;
	case OBJECT_TYPE_EATER: obj = new CEater(x, y); break;
	case OBJECT_TYPE_GEATER: obj = new CGEater(x, y); break;
	case OBJECT_TYPE_PIRANHA: obj = new CPiranha(x, y); break;
	case OBJECT_TYPE_SEWER: obj = new CSewer(x, y, att); break;
	case OBJECT_TYPE_BOX: 
		box = new CBox(x, y);
		box->setItem(att);
		obj = box;
		break;
	case OBJECT_TYPE_GOOMBA:
		goomba = new CGoomba(x, y);
		goomba->SetState(att);
		obj = goomba;
		break;
	case OBJECT_TYPE_TURTLE:
		turtle = new CGTurtle(x, y);
		turtle->SetState(att);
		obj = turtle;
		break;
	case OBJECT_TYPE_HUD: 
		obj = new HUD(x, y, att); 
		hud = (HUD*)obj;
		return;
	case OBJECT_TYPE_BG:
		for (int i = 1; i < 30; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				obj = new CBrick((x + j) * 16.0f, 196.0f - 16.0f * i, att);
				objects.push_back(obj);
			}
		}
		return;
	case OBJECT_TYPE_SECRET_ROOM:
		DrawRoom(att);
		return;
	case OBJECT_TYPE_ROCK:
		rock = new CRock(x, y);
		rock->setType(att);
		obj = rock;
		break;
	case OBJECT_TYPE_BLOCKER:
		for (int i = 1; i < 25; i++)
		{
			CBrick* b = new CBrick(0 * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * i, att);
			objects.push_back(b);
		}
		for (int i = 0; i < 300; i++)
		{
			CBrick* b = new CBrick(i * BRICK_WIDTH * 1.0f, 196.0f - 16.0f * 25, att);
			objects.push_back(b);
		}
		return;
	default:
		DebugOut(L"[ERROR] Invalid object type: %d\n", object_type);
		return;
	}

	// General object setup
	obj->SetPosition(x, y);

	objects.push_back(obj);

}

void CPlayScene::LoadAssets(LPCWSTR assetFile)
{
	DebugOut(L"[INFO] Start loading assets from : %s \n", assetFile);

	ifstream f;
	f.open(assetFile);

	int section = ASSETS_SECTION_UNKNOWN;

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))
	{
		string line(str);

		if (line[0] == '#') continue;	// skip comment lines	

		if (line == "[SPRITES]") { section = ASSETS_SECTION_SPRITES; continue; };
		if (line == "[ANIMATIONS]") { section = ASSETS_SECTION_ANIMATIONS; continue; };
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }

		//
		// data section
		//
		switch (section)
		{
		case ASSETS_SECTION_SPRITES: _ParseSection_SPRITES(line); break;
		case ASSETS_SECTION_ANIMATIONS: _ParseSection_ANIMATIONS(line); break;
		}
	}

	f.close();

	DebugOut(L"[INFO] Done loading assets from %s\n", assetFile);
}

void CPlayScene::Load()
{
	DebugOut(L"[INFO] Start loading scene from : %s \n", sceneFilePath);

	ifstream f;
	f.open(sceneFilePath);

	// current resource section flag
	int section = SCENE_SECTION_UNKNOWN;

	char str[MAX_SCENE_LINE];
	while (f.getline(str, MAX_SCENE_LINE))
	{
		string line(str);

		if (line[0] == '#') continue;	// skip comment lines	
		if (line == "[ASSETS]") { section = SCENE_SECTION_ASSETS; continue; };
		if (line == "[OBJECTS]") { section = SCENE_SECTION_OBJECTS; continue; };
		if (line[0] == '[') { section = SCENE_SECTION_UNKNOWN; continue; }

		//
		// data section
		//
		switch (section)
		{
		case SCENE_SECTION_ASSETS: _ParseSection_ASSETS(line); break;
		case SCENE_SECTION_OBJECTS: _ParseSection_OBJECTS(line); break;
		}
	}

	f.close();

	DebugOut(L"[INFO] Done loading scene  %s\n", sceneFilePath);
}

void CPlayScene::Update(DWORD dt)
{
	// We know that Mario is the first object in the list hence we won't add him into the colliable object list
	// TO-DO: This is a "dirty" way, need a more organized way 

	vector<LPGAMEOBJECT> coObjects;
	for (size_t i = 0; i < objects.size(); i++)
	{
		coObjects.push_back(objects[i]);
	}

	for (size_t i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}

	// skip the rest if scene was already unloaded (Mario::Update might trigger PlayScene::Unload)
	if (player == NULL) return;

	// Update camera to follow mario
	float cx, cy;
	player->GetPosition(cx, cy);

	CGame* game = CGame::GetInstance();
	cx -= 320 / 2;
	cy -= 240 / 2 + 40.0f;

	if (cx < 0) cx = 0;
	if (cy > -100) cy = 40.0f;
	else cy = cy + 140;

	if (cx > 178.5 * 16.0f) cx = 178.5 * 16.0f;

	if (cameraStatus == 1)
	{
		cx = 218.5 * 16.0f - 320 / 2;
		if (cy < -5) cy = -5.0f;
	}

	hud->SetPosition(cx + 158.0f, cy + 185.0f);
	CGame::GetInstance()->SetCamPos(cx, cy);

	PurgeDeletedObjects();
}

void CPlayScene::Render()
{
	for (int i = 0; i < objects.size(); i++)
		objects[i]->Render();
	hud->Render();
}

/*
*	Clear all objects from this scene
*/
void CPlayScene::Clear()
{
	vector<LPGAMEOBJECT>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++)
	{
		delete (*it);
	}
	objects.clear();
}

/*
	Unload scene

	TODO: Beside objects, we need to clean up sprites, animations and textures as well

*/
void CPlayScene::Unload()
{
	for (int i = 0; i < objects.size(); i++)
		delete objects[i];

	objects.clear();
	player = NULL;

	DebugOut(L"[INFO] Scene %d unloaded! \n", id);
}

bool CPlayScene::IsGameObjectDeleted(const LPGAMEOBJECT& o) { return o == NULL; }

void CPlayScene::PurgeDeletedObjects()
{
	vector<LPGAMEOBJECT>::iterator it;
	for (it = objects.begin(); it != objects.end(); it++)
	{
		LPGAMEOBJECT o = *it;
		if (o->IsDeleted())
		{
			delete o;
			*it = NULL;
		}
	}

	// NOTE: remove_if will swap all deleted items to the end of the vector
	// then simply trim the vector, this is much more efficient than deleting individual items
	objects.erase(
		std::remove_if(objects.begin(), objects.end(), CPlayScene::IsGameObjectDeleted),
		objects.end());
}

void CPlayScene::GoMap(int x)
{
	CMario* mario = CMario::GetInstance(1, 1);
	if (x == 2)
	{
		mario->SetPosition(212 * 16.0f, 196.0f - 16.0f * 8);
		cameraStatus = 1;
	}

	if (x == 1)
	{
		mario->SetPosition(164.5 * 16.0f, 196.0f - 16.0f * 5);
		cameraStatus = 0;
	}
}