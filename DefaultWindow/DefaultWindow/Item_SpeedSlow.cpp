#include "stdafx.h"
#include "Item_SpeedSlow.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Enemy.h"
#include "Player.h"

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

	m_fSpeed = 2.f;

	m_pTarget = CGameCore::GetInst()->GetPlayer();
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
	TCHAR szName[32] = L"천천히";
	TextOut(hDC, m_tInfo.fX - 30.f, m_tInfo.fY + 20.f, szName, lstrlen(szName));
}

void CItem_SpeedSlow::Release()
{
}

void CItem_SpeedSlow::OnCollision(CObj * _pObj)
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

void CItem_SpeedSlow::Use_Item(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		list<CObj*>& MonsterList = CSceneMgr::GetInst()->GetCurrScene()->GetObjTypeList(OBJECT_TYPE::MONSTER);

		list<CObj*> ::iterator Iter = MonsterList.begin();

		for (auto iter : MonsterList)
		{
			// TODO:몬스터 속도 느리게해야함
		}

		list<CObj*>& Enemy_ProjectileList = CSceneMgr::GetInst()->GetCurrScene()->GetObjTypeList(OBJECT_TYPE::ENEMY_PROJECTILE);
		list<CObj*> ::iterator Iter2 = Enemy_ProjectileList.begin();
		for (auto iter2 : Enemy_ProjectileList)
		{
			// TODO:적 총알 속도 느리게해야함
		}
	}
}

