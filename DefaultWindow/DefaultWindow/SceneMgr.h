#pragma once
#include "stdafx.h"

class CScene;
class CSceneMgr
{
	SINGLETON(CSceneMgr);

private:
	CScene*				m_arrScene[(int)SCENE_TYPE::END];
	CScene*				m_pCurrScene;

public:
	CScene*		GetCurrScene() { return m_pCurrScene; }


public:
	void		Initialize();
	void		Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

private:
	void		ChangeScene(SCENE_TYPE _eType);

	friend class CEventMgr;

};

