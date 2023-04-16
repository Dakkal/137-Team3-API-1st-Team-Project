#pragma once
#include "Scene.h"
class CScene_GameOver :
	public CScene
{
public:
	explicit CScene_GameOver();
	virtual ~CScene_GameOver();

public:
	// CScene을(를) 통해 상속됨
	virtual void Enter()				override;
	virtual void Update()				override;
	virtual void Late_Update()			override;
	virtual void Render(HDC hDC)		override;
	virtual void Exit()					override;

public:
	virtual void GameOver()				override;

private:
	bool		Input_Space();

	DWORD m_dwTime;

	TCHAR		m_szTitle[32];
	TCHAR		m_szSubTitle[32];
	TCHAR		m_szScore[32];

	HFONT		hTitleFont;
	HFONT		hOldFont;

	int m_iCount;

};

