#include "stdafx.h"
#include "FollwGun.h"


CFollwGun::CFollwGun()
{
}


CFollwGun::~CFollwGun()
{
	Release();
}

void CFollwGun::Initialize()
{
	m_eGunType = GUN_TYPE::FOLLOWGUN;
}

int CFollwGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;


	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CFollwGun::Late_Update()
{
}

void CFollwGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX - 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY - 30);
	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY);
}

void CFollwGun::Release()
{

}

void CFollwGun::OnCollision(CObj * _pObj)
{
}
