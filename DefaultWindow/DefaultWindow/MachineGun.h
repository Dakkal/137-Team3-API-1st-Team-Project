#pragma once
#include "Gun.h"
class CMachineGun :
	public CGun
{
public:
	explicit CMachineGun();
	virtual ~CMachineGun();

	// Inherited via CBullet
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	virtual void	OnCollision(CObj* _pObj)	override;
};

