#pragma once
#include "Scene.h"
class CScene_Stage3 :
	public CScene
{
public:
	CScene_Stage3();
	virtual ~CScene_Stage3();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void Enter()			override;
	virtual void Update()			override;
	virtual void Late_Update()		override;
	virtual void Render(HDC hDC)	override;
	virtual void Exit()				override;
	virtual void GameOver()			override;

private:
	void		StartWait();
	void		ExcutePattern();
	void		Pattern_1();
	void		Pattern_2();
	void		Pattern_3();
	void		ClearWait();

private:
	LONG		m_dwStartTime;
	LONG		m_dwDeltaTime;

	int			m_iPatternCount;
	wstring		strSceneName;
};

