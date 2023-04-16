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
	, m_pBossHead(nullptr)
	, m_pBossGun_1(nullptr)
	, m_pBossGun_2(nullptr)
	, m_pBossMissile_Pot(nullptr)
{
}


CBoss::~CBoss()
{
	Release();
}

void CBoss::Initialize()
{
	m_tInfo = { 400.f, 100.f, 200.f, 100.f };
	m_fSpeed = 5.f;

	//보스머리
	m_pBossHead = new CBossHead;
	m_pBossHead->Initialize();
	m_pBossHead->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	static_cast<CBossHead*>(m_pBossHead)->Set_BossSpeed(m_fSpeed);

	//보스 총 1
	m_pBossGun_1 = new CBossGun;
	m_pBossGun_1->Initialize();
	m_pBossGun_1->Set_Pos(m_tInfo.fX - 80.f, m_tInfo.fY + 30);
	static_cast<CBossGun*>(m_pBossGun_1)->Set_GunType(1);
	static_cast<CBossGun*>(m_pBossGun_1)->Set_BossSpeed(m_fSpeed);

	//보스 총 2
	m_pBossGun_2 = new CBossGun;
	m_pBossGun_2->Initialize();
	m_pBossGun_2->Set_Pos(m_tInfo.fX + 80, m_tInfo.fY + 30);
	static_cast<CBossGun*>(m_pBossGun_2)->Set_GunType(2);
	static_cast<CBossGun*>(m_pBossGun_2)->Set_BossSpeed(m_fSpeed);

	// 보스 미사일포트
	m_pBossMissile_Pot = new CBossMissile_Pot;
	m_pBossMissile_Pot->Initialize();
	m_pBossMissile_Pot->Set_Pos(m_tInfo.fX, m_tInfo.fY + 50);
	static_cast<CBossMissile_Pot*>(m_pBossGun_2)->Set_BossSpeed(m_fSpeed);
}

int CBoss::Update()
{
	m_tInfo.fX += m_fSpeed;

	m_pBossHead->Update();
	m_pBossGun_1->Update();
	m_pBossGun_2->Update();
	m_pBossMissile_Pot->Update();

	__super::Update_Rect();

	return 0;
}

void CBoss::Late_Update()
{
	if (m_tRect.left <= 0 || m_tRect.right >= WINCX)
		m_fSpeed *= -1.f;

	Update_BossLocate();

	m_pBossHead->Late_Update();
	m_pBossGun_1->Late_Update();
	m_pBossGun_2->Late_Update();
	m_pBossMissile_Pot->Late_Update();


	if(!m_pBossHead)
		DeleteObjEvt(this);
}

void CBoss::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	m_pBossHead->Render(hDC);
	m_pBossGun_1->Render(hDC);
	m_pBossGun_2->Render(hDC);
	m_pBossMissile_Pot->Render(hDC);
}

void CBoss::Release()
{
	if (!m_pBossHead) Safe_Delete<CObj*>(m_pBossHead);
	if (!m_pBossGun_1) Safe_Delete<CObj*>(m_pBossGun_1);
	if (!m_pBossGun_2) Safe_Delete<CObj*>(m_pBossGun_2);
	if (!m_pBossMissile_Pot) Safe_Delete<CObj*>(m_pBossMissile_Pot);
}

void CBoss::OnCollision(CObj * _pObj)
{
}

void CBoss::Update_BossLocate()
{
	static_cast<CBossHead*>(m_pBossHead)->Set_BossPosX(m_tInfo.fX);
	static_cast<CBossGun*>(m_pBossGun_1)->Set_BossPosX(m_tInfo.fX - 80.f);
	static_cast<CBossGun*>(m_pBossGun_2)->Set_BossPosX(m_tInfo.fX + 80.f);
	static_cast<CBossMissile_Pot*>(m_pBossMissile_Pot)->Set_BossPosX(m_tInfo.fX);

	static_cast<CBossHead*>(m_pBossHead)->Set_BossSpeed(m_fSpeed);
	static_cast<CBossGun*>(m_pBossGun_1)->Set_BossSpeed(m_fSpeed);
	static_cast<CBossGun*>(m_pBossGun_2)->Set_BossSpeed(m_fSpeed);
	static_cast<CBossMissile_Pot*>(m_pBossMissile_Pot)->Set_BossSpeed(m_fSpeed);
	
}
