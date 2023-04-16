#include "stdafx.h"
#include "Scene_Boss.h"
#include "Obj.h"
#include "Player.h"
#include "EventFunc.h"
#include "Item_Timestop.h"
#include "CollisionMgr.h"
#include "Boss.h"
#include "BossHead.h"


CScene_Boss::CScene_Boss()
	:CScene(SCENE_TYPE::TEST)
	, m_pBoss(nullptr)
{
}


CScene_Boss::~CScene_Boss()
{

}

void CScene_Boss::Enter()
{
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() <= 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());

	m_pBoss = new CBoss;
	AddObjEvt(m_pBoss);

}

void CScene_Boss::Update()
{
	if (m_pBoss->IsDestroy())
		GameClear();
	CScene::Update();
}

void CScene_Boss::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Boss::Render(HDC _dc)
{
	CScene::Render(_dc);
}

void CScene_Boss::Exit()
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

void CScene_Boss::GameClear()
{
	ChangeSceneEvt(SCENE_TYPE::CLEAR);
}

void CScene_Boss::GameOver()
{
	ChangeSceneEvt(SCENE_TYPE::GAMEOVER);
}
