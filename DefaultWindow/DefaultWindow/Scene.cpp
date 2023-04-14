#include "stdafx.h"
#include "Scene.h"



CScene::CScene(SCENE_TYPE _eType)
	: m_eType(_eType)
{
}

CScene::~CScene()
{
}

void CScene::Update()
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end(); ++iter)
			(*iter)->Update();
	}
}

void CScene::Late_Update()
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end(); ++iter)
			(*iter)->Late_Update();
	}

}

void CScene::Render(HDC hDC)
{
	for (int i = 0; i < (int)OBJECT_TYPE::END; ++i)
	{
		list<CObj*>::iterator iter = m_arrObjList[i].begin();
		for (; iter != m_arrObjList[i].end(); ++iter)
			(*iter)->Render(hDC);
	}
}
