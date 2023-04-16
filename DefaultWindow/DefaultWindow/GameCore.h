#pragma once
#include "stdafx.h"

class CPlayer;
class CGameCore
{
	SINGLETON(CGameCore);

public:
	void		Initialize(HWND _hWnd);
	void		Tick();
	void		Stop() { m_bPlaying = false; }
	
	void		TimeRewind();

	void		Release();

public:
	CPlayer*	GetPlayer() { return m_pPlayer; }
	bool		IsPlaying() { return m_bPlaying; }
	POINT		GetMousePos() { return m_ptMousePos; }

public:
	//액세스 메서드
	HWND		GetMainHwnd()	{ return m_hWnd; }
	HDC			GetMainDC()		{ return m_hDC; }

public:
	//GDI 관련(색깔 바꾸기 용 함수)
	HBRUSH		GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN		GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; };

private:
	HBITMAP		ScreenCapture(void);
	void		ClearScreen() { Rectangle(m_memDC, -1, -1, WINCX + 1, WINCY + 1); }
	void		CreateBrusnAndPen();

private:
	CPlayer*	m_pPlayer;
	bool		m_bPlaying;

	HBRUSH		m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN		m_arrPen[(UINT)PEN_TYPE::END];

	HWND		m_hWnd;
	HDC			m_hDC;

	HBITMAP		m_hBitmap;
	HDC			m_memDC;

	POINT		m_ptMousePos;
	Image*		m_pImgCursor;

	list<HDC>	m_dcList;
	DWORD		dwSaveTime;

};

