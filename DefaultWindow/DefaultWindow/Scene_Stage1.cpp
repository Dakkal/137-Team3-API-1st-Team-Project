#include "stdafx.h"
#include "Scene_Stage1.h"
#include "Obj.h"
#include "Player.h"
#include "NormalGun.h"
#include "EventFunc.h"
#include "Item_Timestop.h"
#include "Enemy.h"
#include "CollisionMgr.h"
#include "Item_Bomb.h"
#include "Citem_ScrewGun.h"
#include "SceneMgr.h"

CScene_Stage1::CScene_Stage1()
	:	CScene(SCENE_TYPE::STAGE1)
	,	m_iPatternCount(1)
	,	strSceneName(L"Stage 1")
{
}


CScene_Stage1::~CScene_Stage1()
{

}

void CScene_Stage1::Enter()
{	
	StartWait();
	m_dwStartTime = GetTickCount();

	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() <= 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());

	m_iPatternCount = 1;


}
void CScene_Stage1::Update()
{
	CScene::Update();
	m_dwDeltaTime = GetTickCount() - m_dwStartTime;

	ExcutePattern();
}

void CScene_Stage1::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Stage1::Render(HDC hDC)
{
	CScene::Render(hDC);
	TextOut(hDC, WINCX / 2, 0, strSceneName.c_str(), strSceneName.size());
	TextOut(hDC, WINCX - 50, 100, to_wstring((float)m_dwDeltaTime / 1000).c_str(), to_wstring((float)m_dwDeltaTime / 1000).size());
}

void CScene_Stage1::Exit()
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

void CScene_Stage1::GameOver()
{
	ChangeSceneEvt(SCENE_TYPE::GAMEOVER);
}

void CScene_Stage1::StartWait()
{
	/*while (true)
	{
		if (GetAsyncKeyState(VK_RETURN))
			return;
		
		SelectGDI(CGameCore::GetInst()->GetMainDC(), PEN_TYPE::BLUE);
		wstring strStartMsg = L"Press Enter to Start";
		TextOut(CGameCore::GetInst()->GetMainDC(), WINCX / 2, WINCY / 2, strStartMsg.c_str(), strStartMsg.size());
	}*/
}

void CScene_Stage1::ExcutePattern()
{
	int iSize = GetObjTypeList(OBJECT_TYPE::MONSTER).size() != 0;
	if (iSize > 0 || m_iPatternCount > 4)
		return;

	m_iPatternCount++;

	if (m_iPatternCount == 1)
		Pattern_1();
	if (m_iPatternCount == 2)
		Pattern_2();
	if (m_iPatternCount == 3)
		Pattern_3();
	if (m_iPatternCount >= 4)
		ChangeSceneEvt(SCENE_TYPE::STAGE2);

	
}

void CScene_Stage1::Pattern_1()
{
	for (int i = 0; i < 4; ++i)
	{
		CEnemy* pEnemy = new CEnemy;
		pEnemy->Set_Pos(100 * (i + 1), 100);
		pEnemy->SetHp(1);
		pEnemy->SetPause(1);
		AddObjEvt(pEnemy);
	}
}

void CScene_Stage1::Pattern_2()
{
	for (int i = 0; i < 8; ++i)
	{
		CEnemy* pEnemy = new CEnemy;
		if (i < 4)
			pEnemy->Set_Pos(100 * (i + 1), 100);
		else
			pEnemy->Set_Pos(100 * ((i / 2) + 1), 200);

		pEnemy->SetHp(1);
		pEnemy->SetPause(1);
		AddObjEvt(pEnemy);
	}
}

void CScene_Stage1::Pattern_3()
{
	for (int i = 0; i < 5; ++i)
	{
		CEnemy* pEnemy = new CEnemy;
		pEnemy->Set_Pos(100 * (i + 1), 100);
		pEnemy->SetHp(1);
		pEnemy->SetPause(1);
		AddObjEvt(pEnemy);
	}
}

void CScene_Stage1::ClearWait()
{
}
