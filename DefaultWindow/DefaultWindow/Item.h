#pragma once
#include "Obj.h"

class CItem :
	public CObj
{
public:
	explicit CItem();
	virtual ~CItem();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void	Initialize()					PURE;
	virtual int		Update()						PURE;
	virtual void	Late_Update()					PURE;
	virtual void	Render(HDC hDC) 				PURE;
	virtual void	Release()						PURE;
	virtual void	OnCollision(CObj* _pObj)		PURE;
	virtual void Use_Item(CObj* _pObj) PURE;
	virtual void Set_Magnetic(bool _bMagnetic) { m_bMagnetic = _bMagnetic; }

protected:
	float	m_fWidth;
	float m_fHeight;
	float m_fDiagonal;
	float	m_fRadian;

	bool m_bMagnetic;

};