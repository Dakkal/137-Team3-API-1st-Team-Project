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
	// CObj을(를) 통해 상속됨
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release()		override;

public:
	virtual void	OnCollision(CObj* _pObj)	override;

private:
	void			Key_Input();				// 키보드 입력
	void			Sort_Interval_Satellite();	// 플레이어 위성별 위치값 조정

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

	float			m_fAngle;			// 각도(Degree)

	POINT			m_ptShotPoint;		// Gun의 위치.
	int				m_iSatelliteCount;	// 플레이어의 위성 개수

	float			m_lFireDelay;		// 총알 발사 시간
	LONG			m_lRecoverTime;		// 충돌 변수 m_bCollision의 복구 시간.
	DWORD			dwCollisionTime;	// 시간 체크용 변수
	DWORD			dwFireTime;

	bool			m_bFire;
	
	CGun*			m_pGun;
	CGun*			m_pArrGun[(int)GUN_TYPE::END];
	
};

