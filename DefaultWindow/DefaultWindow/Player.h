#pragma once
#include "Obj.h"

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

private:
	int				m_iHp;
	int				m_iMaxHp;

	float			m_fAngle;			// ����(Degree)
	float			m_fAccTime;			// �帥�ð�
	float			m_fInvinTime;		// �����ð�
	POINT			m_ptShotPoint;		// TODO :: Delete(Gun�� ��ġ.)

	int				m_iSatelliteCount;	// �÷��̾��� ���� ����

	LONG			m_lRecoverTime;		// �浹 ���� m_bCollision�� ���� �ð�.
	DWORD			dwTime;				// �ð� üũ�� ����


public:
	CObj*		Get_Gun();

	void		Set_Gun(list<CObj*>* _pGunList) { m_pGunList = _pGunList; }
	POINT		Get_ShotPoint() { return m_ptShotPoint; }

private:
	list<CObj*>*		m_pGunList;
	
};

