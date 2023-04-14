#include "stdafx.h"
#include "FollowGun.h"


CFollowGun::CFollowGun()
{
}


CFollowGun::~CFollowGun()
{
	Release();
}

void CFollowGun::Initialize()
{
	m_eGunType = GUN_TYPE::FOLLOWGUN;

	m_fDistance = 30.f;
}

int CFollowGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CFollowGun::Late_Update()
{
}

void CFollowGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CFollowGun::Release()
{

}

void CFollowGun::OnCollision(CObj * _pObj)
{
}
