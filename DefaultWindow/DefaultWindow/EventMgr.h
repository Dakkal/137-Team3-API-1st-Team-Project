#pragma once
#include "stdafx.h"
class CObj;

struct tagEvent
{
	DWORD_PTR	lParam;
	DWORD_PTR	rParam;
	EVENT_TYPE	evtType;
};
struct tagTemp
{

};

class CEventMgr
{
	SINGLETON(CEventMgr);


public:
	void Update();
	void AddEvent(tagEvent _eve) { m_vecEvent.push_back(_eve); }
	
private:
	void ExcuteEvent(tagEvent _eve);
	
private: 
	vector<tagEvent>	m_vecEvent;
	vector<CObj*>		m_vecDeleteObj;

};

