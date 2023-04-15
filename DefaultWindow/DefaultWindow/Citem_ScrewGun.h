#pragma once
#include "Item.h"
class Citem_ScrewGun :
	public CItem
{
public:
	explicit Citem_ScrewGun();
	virtual ~Citem_ScrewGun();

	// CItem을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;
	virtual void Use_Item(CObj * _pObj) override;
};

