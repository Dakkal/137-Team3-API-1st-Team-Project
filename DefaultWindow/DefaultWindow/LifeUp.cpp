#include "stdafx.h"
#include "LifeUp.h"


CLifeUp::CLifeUp()
{
}


CLifeUp::~CLifeUp()
{
}

void CLifeUp::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CLifeUp::Update()
{
	if (m_bEvent)
		return OBJ_EVENT;



	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CLifeUp::Late_Update()
{
}

void CLifeUp::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CLifeUp::Release()
{
}

void CLifeUp::OnCollision(CObj * _pObj)
{
}

void CLifeUp::Use_Item(CObj * _pObj)
{
}
