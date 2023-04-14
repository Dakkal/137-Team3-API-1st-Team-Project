#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
	:CObj(OBJECT_TYPE::MONSTER)
{

}


CEnemy::~CEnemy()
{
	Release();
}

void CEnemy::Initialize()
{
	m_tInfo = { 400.f, -200.f, 50.f, 50.f };
	m_fSpeed = 4.f;
	m_fDownSpeed = (rand() % 3) + 1;
}

int CEnemy::Update()
{
	m_tInfo.fX += m_fSpeed;
	m_tInfo.fY += m_fDownSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CEnemy::Late_Update()
{
	if (m_tRect.left <= 0 || m_tRect.right >= WINCX)
		m_fSpeed *= -1.f;
}

void CEnemy::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CEnemy::Release()
{
}

void CEnemy::OnCollision(CObj * _pObj)
{
}

