#include "stdafx.h"
#include "Item_Life.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Player.h"

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

	m_pTarget = CGameCore::GetInst()->GetPlayer();
}

int CItem_Life::Update()
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

void CItem_Life::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_Life::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TCHAR szName[32] = L"¸ñ¼û+1";
	TextOut(hDC, m_tInfo.fX - 30.f, m_tInfo.fY + 20.f, szName, lstrlen(szName));
}

void CItem_Life::Release()
{
}

void CItem_Life::OnCollision(CObj * _pObj)
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

void CItem_Life::Use_Item(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		CPlayer* pPlayer = dynamic_cast<CPlayer*>(_pObj);
		if (pPlayer->Get_Hp() == 3)
			return;
		else
			pPlayer->Set_Hp(pPlayer->Get_Hp() + 1);
	}
}
