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
	void ChangeScene(SCENE_TYPE _eType);

public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render(HDC hDC);
	void Release();

};

