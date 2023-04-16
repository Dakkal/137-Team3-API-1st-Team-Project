#pragma once
#include "Scene.h"
class CScene_Test :
	public CScene
{
public:
	CScene_Test();
	virtual ~CScene_Test();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Enter()			override;
	virtual void Update()			override;
	virtual void Late_Update()		override;
	virtual void Render(HDC _dc)	override;
	virtual void Exit()				override;

public:
	virtual void GameOver()			override;
};

