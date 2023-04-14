#include "stdafx.h"
#include "GameCore.h"
#include "SceneMgr.h"
#include "Player.h"
#include "SelectGDI.h"
#include "EventMgr.h"


CGameCore::CGameCore()
	: m_hWnd(0)
	, m_bPlaying(true)
	, m_pPlayer(nullptr)
	, m_ptMousePos{0, 0}
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

	m_pImgCursor = Image::FromFile(L"../Output/Resource/Cursor/0.png");

	CSceneMgr::GetInst()->Initialize();
	ShowCursor(false);
}

void CGameCore::Tick()
{
	GetCursorPos(&m_ptMousePos);
	ScreenToClient(m_hWnd, &m_ptMousePos);
	
	//Manager Update & Late_Update
	CSceneMgr::GetInst()->Update();
	CSceneMgr::GetInst()->Late_Update();

	ClearScreen();

	// Manager Render
	CSceneMgr::GetInst()->Render(m_hDC);

	// Cursor Render
	Graphics g(m_hDC);
	g.DrawImage(m_pImgCursor, m_ptMousePos.x, m_ptMousePos.y, 32, 32);

	CEventMgr::GetInst()->Update();
}

void CGameCore::Release()
{
	if (m_pPlayer) 
		Safe_Delete<CPlayer*>(m_pPlayer);

	if (m_pImgCursor)
		Safe_Delete<Image*>(m_pImgCursor);

	ReleaseDC(m_hWnd, m_hDC);
}
