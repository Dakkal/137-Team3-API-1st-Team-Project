#pragma once
#include "Gun.h"
class CNormalGun :
	public CGun
{
public:
	explicit CNormalGun();
	virtual ~CNormalGun();

	// Inherited via CBullet
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	virtual void	OnCollision(CObj* _pObj)	override;

	// Inherited via CGun
	virtual void Reload_Gun() override;
	virtual void Fire_Gun() override;
	virtual CObj* Create_Bullet() override;
	virtual void Create_Magazine() override;

};

