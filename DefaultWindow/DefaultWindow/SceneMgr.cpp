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



CSceneMgr::CSceneMgr()
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::ChangeScene(SCENE_TYPE _eType)
{
	auto findLambda = [_eType](CScene* _pScene) -> 
		const bool { if (_eType == _pScene->GetSceneType()) return true; else return false; };

	vector<CScene*>::iterator findIt = find_if(m_vecScene.begin(), m_vecScene.end(), findLambda);

	if (findIt == m_vecScene.end()) return;

	m_vecBackScene.push_back(m_pCurrScene);

	m_pCurrScene->Exit();
	m_pCurrScene = *findIt;
	m_pCurrScene->Enter();
}

void CSceneMgr::BackScene()
{
	if (m_vecBackScene.empty()) return;

	m_pCurrScene->Exit();
	m_pCurrScene = m_vecBackScene.back();
	m_vecBackScene.pop_back();
	m_pCurrScene->Enter();
}

void CSceneMgr::Initialize()
{
	m_vecScene.reserve((size_t)SCENE_TYPE::END);

	CScene* pTemp = new CScene_Start;
	if (pTemp != nullptr) m_vecScene.push_back(pTemp);

	pTemp = new CScene_Stage1;
	if (pTemp != nullptr) m_vecScene.push_back(pTemp);

	pTemp = new CScene_Stage2;
	if (pTemp != nullptr) m_vecScene.push_back(pTemp);

	pTemp = new CScene_GameOver;
	if (pTemp != nullptr) m_vecScene.push_back(pTemp);

	pTemp = new CScene_Clear;
	if (pTemp != nullptr) m_vecScene.push_back(pTemp);

	pTemp = new CScene_Exit;
	if (pTemp != nullptr) m_vecScene.push_back(pTemp);

	m_pCurrScene = m_vecScene.front();
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

void CSceneMgr::Render()
{
	m_pCurrScene->Render();
}

void CSceneMgr::Release()
{
	for_each(m_vecScene.begin(), m_vecScene.end(), Safe_Delete<CScene*>);

	m_vecScene.clear();
	m_vecBackScene.clear();
	m_vecScene.shrink_to_fit();
	m_vecBackScene.shrink_to_fit();
}
