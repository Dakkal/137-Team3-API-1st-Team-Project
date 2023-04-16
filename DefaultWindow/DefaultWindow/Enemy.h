#pragma once
#include "Obj.h"

class CEnemy :
	public CObj
{
public:
	explicit CEnemy();
	virtual ~CEnemy();

public:
	// CObj을(를) 통해 상속됨
	virtual void	Initialize()				override;
	virtual int		Update()					override;
	virtual void	Late_Update()				override;
	virtual void	Render(HDC hDC)				override;
	virtual void	Release()					override;

public:
	virtual void	OnCollision(CObj* _pObj)	override;

public:
	int				GetHp()						{ return m_iHp; }
	void			SetHp(int _iHp)				{ m_iHp = _iHp; }

public:
	void			SetPause(int _iPauseTime)	{ m_bPause = true; m_lPauseTime = _iPauseTime * 1000; m_dwPauseTime = GetTickCount(); }
	void			SetSpeed(int _iSpeed)		{ m_iSpeed = _iSpeed; }


private:
	void			OnDamaged();
	void			Update_Pause();

private:
	int				m_iHp;
	int				m_iMaxHp;
	int				m_iSpeed;

	LONG			m_lRecoverTime;
	LONG			m_dwCollisionTime;

	bool			m_bPause;
	LONG			m_dwPauseTime;
	LONG			m_lPauseTime;
};

