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

	m_fDistance = 30.f;
}

int CFollwGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CFollwGun::Late_Update()
{
}

void CFollwGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CFollwGun::Release()
{

}

void CFollwGun::OnCollision(CObj * _pObj)
{
}
