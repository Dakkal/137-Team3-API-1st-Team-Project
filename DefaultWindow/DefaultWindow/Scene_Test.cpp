#include "stdafx.h"
#include "Scene_Test.h"
#include "Obj.h"
#include "Player.h"
#include "NormalGun.h"
#include "EventFunc.h"
#include "Item_Timestop.h"
#include "Enemy.h"
#include "CollisionMgr.h"
#include "Item_Bomb.h"
#include "Citem_ScrewGun.h"

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

	CItem_Timestop* pItem = new CItem_Timestop;
	pItem->Initialize();
	pItem->Set_Pos(WINCX / 2, 0);

	AddObjEvt(pItem);
	
	for (int i = 0; i < 10; ++i)
	{
		CEnemy* pEnemy = new CEnemy;
		AddObjEvt(pEnemy);
	}
}

void CScene_Test::Update()
{
	CScene::Update();
}

void CScene_Test::Late_Update()
{
	CScene::Late_Update();
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::PLAYER), GetObjTypeList(OBJECT_TYPE::ITEM));
}

void CScene_Test::Render(HDC _dc)
{
	CScene::Render(_dc);
}

void CScene_Test::Exit()
{
}

void CScene_Test::GameOver()
{
}
