#include "stdafx.h"
#include "Scene_Test.h"
#include "Obj.h"
#include "Player.h"
#include "NormalGun.h"
#include "EventFunc.h"
#include "Item_Timestop.h"
#include "Enemy.h"
#include "CollisionMgr.h"
#include "Item_Bomb.h"
#include "Citem_ScrewGun.h"

CScene_Test::CScene_Test()
	:CScene(SCENE_TYPE::TEST)
{
}


CScene_Test::~CScene_Test()
{
	
}

void CScene_Test::Enter()
{
	

}

void CScene_Test::Update()
{
	CScene::Update();
	m_dwDeltaTime = GetTickCount() - m_dwStartTime;
}

void CScene_Test::Late_Update()
{
	CScene::Late_Update();
}

void CScene_Test::Render(HDC _dc)
{
	CScene::Render(_dc);
}

void CScene_Test::Exit()
{
	
}

void CScene_Test::GameOver()
{
	Exit();
}
