#pragma once
#include "Scene.h"
class CScene_Clear :
	public CScene
{
public:
	explicit CScene_Clear();
	virtual ~CScene_Clear();

public:
	// CScene을(를) 통해 상속됨
	virtual void Enter()				override;
	virtual void Update()				override;
	virtual void Late_Update()			override;
	virtual void Render(HDC hDC)		override;
	virtual void Exit()					override;

public:
	virtual void GameOver()				override;

	HFONT		hTitleFont;
	HFONT		hOldFont;


private:
	bool		Input_Space();

	TCHAR		m_szTitle[32];
	TCHAR		m_szSubTitle[32];
	TCHAR		m_szScore[32];
};

