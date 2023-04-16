#include "stdafx.h"
#include "BossHead.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"


CBossHead::CBossHead(CBoss* _pOwner)
	: m_pOwner(_pOwner)
	, m_lRecoverTime(100)
	, dwCollisionTime(GetTickCount())
{
}


CBossHead::~CBossHead()
{
	Release();
}

void CBossHead::Initialize()
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_iHp = 30;
	m_iMaxHp = 30;

	m_fSpeed = m_pOwner->GetSpeed();
}

int CBossHead::Update()
{
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

	__super::Update_Rect();

	return 0;
}

void CBossHead::Late_Update()
{
	if (m_tRect.left <= 0 + 75.f || m_tRect.right >= WINCX - 75.f)
		m_fSpeed *= -1.f;

}

void CBossHead::Render(HDC hDC)
{

	if (!m_bCollision)
	{
		SelectGDI g(hDC, BRUSH_TYPE::RED);
		Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	}
	else
	{
		SelectGDI brush(hDC, BRUSH_TYPE::ORANGE);
		Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	}

	//HP_BAR
	for (int i = 0; i < m_iMaxHp; ++i)
	{
		RECT rect = GetRectWithXY((int)m_tInfo.fX - 150, (int)m_tInfo.fY, (10 * (i + 1)), -100, 10);
		if (m_iHp >= (i + 1))
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

void CBossHead::Release()
{
}

void CBossHead::OnCollision(CObj * _pObj)
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
