#pragma once
#include "Boss.h"
class CBossMissile :
	public CBoss
{
public:
	CBossMissile();
	virtual ~CBossMissile();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;

public:
	virtual	BOSS_PART Get_BossPart() override { return m_eBossPart; }
	virtual	int Get_GunType() override { return m_iGunType; }

	virtual void Set_BossSpeed(float _fSpeed) override { m_fSpeed = _fSpeed; }
	virtual void Set_BossPosX(float _fX) override { m_tInfo.fX = _fX; }
	virtual void Set_GunType(int _iType) override { m_iGunType = _iType; }

private:
	CObj*	Create_Missile_Bullet();
	int		iCount;
};

