#include "stdafx.h"
#include "Cunsumption.h"


Ccunsumption::Ccunsumption()
{
}

Ccunsumption::~Ccunsumption()
{
}

void Ccunsumption::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
}

int Ccunsumption::Update()
{
	m_tInfo.fX += m_fSpeed;

	//switch (m_eDir)
	//{
	//case DIR_TYPE::UP:
	//	m_tInfo.fY -= m_fSpeed;
	//	break;

	//case DIR_TYPE::DOWN:
	//	m_tInfo.fY += m_fSpeed;
	//	break;
	//}


	__super::Update_Rect();



	return OBJ_NOEVENT;
}

void Ccunsumption::Late_Update()
{
	//if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right)
	//{
	//	m_fSpeed *= -1.f;

	//	if (DIR_TYPE::UP == m_eDir)
	//	{
	//		m_eDir = DIR_TYPE::DOWN;
	//	}

	//	else
	//	{
	//		m_eDir = DIR_TYPE::UP;
	//	}
	//}

	//if (100 >= m_tRect.top || WINCY - 100 <= m_tRect.bottom)
	//{
	//	if (DIR_TYPE::UP == m_eDir)
	//	{
	//		m_eDir = DIR_TYPE::DOWN;
	//	}

	//	else
	//	{
	//		m_eDir = DIR_TYPE::UP;
	//	}
	//}
}

void Ccunsumption::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Ccunsumption::Release()
{
}

void Ccunsumption::OnCollision()
{


}

void Ccunsumption::Use_Item()
{
}
