#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
	:CObj(OBJECT_TYPE::PLAYER_PROJECTILE)
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_tInfo.iAttack = 10;

	m_fSpeed = 5.f;
}

int CBullet::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;

	if (m_eGunType == GUN_TYPE::NORMALGUN) { Normal_Pattern(); }
	if (m_eGunType == GUN_TYPE::SHOTGUN) { ShotGun_Pattern(); }
	if (m_eGunType == GUN_TYPE::MACHINEGUN) { MachineGun_Pattern(); }
	if (m_eGunType == GUN_TYPE::SCRWGUN) { ScrewGun_Pattern(); }
	if (m_eGunType == GUN_TYPE::FOLLOWGUN) { FolloewGun_Pattern(); }

	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
}

void CBullet::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX - 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY - 30);
	LineTo(hDC, m_tInfo.fX + 10, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY);
}

void CBullet::Release()
{
}

void CBullet::OnCollision(CObj * _pObj)
{
	if (m_eObjType == OBJECT_TYPE::MONSTER)
	{
		Safe_Delete<CObj*>(_pObj);
	}
}

void CBullet::Normal_Pattern()
{
	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
}

void CBullet::ShotGun_Pattern()
{
}

void CBullet::MachineGun_Pattern()
{
}

void CBullet::ScrewGun_Pattern()
{
}

void CBullet::FolloewGun_Pattern()
{
}

