#include "stdafx.h"
#include "Bullet.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "SelectGDI.h"
#include "BossHead.h"
#include "BossGun.h"
#include "BossMissile.h"

CBullet::CBullet()
	:CObj(OBJECT_TYPE::PLAYER_PROJECTILE)
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;

	m_fSpeed = 5.f;
	m_fDistance = 30.f;
	
	//스크류
	m_bStart = true;
	m_fBullRotAngle = 0.f;
	m_fBullRotSpeed = 30.f;
	ZeroMemory(&m_tCenter, sizeof(POINT));

	// 유도
	m_fMin = 600.f;
	m_fDiagonal = 0.f;
	m_fWidth = 0.f;
	m_fHeigth = 0.f;
	
}

int CBullet::Update()
{
	/*if (m_tRect.left <= 0 || m_tRect.top <= 0 || m_tRect.right >= WINCX)
		DeleteObjEvt(this);*/

	CScene* pScene = CSceneMgr::GetInst()->GetCurrScene();
	list<CObj*>& copyList = pScene->GetObjTypeList(OBJECT_TYPE::MONSTER);
	CScene* pBossScene = CSceneMgr::GetInst()->GetCurrScene();
	list<CObj*>& copyBossList = pBossScene->GetObjTypeList(OBJECT_TYPE::BOSS);

	if (GUN_TYPE::NORMALGUN == m_eGunType)	{ Normal_Pattern(); }
	if (GUN_TYPE::SHOTGUN == m_eGunType)	{ ShotGun_Pattern(); }
	if (GUN_TYPE::MACHINEGUN == m_eGunType) { MachineGun_Pattern(); }
	if (GUN_TYPE::SCREWGUN == m_eGunType)	{ ScrewGun_Pattern(); }
	if (GUN_TYPE::FOLLOWGUN == m_eGunType) 
	{ 
		for (auto iter : copyList)
			Find_Follow_Distance(iter);
		for (auto iter : copyBossList)
			Find_Follow_Distance(iter);

		FollowGun_Pattern(); 
	}

	__super::Update_Rect();

	return 0;
}

void CBullet::Late_Update()
{
	
}

void CBullet::Render(HDC hDC)
{
	float fRadian = m_fAngle * (PI / 180);

	/*MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_tInfo.fX - 10.f, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY - 30.f);
	LineTo(hDC, m_tInfo.fX + 10.f, m_tInfo.fY);
	LineTo(hDC, m_tInfo.fX, m_tInfo.fY);*/
	SelectGDI g(hDC, BRUSH_TYPE::BLUE);
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}

void CBullet::OnCollision(CObj * _pObj)
{
	if (!m_bCollision)
		return;

	switch (_pObj->GetObjType())
	{
	case OBJECT_TYPE::MONSTER:
		DeleteObjEvt(this);
		break;
	case OBJECT_TYPE::BOSS:
		DeleteObjEvt(this);
		break;
	}
	m_bCollision = false;

}

void CBullet::Normal_Pattern()
{
	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
}

void CBullet::ShotGun_Pattern()
{
	if (m_eDirType == DIR_TYPE::LEFT) 
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 90.f);
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
	}
	if (m_eDirType == DIR_TYPE::UP) 
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
	}
	if (m_eDirType == DIR_TYPE::RIGHT) 
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 720.f);
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
	}
}

void CBullet::MachineGun_Pattern()
{
	m_fSpeed = 10.f;

	m_tInfo.fX += m_fSpeed * cosf(m_fAngle * PI / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * PI / 180.f);
}

void CBullet::ScrewGun_Pattern()
{
	if( m_bStart == true)
	{
		m_tCenter.x = (LONG)m_tInfo.fX;
		m_tCenter.y = (LONG)m_tInfo.fY;
		m_bStart = false;
	} 

	m_tCenter.x += LONG(m_fSpeed * cosf(m_fAngle * PI / 180.f));
	m_tCenter.y -= LONG(m_fSpeed * sinf(m_fAngle * PI / 180.f));

	m_fBullRotAngle += m_fBullRotSpeed;

	m_tInfo.fX = m_tCenter.x + m_fDistance * cosf(m_fBullRotAngle * PI / 180.f);
	m_tInfo.fY = m_tCenter.y - m_fDistance * -sinf(m_fBullRotAngle * PI / 180.f);

	m_fDistance += .5f;
}

void CBullet::FollowGun_Pattern()
{
	float	fRadian = 0.f;

	fRadian = acosf(m_fWidth / m_fDiagonal);

	if ((m_fHeigth - m_tInfo.fY) > m_tInfo.fY)
		fRadian *= -1.f;

	m_tInfo.fX += m_fSpeed * cosf(fRadian);
	m_tInfo.fY -= m_fSpeed * sinf(fRadian);

}

void CBullet::Find_Follow_Distance(CObj * _pObj)
{
	float f_Diagonal = 0.f;
	float fWidth = 0.f;
	float fHeigth = 0.f;

	if (_pObj->GetObjType() == OBJECT_TYPE::MONSTER)
	{
		fWidth = _pObj->Get_Info().fX - m_tInfo.fX;
		fHeigth = _pObj->Get_Info().fY - m_tInfo.fY;
		f_Diagonal = sqrtf(fWidth * fWidth + fHeigth * fHeigth);

		if (f_Diagonal <= m_fMin)
		{
			m_fDiagonal = f_Diagonal;
			m_fWidth = fWidth;
			m_fHeigth = fHeigth;
			m_fMin = m_fDiagonal;
		}
	}

	if (_pObj->GetObjType() == OBJECT_TYPE::BOSS)
	{
		fWidth = _pObj->Get_Info().fX - m_tInfo.fX;
		fHeigth = _pObj->Get_Info().fY - m_tInfo.fY;
		f_Diagonal = sqrtf(fWidth * fWidth + fHeigth * fHeigth);

		if (f_Diagonal <= m_fMin)
		{
			m_fDiagonal = f_Diagonal;
			m_fWidth = fWidth;
			m_fHeigth = fHeigth;
			m_fMin = m_fDiagonal;
		}
	}
	
}
