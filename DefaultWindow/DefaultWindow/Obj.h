#pragma once

#include "stdafx.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void	Initialize(void)  PURE;
	virtual int		Update(void)	  PURE;
	virtual void	Late_Update(void) PURE;
	virtual void	Render(HDC hDC)	  PURE;
	virtual void	Release(void)	  PURE;

protected:
	void		Update_Rect(void);

protected:
	INFO		m_tInfo;
	RECT		m_tRect;

	float		m_fSpeed;
};

