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
}

void CItem::Release()
{
}

void CItem::OnCollision()
{
}
