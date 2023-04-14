#include "stdafx.h"
#include "EventMgr.h"
#include "SceneMgr.h"
#include "Scene.h"


CEventMgr::CEventMgr()
{
}


CEventMgr::~CEventMgr()
{
}

void CEventMgr::Update()
{
	for (size_t i = 0; i < m_vecDeleteObj.size(); i++)
	{
		if (nullptr != m_vecDeleteObj[i])
			Safe_Delete<CObj*>(m_vecDeleteObj[i]);
	}
	m_vecDeleteObj.clear();

	for (size_t i = 0; i < m_vecEvent.size(); ++i)
	{
		ExcuteEvent(m_vecEvent[i]);
	}
	m_vecEvent.clear();
}

void CEventMgr::ExcuteEvent(tagEvent _eve)
{
	switch (_eve.evtType)
	{
	case EVENT_TYPE::ADD_OBJ :
		// lParam : CObj*
		CSceneMgr::GetInst()->GetCurrScene()->AddObj((CObj*)_eve.lParam);
		break;

	case EVENT_TYPE::CHANGE_SCENE :
		// lParam : SCENE_TYPE(ENUM)
		CSceneMgr::GetInst()->ChangeScene((SCENE_TYPE)_eve.evtType);
		break;

	case EVENT_TYPE::DELETE_OBJ :
		// lParam : CObj*
		m_vecDeleteObj.push_back((CObj*)_eve.lParam);
		break;
	}
}


