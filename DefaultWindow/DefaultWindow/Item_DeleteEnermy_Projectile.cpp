#include "stdafx.h"
#include "Item_DeleteEnermy_Projectile.h"
#include "Scene.h"
#include "SceneMgr.h"
#include "EventFunc.h"
#include "Enemy.h"

CItem_DeleteEnermy_Projectile::CItem_DeleteEnermy_Projectile()
{
}


CItem_DeleteEnermy_Projectile::~CItem_DeleteEnermy_Projectile()
{
}

void CItem_DeleteEnermy_Projectile::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 5.f;
}

int CItem_DeleteEnermy_Projectile::Update()
{
	m_tInfo.fY += m_fSpeed;

	__super ::Update_Rect();
	return OBJ_NOEVENT;
}

void CItem_DeleteEnermy_Projectile::Late_Update()
{
	if (WINCY <= m_tRect.bottom)
		m_bDead;
}

void CItem_DeleteEnermy_Projectile::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CItem_DeleteEnermy_Projectile::Release()
{
}

void CItem_DeleteEnermy_Projectile::OnCollision(CObj * _pObj)
{
	if (_pObj->GetObjType() == OBJECT_TYPE::PLAYER)
	{
		Use_Item(_pObj);
		DeleteObjEvt(_pObj);
	}
}

void CItem_DeleteEnermy_Projectile::Use_Item(CObj * _pObj)
{
	list<CObj*>& objList = CSceneMgr::GetInst()->GetCurrScene()->GetObjTypeList(OBJECT_TYPE::ENEMY_PROJECTILE);
	
	list<CObj*> ::iterator Iter = objList.begin();

	for (auto iter : objList)
	{
		DeleteObjEvt(iter);
	}
}
