#include "stdafx.h"
#include "Obj.h"
#include "EventMgr.h"

void AddObjEvt(CObj* _pObj)
{
	tagEvent eve;
	eve.lParam = (DWORD_PTR)_pObj;
	eve.evtType = EVENT_TYPE::ADD_OBJ;

	CEventMgr::GetInst()->AddEvent(eve);
}

void ChangeSceneEvt(SCENE_TYPE _eType)
{
	tagEvent eve;
	eve.lParam = (DWORD_PTR)_eType;
	eve.evtType = EVENT_TYPE::CHANGE_SCENE;

	CEventMgr::GetInst()->AddEvent(eve);
}

void DeleteObjEvt(CObj* _pObj)
{
	tagEvent eve;
	eve.lParam = (DWORD_PTR)_pObj;
	eve.evtType = EVENT_TYPE::DELETE_OBJ;

	CEventMgr::GetInst()->AddEvent(eve);
}