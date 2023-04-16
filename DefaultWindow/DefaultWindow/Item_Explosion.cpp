#include "stdafx.h"
#include "Item_Explosion.h"
#include "EventFunc.h"
#include "Scene.h"
#include "Player.h"

CItem_Explosion::CItem_Explosion()
{
}


CItem_Explosion::~CItem_Explosion()
{
}

void CItem_Explosion::Initialize()
{
	m_tInfo.fCX = 5.f;
	m_tInfo.fCY = 5.f;

	m_fSpeed = 2.f;

	m_tInfo.fX = CGameCore::GetInst()->GetMousePos().x;
	m_tInfo.fY = CGameCore::GetInst()->GetMousePos().y;

	m_bMax = true;
	
	m_dwTime = GetTickCount();
	Set_ObjType(OBJECT_TYPE::PLAYER_PROJECTILE);
}

int CItem_Explosion::Update()
{
	if (m_bMax) 
	{
	m_tInfo.fCX += m_fSpeed;
	m_tInfo.fCY += m_fSpeed;
	}
	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void CItem_Explosion::Late_Update()
{
	if (m_tInfo.fCX >= 200.f)
	{
		m_bMax = false;

		if (m_dwTime + 1200 <= GetTickCount())
		{
			DeleteObjEvt(this);
			m_dwTime = GetTickCount();
		}
	}
}

void CItem_Explosion::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_Explosion::Release()
{
}

void CItem_Explosion::OnCollision(CObj * _pObj)
{
	if (m_bCollision)
	{
		if (_pObj->GetObjType() == OBJECT_TYPE::MONSTER)
		{
			m_bCollision = false;
			DeleteObjEvt(_pObj);
		}
	}
	
}

void CItem_Explosion::Use_Item(CObj * _pObj)
{
}
