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
	Release();
}

void CBossBullet::Initialize()
{
	m_dwTime = GetTickCount();

	m_bRageCheck = false;

	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
	m_fDistance = 30.f;

	//스크류
	m_bStart = true;
	m_fBullRotAngle = 0.f;
	m_fBullRotSpeed = 30.f;
	ZeroMemory(&m_tCenter, sizeof(POINT));

	// 유도
	m_fDiagonal = 0.f;
	m_fWidth = 0.f;
	m_fHeigth = 0.f;
}

int CBossBullet::Update()
{
	if ((int)PATTERN_TYPE::FASTPT == m_iCheckPattern) { Fast_Pattern(); }
	if ((int)PATTERN_TYPE::FIREWORKPT == m_iCheckPattern) { FireWork_Pattern(); }
	if ((int)PATTERN_TYPE::FOLLOWPT == m_iCheckPattern) { Follow_Pattern(); }
	if ((int)PATTERN_TYPE::RANDOMPT == m_iCheckPattern) { Random_Pattern(); }
	if ((int)PATTERN_TYPE::SCREWPT == m_iCheckPattern) { Screw_Pattern(); }
	if (m_bRageCheck == true) { Rage_Pattern();}


	__super::Update_Rect();

	return 0;
}

void CBossBullet::Late_Update()
{
	if (m_tRect.left <= 0 || m_tRect.top <= 0 || m_tRect.right >= WINCX || m_tRect.bottom >= WINCY)
	{
		DeleteObjEvt(this);
	}

	// 보스 스탯가져와서 보스 체력이 30퍼 밑이면 m_bRageCheck true로

	if (m_bRageCheck == true && m_dwTime + 3000 <= GetTickCount())
	{
		m_bRageCheck = false;
	}

	m_iCheckPattern = Keep_Pattern();
}

void CBossBullet::Render(HDC hDC)
{
	if (m_bRageCheck == true)
	{
		Rectangle(hDC, m_tRect.left - 20.f, m_tRect.top, m_tRect.right +20.f, m_tRect.bottom);
		return;
	}

	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBossBullet::Release()
{
}

void CBossBullet::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		DeleteObjEvt(this);
		//CGameCore::GetInst()->GetPlayer()->Get_Info().iHp -= m_tInfo.iAttack;
		// 플레이어 HP변하는 함수 필요.
	}

	if (_pObj->GetObjType() == OBJECT_TYPE::SATTELLITE)
	{
		DeleteObjEvt(_pObj);
		DeleteObjEvt(this);
	}
}

void CBossBullet::Fast_Pattern()
{
	m_tInfo.iAttack = 10;

	m_tInfo.fY += m_fSpeed;

	m_fSpeed++;
}

void CBossBullet::FireWork_Pattern()
{
	//미완성
	float	f_Distance = 100.f;
	float	f_Dest = 0.f;
	
	if (m_bStart = true)
	{
		m_tCenter.x = (LONG)m_tInfo.fX;
		m_tCenter.y = (LONG)m_tInfo.fY;
		f_Dest = m_tCenter.y + f_Distance;
		m_bStart = false;
	}

	m_tCenter.y += m_fSpeed;

	if (m_tCenter.y >= f_Dest)
	{
	}

}

void CBossBullet::Follow_Pattern()
{
	float f_Diagonal = 0.f;
	float fWidth = 0.f;
	float fHeigth = 0.f;
	float fRadian = 0.f;

	fWidth = CGameCore::GetInst()->GetPlayer()->Get_Info().fX - m_tInfo.fX;
	fHeigth = CGameCore::GetInst()->GetPlayer()->Get_Info().fY - m_tInfo.fY;
	f_Diagonal = sqrtf(fWidth * fWidth + fHeigth * fHeigth);

	fRadian = acosf(m_fWidth / m_fDiagonal);

	if ((m_fHeigth - m_tInfo.fY) > m_tInfo.fY)
		fRadian *= -1.f;

	m_tInfo.fX += m_fSpeed * cosf(fRadian);
	m_tInfo.fY -= m_fSpeed * sinf(fRadian);

}

void CBossBullet::Random_Pattern()
{
}

void CBossBullet::Rage_Pattern()
{
	m_tInfo.iAttack = 30;
}

void CBossBullet::Screw_Pattern()
{
	m_tInfo.iAttack = 15;

	if (m_bStart == true)
	{
		m_tCenter.x = (LONG)m_tInfo.fX;
		m_tCenter.y = (LONG)m_tInfo.fY;
		m_bStart = false;
	}

	m_tCenter.x += LONG(m_fSpeed * cosf(m_fAngle * PI / 180.f));
	m_tCenter.y -= LONG(m_fSpeed * sinf(m_fAngle * PI / 180.f));

	m_fBullRotAngle += m_fBullRotSpeed;

	m_tInfo.fX = m_tCenter.x + m_fDistance * cosf(m_fBullRotAngle * PI / 180.f);
	m_tInfo.fY = m_tCenter.y - m_fDistance * -sinf(m_fBullRotAngle * PI / 180.f);

	m_fDistance += 0.5f;
}

int CBossBullet::Keep_Pattern()
{
	int iPattern = m_iCheckPattern;

	if (m_dwTime + 3000 <= GetTickCount())
	{
		return rand() % 5;
	}

	return iPattern;
}
