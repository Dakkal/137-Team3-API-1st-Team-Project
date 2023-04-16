#include "stdafx.h"
#include "Scene_Stage2.h"
#include "Player.h"

CScene_Stage2::CScene_Stage2()
	:CScene(SCENE_TYPE::STAGE2)
{
}


CScene_Stage2::~CScene_Stage2()
{
}

void CScene_Stage2::Enter()
{
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() == 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());
}

void CScene_Stage2::Update()
{
	CScene::Update();
}

void CScene_Stage2::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Stage2::Render(HDC hDC)
{
	CScene::Render(hDC);
}

void CScene_Stage2::Exit()
{
}

void CScene_Stage2::GameOver()
{
}
