#include "stdafx.h"
#include "ScrewGun.h"


CScrewGun::CScrewGun()
{
}


CScrewGun::~CScrewGun()
{
	Release();
}

void CScrewGun::Initialize()
{
	m_eGunType = GUN_TYPE::SCREWGUN;

	m_fDistance = 30.f;
}

int CScrewGun::Update()
{

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	__super::Update_Rect();

	return 0;

}

void CScrewGun::Late_Update()
{
}

void CScrewGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CScrewGun::Release()
{
}

void CScrewGun::OnCollision(CObj * _pObj)
{
}
