#include "stdafx.h"
#include "Scene_Exit.h"
#include "Player.h"

CScene_Exit::CScene_Exit()
	: CScene(SCENE_TYPE::EXIT)
{
}


CScene_Exit::~CScene_Exit()
{
}

void CScene_Exit::Enter()
{
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() <= 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());
}

void CScene_Exit::Update()
{
	CScene::Update();
}

void CScene_Exit::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Exit::Render(HDC hDC)
{
	CScene::Render(hDC);
}

void CScene_Exit::Exit()
{
}

void CScene_Exit::GameOver()
{
}
