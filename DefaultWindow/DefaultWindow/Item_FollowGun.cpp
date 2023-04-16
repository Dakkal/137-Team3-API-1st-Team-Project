#include "stdafx.h"
#include "Item_FollowGun.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Player.h"

CItem_FollowGun::CItem_FollowGun()
{
}


CItem_FollowGun::~CItem_FollowGun()
{
}

void CItem_FollowGun::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 2.f;

	m_pTarget = CGameCore::GetInst()->GetPlayer();
}

int CItem_FollowGun::Update()
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

void CItem_FollowGun::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_FollowGun::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TCHAR szName[32] = L"À¯µµÅº";
	TextOut(hDC, m_tInfo.fX - 30.f, m_tInfo.fY + 20.f, szName, lstrlen(szName));
}

void CItem_FollowGun::Release()
{
}

void CItem_FollowGun::OnCollision(CObj * _pObj)
{
	if (m_bCollision)
	{
		if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
		{
			m_bCollision = false;
			Use_Item(_pObj);
			DeleteObjEvt(this);
		}
	}
}

void CItem_FollowGun::Use_Item(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	dynamic_cast<CPlayer*>(_pObj)->Set_Gun(GUN_TYPE::FOLLOWGUN);
}
