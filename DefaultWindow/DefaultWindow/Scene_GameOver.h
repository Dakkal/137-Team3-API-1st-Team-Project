#pragma once
#include "Scene.h"
class CScene_GameOver :
	public CScene
{
public:
	explicit CScene_GameOver();
	virtual ~CScene_GameOver();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Enter()		override;
	virtual void Update()		override;
	virtual void Late_Update()	override;
	virtual void Render()		override;
	virtual void Exit()			override;
};

