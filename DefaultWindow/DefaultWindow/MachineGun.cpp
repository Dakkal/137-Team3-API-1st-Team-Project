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
	m_eGunType = GUN_TYPE::MACHINEGUN;

	m_fDistance = 30.f;
}

int CMachineGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMachineGun::Late_Update()
{
}

void CMachineGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CMachineGun::Release()
{
}

void CMachineGun::OnCollision(CObj * _pObj)
{
}
