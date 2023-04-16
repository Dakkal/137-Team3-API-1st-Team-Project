#include "stdafx.h"
#include "BossMissile.h"
#include "BossBullet.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"

CBossMissile::CBossMissile() : iCount(1)
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
	m_tInfo.iHp = 2;
}

int CBossMissile::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super::Update_Rect();

	if (m_tInfo.fY >= 300.f)
	{
		for (int i = 0; i < 8; ++i)
		{
			AddObjEvt(Create_Missile_Bullet());
			m_fAngle += (i + 1.f) * 80.f;
		}
		m_fAngle = 0.f;
		DeleteObjEvt(this);
	}

	if (m_tInfo.iHp <= 0)
	{
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
	if (OBJECT_TYPE::PLAYER_PROJECTILE == _pObj->GetObjType())
	{
		m_tInfo.iHp -= _pObj->Get_Info().iAttack;
	}
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
