#pragma once
#include "Item.h"
class Citem_ShotGun :
	public CItem
{
public:
	explicit Citem_ShotGun();
	virtual ~Citem_ShotGun();

	// CItem��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;
	virtual void Use_Item(CObj * _pObj) override;
};

