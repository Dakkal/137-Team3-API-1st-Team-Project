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
	m_tInfo.fX = rand() % 550 + 120;
	m_tInfo.fY = 10.f;
	m_tInfo.fCX = 35.f;
	m_tInfo.fCY = 35.f;


	m_tInfo2.fX = 300.f;
	m_tInfo2.fY = 10.f;
	
	m_tInfo2.fCX = 30.f;
	m_tInfo2.fCY = 30.f;


	m_tInfo3.fX = 500.f;
	m_tInfo3.fY = 10.f;

	m_tInfo3.fCX = 30.f;
	m_tInfo3.fCY = 30.f;

	m_fSpeed = rand() % 5 + 1;


}

int CEnemy::Update()
{

	m_tInfo.fY += m_fSpeed;


	m_tInfo2.fY += m_fSpeed;
	m_tInfo2.fX -= m_fSpeed;

	m_tInfo3.fY += m_fSpeed;
	m_tInfo3.fX += m_fSpeed;
	
	
	if (WINCY/2 < m_tInfo2.fY) {
		m_tInfo2.fX += (m_fSpeed)*2.f;
	}

	if (WINCY / 2 < m_tInfo3.fY) {
		m_tInfo3.fX -= (m_fSpeed)*2.f;
	}

	__super::Update_Rect();
	Update_Rect2();
	Update_Rect3();
		
	return OBJ_NOEVENT;
}




void CEnemy::Late_Update()
{

	if (WINCY - 100 <= m_tRect.bottom)
	{
		m_bDead = true;
	}

	if (WINCY - 100 <= m_tRect2.bottom)
	{
		m_bDead = true;
	}

	if (WINCY - 100 <= m_tRect3.bottom)
	{
		m_bDead = true;
	}
	
}

void CEnemy::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	Ellipse(hDC, m_tRect2.left, m_tRect2.top, m_tRect2.right, m_tRect2.bottom);
	Ellipse(hDC, m_tRect3.left, m_tRect3.top, m_tRect3.right, m_tRect3.bottom);
}

	

void CEnemy::Update_Rect2()
{
	m_tRect2.left = LONG(m_tInfo2.fX - (m_tInfo2.fCX * 0.5f));
	m_tRect2.top = LONG(m_tInfo2.fY - (m_tInfo2.fCY * 0.5f));
	m_tRect2.right = LONG(m_tInfo2.fX + (m_tInfo2.fCX * 0.5f));
	m_tRect2.bottom = LONG(m_tInfo2.fY + (m_tInfo2.fCY * 0.5f));
}

void CEnemy::Update_Rect3()
{
	m_tRect3.left = LONG(m_tInfo3.fX - (m_tInfo3.fCX * 0.5f));
	m_tRect3.top = LONG(m_tInfo3.fY - (m_tInfo3.fCY * 0.5f));
	m_tRect3.right = LONG(m_tInfo3.fX + (m_tInfo3.fCX * 0.5f));
	m_tRect3.bottom = LONG(m_tInfo3.fY + (m_tInfo3.fCY * 0.5f));

}

void CEnemy::Release()
{
}


void CEnemy::OnCollision(CObj * _pObj)
{
	return;
}



