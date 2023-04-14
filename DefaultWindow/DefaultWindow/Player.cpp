#include "stdafx.h"
#include "Player.h"
#include "SelectGDI.h"
#include "GameCore.h"

CPlayer::CPlayer()
	:	CObj(OBJECT_TYPE::PLAYER)
	,	m_fAngle(0.f)
	,	m_ptShotPoint{0, 0}
{
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo = { 400.f, 300.f, 50.f, 50.f };
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
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(hDC, m_ptShotPoint.x, m_ptShotPoint.y);
	
}

void CPlayer::Release(void)
{
}

void CPlayer::OnCollision(CObj * _pObj)
{
	
}


void CPlayer::Key_Input(void)
{
	//GetKeyState()
	if (GetAsyncKeyState('W'))
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState('S'))
		m_tInfo.fY += m_fSpeed;
	
	if (GetAsyncKeyState('A'))
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState('D'))
		m_tInfo.fX += m_fSpeed;

}
