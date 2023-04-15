#include "stdafx.h"
#include "Item_SpeedUp.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"


CItem_SpeedUp::CItem_SpeedUp()
{
}


CItem_SpeedUp::~CItem_SpeedUp()
{
}

void CItem_SpeedUp::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CItem_SpeedUp::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void CItem_SpeedUp::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_SpeedUp::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_SpeedUp::Release()
{
}

void CItem_SpeedUp::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		Use_Item(_pObj);
		DeleteObjEvt(_pObj);
	}
}

void CItem_SpeedUp::Use_Item(CObj * _pObj)
{
	//TODO: 오브젝트 스피드값 올려줘야 함. _pObj->Set_Speed();
}
