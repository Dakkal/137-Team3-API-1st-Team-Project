#include "stdafx.h"
#include "MachineGun.h"


CMachineGun::CMachineGun()
{
}


CMachineGun::~CMachineGun()
{
	Release();
}

void CMachineGun::Initialize()
{
	m_eBullType = BULLET_TYPE::MACHINEGUN;
}

int CMachineGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;




	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMachineGun::Late_Update()
{
}

void CMachineGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX - 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY - 30);
	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY);
}

void CMachineGun::Release()
{
}

void CMachineGun::OnCollision(CObj * _pObj)
{
}
