#include "stdafx.h"
#include "Scene_Clear.h"
#include "Player.h"
#include "Scene.h"
#include "EventFunc.h"
#include "Scene.h"

CScene_Clear::CScene_Clear()
	: CScene(SCENE_TYPE::CLEAR)
{
	
	//TODO : wsprintfW(m_szScore, L"현재 스코어 : %d", CScene::Get_Score());
}


CScene_Clear::~CScene_Clear()
{
}

void CScene_Clear::Enter()
{
	int i = 0;
	if (GetObjTypeList(OBJECT_TYPE::PLAYER).size() == 0)
		GetObjTypeList(OBJECT_TYPE::PLAYER).push_back(CGameCore::GetInst()->GetPlayer());

	swprintf_s(m_szTitle, L"축하합니다.");
	swprintf_s(m_szSubTitle, L"space바를 눌러 종료");
}

void CScene_Clear::Update()
{
	if (Input_Space())
		ChangeSceneEvt(SCENE_TYPE::START);
}

void CScene_Clear::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Clear::Render(HDC hDC)
{
	hTitleFont = CreateFont(120, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
	hOldFont = (HFONT)SelectObject(hDC, hTitleFont);
	SetTextColor(hDC, RGB(0, 0, 0));
	SetBkMode(hDC, TRANSPARENT);
	TextOut(hDC, 185, 100, m_szTitle, lstrlen(m_szTitle));
	SelectObject(CGameCore::GetInst()->GetMainDC(), hOldFont);
	DeleteObject(hTitleFont);

	hTitleFont = CreateFont(40, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
	hOldFont = (HFONT)SelectObject(hDC, hTitleFont);
	SetTextColor(hDC, RGB(0, 0, 0));
	SetBkMode(hDC, TRANSPARENT);
	TextOut(hDC, 250, 400, m_szSubTitle, lstrlen(m_szSubTitle));
	SelectObject(CGameCore::GetInst()->GetMainDC(), hOldFont);
	DeleteObject(hTitleFont);

	/*hTitleFont = CreateFont(40, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, TEXT("Arial"));
	hOldFont = (HFONT)SelectObject(hDC, hTitleFont);
	SetTextColor(hDC, RGB(0, 0, 0));
	SetBkMode(hDC, TRANSPARENT);
	TextOut(hDC, 220, 300, m_szScore, lstrlen(m_szScore));
	SelectObject(CGameCore::GetInst()->GetMainDC(), hOldFont);
	DeleteObject(hTitleFont);*/
}

void CScene_Clear::Exit()
{
}

void CScene_Clear::GameOver()
{

}

bool CScene_Clear::Input_Space()
{
	if (GetAsyncKeyState(VK_SPACE))
		return true;

	return false;
}
