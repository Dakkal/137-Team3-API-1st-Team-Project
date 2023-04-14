#include "stdafx.h"
#include "Bullet.h"
#include "SceneMgr.h"
#include "Scene.h"

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

	// 타입 - 플레이어에서 바꿔줘야하나?, 세트 함수는 만듬
	// m_eBullType = BULLET_TYPE::NORMAL;
}

int CBullet::Update()
{
	//if (m_bEvent)
	//	return OBJ_EVENT;

	/*switch (m_eBullType)
	{
	case BULLET_TYPE::NORMAL:
		

	case BULLET_TYPE::EPIC:
		m_tInfo.iAttack = 15;
		m_fSpeed = 7.f;
		m_tInfo.fX -= m_fSpeed;
		break;

	case BULLET_TYPE::LEGEND:
		m_tInfo.iAttack = 20;
		m_fSpeed = 9.f;
		m_tInfo.fX -= m_fSpeed;
		break;
	}*/
	


	m_tInfo.iAttack = 10;
	m_fSpeed = 5.f;
	m_tInfo.fY -= m_fSpeed;
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	
}

void CBullet::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(hDC, (int)m_tInfo.fX - 10, (int)m_tInfo.fY);
	LineTo(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY - 30);
	LineTo(hDC, (int)m_tInfo.fX + 10, (int)m_tInfo.fY);
	LineTo(hDC, (int)m_tInfo.fX, (int)m_tInfo.fY);
}

void CBullet::Release()
{
}

void CBullet::OnCollision(CObj * _pObj)
{
}

