#include "stdafx.h"
#include "Item_NormalGun.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Player.h"


CItem_NormalGun::CItem_NormalGun()
{
}


CItem_NormalGun::~CItem_NormalGun()
{
}

void CItem_NormalGun::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CItem_NormalGun::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void CItem_NormalGun::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_NormalGun::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_NormalGun::Release()
{
}

void CItem_NormalGun::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		Use_Item(_pObj);
		DeleteObjEvt(_pObj);
	}
}

void CItem_NormalGun::Use_Item(CObj * _pObj)
{
	dynamic_cast<CPlayer*>(_pObj)->Set_Gun(GUN_TYPE::NORMALGUN);
}
