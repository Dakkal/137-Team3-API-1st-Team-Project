#include "stdafx.h"
#include "Item.h"


CItem::CItem()
	:CObj(OBJECT_TYPE::ITEM)
{
}


CItem::~CItem()
{
	Release();
}

void CItem::Initialize()
{
}

int CItem::Update()
{
	return 0;
}

void CItem::Late_Update()
{
	//if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right)
	//{
	//	m_fSpeed *= -1.f;

	//	if (DIR_UP == m_eDir)
	//	{
	//		m_eDir = DIR_DOWN;
	//	}

	//	else
	//	{
	//		m_eDir = DIR_UP;
	//	}
	//}

	//if (100 >= m_tRect.top || WINCY - 100 <= m_tRect.bottom)
	//{
	//	if (DIR_UP == m_eDir)
	//	{
	//		m_eDir = DIR_DOWN;
	//	}

	//	else
	//	{
	//		m_eDir = DIR_UP;
	//	}
	//}
}

void CItem::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem::Release()
{
}

void CItem::OnCollision()
{
}
