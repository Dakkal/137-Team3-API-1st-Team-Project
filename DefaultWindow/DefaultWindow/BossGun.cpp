#include "stdafx.h"
#include "BossGun.h"
#include "BossBullet.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"

CBossGun::CBossGun(CBoss* _pOwner)
	: m_pOwner(_pOwner)
	, dwCollisionTime(GetTickCount())
	, m_lRecoverTime(100)
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

	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_iHp		= 1;
	m_iMaxHp	= 20;

	m_fSpeed = m_pOwner->GetSpeed();

}

int CBossGun::Update()
{

	m_fSpeed = m_pOwner->GetSpeed();
	if (m_iHp <= 0)
	{
		m_pOwner->Destroy_Child();
		DeleteObjEvt(this);
	}
		
	if (!m_bCollision)
	{
		if (dwCollisionTime + m_lRecoverTime < GetTickCount())
		{
			m_bCollision = true;
			dwCollisionTime = GetTickCount();
		}
	}

	m_tInfo.fX += m_fSpeed;

	if (m_dwTime + 1400 <= GetTickCount())
	{
		if (m_iGunType == 1)
			AddObjEvt(Create_Bullet_1());

		if (m_iGunType == 2)
			AddObjEvt(Create_Bullet_2());

		m_dwTime = GetTickCount();
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
		SelectGDI pen(hDC, PEN_TYPE::BLUE);
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom + 40);
	}
	else
	{
		SelectGDI pen(hDC, PEN_TYPE::BLUE);
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom + 40);
	}

	for (int i = 0; i < m_iMaxHp; ++i)
	{
		RECT rect = GetRectWithXY((int)m_tInfo.fX, (int)m_tInfo.fY, -40, -1 * (10 * (i + 1)), 10);
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
