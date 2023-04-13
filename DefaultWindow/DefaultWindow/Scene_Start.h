#pragma once
#include "Scene.h"
class CScene_Start :
	public CScene
{
public:
	explicit CScene_Start();
	virtual ~CScene_Start();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Enter()				override;
	virtual void Update()				override;
	virtual void Late_Update()			override;
	virtual void Render(HDC hDC)		override;
	virtual void Exit()					override;
};

