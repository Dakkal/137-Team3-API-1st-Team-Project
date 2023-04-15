#include "stdafx.h"
#include "Citem_ScrewGun.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Player.h"

Citem_ScrewGun::Citem_ScrewGun()
{
}


Citem_ScrewGun::~Citem_ScrewGun()
{
}

void Citem_ScrewGun::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int Citem_ScrewGun::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void Citem_ScrewGun::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void Citem_ScrewGun::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void Citem_ScrewGun::Release()
{
}

void Citem_ScrewGun::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		Use_Item(_pObj);
		DeleteObjEvt(_pObj);
	}
}

void Citem_ScrewGun::Use_Item(CObj * _pObj)
{
	dynamic_cast<CPlayer*>(_pObj)->Set_Gun(GUN_TYPE::SCREWGUN);
}
