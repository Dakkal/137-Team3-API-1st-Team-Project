#pragma once
#include "Item.h"
class CEquip :
	public CItem
{
public:
	CEquip();
	~CEquip();

	// CItem��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision() override;
};

