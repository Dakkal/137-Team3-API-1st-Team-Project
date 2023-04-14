#pragma once

#include "stdafx.h"

class CObj
{
public:
	explicit CObj(OBJECT_TYPE _eType);
	virtual ~CObj();

public:
	virtual void	Initialize()					PURE;
	virtual int		Update()						PURE;
	virtual void	Late_Update()					PURE;
	virtual void	Render(HDC hDC)					PURE;
	virtual void	Release()						PURE;


	virtual void	OnCollision(CObj* _pObj)		PURE;

public:
	OBJECT_TYPE GetObjType() { return m_eObjType; }
	INFO		Get_Info() { return m_tInfo; }
	RECT		Get_Rect() { return m_tRect; }


	void Set_Pos(float _X, float _Y){m_tInfo.fX = _X; m_tInfo.fY = _Y;}
	void Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void Set_Dis(float _fDis) { m_fDistance = _fDis; }
	void Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
	void Set_ObjType(OBJECT_TYPE _eObjType) { m_eObjType = _eObjType; }


protected:
	void		Update_Rect();


protected:
	INFO			m_tInfo;
	RECT			m_tRect;
	CObj*			m_pTarget;
	DWORD			m_dwTime;

	OBJECT_TYPE		m_eObjType;

	float			m_fSpeed;
	float			m_fAngle;
	float			m_fDistance;

	bool			m_bEvent;
};

