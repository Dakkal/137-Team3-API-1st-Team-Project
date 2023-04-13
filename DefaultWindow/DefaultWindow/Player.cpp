#include "stdafx.h"
#include "Player.h"
#include "SelectGDI.h"

CPlayer::CPlayer()
	:CObj(OBJECT_TYPE::PLAYER)
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

}

void CPlayer::Render(HDC hDC)
{
	SelectGDI p(hDC, PEN_TYPE::BLUE);
	SelectGDI b(hDC, BRUSH_TYPE::HOLLOW);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CPlayer::Release(void)
{
}

void CPlayer::OnCollision()
{
}

void CPlayer::Key_Input(void)
{
	//GetKeyState()
	if (GetAsyncKeyState(VK_RIGHT))
		m_tInfo.fX += m_fSpeed;

	if (GetAsyncKeyState(VK_LEFT))
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;

}
