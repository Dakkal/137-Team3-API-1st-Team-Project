#include "stdafx.h"
#include "Scene_GameOver.h"
#include "Player.h"
#include "EventFunc.h"
#include "Scene.h"




CScene_GameOver::CScene_GameOver()
	: CScene(SCENE_TYPE::GAMEOVER)
{
	m_iCount = 10;
}


CScene_GameOver::~CScene_GameOver()
{
}

void CScene_GameOver::Enter()
{
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() == 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());

	m_dwTime = GetTickCount();
}

void CScene_GameOver::Update()
{
	if(!CGameCore::GetInst()->GetPlayer()->Is_Dead())
		GameOver();

	if (m_iCount <= 0 || Input_Space())
	{
		ChangeSceneEvt(SCENE_TYPE::START);
	}

	CScene::Update();
	
}

void CScene_GameOver::Late_Update()
{
	CScene::Late_Update();
}

void CScene_GameOver::Render(HDC hDC)
{
	CScene::Render(hDC);
	if (!CGameCore::GetInst()->GetPlayer()->Is_Dead())
	{
		hTitleFont = CreateFont(70, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
		hOldFont = (HFONT)SelectObject(hDC, hTitleFont);
		SetTextColor(hDC, RGB(0, 0, 0));
		SetBkMode(hDC, TRANSPARENT);
		TextOut(hDC, 185, 200, m_szTitle, lstrlen(m_szTitle));
		SelectObject(CGameCore::GetInst()->GetMainDC(), hOldFont);
		DeleteObject(hTitleFont);

		hTitleFont = CreateFont(40, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
		hOldFont = (HFONT)SelectObject(hDC, hTitleFont);
		SetTextColor(hDC, RGB(0, 0, 0));
		SetBkMode(hDC, TRANSPARENT);
		TextOut(hDC, 250, 400, m_szSubTitle, lstrlen(m_szSubTitle));
		SelectObject(CGameCore::GetInst()->GetMainDC(), hOldFont);
		DeleteObject(hTitleFont);

		//hTitleFont = CreateFont(40, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
		//hOldFont = (HFONT)SelectObject(hDC, hTitleFont);
		//SetTextColor(hDC, RGB(0, 0, 0));
		//SetBkMode(hDC, TRANSPARENT);
		//TextOut(hDC, 240, 300, m_szScore, lstrlen(m_szScore));
		//SelectObject(CGameCore::GetInst()->GetMainDC(), hOldFont);
		//DeleteObject(hTitleFont);
	}
}

void CScene_GameOver::Exit()
{
}

void CScene_GameOver::GameOver()
{
	if (m_dwTime + 1000 <= GetTickCount())
	{
		m_iCount--;
		swprintf_s(m_szTitle, L"GAME OVER %d", m_iCount);
		swprintf_s(m_szSubTitle, L"space바를 눌러 다시하기");
		//TODO : wsprintfW(m_szScore, L"현재 스코어 : %d", CScene::Get_Score());
		m_dwTime = GetTickCount();
	}
}

bool CScene_GameOver::Input_Space()
{
	if (GetAsyncKeyState(VK_SPACE))
		return true;

	return false;
}
