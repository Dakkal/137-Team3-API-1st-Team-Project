#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
	:CObj(OBJECT_TYPE::MONSTER)
{

}


CEnemy::~CEnemy()
{
	Release();
}

void CEnemy::Initialize()
{
}

int CEnemy::Update()
{
	return 0;
}

void CEnemy::Late_Update()
{
}

void CEnemy::Render(HDC hDC)
{
}

void CEnemy::Release()
{
}

void CEnemy::OnCollision(CObj * _pObj)
{
}

