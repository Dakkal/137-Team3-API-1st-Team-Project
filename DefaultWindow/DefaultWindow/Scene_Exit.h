#pragma once
#include "Scene.h"
class CScene_Exit :
	public CScene
{
public:
	explicit CScene_Exit();
	virtual ~CScene_Exit();

public:
	// CScene을(를) 통해 상속됨
	virtual void Enter()		override;
	virtual void Update()		override;
	virtual void Late_Update()	override;
	virtual void Render()		override;
	virtual void Exit()			override;
};

