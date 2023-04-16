#pragma once
#include "Obj.h"
#include "CustomFunc.h"

class CGun;
class CPlayer :	public CObj
{
public:
	explicit CPlayer();
	virtual ~CPlayer();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release()		override;

public:
	virtual void	OnCollision(CObj* _pObj)	override;

private:
	void			Key_Input();				// Ű���� �Է�
	void			Sort_Interval_Satellite();	// �÷��̾� ������ ��ġ�� ����

public:
	CGun*			Get_Gun()					{ return m_pGun; }
	void			Set_Gun(GUN_TYPE _eType)	{ m_pGun = m_pArrGun[(int)_eType]; }
	POINT			Get_ShotPoint()				{ return m_ptShotPoint; }
	int				Get_Hp()					{ return m_iHp; }
	void			Set_Hp(int iHp)				{ m_iHp = iHp; }


	void			Set_FireDelay(float _f)		{ m_lFireDelay = _f; }

private:
	void			OnDamaged();

private:
	int				m_iHp;
	int				m_iMaxHp;

	float			m_fAngle;			// ����(Degree)

	POINT			m_ptShotPoint;		// Gun�� ��ġ.
	int				m_iSatelliteCount;	// �÷��̾��� ���� ����

	float			m_lFireDelay;		// �Ѿ� �߻� �ð�
	LONG			m_lRecoverTime;		// �浹 ���� m_bCollision�� ���� �ð�.
	DWORD			dwCollisionTime;	// �ð� üũ�� ����
	DWORD			dwFireTime;

	bool			m_bFire;
	
	CGun*			m_pGun;
	CGun*			m_pArrGun[(int)GUN_TYPE::END];
	
};

