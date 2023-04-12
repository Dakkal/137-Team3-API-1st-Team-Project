#pragma once
#include "GameCore.h"

class CScene
{
public:
	virtual void Enter()		PURE;
	virtual void Update()		PURE;
	virtual void Late_Update()	PURE;
	virtual void Render()		PURE;
	virtual void Exit()			PURE;

public:
	SCENE_TYPE GetSceneType() { return m_eType; }
public:
	explicit CScene(SCENE_TYPE _eType);
	virtual ~CScene();

private:
	SCENE_TYPE m_eType;
};

