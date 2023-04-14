#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
	:CObj(OBJECT_TYPE::PLAYER_PROJECTILE), m_fBullRotAngle(0.f), m_fBullRotSpeed(0.f)
{
	ZeroMemory(&m_tCenter, sizeof(POINT));
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_tInfo.iAttack = 10;

	m_fSpeed = 5.f;
	m_fDistance = 30.f;
	m_bStart = true;
}

int CBullet::Update()
{
	if (m_bEvent == true)
		return OBJ_EVENT;

	if (GUN_TYPE::NORMALGUN == m_eGunType) { Normal_Pattern(); }
	if (GUN_TYPE::SHOTGUN == m_eGunType) { ShotGun_Pattern(); }
	if (GUN_TYPE::MACHINEGUN == m_eGunType) { MachineGun_Pattern(); }
	if (GUN_TYPE::SCRWGUN == m_eGunType) { ScrewGun_Pattern(); }
	if (GUN_TYPE::FOLLOWGUN == m_eGunType) { FolloewGun_Pattern(); }


	__super::Update_Rect();

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
	if (m_eDirType == DIR_TYPE::LEFT) 
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 90.f);
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
	}
	if (m_eDirType == DIR_TYPE::UP) 
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
	}
	if (m_eDirType == DIR_TYPE::RIGHT) 
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 720.f);
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
	}
}

void CBullet::MachineGun_Pattern()
{
	m_fSpeed = 8.f;

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
}

void CBullet::ScrewGun_Pattern()
{
	if( m_bStart == true)
	{
		m_tCenter.x = (LONG)m_tInfo.fX;
		m_tCenter.y = (LONG)m_tInfo.fY;
		m_bStart = false;
	} 

	m_tCenter.x += LONG(m_fSpeed * cosf(m_fAngle * PI / 180.f));
	m_tCenter.y -= LONG(m_fSpeed * sinf(m_fAngle * PI / 180.f));

	m_fBullRotAngle += m_fBullRotSpeed;

	m_tInfo.fX = m_tCenter.x + m_fDistance * cosf(m_fBullRotAngle * PI / 180.f);
	m_tInfo.fY = m_tCenter.y - m_fDistance * -sinf(m_fBullRotAngle * PI / 180.f);

}

void CBullet::FolloewGun_Pattern()
{
	float	fWidth = 0.f, fHeight = 0.f, fDiagonal = 0.f;
	float	fRadian = 0.f;

	fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
	fRadian = acosf(fWidth / fDiagonal);

	if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		fRadian *= -1.f;

	m_tInfo.fX += m_fSpeed * cosf(fRadian);
	m_tInfo.fY -= m_fSpeed * sinf(fRadian);

}

