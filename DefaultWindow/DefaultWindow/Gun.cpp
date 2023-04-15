#include "stdafx.h"
#include "Gun.h"
#include "GameCore.h"
#include "SceneMgr.h"
#include "Player.h"
CGun::CGun()
	: CObj(OBJECT_TYPE::GUN)
	, m_pOwner(nullptr)
{
	m_pOwner = CGameCore::GetInst()->GetPlayer();
}

CGun::~CGun()
{
}