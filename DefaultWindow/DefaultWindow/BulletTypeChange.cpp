#include "stdafx.h"
#include "BulletTypeChange.h"


CBulletTypeChange::CBulletTypeChange()
{
}


CBulletTypeChange::~CBulletTypeChange()
{
}

void CBulletTypeChange::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 1.f;
}

int CBulletTypeChange::Update()
{
	if (m_bEvent)
		return OBJ_EVENT;

	m_tInfo.fY += m_fSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBulletTypeChange::Late_Update()
{
}

void CBulletTypeChange::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBulletTypeChange::Release()
{
}

void CBulletTypeChange::OnCollision(CObj * _pObj)
{
}

void CBulletTypeChange::Use_Item(CObj * _pObj)
{
}
