#include "stdafx.h"
#include "Item_SpeedSlow.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Enemy.h"

CItem_SpeedSlow::CItem_SpeedSlow()
{
}


CItem_SpeedSlow::~CItem_SpeedSlow()
{
}

void CItem_SpeedSlow::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CItem_SpeedSlow::Update()
{
	m_fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	m_fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	m_fDiagonal = sqrtf(pow(m_fWidth, 2) + pow(m_fHeight, 2));
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

void CItem_SpeedSlow::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_SpeedSlow::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_SpeedSlow::Release()
{
}

void CItem_SpeedSlow::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{

		DeleteObjEvt(_pObj);
	}
}

void CItem_SpeedSlow::Use_Item(CObj * _pObj)
{
	list<CObj*>& objList = CSceneMgr::GetInst()->GetCurrScene()->GetObjTypeList(OBJECT_TYPE::MONSTER);

	list<CObj*> ::iterator Iter = objList.begin();

	for (auto iter : objList)
	{
		
	}
}
