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
	RECT Get_Rect() { return m_tRect; }
	INFO Get_Info() { return m_tInfo; }

	void Set_Pos(float _X, float _Y)
	{
		m_tInfo.fX = _X;
		m_tInfo.fY = _Y;
	}


protected:
	void		Update_Rect();


protected:
	INFO			m_tInfo;
	RECT			m_tRect;


	OBJECT_TYPE		m_eObjType;
	float			m_fSpeed;

	bool			m_bEvent;
};

