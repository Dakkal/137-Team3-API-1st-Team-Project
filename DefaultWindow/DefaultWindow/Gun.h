#pragma once
#include "Obj.h"
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
	virtual void OnCollision(CObj * _pObj) PURE;

	virtual void Reload_Gun() PURE;
	virtual void Fire_Gun() PURE;
	virtual void Create_Magazine() PURE;
	virtual CObj* Create_Bullet() PURE;


	/*GUN_TYPE Get_GunType() { return m_eGunType; }
	void Set_GunType(GUN_TYPE _eGunType) { m_eGunType = _eGunType; }*/


protected:
	POINT			m_tPosin;
	GUN_TYPE		m_eGunType;

	int				m_iRemainBullet;
	int				m_iMagazineSize;
};

