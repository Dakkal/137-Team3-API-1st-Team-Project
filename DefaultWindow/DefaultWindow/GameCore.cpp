#include "stdafx.h"
#include "GameCore.h"
#include "SceneMgr.h"
#include "Player.h"


CGameCore::CGameCore()
	: m_bPlaying(true), m_pPlayer(nullptr)
{
}


CGameCore::~CGameCore()
{
	Release();
}

void CGameCore::Initialize()
{
	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();

	CSceneMgr::GetInst()->Initialize();
}

void CGameCore::Tick()
{
	CSceneMgr::GetInst()->Update();
	CSceneMgr::GetInst()->Late_Update();
	CSceneMgr::GetInst()->Render();
}

void CGameCore::Release()
{
	if (m_pPlayer) Safe_Delete<CPlayer*>(m_pPlayer);
}
