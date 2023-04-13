#pragma once
#include "GameCore.h"
#include "Obj.h"
class CScene
{
public:
	virtual void Enter()				PURE;
	virtual void Update();
	virtual void Late_Update();
	virtual void Render(HDC hDC);
	virtual void Exit()					PURE;

public:
	SCENE_TYPE		GetSceneType()						{ return m_eType; }

	void			AddObj(CObj* _pObj)					{ m_arrObjList[(int)_pObj->GetObjType()].push_back(_pObj); }
	list<CObj*>&	GetObjTypeList(OBJECT_TYPE _eType)	{ return m_arrObjList[(int)_eType]; }

public:
	// TODO :: �浹üũ �Լ� ����� �����ϱ�.

public:
	explicit CScene(SCENE_TYPE _eType);
	virtual ~CScene();

private:
	SCENE_TYPE		m_eType;
	list<CObj*>		m_arrObjList[(int)OBJECT_TYPE::END];
};

