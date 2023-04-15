#include "stdafx.h"
#include "ShotGun.h"
#include "Bullet.h"
#include "GameCore.h"
#include "Player.h"
#include "EventFunc.h"


CShotGun::CShotGun()
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

	m_iMagazineSize = 10;
}

int CShotGun::Update()
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

void CShotGun::Late_Update()
{
	m_tInfo.fX = CGameCore::GetInst()->GetPlayer()->Get_ShotPoint().x;
	m_tInfo.fY = CGameCore::GetInst()->GetPlayer()->Get_ShotPoint().y;

	POINT ptMouse = CGameCore::GetInst()->GetMousePos();
	m_fAngle = (atan2(m_tInfo.fY - (float)ptMouse.y, (float)ptMouse.x - m_tInfo.fX) * 57.2958f);

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));
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

void CShotGun::Reload_Gun()
{
	if (m_iRemainBullet <= 0 && m_dwTime + 1030 <= GetTickCount())
	{
		Create_Magazine();

		m_dwTime = GetTickCount();
	}
	else
		m_dwTime = GetTickCount();
}

void CShotGun::Fire_Gun()
{
	if (m_iRemainBullet > 0)
	{
		AddObjEvt(Create_Bullet());
		AddObjEvt(Create_Left_Bullet());
		AddObjEvt(Create_Right_Bullet());
		--m_iRemainBullet;
	}
}

void CShotGun::Create_Magazine()
{
	m_iRemainBullet = m_iMagazineSize;
}

CObj * CShotGun::Create_Bullet()
{
	CBullet* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tPosin.x, m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);
	pBullet->Set_GunType(m_eGunType);
	pBullet->Set_DirType(DIR_TYPE::UP);

	return pBullet;
}

CObj * CShotGun::Create_Left_Bullet()
{
	CBullet* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tPosin.x, m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);
	pBullet->Set_GunType(m_eGunType);
	pBullet->Set_DirType(DIR_TYPE::LEFT);

	return pBullet;
}

CObj * CShotGun::Create_Right_Bullet()
{
	CBullet* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tPosin.x, m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);
	pBullet->Set_GunType(m_eGunType);
	pBullet->Set_DirType(DIR_TYPE::RIGHT);

	return pBullet;
}
