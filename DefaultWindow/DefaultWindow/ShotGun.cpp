#include "stdafx.h"
#include "ShotGun.h"


CShotGun::CShotGun()
	: m_eDirType(DIR_TYPE::END)
{
}


CShotGun::~CShotGun()
{
	Release();
}

void CShotGun::Initialize()
{
	m_eGunType = GUN_TYPE::SHOTGUN;

	m_fDistance = 30.f;
}

int CShotGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CShotGun::Late_Update()
{
}

void CShotGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tPosin.x, m_tPosin.y);
}

void CShotGun::Release()
{
}

void CShotGun::OnCollision(CObj * _pObj)
{
}
