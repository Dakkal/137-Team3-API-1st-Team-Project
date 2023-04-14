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
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release()		override;

	virtual void	OnCollision()	override;

public:
	void Set_BullType(BULLET_TYPE _eBullType) { m_eBullType = _eBullType; }

private:
	BULLET_TYPE		m_eBullType;
	OBJECT_TYPE		m_eBullObject;
};

