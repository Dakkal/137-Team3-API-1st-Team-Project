#include "stdafx.h"
#include "BossMissile.h"
#include "BossBullet.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"

CBossMissile::CBossMissile()
{
}


CBossMissile::~CBossMissile()
{
	Release();
}

void CBossMissile::Initialize()
{
	m_eBossPart = BOSS_PART::MISSILE;

	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;

	m_fSpeed = 3.f;
	m_tInfo.iHp = 1;
}

int CBossMissile::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super::Update_Rect();


	if (m_tInfo.fY >= 400.f)
	{
		const float fInterval = 360.f / 12.f;
		for (int i = 0; i < 12; ++i)
		{
			AddObjEvt(Create_Missile_Bullet());
			m_fAngle += fInterval;
		}
		m_fAngle = 0.f;
		DeleteObjEvt(this);
	}

	

	return 0;
}

void CBossMissile::Late_Update()
{
}


void CBossMissile::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom + 20);
}

void CBossMissile::Release()
{
}

void CBossMissile::OnCollision(CObj * _pObj)
{
	if (!m_bCollision)
		return;

	switch (_pObj->GetObjType())
	{
	case OBJECT_TYPE::PLAYER_PROJECTILE:
		DeleteObjEvt(this);
		break;
	}
	m_bCollision = false;
}

CObj* CBossMissile::Create_Missile_Bullet()
{
	CBossBullet* pBossBullet = new CBossBullet;
	pBossBullet->Initialize();
	pBossBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	pBossBullet->Set_Angle(m_fAngle);
	pBossBullet->Set_BossBullet_Type(BOSSBULLET_TYPE::FIREWORK);

	return pBossBullet;
}
