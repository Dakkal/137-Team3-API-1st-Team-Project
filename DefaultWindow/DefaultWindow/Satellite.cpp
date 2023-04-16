#include "stdafx.h"
#include "Obj.h"
#include "Satellite.h"
#include "Player.h"
#include "EventFunc.h"
#include "Bullet.h"

CSatellite::CSatellite(CObj* _pPlayer)
	: CObj(OBJECT_TYPE::SATTELLITE)
	, m_pOwner(_pPlayer)
	, m_fRotateSpeed(5.f)
	, m_fDist(100.f)
	, m_lShotDelayTime(3000.f)
	, m_lCurTime(0.f)
{
	m_tInfo = INFO{ m_pOwner->Get_Info().fX, m_pOwner->Get_Info().fY, SATELLITE_SIZE, SATELLITE_SIZE };
	m_fAngle = 0.f;
}

CSatellite::~CSatellite()
{
}

void CSatellite::Initialize()
{
	m_lCurTime = GetTickCount();
	m_lStartTime = GetTickCount();
}

int CSatellite::Update()
{
	m_fAngle += m_fRotateSpeed;

	if (m_fAngle >= 360.f)
		m_fAngle = 0.f;
	
	m_tInfo = { m_pOwner->Get_Info().fX, m_pOwner->Get_Info().fY, SATELLITE_SIZE, SATELLITE_SIZE };

	m_tInfo.fX -= m_fDist * cos(m_fAngle * (PI / 180));
	m_tInfo.fY += m_fDist * sin(m_fAngle * (PI / 180));

	__super::Update_Rect();

	/*m_lCurTime = GetTickCount();
	if (m_lCurTime - m_lStartTime >= m_lShotDelayTime)
	{
		Shoot();
		m_lStartTime = GetTickCount();
	}*/

	return 0;
}

void CSatellite::Late_Update()
{
}

void CSatellite::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CSatellite::Release()
{

}

void CSatellite::OnCollision(CObj * _pObj)
{
	switch (_pObj->GetObjType())
	{
	case OBJECT_TYPE::MONSTER:
		break;
	case OBJECT_TYPE::ENEMY_PROJECTILE:
		break;
	}
}

void CSatellite::Shoot()
{
	CBullet* pBullet = new CBullet;
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	AddObjEvt(pBullet);
}
