#include "stdafx.h"
#include "Scene_Test.h"
#include "Obj.h"
#include "Player.h"
#include "NormalGun.h"

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

	if (GetObjTypeList(OBJECT_TYPE::GUN).size() <= 0)
	static_cast<CPlayer*>(GetObjTypeList(OBJECT_TYPE::PLAYER).front())->Set_Gun(&GetObjTypeList(OBJECT_TYPE::GUN));

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
