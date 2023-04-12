#pragma once

#include "stdafx.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void	Initialize()      PURE;
	virtual int		Update()	      PURE;
	virtual void	Late_Update()	  PURE;
	virtual void	Render(HDC hDC)	  PURE;
	virtual void	Release()		  PURE;

protected:
	void		Update_Rect();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;

	float		m_fSpeed;
};

