#include "stdafx.h"
#include "Item_TimeStop.h"
#include "SelectGDI.h"
#include "EventFunc.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "GameCore.h"
#include "Player.h"
#include "Enemy.h"

CItem_Timestop::CItem_Timestop()
{

}


CItem_Timestop::~CItem_Timestop()
{

}

void CItem_Timestop::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 2.f;

	m_pTarget = CGameCore::GetInst()->GetPlayer();
}

int CItem_Timestop::Update()
{
	m_fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	m_fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	m_fDiagonal = sqrtf(pow(m_fWidth,2) + pow(m_fHeight,2));
	m_fRadian = acosf(m_fWidth / m_fDiagonal);

	m_fAngle = m_fRadian * 180.f / PI;

	switch (m_bMagnetic)
	{
	case true:

		if (m_pTarget->Get_Info().fY > m_tInfo.fY)
			m_fAngle *= -1.f;

		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);

		break;

	case false:
		m_tInfo.fY += m_fSpeed;

		break;
	}

	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void CItem_Timestop::Late_Update()
{
}

void CItem_Timestop::Render(HDC hDC)
{
	SelectGDI g(hDC, BRUSH_TYPE::BLACK);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	
	TCHAR szName[32] = L"시간정지";
	TextOut(hDC, m_tInfo.fX-30.f, m_tInfo.fY + 20.f, szName,lstrlen(szName));

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
	list<CObj*>& objList = CSceneMgr::GetInst()->GetCurrScene()->GetObjTypeList(OBJECT_TYPE::MONSTER);
	list<CObj*>::iterator iter = objList.begin();
	for (; iter != objList.end(); ++iter)
	{
		(dynamic_cast<CEnemy*>(*iter))->SetPause(3);
	}
	
	
	//TODO : 시간정지 아이템 : 몬스터만 시간이 멈춰야함. 
}
