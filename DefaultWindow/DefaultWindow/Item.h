#pragma once
#include "Obj.h"

class CItem :
	public CObj
{
public:
	explicit CItem();
	virtual ~CItem();

public:
	// CObj을(를) 통해 상속됨
	virtual void	Initialize()					PURE;
	virtual int		Update()						PURE;
	virtual void	Late_Update()					PURE;
	virtual void	Render(HDC hDC) 				PURE;
	virtual void	Release()						PURE;					  	  
	virtual void	OnCollision(CObj* _pObj)		PURE;

public:
	virtual void Use_Item(CObj* _pObj) PURE;

};