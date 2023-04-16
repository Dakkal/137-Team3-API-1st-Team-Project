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
	, m_iHp(100)
	, m_iMaxHp(100)
	, m_iCountPart(0)
{
}


CBoss::~CBoss()
{
	Release();
}

void CBoss::Initialize()
{
	m_tInfo = { 400.f, 100.f, 200.f, 50.f };
	m_fSpeed = 5.f;


	
	Create_Missile_Pot();
	Create_Gun1();
	Create_Gun2();
	Create_Head();
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


void CBoss::Create_Head()
{
	CBossHead* pBossHead = new CBossHead(this);
	pBossHead->Initialize();
	pBossHead->Set_Pos(m_tInfo.fX, m_tInfo.fY + 50);

	AddObjEvt(pBossHead);
	m_iCountPart++;
}

void CBoss::Create_Gun1()
{
	CBossGun* pBossGun1 = new CBossGun(this);
	pBossGun1->Initialize();
	pBossGun1->Set_Pos(m_tInfo.fX - 80, m_tInfo.fY + 30);
	pBossGun1->SetGunType(1);
	AddObjEvt(pBossGun1);

	m_iCountPart++;
}

void CBoss::Create_Gun2()
{
	CBossGun* pBossGun2 = new CBossGun(this);
	pBossGun2->Initialize();
	pBossGun2->Set_Pos(m_tInfo.fX + 80, m_tInfo.fY + 30);
	pBossGun2->SetGunType(2);
	AddObjEvt(pBossGun2);

	m_iCountPart++;
}

void CBoss::Create_Missile_Pot()
{
	CBossMissile_Pot* pBossPot = new CBossMissile_Pot(this);
	pBossPot->Initialize();
	pBossPot->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	AddObjEvt(pBossPot);

}
