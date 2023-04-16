#include "stdafx.h"
#include "Scene_Stage2.h"
#include "Player.h"
#include "Enemy.h"
#include "EventFunc.h"

CScene_Stage2::CScene_Stage2()
	:CScene(SCENE_TYPE::STAGE2)
	, m_iPatternCount(1)
	, strSceneName(L"Stage 2")
{
}


CScene_Stage2::~CScene_Stage2()
{
}

void CScene_Stage2::Enter()
{
	StartWait();
	m_dwStartTime = GetTickCount();

	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() == 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());

	
}

void CScene_Stage2::Update()
{
	CScene::Update();
	m_dwDeltaTime = GetTickCount() - m_dwStartTime;

	ExcutePattern();
}

void CScene_Stage2::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Stage2::Render(HDC hDC)
{
	CScene::Render(hDC);
	TextOut(hDC, WINCX / 2, 0, strSceneName.c_str(), strSceneName.size());
	TextOut(hDC, WINCX - 50, 100, to_wstring((float)m_dwDeltaTime / 1000).c_str(), to_wstring((float)m_dwDeltaTime / 1000).size());
	wstring strScore = L"Á¡¼ö : " + to_wstring(g_iScore);
	TextOut(hDC, WINCX - 50, 200, strScore.c_str(), strScore.size());
}

void CScene_Stage2::Exit()
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		if (i == (int)OBJECT_TYPE::PLAYER)
			continue;
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end(); ++iter)
			Safe_Delete<CObj*>(*iter);

		m_arrObjList[i].clear();
	}
}

void CScene_Stage2::GameOver()
{
	ChangeSceneEvt(SCENE_TYPE::GAMEOVER);
}

void CScene_Stage2::StartWait()
{

}

void CScene_Stage2::ExcutePattern()
{
	if (GetObjTypeList(OBJECT_TYPE::MONSTER).size() != 0)
		return;

	if (m_iPatternCount == 1)
		Pattern_1();
	if (m_iPatternCount == 2)
		Pattern_2();
	if (m_iPatternCount == 3)
		Pattern_3();
	if (m_iPatternCount >= 4)
		ChangeSceneEvt(SCENE_TYPE::STAGE3);

	m_iPatternCount++;
}

void CScene_Stage2::Pattern_1()
{
	for (int i = 0; i < 5; ++i)
	{
		CEnemy* pEnemy = new CEnemy;
		pEnemy->Set_Pos(100 * (i + 1), 100 + (i * 10));
		pEnemy->SetHp(1);
		pEnemy->SetPause(1);
		AddObjEvt(pEnemy);
	}
}

void CScene_Stage2::Pattern_2()
{
	for (int i = 0; i < 5; ++i)
	{
		CEnemy* pEnemy = new CEnemy;
		pEnemy->Set_Pos(100 * (i + 1), 200);
		pEnemy->SetHp(1);
		pEnemy->SetPause(1);
		AddObjEvt(pEnemy);
	}
}

void CScene_Stage2::Pattern_3()
{
	for (int i = 0; i < 5; ++i)
	{
		CEnemy* pEnemy = new CEnemy;
		pEnemy->Set_Pos(100 * (i + 1), 100);
		pEnemy->SetHp(2);
		pEnemy->SetPause(1);
		AddObjEvt(pEnemy);
	}
}

void CScene_Stage2::ClearWait()
{
}
