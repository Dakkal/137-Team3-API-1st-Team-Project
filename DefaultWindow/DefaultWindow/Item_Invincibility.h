#pragma once
#include "Item.h"
class CItem_Invincibility :
	public CItem
{
public:
	explicit CItem_Invincibility();
	virtual ~CItem_Invincibility();

	// CItem을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;
	virtual void Use_Item(CObj * _pObj) override;
};

