#pragma once

#include "stdafx.h"
#include "Player.h"

class CMainGame
{
public:
	void		Initialize(void);
	void		Update(void);
	void		Late_Update(void);
	void		Render(void);
	void		Release(void);

private:
	HDC			m_DC;
	CObj*		m_pPlayer;

public:
	CMainGame();
	~CMainGame();
};

