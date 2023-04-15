#pragma once
#include "Obj.h"

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

private:
	int				m_iHp;
	int				m_iMaxHp;

	float			m_fAngle;			// 각도(Degree)
	float			m_fAccTime;			// 흐른시간
	float			m_fInvinTime;		// 무적시간
	POINT			m_ptShotPoint;		// TODO :: Delete(Gun의 위치.)

	int				m_iSatelliteCount;	// 플레이어의 위성 개수

	LONG			m_lRecoverTime;		// 충돌 변수 m_bCollision의 복구 시간.
	DWORD			dwTime;				// 시간 체크용 변수


public:
	CObj*		Get_Gun();

	void		Set_Gun(list<CObj*>* _pGunList) { m_pGunList = _pGunList; }
	POINT		Get_ShotPoint() { return m_ptShotPoint; }

private:
	list<CObj*>*		m_pGunList;
	
};

