#include "stdafx.h"
#include "NormalGun.h"
#include "Bullet.h"
#include "GameCore.h"
#include "Player.h"
#include "EventFunc.h"


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
	m_fDistance = 30.f;

	m_iMagazineSize = 30;

	Create_Magazine();
}

int CNormalGun::Update()
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

void CNormalGun::Late_Update()
{

	m_tInfo.fX = CGameCore::GetInst()->GetPlayer()->Get_ShotPoint().x;
	m_tInfo.fY = CGameCore::GetInst()->GetPlayer()->Get_ShotPoint().y;

	POINT ptMouse = CGameCore::GetInst()->GetMousePos();
	m_fAngle = (atan2(m_tInfo.fY - (float)ptMouse.y, (float)ptMouse.x - m_tInfo.fX) * 57.2958f);

	m_tPosin.x = LONG(m_tInfo.fX + (m_fDistance * cos(m_fAngle * (PI / 180.f))));
	m_tPosin.y = LONG(m_tInfo.fY - (m_fDistance * sin(m_fAngle * (PI / 180.f))));

	Reload_Gun();
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

void CNormalGun::Reload_Gun()
{
	if (m_iRemainBullet <= 0 && m_dwTime + 1010 <= GetTickCount())
	{
		Create_Magazine();

		m_dwTime = GetTickCount();
	}
	else
		m_dwTime = GetTickCount();
}

void CNormalGun::Fire_Gun()
{
	if (m_iRemainBullet > 0)
	{
		AddObjEvt(Create_Bullet());
		--m_iRemainBullet;
	}
}

CObj * CNormalGun::Create_Bullet()
{
	CBullet* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tPosin.x, m_tPosin.y);
	pBullet->Set_Angle(m_fAngle);
	pBullet->Set_GunType(m_eGunType);

	return pBullet;
}

void CNormalGun::Create_Magazine()
{
	m_iRemainBullet = m_iMagazineSize;
}