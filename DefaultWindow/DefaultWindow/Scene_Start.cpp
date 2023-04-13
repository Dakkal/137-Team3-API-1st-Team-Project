#include "stdafx.h"
#include "Scene_Start.h"
#include "GameCore.h"
#include "Player.h"


CScene_Start::CScene_Start()
	:CScene(SCENE_TYPE::START)
{
}


CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() <= 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());
		
}

void CScene_Start::Update()
{
	CScene::Update();
}

void CScene_Start::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Start::Render(HDC hDC)
{
	CScene::Render(hDC);
}

void CScene_Start::Exit()
{
}
