#include "stdafx.h"
#include "NormalGun.h"


CNormalGun::CNormalGun()
{
	ZeroMemory(&m_tPosin, sizeof(POINT));
}


CNormalGun::~CNormalGun()
{
	Release();
}

void CNormalGun::Initialize()
{
	m_eGunType = GUN_TYPE::NORMALGUN;
	m_iBulletSize = 30;


	m_fDistance = 30.f;
}

int CNormalGun::Update()
{

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	__super::Update_Rect();

	return 0;
}

void CNormalGun::Late_Update()
{
}

void CNormalGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CNormalGun::Release()
{
}

void CNormalGun::OnCollision(CObj * _pObj)
{
}
