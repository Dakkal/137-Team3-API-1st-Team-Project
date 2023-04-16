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

public:
	virtual	BOSS_PART Get_BossPart() { return m_eBossPart; }
	virtual	int Get_GunType() { return m_iGunType; }

	virtual void Set_BossSpeed(float _fSpeed) { m_fSpeed = _fSpeed; }
	virtual void Set_BossPosX(float _fX) { m_tInfo.fX = _fX; }
	virtual void Set_GunType(int _iType) { m_iGunType = _iType; }
private:
	void	Update_BossLocate();
	CObj*	Create_Head();
	CObj*	Create_Gun1();
	CObj*	Create_Gun2();
	CObj*	Create_Missile_Pot();

protected:
	BOSS_PART	m_eBossPart;
	int			m_iGunType;
};

