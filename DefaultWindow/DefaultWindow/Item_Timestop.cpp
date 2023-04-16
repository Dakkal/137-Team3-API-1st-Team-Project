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

	m_bMagnetic = true;
	m_fSpeed = 5.f;
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
	// ������ ȿ���� ����.
	list<CObj*>& objList = CSceneMgr::GetInst()->GetCurrScene()->GetObjTypeList(OBJECT_TYPE::MONSTER);
	//TODO : �ð����� ������ : ���͸� �ð��� �������. 
}
