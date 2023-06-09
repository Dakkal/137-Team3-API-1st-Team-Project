#pragma once

#include "stdafx.h"

class CObj
{
public:
	explicit CObj(OBJECT_TYPE _eType);
	virtual ~CObj();

public:
	virtual void	Initialize()		PURE;
	virtual int		Update()			PURE;
	virtual void	Late_Update()		PURE;
	virtual void	Render(HDC hDC)		PURE;
	virtual void	Release()			PURE;
	virtual void	OnCollision()		PURE;

public:
	OBJECT_TYPE GetObjType() { return m_eObjType; }

protected:
	void		Update_Rect();


protected:
	INFO			m_tInfo;
	RECT			m_tRect;


	OBJECT_TYPE		m_eObjType;
	float			m_fSpeed;
};

