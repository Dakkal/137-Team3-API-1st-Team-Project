#include "stdafx.h"
#include "BossGun.h"
#include "BossBullet.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"

CBossGun::CBossGun(CBoss* _pOwner)
	: m_pOwner(_pOwner)
	, m_dwCollisionTime(GetTickCount())
	, m_lRecoverTime(100)
	, m_lSpecialTime(1000)
{
}


CBossGun::~CBossGun()
{
	Release();
}

void CBossGun::Initialize()
{
	m_eBossPart = BOSS_PART::GUN;
	m_dwTime = GetTickCount();
	m_dwSpecialTime = GetTickCount();

	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 100.f;

	m_iHp		= 20;
	m_iMaxHp	= 20;

	m_fSpeed = m_pOwner->GetSpeed();

}

int CBossGun::Update()
{

	m_fSpeed = m_pOwner->GetSpeed();
	m_tInfo.fX += m_fSpeed;
	if (m_iHp <= 0)
	{
		m_pOwner->Destroy_Child();
		DeleteObjEvt(this);
	}
		
	if (!m_bCollision)
	{
		if (m_dwCollisionTime + m_lRecoverTime < GetTickCount())
		{
			m_bCollision = true;
			m_dwCollisionTime = GetTickCount();
		}
	}
	

	if (m_dwTime + 1400 <= GetTickCount())
	{
		if (m_iGunType == 1)
			AddObjEvt(Create_Bullet_1());

		if (m_iGunType == 2)
			AddObjEvt(Create_Bullet_2());

		m_dwTime = GetTickCount();
	}

	if (m_dwSpecialTime + m_lSpecialTime <= GetTickCount() && m_iHp < (m_iMaxHp / 2))
	{
		GenerateSpecialPattern();
		m_dwSpecialTime = GetTickCount();
	}

	__super::Update_Rect();
	return 0;
}

void CBossGun::Late_Update()
{
	if (m_iGunType == 1)
	{
		if (m_tRect.left <= 0 + 10.f || m_tRect.right >= WINCX - 170.f)
			m_fSpeed *= -1.f;
	}

	if (m_iGunType == 2)
	{
		if (m_tRect.left <= 0 + 170.f || m_tRect.right >= WINCX - 10.f)
			m_fSpeed *= -1.f;
	}
	

}

void CBossGun::Render(HDC hDC)
{
	if (!m_bCollision)
	{
		SelectGDI g(hDC, BRUSH_TYPE::RED);
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	}
	else
	{
		SelectGDI pen(hDC, BRUSH_TYPE::ORANGE);
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	}

	for (int i = 0; i < m_iMaxHp; ++i)
	{
		RECT rect = GetRectWithXY((int)m_tInfo.fX - 70, (int)m_tInfo.fY, (10 * (i / 2 + 1)), 70, 10);

		if (i % 2 == 0)
			continue;

		if (m_iHp >= i + 1)
		{
			SelectGDI g(hDC, BRUSH_TYPE::RED);
			Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
		}
		else
		{
			SelectGDI g(hDC, BRUSH_TYPE::HOLLOW);
			Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
		}
	}
}

void CBossGun::Release()
{
}

void CBossGun::OnCollision(CObj * _pObj)
{
	if (!m_bCollision)
		return;

	switch (_pObj->GetObjType())
	{
	case OBJECT_TYPE::PLAYER_PROJECTILE:
		m_iHp--;
		break;
	}
	m_bCollision = false;
}

CObj* CBossGun::Create_Bullet_1()
{
	CBossBullet* pBullet = new CBossBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	pBullet->Set_BossBullet_Type(BOSSBULLET_TYPE::NORMAL);

	return pBullet;
}

CObj* CBossGun::Create_Bullet_2()
{
	CBossBullet* pBullet = new CBossBullet;
	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tRect.bottom + 40);
	pBullet->Set_BossBullet_Type(BOSSBULLET_TYPE::FOLLOW);

	return pBullet;
}

void CBossGun::GenerateSpecialPattern()
{
	int iRandom = rand() % 200;

	if (iRandom % 2 == 0)
		Pattern1();
	else
		Pattern2();
}

void CBossGun::Pattern1()
{
	const float fInterval = 360.f / 12.f;
	for (int i = 0; i < 12; ++i)
	{
		CBossBullet* pBossBullet = new CBossBullet;
		pBossBullet->Initialize();
		pBossBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
		pBossBullet->Set_Angle(m_fAngle);
		pBossBullet->Set_BossBullet_Type(BOSSBULLET_TYPE::NORMAL);
		AddObjEvt(pBossBullet);

		m_fAngle += fInterval;
	}
	m_fAngle = 0;
}

void CBossGun::Pattern2()
{
	const float fInterval = 360.f / 12.f;
	for (int i = 0; i < 12; ++i)
	{
		CBossBullet* pBossBullet = new CBossBullet;
		pBossBullet->Initialize();
		pBossBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
		pBossBullet->Set_Angle(m_fAngle);
		pBossBullet->Set_BossBullet_Type(BOSSBULLET_TYPE::NORMAL);
		AddObjEvt(pBossBullet);

		m_fAngle += fInterval;
	}
	m_fAngle = 0;
}
