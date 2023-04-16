#pragma once
#include "Obj.h"
class CBossBullet :
	public CObj
{
public:
	CBossBullet();
	virtual ~CBossBullet();

	// Inherited via CObj
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;

public:
	BOSSBULLET_TYPE		Get_BossBullet_Type() { return m_eBulletType; }
	void				Set_BossBullet_Type(BOSSBULLET_TYPE _eType) { m_eBulletType = _eType; }

private:
	BOSSBULLET_TYPE		m_eBulletType;
};

