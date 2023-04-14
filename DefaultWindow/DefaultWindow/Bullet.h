#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	explicit CBullet();
	virtual ~CBullet();

public:
	// CObj을(를) 통해 상속됨
	virtual void	Initialize()	PURE;
	virtual int		Update()		PURE;
	virtual void	Late_Update()	PURE;
	virtual void	Render(HDC hDC) PURE;
	virtual void	Release()		PURE;

public:
	virtual void	OnCollision(CObj* _pObj)	PURE;

	BULLET_TYPE Get_BullType() { return m_eBullType; }

	void Set_BullType(BULLET_TYPE _eBullType) { m_eBullType = _eBullType; }
	

protected:
	BULLET_TYPE		m_eBullType;

};

