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
	m_eBullType = BULLET_TYPE::SCRWGUN;
}

int CScrewGun::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;



	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CScrewGun::Late_Update()
{
}

void CScrewGun::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX - 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY - 30);
	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY);
}

void CScrewGun::Release()
{
}

void CScrewGun::OnCollision(CObj * _pObj)
{
}
