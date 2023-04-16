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
	, m_hBitmap(0)
	, m_memDC(0)
	, dwSaveTime(GetTickCount())
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

	m_memDC = CreateCompatibleDC(m_hDC);
	m_hBitmap = CreateCompatibleBitmap(m_hDC, WINCX, WINCY);

	HBITMAP hOld = (HBITMAP)SelectObject(m_memDC, (HBITMAP)m_hBitmap);
	DeleteObject(hOld);

	m_pPlayer = new CPlayer;
	m_pPlayer->Initialize();

	m_pImgCursor = Image::FromFile(L"../Output/Resource/Cursor/0.png");
	CreateBrusnAndPen();

	CSceneMgr::GetInst()->Initialize();
	ShowCursor(false);
}

void CGameCore::Tick()
{
	GetCursorPos(&m_ptMousePos);
	ScreenToClient(m_hWnd, &m_ptMousePos);
	
	if (GetAsyncKeyState('0'))
		TimeRewind();


	//Manager Update & Late_Update
	CSceneMgr::GetInst()->Update();
	CSceneMgr::GetInst()->Late_Update();

	ClearScreen();
	// Manager Render
	CSceneMgr::GetInst()->Render(m_memDC);
	
	// Cursor Render
	Graphics g(m_memDC);
	g.DrawImage(m_pImgCursor, m_ptMousePos.x, m_ptMousePos.y, 32, 32);


	if (dwSaveTime + 1000 <= GetTickCount())
	{
		m_dcList.push_back(CreateCompatibleDC(m_memDC));
		dwSaveTime = GetTickCount();
	}
	

	BitBlt(m_hDC, 0, 0, WINCX, WINCY, m_memDC, 0, 0, SRCCOPY);

	CEventMgr::GetInst()->Update();
}

void CGameCore::TimeRewind()
{
	list<HDC>::iterator iter = m_dcList.begin();
	while (iter != m_dcList.end())
	{
		BitBlt(m_memDC, 0, 0, WINCX, WINCY, *iter, 0, 0, SRCCOPY);
	}
	m_dcList.clear();
}

void CGameCore::Release()
{
	if (m_pImgCursor)
		Safe_Delete<Image*>(m_pImgCursor);

	/*if (m_pPlayer)
		Safe_Delete<CPlayer*>(m_pPlayer);*/
	CSceneMgr::GetInst()->Release();


	DeleteObject(m_hBitmap);
	DeleteDC(m_memDC);
	ReleaseDC(m_hWnd, m_hDC);
}

void CGameCore::CreateBrusnAndPen()
{
	//CreateSolidBrush(RGB(255, 0, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW]	= (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	m_arrBrush[(UINT)BRUSH_TYPE::BLACK]		= (HBRUSH)GetStockObject(BLACK_BRUSH);
	m_arrBrush[(UINT)BRUSH_TYPE::WHITE]		= (HBRUSH)GetStockObject(WHITE_BRUSH);
	m_arrBrush[(UINT)BRUSH_TYPE::RED]		= CreateSolidBrush(RGB(255, 0, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::GREEN]		= CreateSolidBrush(RGB(0, 255, 0));
	m_arrBrush[(UINT)BRUSH_TYPE::BLUE]		= CreateSolidBrush(RGB(0, 0, 255));


	m_arrPen[(UINT)PEN_TYPE::RED]			= CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::GREEN]			= CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE]			= CreatePen(PS_SOLID, 1, RGB(0, 0, 255));;
	
	
}

HBITMAP CGameCore::ScreenCapture(void)
{
	// 메인 모니터의 해상도를 구한다.
	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	HDC hScrDC, hMemDC;
	HBITMAP hBitmap;

	// 화면 DC와 스크린샷을 저장할 비트맵을 생성한다.
	hScrDC = CreateDC(L"DISPLAY", NULL, NULL, NULL);
	hMemDC = CreateCompatibleDC(hScrDC);
	hBitmap = CreateCompatibleBitmap(hScrDC, ScreenWidth, ScreenHeight);
	SelectObject(hMemDC, hBitmap);

	// 현재 화면을 비트맵으로 복사한다.
	BitBlt(hMemDC, 0, 0, ScreenWidth, ScreenHeight, hScrDC, 0, 0, SRCCOPY);

	DeleteDC(hMemDC);
	DeleteDC(hScrDC);

	return hBitmap;
}

