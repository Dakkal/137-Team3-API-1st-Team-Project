#include "stdafx.h"
#include "Obj.h"


CObj::CObj(OBJECT_TYPE _eType)
	: m_fSpeed(0.f)
	, m_fAngle(0.f)
	, m_fDistance(0.f)
	, m_eObjType(_eType)
	, m_bEvent(false)
	, m_dwTime(GetTickCount())
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}

void CObj::Update_Rect(void)
{
	m_tRect.left	= LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top		= LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.right	= LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom	= LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}
