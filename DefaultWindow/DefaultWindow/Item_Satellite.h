#pragma once
#include "Item.h"
class CItem_Satellite :
	public CItem
{
public:
	CItem_Satellite();
	virtual ~CItem_Satellite();

	// CItem��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;
	virtual void Use_Item(CObj * _pObj) override;
};

