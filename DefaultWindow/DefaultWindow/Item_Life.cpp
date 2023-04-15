#include "stdafx.h"
#include "Item_Life.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"


CItem_Life::CItem_Life()
{
}
CItem_Life::~CItem_Life()
{
}

void CItem_Life::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CItem_Life::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super ::Update_Rect();


	return OBJ_NOEVENT;
}

void CItem_Life::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_Life::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_Life::Release()
{
}

void CItem_Life::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		Use_Item(_pObj);
		DeleteObjEvt(this);
	}
}

void CItem_Life::Use_Item(CObj * _pObj)
{
	//TODO : 플레이어 HP 회복시켜야함. _pObj->Get_Info().Set_HP();
}
