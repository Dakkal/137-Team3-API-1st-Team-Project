#include "stdafx.h"
#include "Player.h"
#include "SelectGDI.h"
#include "GameCore.h"
#include "ASCII.h"
#include "EventFunc.h"
#include "Satellite.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "CustomFunc.h"
#include "Bullet.h"
#include "NormalGun.h"

CPlayer::CPlayer()
	:	CObj(OBJECT_TYPE::PLAYER)
	,	m_iHp(3)
	,	m_iMaxHp(3)
	,	m_fAngle(0.f)
	,	m_ptShotPoint{0, 0}
	,	m_fInvinTime(3000.f)
	,	m_iSatelliteCount(0)
	,	m_lRecoverTime(3000.f)
	,	dwTime(0)
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo = { WINCX / 2, WINCY - 50.f, 50.f, 50.f };
	m_fSpeed = 10.f;
	
	dwTime = GetTickCount();

	
}

int CPlayer::Update(void)
{
	Key_Input();
	Sort_Interval_Satellite();
	__super::Update_Rect();
	
	return 0;
}

void CPlayer::Late_Update(void)
{
	POINT ptMouse = CGameCore::GetInst()->GetMousePos();

	m_fAngle = (atan2(m_tInfo.fY - (float)ptMouse.y, (float)ptMouse.x - m_tInfo.fX) * 57.2958f);

	m_ptShotPoint.x = LONG(m_tInfo.fX + (50.f * cos(m_fAngle * (PI / 180.f))));
	m_ptShotPoint.y = LONG(m_tInfo.fY - (50.f * sin(m_fAngle * (PI / 180.f))));

}

void CPlayer::Render(HDC hDC)
{
	POINT temp{};
	ZeroMemory(&temp, sizeof(POINT));
	
	
	
	if (!m_bCollision)
	{
		if (dwTime + m_lRecoverTime < GetTickCount())
		{
			m_bCollision = true;
			dwTime = GetTickCount();
		}
	}
	else
	{
		dwTime = GetTickCount();
	}


	// 포신위치. 곧 Gun의 위치가 될거다.
	Ellipse(hDC, m_ptShotPoint.x - 10, m_ptShotPoint.y - 10, m_ptShotPoint.x + 10, m_ptShotPoint.y + 10);
	
	if (!m_bCollision)
	{
		SelectGDI g(hDC, BRUSH_TYPE::RED);
		Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	}
	else
		Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

	TextOut(hDC, (int)m_tRect.left, (int)m_tInfo.fY + 30, L"플레이어", wcsnlen_s(L"플레이어", 10));
	
	
	

	//UI_RENDER

	// 1. HP Bar
	for (int i = 0; i < m_iMaxHp; ++i)
	{
		RECT rect = GetRectWithXY((int)m_tInfo.fX, (int)m_tInfo.fY, -40, -1 * (10 * (i + 1)), 10);
		if (m_iHp >= i + 1)
		{
			SelectGDI g(hDC, BRUSH_TYPE::RED);
			Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
		}
		else
		{
			SelectGDI g(hDC, BRUSH_TYPE::HOLLOW);
			Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
		}
	}

	// 2. SP(총알) Bar

	
	
	/*MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, &temp);
	LineTo(hDC, m_ptShotPoint.x, m_ptShotPoint.y);  */      

	//Safe_Delete<SelectGDI*>(p);
}

void CPlayer::Release(void)
{

}

void CPlayer::OnCollision(CObj * _pObj)
{
	if (!m_bCollision)
		return;

	switch (_pObj->GetObjType())
	{
	case OBJECT_TYPE::ENEMY_PROJECTILE :
		break;
	case OBJECT_TYPE::MONSTER :
		break;
	case OBJECT_TYPE::ITEM :
		break;
	}
}


void CPlayer::Key_Input(void)
{	
	if (GetAsyncKeyState('A'))
	{
		if (m_tRect.left <= 0)
			return;
		m_tInfo.fX -= m_fSpeed;
	}
		

	if (GetAsyncKeyState('D'))
	{
		if (m_tRect.right >= WINCX)
			return;
		m_tInfo.fX += m_fSpeed;
	}

	if (GetAsyncKeyState(VK_LBUTTON))
	{
		// TODO :: Shoot();
		AddObjEvt(new CSatellite(this));
	}

	if (GetAsyncKeyState('1'))
	{
		m_pGunList->push_back(Get_Gun());
	}
	
	
	if (GetAsyncKeyState(VK_SPACE))
	{
		// TODO :: Shoot();
		static_cast<CGun*>(m_pGunList->front())->Fire_Gun();
	}

}

void CPlayer::Sort_Interval_Satellite()
{
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurrScene();
	list<CObj*>& copyList = pCurScene->GetObjTypeList(OBJECT_TYPE::SATTELLITE);

	if (copyList.size() == m_iSatelliteCount)
		return;

	m_iSatelliteCount = copyList.size();
	list<CObj*>::iterator iter = copyList.begin();

	for (int i = 0; iter != copyList.end(); ++iter, ++i)
		(*iter)->SetAngle((float)(360 / copyList.size()) * (i + 1));
	
}

//CObj* CPlayer::Create_Bullet()
//{
//	m_pBullet = new CBullet;
//	m_pBullet->Initialize();
//	m_pBullet->Set_Pos(m_ptShotPoint.x, m_ptShotPoint.y);
//	m_pBullet->Set_Angle(m_fAngle);
//	dynamic_cast<CBullet*>(m_pBullet)->Set_GunType(GUN_TYPE::NORMALGUN);
//
//	return m_pBullet;
//}

CObj* CPlayer::Get_Gun()
{
	CObj* pGun = new CNormalGun;
	pGun->Initialize();
	

	return pGun;
}
