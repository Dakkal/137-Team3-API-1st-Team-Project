#pragma once
#include "Item.h"
class Ccunsumption :
	public CItem
{
public:
	Ccunsumption();
	~Ccunsumption();

	// CItem��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision() override;


	// CItem��(��) ���� ��ӵ�
	virtual void Use_Item() override;

};

