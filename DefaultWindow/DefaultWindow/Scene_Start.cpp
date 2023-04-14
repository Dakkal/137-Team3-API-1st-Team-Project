#include "stdafx.h"
#include "Scene_Start.h"
#include "SceneMgr.h"
#include "GameCore.h"


CScene_Start::CScene_Start()
	:CScene(SCENE_TYPE::START)
{
	swprintf_s(m_szTitle, L"1373");
	swprintf_s(m_szSubTitle, L"space바를 눌러 시작");
}


CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
}

void CScene_Start::Update()
{
	if (Input_Space())
		//ChangeSceneEvt(SCENE_TYPE::STAGE1);
}

void CScene_Start::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Start::Render(HDC hDC)
{
	hTitleFont = CreateFont(200, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
	hOldFont = (HFONT)SelectObject(hDC, hTitleFont);
	SetTextColor(hDC, RGB(0, 0, 0));
	SetBkMode(hDC, TRANSPARENT);
	TextOut(hDC, 185, 100, m_szTitle, lstrlen(m_szTitle));
	SelectObject(CGameCore::GetInst()->GetMainDC(), hOldFont);
	DeleteObject(hTitleFont);

	hTitleFont = CreateFont(30, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
	hOldFont = (HFONT)SelectObject(hDC, hTitleFont);
	SetTextColor(hDC, RGB(0, 0, 0));
	SetBkMode(hDC, TRANSPARENT);
	TextOut(hDC, 300, 400, m_szSubTitle, lstrlen(m_szSubTitle));
	SelectObject(CGameCore::GetInst()->GetMainDC(), hOldFont);
	DeleteObject(hTitleFont);
}

void CScene_Start::Exit()
{
	
}

bool CScene_Start::Input_Space()
{
	if (GetAsyncKeyState(VK_SPACE))
		return true;

	return false;
}
