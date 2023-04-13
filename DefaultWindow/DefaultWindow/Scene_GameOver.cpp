#include "stdafx.h"
#include "Scene_GameOver.h"
#include "Player.h"


CScene_GameOver::CScene_GameOver()
	: CScene(SCENE_TYPE::GAMEOVER)
{
}


CScene_GameOver::~CScene_GameOver()
{
}

void CScene_GameOver::Enter()
{
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() == 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());
}

void CScene_GameOver::Update()
{
	CScene::Update();
	
}

void CScene_GameOver::Late_Update()
{
	CScene::Late_Update();
}

void CScene_GameOver::Render(HDC hDC)
{
	CScene::Render(hDC);
}

void CScene_GameOver::Exit()
{
}
