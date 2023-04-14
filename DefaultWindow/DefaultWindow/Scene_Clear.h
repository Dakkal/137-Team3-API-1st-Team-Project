#pragma once
#include "Scene.h"
class CScene_Clear :
	public CScene
{
public:
	explicit CScene_Clear();
	virtual ~CScene_Clear();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Enter()				override;
	virtual void Update()				override;
	virtual void Late_Update()			override;
	virtual void Render(HDC hDC)		override;
	virtual void Exit()					override;
};

