#include "stdafx.h"
#include "Scene_Stage1.h"
#include "Player.h"
#include "Enemy.h"

CScene_Stage1::CScene_Stage1()
	:CScene(SCENE_TYPE::STAGE1), m_dwTime(GetTickCount())
{
}


CScene_Stage1::~CScene_Stage1()
{
}

void CScene_Stage1::Enter()
{
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() <= 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());

	m_pEnemy = new CEnemy;
	m_pEnemy->Initialize();
	GetObjTypeList(OBJECT_TYPE::MONSTER).push_back(m_pEnemy);
	
}

void CScene_Stage1::Update()
{
	CScene::Update();
}

void CScene_Stage1::Late_Update()
{
	CScene::Late_Update();

	if (m_dwTime + 1003 <= GetTickCount())
	{
		m_pEnemy = new CEnemy;
		m_pEnemy->Initialize();
		GetObjTypeList(OBJECT_TYPE::MONSTER).push_back(m_pEnemy);
		m_dwTime = GetTickCount();
	}
}

void CScene_Stage1::Render(HDC hDC)
{
	CScene::Render(hDC);
}

void CScene_Stage1::Exit()
{
}
