#include "stdafx.h"
#include "FollowGun.h"
#include "Bullet.h"
#include "GameCore.h"
#include "Player.h"
#include "EventFunc.h"

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

	m_iMagazineSize = 10;

	Create_Magazine();
}

int CFollowGun::Update()
{
	m_tInfo.fX = CGameCore::GetInst()->GetPlayer()->Get_ShotPoint().x;
	m_tInfo.fY = CGameCore::GetInst()->GetPlayer()->Get_ShotPoint().y;

	POINT ptMouse = CGameCore::GetInst()->GetMousePos();
	m_fAngle = (atan2(m_tInfo.fY - (float)ptMouse.y, (float)ptMouse.x - m_tInfo.fX) * 57.2958f);

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	__super::Update_Rect();

	return 0;
}

void CFollowGun::Late_Update()
{
	m_tInfo.fX = CGameCore::GetInst()->GetPlayer()->Get_ShotPoint().x;
	m_tInfo.fY = CGameCore::GetInst()->GetPlayer()->Get_ShotPoint().y;

	POINT ptMouse = CGameCore::GetInst()->GetMousePos();
	m_fAngle = (atan2(m_tInfo.fY - (float)ptMouse.y, (float)ptMouse.x - m_tInfo.fX) * 57.2958f);

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	Reload_Gun();
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

void CFollowGun::Reload_Gun()
{
	if (m_iRemainBullet <= 0 && m_dwTime + 1040 <= GetTickCount())
	{
		Create_Magazine();

		m_dwTime = GetTickCount();
	}
}

void CFollowGun::Fire_Gun()
{
	if (m_iRemainBullet > 0)
	{
		AddObjEvt(Create_Bullet());
		--m_iRemainBullet;
	}
}

void CFollowGun::Create_Magazine()
{
	m_iRemainBullet = m_iMagazineSize;
}

CObj * CFollowGun::Create_Bullet()
{
	CBullet* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tPosin.x, m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);
	pBullet->Set_GunType(m_eGunType);

	return pBullet;
}
