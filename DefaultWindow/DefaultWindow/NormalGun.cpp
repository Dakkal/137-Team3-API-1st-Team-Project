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
	m_eGunType = GUN_TYPE::NORMALGUN;
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
}

void CNormalGun::Release()
{
}

void CNormalGun::OnCollision(CObj * _pObj)
{
}
