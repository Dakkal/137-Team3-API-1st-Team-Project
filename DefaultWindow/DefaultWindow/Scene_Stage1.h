#pragma once
#include "Scene.h"
class CScene_Stage1 :
	public CScene
{
public:
	explicit CScene_Stage1();
	virtual ~CScene_Stage1();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Enter()				override;
	virtual void Update()				override;
	virtual void Late_Update()			override;
	virtual void Render(HDC hDC)		override;
	virtual void Exit()					override;
};

