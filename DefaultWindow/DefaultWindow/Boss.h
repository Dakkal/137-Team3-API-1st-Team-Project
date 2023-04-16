#pragma once
#include "Obj.h"
class CBoss :
	public CObj
{
public:
	explicit CBoss();
	virtual ~CBoss();

public:
	// Inherited via CObj
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnCollision(CObj * _pObj) override;

public:
	float	GetSpeed() { return m_fSpeed; }
	void	Destroy_Child() { --m_iCountPart; }
	int		IsDestroy() { return m_iCountPart <= 0; }

private:
	void	Create_Head();
	void	Create_Gun1();
	void	Create_Gun2();
	void	Create_Missile_Pot();

protected:
	BOSS_PART	m_eBossPart;
	int			m_iGunType;

	int			m_iHp;
	int			m_iMaxHp;

	int			m_iCountPart;

};

