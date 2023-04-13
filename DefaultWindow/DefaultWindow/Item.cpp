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
