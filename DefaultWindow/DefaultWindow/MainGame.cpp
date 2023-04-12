#include "stdafx.h"
#include "MainGame.h"

CMainGame::CMainGame()
	: m_pPlayer(nullptr)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

}

void CMainGame::Update(void)
{
	m_pPlayer->Update();
}

void CMainGame::Late_Update(void)
{
}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_DC);

}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);

	ReleaseDC(g_hWnd, m_DC);
	
}

