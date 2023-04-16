#include "stdafx.h"
#include "BossGun.h"
#include "BossBullet.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"

CBossGun::CBossGun()
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
	m_tInfo.iHp = 100;

}

int CBossGun::Update()
{
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
	if (m_tInfo.iHp <= 0)
		DeleteObjEvt(this);
}

void CBossGun::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom + 40);
}

void CBossGun::Release()
{
}

void CBossGun::OnCollision(CObj * _pObj)
{
	if (OBJECT_TYPE::PLAYER_PROJECTILE == _pObj->GetObjType())
	{
		m_tInfo.iHp -= _pObj->Get_Info().iAttack;
	}
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
