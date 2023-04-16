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
#include "ShotGun.h"
#include "MachineGun.h"
#include "ScrewGun.h"
#include "FollowGun.h"

CPlayer::CPlayer()
	:	CObj(OBJECT_TYPE::PLAYER)
	,	m_iHp(3)
	,	m_iMaxHp(3)
	,	m_fAngle(0.f)
	,	m_ptShotPoint{0, 0}
	,	m_iSatelliteCount(0)
	,	m_lRecoverTime(1000.f)
	,	m_lFireDelay(100.f)
	,	dwCollisionTime(0)
	,	m_pGun(nullptr)
	,	m_bFire(true)
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

	m_pArrGun[(int)GUN_TYPE::NORMALGUN]		=	new CNormalGun;
	m_pArrGun[(int)GUN_TYPE::SHOTGUN]		=	new CShotGun;
	m_pArrGun[(int)GUN_TYPE::MACHINEGUN]	=	new CMachineGun;
	m_pArrGun[(int)GUN_TYPE::SCREWGUN]		=	new CScrewGun;
	m_pArrGun[(int)GUN_TYPE::FOLLOWGUN]		=	new CFollowGun;

	for (int i = 0; i < (int)GUN_TYPE::END; ++i)
		m_pArrGun[i]->Initialize();

	m_pGun = m_pArrGun[(int)GUN_TYPE::NORMALGUN];

	dwCollisionTime = GetTickCount();
	dwFireTime = GetTickCount();
}

int CPlayer::Update(void)
{
	m_pGun->Update();
	Key_Input();
	Sort_Interval_Satellite();

	if (!m_bCollision)
	{
		if (dwCollisionTime + m_lRecoverTime < GetTickCount())
		{
			m_bCollision = true;
			dwCollisionTime = GetTickCount();
		}
	}
	else
	{
		dwCollisionTime = GetTickCount();
	}

	if (!m_bFire)
	{
		if (dwFireTime + m_lFireDelay < GetTickCount())
		{
			m_bFire = true;
			dwFireTime = GetTickCount();
		}
	}
	else
	{
		dwFireTime = GetTickCount();
	}


	__super::Update_Rect();
	
	return 0;
}

void CPlayer::Late_Update(void)
{
	m_pGun->Late_Update();
	POINT ptMouse = CGameCore::GetInst()->GetMousePos();

	m_fAngle = (atan2(m_tInfo.fY - (float)ptMouse.y, (float)ptMouse.x - m_tInfo.fX) * 57.2958f);
	m_ptShotPoint.x = LONG(m_tInfo.fX + (50.f * cos(m_fAngle * (PI / 180.f))));
	m_ptShotPoint.y = LONG(m_tInfo.fY - (50.f * sin(m_fAngle * (PI / 180.f))));

	for (int i = 0; i < (int)GUN_TYPE::END; ++i)
	{
		if (m_pGun == m_pArrGun[i])
			continue;

		m_pArrGun[i]->Reload();
	}
}

void CPlayer::Render(HDC hDC)
{
	POINT temp{};
	ZeroMemory(&temp, sizeof(POINT));



	// 포신위치. 곧 Gun의 위치가 될거다.
	m_pGun->Render(hDC);
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
	for (int i = 0; i < m_pGun->GetMaxBullet(); ++i)
	{
		RECT rect = GetRectWithXY((int)10, (int)10, (10 * (i + 1)), 0, 10);
		if (m_pGun->GetRemainBullet() >= i + 1)
		{
			SelectGDI g(hDC, BRUSH_TYPE::GREEN);
			Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
		}
		else
		{
			SelectGDI g(hDC, BRUSH_TYPE::HOLLOW);
			Rectangle(hDC, rect.left, rect.top, rect.right, rect.bottom);
		}
	}
	wstring strBullet;
	strBullet.append(L"Bullet : ");
	strBullet.append(to_wstring(m_pGun->GetRemainBullet()));
	strBullet.append(L" / ");
	strBullet.append(to_wstring(m_pGun->GetMaxBullet()));
	
	const wstring strGunName = STR_GUN[(int)m_pGun->GetGunType()];
	
	TextOut(hDC, 30, 30, strBullet.c_str(), strBullet.size());
	TextOut(hDC, 30, 60, strGunName.c_str(), strGunName.size());
	
	
	/*MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, &temp);
	LineTo(hDC, m_ptShotPoint.x, m_ptShotPoint.y);  */      

	//Safe_Delete<SelectGDI*>(p);
}

void CPlayer::Release(void)
{
	for (int i = 0; i < (int)GUN_TYPE::END; ++i)
	{
		if (nullptr != m_pArrGun[i])
			Safe_Delete<CGun*>(m_pArrGun[i]);
	}
}

void CPlayer::OnCollision(CObj * _pObj)
{
	if (!m_bCollision)
		return;

	

	switch (_pObj->GetObjType())
	{
	case OBJECT_TYPE::ENEMY_PROJECTILE :
		OnDamaged();
		m_bCollision = false;
		break;
	case OBJECT_TYPE::MONSTER :
		OnDamaged();
		m_bCollision = false;
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
		if (m_bFire)
		{
			m_bFire = false;
			m_pGun->Fire();
		}
	}

	if (GetAsyncKeyState('1'))
	{
		Set_Gun(GUN_TYPE::NORMALGUN);
		m_lFireDelay = 300;
	}

	if (GetAsyncKeyState('2'))
	{
		Set_Gun(GUN_TYPE::MACHINEGUN);
		m_lFireDelay = 200;
	}

	if (GetAsyncKeyState('3'))
	{
		Set_Gun(GUN_TYPE::SHOTGUN);
		m_lFireDelay = 700;
	}

	if (GetAsyncKeyState('4'))
	{
		Set_Gun(GUN_TYPE::SCREWGUN);
		m_lFireDelay = 300;
	}


	if (GetAsyncKeyState('5'))
	{
		Set_Gun(GUN_TYPE::FOLLOWGUN);
		m_lFireDelay = 500;
	}
	
	
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		//TODO :: USE SPECIAL ITEM
		CSatellite* pBarrior = new CSatellite(this);
		AddObjEvt(pBarrior);
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

void CPlayer::OnDamaged()
{
	m_iHp > 0 ? --m_iHp : 0;
	m_bCollision = false;


}

