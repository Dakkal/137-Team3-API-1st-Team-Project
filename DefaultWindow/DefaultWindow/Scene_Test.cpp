#include "stdafx.h"
#include "Scene_Test.h"
#include "Obj.h"
#include "Player.h"
#include "EventFunc.h"
#include "Item_Timestop.h"
#include "CollisionMgr.h"
#include "Boss.h"
#include "BossHead.h"


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

	if (GetObjTypeList(OBJECT_TYPE::BOSS).size() <= 0)
	{
		CObj* pBoss = new CBoss;
		pBoss->Initialize();
		AddObjEvt(pBoss);
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
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::PLAYER_PROJECTILE), GetObjTypeList(OBJECT_TYPE::BOSS));
	//Boss_Clear();
	//GameOver();
}

void CScene_Test::Render(HDC _dc)
{
	CScene::Render(_dc);
}

void CScene_Test::Exit()
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		if (i == (int)OBJECT_TYPE::PLAYER)
			continue;
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end(); ++iter)
		{
			Safe_Delete<CObj*>(*iter);
		}
		m_arrObjList[i].clear();
	}
}

void CScene_Test::GameOver()
{
	if (CGameCore::GetInst()->GetPlayer()->Get_Hp() <= 0)
	{
		ChangeSceneEvt(SCENE_TYPE::GAMEOVER);
	}
}

void CScene_Test::Boss_Clear()
{
	for (auto iter : GetObjTypeList(OBJECT_TYPE::BOSS))
	{
		if (static_cast<CBossHead*>(iter)->Get_BossPart() == BOSS_PART::HEAD)
			return;
		else
			ChangeSceneEvt(SCENE_TYPE::CLEAR);
	}
}

void CScene_Test::Gun_Clear()
{
}

void CScene_Test::Missile_Clear()
{
}
