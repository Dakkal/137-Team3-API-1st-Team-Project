#pragma once
#include "Scene.h"
class CScene_Stage1 :
	public CScene
{
public:
	explicit CScene_Stage1();
	virtual ~CScene_Stage1();

public:
	// CScene을(를) 통해 상속됨
	virtual void Enter()				override;
	virtual void Update()				override;
	virtual void Late_Update()			override;
	virtual void Render(HDC hDC)		override;
	virtual void Exit()					override;

public:
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
	int			iPatternCount;
	wstring		strSceneName;
};

