#pragma once
#include "Item.h"
class CItem_Ball :
	public CItem
{
public:
	explicit CItem_Ball();
	virtual ~CItem_Ball();

	// CItem��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;
	virtual void Use_Item(CObj * _pObj) override;

private:
	int m_iCount;
};

