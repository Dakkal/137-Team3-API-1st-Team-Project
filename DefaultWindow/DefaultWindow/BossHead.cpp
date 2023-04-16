#include "stdafx.h"
#include "BossHead.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"

CBossHead::CBossHead()
{
}


CBossHead::~CBossHead()
{
	Release();
}

void CBossHead::Initialize()
{
	m_eBossPart = BOSS_PART::HEAD;

	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;
	m_tInfo.iHp = 1;
}

int CBossHead::Update()
{
	m_tInfo.fX += m_fSpeed;

	__super::Update_Rect();

	return 0;
}

void CBossHead::Late_Update()
{
	if (m_tRect.left <= 0 + 75.f || m_tRect.right >= WINCX - 75.f)
		m_fSpeed *= -1.f;


	if (m_tInfo.iHp <= 0)
		DeleteObjEvt(this);
}

void CBossHead::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
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
		m_tInfo.iHp -= _pObj->Get_Info().iAttack;
		break;
	}
	m_bCollision = false;

}
