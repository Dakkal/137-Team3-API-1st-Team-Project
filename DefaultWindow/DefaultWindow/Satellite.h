#pragma once
#include "Obj.h"

#define SATELLITE_SIZE 30.f
class CSatellite :
	public CObj
{
public:
	explicit CSatellite(CObj* _pPlayer);
	virtual ~CSatellite();

public:
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;

public:
	virtual void	OnCollision(CObj * _pObj) override;

public:
	void SetOwner(CObj* _pPlayer) { m_pOwner = _pPlayer; }

public:
	void Shoot();

private:
	CObj*	m_pOwner;
	float	m_fRotateSpeed;
	float	m_fDist;

	LONG	m_lShotDelayTime;
	LONG	m_lStartTime;
	LONG	m_lCurTime;

};

