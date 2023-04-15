#pragma once
#include "Item.h"
class CItem_Timestop :
	public CItem
{

public:
	explicit CItem_Timestop();
	virtual ~CItem_Timestop();


public:
	// CItem��(��) ���� ��ӵ�
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;

public:
	virtual void OnCollision(CObj * _pObj) override;
	virtual void Use_Item(CObj * _pObj) override;
};

