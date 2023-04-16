#pragma once
#include "Scene.h"
class CBoss;
class CScene_Boss :
	public CScene
{
public:
	CScene_Boss();
	virtual ~CScene_Boss();

public:
	// CScene을(를) 통해 상속됨
	virtual void Enter()			override;
	virtual void Update()			override;
	virtual void Late_Update()		override;
	virtual void Render(HDC _dc)	override;
	virtual void Exit()				override;

public:
	void		GameClear();
	virtual void GameOver()			override;

private:
	CBoss* m_pBoss;
};

