#pragma once
#include "Bullet.h"
class CScrewGun :
	public CBullet
{
public:
	explicit CScrewGun();
	virtual ~CScrewGun();

	// Inherited via CBullet
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	virtual void OnCollision(CObj * _pObj) override;
};

