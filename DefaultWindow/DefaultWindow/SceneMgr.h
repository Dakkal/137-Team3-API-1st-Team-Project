#pragma once
#include "stdafx.h"

class CScene;
class CSceneMgr
{
	SINGLETON(CSceneMgr);

private:
	vector<CScene*>		m_vecScene;
	vector<CScene*>		m_vecBackScene;
	CScene*				m_pCurrScene;

public:
	void ChangeScene(SCENE_TYPE _eType);
	void BackScene();

public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render();
	void Release();

};

