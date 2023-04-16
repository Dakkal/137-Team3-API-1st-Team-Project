#include "stdafx.h"
#include "Item_Ball.h"


CItem_Ball::CItem_Ball()
{
}


CItem_Ball::~CItem_Ball()
{
}

void CItem_Ball::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY - 30.f;

	m_fSpeed = 5.f;

	srand(unsigned int(time(NULL)));

	m_fAngle = rand() % 360;

}

int CItem_Ball::Update()
{
	m_tInfo.fX += LONG((m_fSpeed * cos(m_fAngle*PI / 180.f)));
	m_tInfo.fY -= LONG((m_fSpeed * sin(m_fAngle*PI / 180.f)));

	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void CItem_Ball::Late_Update()
{
	if (0 >= m_tRect.left)
		m_fAngle + 90.f;

	if (WINCX <= m_tRect.right)
		m_fAngle + 90.f;

	if (0 >= m_tRect.top)
		m_fAngle + 90.f;

	if (WINCY <= m_tRect.bottom)
		m_fAngle + 90.f;


}

void CItem_Ball::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_Ball::Release()
{
}

void CItem_Ball::OnCollision(CObj * _pObj)
{
}

void CItem_Ball::Use_Item(CObj * _pObj)
{
}
