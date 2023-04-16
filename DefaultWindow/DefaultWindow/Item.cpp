#include "stdafx.h"
#include "Item.h"
#include "GameCore.h"



CItem::CItem()
	: CObj(OBJECT_TYPE::ITEM), m_bMagnetic(false)
{
	m_fWidth = 0.f;
	m_fHeight = 0.f;
	m_fDiagonal = 0.f;
	m_fRadian = 0.f;
}
CItem::~CItem()
{

}