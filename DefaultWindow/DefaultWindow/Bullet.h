#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	explicit CBullet();
	virtual ~CBullet();

public:
	// CObj을(를) 통해 상속됨
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release()		override;

public:
	virtual void	OnCollision(CObj* _pObj)	override;

	//GUN_TYPE Get_GunType() { return m_eGunType; }

	void Set_GunType(GUN_TYPE _eGunType) { m_eGunType = _eGunType; }
	void Set_DirType(DIR_TYPE _eDirType) { m_eDirType = _eDirType; }
	
public:
	void		Normal_Pattern();
	void		ShotGun_Pattern();
	void		MachineGun_Pattern();
	void		ScrewGun_Pattern();
	void		FolloewGun_Pattern();


protected:
	GUN_TYPE		m_eGunType;
	DIR_TYPE		m_eDirType;

	POINT			m_tCenter;
	float			m_fBullRotAngle;
	float			m_fBullRotSpeed;

	bool			m_bStart;

};

