#pragma once
#include "Item.h"
class CEquip :
	public CItem
{
public:
	CEquip();
	~CEquip();

	/*EQUIP_TYPE Get_EquipType(void) { return m_eEquipType; }*/
	// CItem을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision() override;

private:
	//EQUIP_TYPE m_eEquipType;
};

