#include "stdafx.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Scene_Start.h"
#include "Scene_Stage1.h"
#include "Scene_Stage2.h"
#include "Scene_GameOver.h"
#include "Scene_Clear.h"
#include "Scene_Exit.h"
#include "GameCore.h"
#include "Scene_Test.h"



CSceneMgr::CSceneMgr()
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::ChangeScene(SCENE_TYPE _eType)
{
	if (_eType == m_pCurrScene->GetSceneType())
		return;

	m_pCurrScene->Exit();
	m_pCurrScene = m_arrScene[(int)_eType];
	m_pCurrScene->Enter();
	
}


void CSceneMgr::Initialize()
{
	m_arrScene[(int)SCENE_TYPE::START]		= new CScene_Start;
	m_arrScene[(int)SCENE_TYPE::STAGE1]		= new CScene_Stage1;
	m_arrScene[(int)SCENE_TYPE::STAGE2]		= new CScene_Stage2;
	m_arrScene[(int)SCENE_TYPE::GAMEOVER]	= new CScene_GameOver;
	m_arrScene[(int)SCENE_TYPE::CLEAR]		= new CScene_Clear;
	m_arrScene[(int)SCENE_TYPE::EXIT]		= new CScene_Exit;
	m_arrScene[(int)SCENE_TYPE::TEST]		= new CScene_Test;

	m_pCurrScene = m_arrScene[(int)SCENE_TYPE::TEST];
	m_pCurrScene->Enter();

}

void CSceneMgr::Update()
{
	m_pCurrScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pCurrScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pCurrScene->Render(hDC);
}

void CSceneMgr::Release()
{
	for (int i = 0; i < (int)SCENE_TYPE::END; ++i)
		Safe_Delete<CScene*>(m_arrScene[i]);
}
