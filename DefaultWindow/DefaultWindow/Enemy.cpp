#include "stdafx.h"
#include "Enemy.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"
#include "Item_Satellite.h"
#include "Item_Invincibility.h"
#include "Item_Life.h"
#include "Item_Magnetic.h"
#include "Item_SpeedSlow.h"
#include "Item_TimeStop.h"
#include "BossBullet.h"

CEnemy::CEnemy()
	:	CObj(OBJECT_TYPE::MONSTER)
	,	m_iHp(3)
	,	m_iMaxHp(3)
	,	m_iSpeed(5)
	,	m_dwCollisionTime(GetTickCount())
	,	m_lRecoverTime(10)
	,	m_dwPauseTime(GetTickCount())
	,	m_bPause(false)
	,	m_lPauseTime(1000)
	,	m_dwShotTime(GetTickCount())
	,   m_lShotTime(1000)
{
}

CEnemy::~CEnemy()
{
	Release();
}

void CEnemy::Initialize()
{
	
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_dwCollisionTime = GetTickCount();
	m_dwPauseTime = GetTickCount();
	m_dwShotTime = GetTickCount();

	m_fSpeed = 2.f;
	
}

int CEnemy::Update()
{
	if (!m_bCollision)
	{
		if (m_dwCollisionTime + m_lRecoverTime < GetTickCount())
		{
			m_bCollision = true;
			m_dwCollisionTime = GetTickCount();
		}
	}
	else
	{
		m_dwCollisionTime = GetTickCount();
	}

	if (!m_bPause)
	{
		m_dwPauseTime = GetTickCount();
		m_tInfo.fY += m_fSpeed;
	}
	else
	{
		Update_Pause();
	}

	__super::Update_Rect();


	if (m_bPause) return 0 ;

	if (m_dwShotTime + m_lShotTime < GetTickCount())
	{
		
		srand(time(NULL));
		srand(rand() * rand() * rand());

		m_dwShotTime = GetTickCount();
		CBossBullet* pBullet = new CBossBullet;
		pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);
		int iAngle = (90 + (rand() % 90));

		pBullet->SetAngle(iAngle);
		pBullet->Set_BossBullet_Type(BOSSBULLET_TYPE::NORMAL);
		AddObjEvt(pBullet);
	}

	
	return 0;
	
}

void CEnemy::Late_Update()
{
	if (m_bDead)
		return;

	if (m_tInfo.fY - 100 > WINCY)
	{
		CGameCore::GetInst()->GetPlayer()->OnCollision(this);
		DeleteObjEvt(this);
	}
}

void CEnemy::Render(HDC hDC)
{
	if (!m_bCollision)
	{
		SelectGDI g(hDC, BRUSH_TYPE::RED);
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	}
	else
	{
		SelectGDI g(hDC, BRUSH_TYPE::ORANGE);
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	}
		


	//UI_RENDER
	// 1. HP Bar
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



void CEnemy::Release()
{
}


void CEnemy::OnCollision(CObj * _pObj)
{
	if (m_bCollision)
	{
		switch (_pObj->GetObjType())
		{
		case OBJECT_TYPE::PLAYER:
			OnDamaged();
			break;
		case OBJECT_TYPE::PLAYER_PROJECTILE:
			OnDamaged();
			break;
		case OBJECT_TYPE::SATTELLITE:
			OnDamaged();
			break;
		}
		
	}
}

void CEnemy::OnDamaged()
{
	m_iHp > 0 ? --m_iHp : 0;
	if (m_iHp <= 0)
	{
		Spawn_Item();
		g_iScore++;
		DeleteObjEvt(this);
	}
		

	m_bCollision = false;
}

void CEnemy::Update_Pause()
{
	if (m_dwPauseTime + m_lPauseTime < GetTickCount())
	{
		m_bPause = false;
		m_dwPauseTime = GetTickCount();
	}
}

void CEnemy::Spawn_Item()
{
	CItem* pItem = nullptr;
	srand((unsigned)time(NULL) * rand());
	int iRandom = 1 + rand() % 1000;
	
	if (iRandom > 900)
		pItem = new CItem_Invincibility;
	else if (iRandom > 850)
		pItem = new CItem_Timestop;
	else if (iRandom > 800)
		pItem = new CItem_Magnetic;
	else if (iRandom > 750)
		pItem = new CItem_Satellite;
	else if (iRandom > 700)
		pItem = new CItem_Life;
	else
		return;

	pItem->Set_Pos(m_tInfo.fX, m_tInfo.fY);
	AddObjEvt(pItem);

}




