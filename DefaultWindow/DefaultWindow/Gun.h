#pragma once
#include "Obj.h"

class CPlayer;
class CGun :
	public CObj
{
public:
	CGun();
	virtual ~CGun();

	// Inherited via CObj
	virtual void	Initialize()		PURE;
	virtual int		Update()			PURE;
	virtual void	Late_Update()		PURE;
	virtual void	Render(HDC hDC)		PURE;
	virtual void	Release()			PURE;

public:
	virtual void	OnCollision(CObj * _pObj) PURE;

	virtual void	Reload() PURE;
	virtual void	Fire() PURE;
	virtual CObj*	Create_Bullet() PURE;

public:
	int				GetRemainBullet() { return m_iRemainBullet; }
	int				GetMaxBullet() { return m_iMagazineSize; }
	GUN_TYPE		GetGunType() { return m_eGunType; }
	void			FullReload() { m_iRemainBullet = m_iMagazineSize; }

protected:
	CObj*			m_pOwner;
	POINT			m_tPosin;
	GUN_TYPE		m_eGunType;

	int				m_iRemainBullet;
	int				m_iMagazineSize;
};

