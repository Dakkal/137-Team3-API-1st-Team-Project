#include "stdafx.h"
#include "Boss.h"
#include "BossHead.h"
#include "BossGun.h"
#include "BossMissile_Pot.h"
#include "BossBullet.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"


CBoss::CBoss()
	: CObj(OBJECT_TYPE::BOSS)
{
}


CBoss::~CBoss()
{
	Release();
}

void CBoss::Initialize()
{
	m_tInfo = { 400.f, 50.f, 200.f, 50.f };
	m_fSpeed = 5.f;

	AddObjEvt(Create_Head());
	AddObjEvt(Create_Gun1());
	AddObjEvt(Create_Gun2());
	AddObjEvt(Create_Missile_Pot());

}

int CBoss::Update()
{
	m_tInfo.fX += m_fSpeed;

	__super::Update_Rect();

	return 0;
}

void CBoss::Late_Update()
{
	if (m_tRect.left <= 0 || m_tRect.right >= WINCX)
		m_fSpeed *= -1.f;
}

void CBoss::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBoss::Release()
{
}

void CBoss::OnCollision(CObj * _pObj)
{
}

void CBoss::Update_BossLocate()
{	
}

CObj * CBoss::Create_Head()
{
	CBossHead* pBossHead = new CBossHead;
	pBossHead->Initialize();
	pBossHead->Set_Pos(m_tInfo.fX, m_tInfo.fY + 50);
	pBossHead->Set_BossSpeed(m_fSpeed);

	return pBossHead;
}

CObj * CBoss::Create_Gun1()
{
	CBossGun* pBossGun1 = new CBossGun;
	pBossGun1->Initialize();
	pBossGun1->Set_Pos(m_tInfo.fX - 80, m_tInfo.fY + 30);
	pBossGun1->Set_BossSpeed(m_fSpeed);
	pBossGun1->Set_GunType(1);

	return pBossGun1;
}

CObj * CBoss::Create_Gun2()
{
	CBossGun* pBossGun2 = new CBossGun;
	pBossGun2->Initialize();
	pBossGun2->Set_Pos(m_tInfo.fX + 80, m_tInfo.fY + 30);
	pBossGun2->Set_BossSpeed(m_fSpeed);
	pBossGun2->Set_GunType(2);

	return pBossGun2;
}

CObj * CBoss::Create_Missile_Pot()
{
	CBossMissile_Pot* pBossPot = new CBossMissile_Pot;
	pBossPot->Initialize();
	pBossPot->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	pBossPot->Set_BossSpeed(m_fSpeed);

	return pBossPot;
}
