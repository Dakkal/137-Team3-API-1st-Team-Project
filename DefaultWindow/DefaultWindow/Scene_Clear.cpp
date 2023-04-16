#include "stdafx.h"
#include "Scene_Clear.h"
#include "Player.h"

CScene_Clear::CScene_Clear()
	: CScene(SCENE_TYPE::CLEAR)
{
}


CScene_Clear::~CScene_Clear()
{
}

void CScene_Clear::Enter()
{
	int i = 0;
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() == 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());
}

void CScene_Clear::Update()
{
	CScene::Update();
}

void CScene_Clear::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Clear::Render(HDC hDC)
{
	CScene::Render(hDC);
}

void CScene_Clear::Exit()
{
}

void CScene_Clear::GameOver()
{

}
