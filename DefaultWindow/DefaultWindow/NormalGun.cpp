#include "stdafx.h"
#include "NormalGun.h"


CNormalGun::CNormalGun()
{
}


CNormalGun::~CNormalGun()
{
	Release();
}

void CNormalGun::Initialize()
{
	m_eBullType = BULLET_TYPE::NORMALGUN;
}

int CNormalGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CNormalGun::Late_Update()
{
}

void CNormalGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX - 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY - 30);
	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY);
}

void CNormalGun::Release()
{
}

void CNormalGun::OnCollision(CObj * _pObj)
{
}
