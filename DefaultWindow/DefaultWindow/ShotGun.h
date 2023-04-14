#pragma once
#include "Gun.h"
class CShotGun :
	public CGun
{
public:
	explicit CShotGun();
	virtual ~CShotGun();

	// Inherited via CBullet
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	virtual void	OnCollision(CObj* _pObj)	override;

	void	Set_Dir_Type(DIR_TYPE _eDirType) { m_eDirType = _eDirType; }

private:
	DIR_TYPE		m_eDirType;
};

