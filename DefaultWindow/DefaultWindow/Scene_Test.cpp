#include "stdafx.h"
#include "Scene_Test.h"
#include "Obj.h"
#include "Player.h"

CScene_Test::CScene_Test()
	:CScene(SCENE_TYPE::TEST)
{
}


CScene_Test::~CScene_Test()
{

}

void CScene_Test::Enter()
{
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() <= 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());
}

void CScene_Test::Update()
{
	CScene::Update();
}

void CScene_Test::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Test::Render(HDC _dc)
{
	CScene::Render(_dc);
}

void CScene_Test::Exit()
{
}
