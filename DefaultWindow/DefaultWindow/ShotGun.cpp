#include "stdafx.h"
#include "ShotGun.h"


CShotGun::CShotGun()
{
}


CShotGun::~CShotGun()
{
	Release();
}

void CShotGun::Initialize()
{
	m_eGunType = GUN_TYPE::SHOTGUN;
}

int CShotGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CShotGun::Late_Update()
{
}

void CShotGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX - 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY - 30);
	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY);
}

void CShotGun::Release()
{
}

void CShotGun::OnCollision(CObj * _pObj)
{
}
