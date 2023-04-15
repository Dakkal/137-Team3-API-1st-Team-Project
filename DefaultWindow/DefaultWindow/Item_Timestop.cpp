#include "stdafx.h"
#include "Item_TimeStop.h"
#include "SelectGDI.h"
#include "EventFunc.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "GameCore.h"
#include "Player.h"

CItem_Timestop::CItem_Timestop()
{

}


CItem_Timestop::~CItem_Timestop()
{

}

void CItem_Timestop::Initialize()
{
	m_tInfo = { 400.f, 100.f, 50.f, 50.f };
	m_bCollision = true;

}

int CItem_Timestop::Update()
{
	m_tInfo.fY += 3;

	__super::Update_Rect();
	return 0;
}

void CItem_Timestop::Late_Update()
{

}

void CItem_Timestop::Render(HDC hDC)
{
	SelectGDI g(hDC, BRUSH_TYPE::BLACK);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_Timestop::Release()
{
}

void CItem_Timestop::OnCollision(CObj * _pObj)
{
	if (m_bCollision)
	{
		Use_Item(_pObj);
		DeleteObjEvt(this);
		m_bCollision = false;
	}
}

void CItem_Timestop::Use_Item(CObj * _pObj)
{
	// 아이템 효과를 구현.
	list<CObj*>& objList = CSceneMgr::GetInst()->GetCurrScene()->GetObjTypeList(OBJECT_TYPE::MONSTER);
	//TODO : 시간정지 아이템 : 몬스터만 시간이 멈춰야함. 
}
