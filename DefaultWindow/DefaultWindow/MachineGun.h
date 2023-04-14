#pragma once
#include "Bullet.h"
class CMachineGun :
	public CBullet
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

