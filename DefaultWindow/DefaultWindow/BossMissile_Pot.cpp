#include "stdafx.h"
#include "BossMissile_Pot.h"
#include "BossMissile.h"
#include "EventFunc.h"


CBossMissile_Pot::CBossMissile_Pot(CBoss* _pOwner)
	: m_pOwner(_pOwner)
{
}


CBossMissile_Pot::~CBossMissile_Pot()
{
	Release();
}

void CBossMissile_Pot::Initialize()
{
	m_eBossPart = BOSS_PART::MISSILE_POT;
	m_dwTime = GetTickCount();

	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = m_pOwner->GetSpeed();
}

int CBossMissile_Pot::Update()
{
	m_tInfo.fX += m_fSpeed;
	
	if (m_dwTime + 2000 <= GetTickCount())
	{
		CBossMissile* pMissile = new CBossMissile;
		pMissile->Initialize();
		pMissile->Set_Pos(m_tInfo.fX, m_tRect.bottom + 40);
		AddObjEvt(pMissile);

		m_dwTime = GetTickCount();
	}

	__super::Update_Rect();

	return 0;
}

void CBossMissile_Pot::Late_Update()
{
	if (m_tRect.left <= 0 + 85.f || m_tRect.right >= WINCX - 85.f)
		m_fSpeed *= -1.f;
}

void CBossMissile_Pot::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom + 40);
}

void CBossMissile_Pot::Release()
{
}

void CBossMissile_Pot::OnCollision(CObj * _pObj)
{
}

