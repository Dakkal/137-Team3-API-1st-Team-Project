#pragma once
#include "Item.h"
class CItem_MachineGun :
	public CItem
{
public:
	explicit CItem_MachineGun();
	virtual ~CItem_MachineGun();

	// CItem��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;
	virtual void Use_Item(CObj * _pObj) override;
};

