#include "stdafx.h"
#include "Player.h"
#include "SelectGDI.h"
#include "GameCore.h"
#include "ASCII.h"

CPlayer::CPlayer()
	:	CObj(OBJECT_TYPE::PLAYER)
	,	m_fAngle(0.f)
	,	m_ptShotPoint{0, 0}
	,	m_fInvinTime(3000.f)
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
}

int CPlayer::Update(void)
{

	Key_Input();
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
	POINT temp;

	Ellipse(hDC, m_ptShotPoint.x - 10, m_ptShotPoint.y - 10, m_ptShotPoint.x + 10, m_ptShotPoint.y + 10);
	/*MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, &temp);
	LineTo(hDC, m_ptShotPoint.x, m_ptShotPoint.y);  */      
	
	TextOut(hDC, m_tRect.left, m_tInfo.fY + 30, L"플레이어", wcsnlen_s(L"플레이어", 10));
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release(void)
{
}

void CPlayer::OnCollision(CObj * _pObj)
{
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
		
}
