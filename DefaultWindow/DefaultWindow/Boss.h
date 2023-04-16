#pragma once
#include "Obj.h"
class CBoss :
	public CObj
{
public:
	CBoss();
	virtual ~CBoss();

	// Inherited via CObj
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;

protected:
	virtual	BOSS_PART Get_BossPart() { return m_eBossPart; }
	virtual	int Get_GunType() { return m_iGunType; }

	virtual void Set_BossSpeed(float _fSpeed) { m_fSpeed = _fSpeed; }
	virtual void Set_BossPosX(float _fX) { m_tInfo.fX = _fX; }
	virtual void Set_GunType(int _iType) { m_iGunType = _iType; }
private:
	void	Update_BossLocate();

protected:
	BOSS_PART	m_eBossPart;
	int			m_iGunType;

private:
	CObj*		m_pBossHead;
	CObj*		m_pBossGun_1;
	CObj*		m_pBossGun_2;
	CObj*		m_pBossMissile_Pot;
};

