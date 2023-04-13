#include "stdafx.h"
#include "GameCore.h"
#include "SceneMgr.h"
#include "Player.h"
#include "SelectGDI.h"


CGameCore::CGameCore()
	: m_hWnd(0)
	, m_bPlaying(true)
	, m_pPlayer(nullptr)
{

}


CGameCore::~CGameCore()
{
	Release();
}

void CGameCore::Initialize(HWND _hWnd)
{
	m_hWnd = _hWnd;

	m_hDC = GetDC(m_hWnd);

	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();

	CSceneMgr::GetInst()->Initialize();
}

void CGameCore::Tick()
{
	CSceneMgr::GetInst()->Update();
	CSceneMgr::GetInst()->Late_Update();

	ClearScreen();
	CSceneMgr::GetInst()->Render(m_hDC);
}

void CGameCore::Release()
{
	if (m_pPlayer) 
		Safe_Delete<CPlayer*>(m_pPlayer);

	ReleaseDC(m_hWnd, m_hDC);
}
