#pragma once
#include "Boss.h"
class CBossGun :
	public CBoss
{
public:
	CBossGun(CBoss*	_pOwner);
	virtual ~CBossGun();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;


public:
	void		SetGunType(int _i) { m_iGunType = _i; }


private:
	CObj*		Create_Bullet_1();
	CObj*		Create_Bullet_2();

	void		GenerateSpecialPattern();
	void		Pattern1();
	void		Pattern2();
private:
	CBoss*	m_pOwner;
	DWORD	m_dwCollisionTime;
	LONG	m_lRecoverTime;

	DWORD	m_dwSpecialTime;
	LONG	m_lSpecialTime;

};

