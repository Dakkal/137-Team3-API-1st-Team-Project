#include "stdafx.h"
#include "BossBullet.h"
#include "EventFunc.h"
#include "GameCore.h"
#include "Player.h"


CBossBullet::CBossBullet()
	: CObj(OBJECT_TYPE::ENEMY_PROJECTILE)
{
}


CBossBullet::~CBossBullet()
{
}

void CBossBullet::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
	m_fSpeed = 4.f;
	m_tInfo.iAttack = 1;
}

int CBossBullet::Update()
{
	if (BOSSBULLET_TYPE::NORMAL == m_eBulletType)
	{
		m_tInfo.fY += m_fSpeed;
		m_fSpeed += 0.5f;
	}

	if (BOSSBULLET_TYPE::FOLLOW == m_eBulletType)
	{
		float fDiagonal = 0.f;
		float fWidth = 0.f;
		float fHeight = 0.f;
		float fRadian = 0.f;

		fWidth = CGameCore::GetInst()->GetPlayer()->Get_Info().fX - m_tInfo.fX;
		fHeight = (CGameCore::GetInst()->GetPlayer()->Get_Info().fY + 80.f) -m_tInfo.fY;
		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

		fRadian = acosf(fWidth / fDiagonal);
		if (fHeight < 0.f)
			fRadian *= -1.f;

			m_tInfo.fX += m_fSpeed * cosf(fRadian);
			m_tInfo.fY += m_fSpeed * sinf(fRadian);
	}

	if (BOSSBULLET_TYPE::FIREWORK == m_eBulletType)
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
		m_tInfo.fY += m_fSpeed * sinf(m_fAngle * PI / 180.f);
	}

	__super::Update_Rect();

	return 0;
}

void CBossBullet::Late_Update()
{
	if (m_tRect.left <= 0 || m_tRect.top <= 0 || m_tRect.right >= WINCX || m_tRect.bottom >= WINCY)
	{
		//DeleteObjEvt(this);
	}
}

void CBossBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBossBullet::Release()
{
}

void CBossBullet::OnCollision(CObj * _pObj)
{
	if (OBJECT_TYPE::PLAYER == _pObj->GetObjType())
	{
		//플레이어 체력줄어드는 함수
		DeleteObjEvt(this);
	}
	if (OBJECT_TYPE::SATTELLITE == _pObj->GetObjType())
	{
		DeleteObjEvt(_pObj);
		DeleteObjEvt(this);
	}
}
