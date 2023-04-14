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
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release()		override;

	virtual void	OnCollision(CObj* _pObj)	override;
};

