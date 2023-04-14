#pragma once
#include "Obj.h"
class CEnemy :
	public CObj
{
public:
	explicit CEnemy();
	virtual ~CEnemy();

public:
	// CObj을(를) 통해 상속됨
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release()		override;

	virtual void	OnCollision(CObj* _pObj)	override;
};

