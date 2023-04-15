#include "stdafx.h"
#include "Item_MachineGun.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Player.h"



CItem_MachineGun::CItem_MachineGun()
{
}


CItem_MachineGun::~CItem_MachineGun()
{
}

void CItem_MachineGun::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CItem_MachineGun::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void CItem_MachineGun::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_MachineGun::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_MachineGun::Release()
{
}

void CItem_MachineGun::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		Use_Item(_pObj);
		DeleteObjEvt(_pObj);
	}
}

void CItem_MachineGun::Use_Item(CObj * _pObj)
{
	dynamic_cast<CPlayer*>(_pObj)->Set_Gun(GUN_TYPE::MACHINEGUN);
}
