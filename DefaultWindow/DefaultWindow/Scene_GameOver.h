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
};

