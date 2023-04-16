#include "stdafx.h"
#include "Scene.h"
#include "Player.h"
#include "CollisionMgr.h"
#include "EventFunc.h"
#include "assert.h"

CScene::CScene(SCENE_TYPE _eType)
	: m_eType(_eType)
{
}

CScene::~CScene()
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end(); ++iter)
		{
			if(!(*iter)->Is_Dead())
				Safe_Delete<CObj*>(*iter);
		}
		m_arrObjList[i].clear();
	}
}


void CScene::Update()
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end(); ++iter)
		{
			if (!(*iter)->Is_Dead())
				(*iter)->Update();
		}
	}


	// 게임 오버 체크
	list<CObj*>::iterator iterMonster = m_arrObjList[(int)OBJECT_TYPE::MONSTER].begin();
	while (iterMonster != m_arrObjList[(int)OBJECT_TYPE::MONSTER].end())
	{
		if ((*iterMonster)->Get_Info().fY > WINCY || CGameCore::GetInst()->GetPlayer()->Get_Hp() <= 0)
		{
			GameOver();
			return;
		}
		else
			++iterMonster;
	}
}

void CScene::Late_Update()
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end(); ++iter)
		{
			if (!(*iter)->Is_Dead())
				(*iter)->Late_Update();
		}
	}

	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::PLAYER), GetObjTypeList(OBJECT_TYPE::MONSTER));
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::PLAYER), GetObjTypeList(OBJECT_TYPE::ITEM));
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::PLAYER), GetObjTypeList(OBJECT_TYPE::ENEMY_PROJECTILE));
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::PLAYER), GetObjTypeList(OBJECT_TYPE::BOSS));
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::SATTELLITE), GetObjTypeList(OBJECT_TYPE::MONSTER));
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::SATTELLITE), GetObjTypeList(OBJECT_TYPE::ENEMY_PROJECTILE));
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::MONSTER), GetObjTypeList(OBJECT_TYPE::PLAYER_PROJECTILE));
	CCollisonMgr::GetInst()->Collision_Rect(GetObjTypeList(OBJECT_TYPE::BOSS), GetObjTypeList(OBJECT_TYPE::PLAYER_PROJECTILE));
}

void CScene::Render(HDC hDC)
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end();)
		{
			if (!(*iter)->Is_Dead())
			{
				(*iter)->Render(hDC);
				++iter;
			}
			else
			{
				iter = m_arrObjList[i].erase(iter);
			}
				
		}
	}
}
