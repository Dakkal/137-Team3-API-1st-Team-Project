#include "stdafx.h"
#include "Item_Magnetic.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Player.h"

CItem_Magnetic::CItem_Magnetic()
{
}


CItem_Magnetic::~CItem_Magnetic()
{
}

void CItem_Magnetic::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CItem_Magnetic::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void CItem_Magnetic::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_Magnetic::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_Magnetic::Release()
{
}

void CItem_Magnetic::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{

		DeleteObjEvt(_pObj);
	}
}

void CItem_Magnetic::Use_Item(CObj * _pObj)
{
	list<CObj*>& objList = CSceneMgr::GetInst()->GetCurrScene()->GetObjTypeList(OBJECT_TYPE::ITEM);

	list<CObj*> ::iterator Iter = objList.begin();

	for (auto iter : objList)
	{

	}
}
