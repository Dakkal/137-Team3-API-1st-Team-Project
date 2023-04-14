#include "stdafx.h"
#include "Bullet.h"


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
}

int CBullet::Update()
{
	return 0;
}

void CBullet::Late_Update()
{
}

void CBullet::Render(HDC hDC)
{
}

void CBullet::Release()
{
}

void CBullet::OnCollision(CObj * _pObj)
{
}

