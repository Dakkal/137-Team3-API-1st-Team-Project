#pragma once
#include "stdafx.h"

class CPlayer;

class CGameCore
{
	SINGLETON(CGameCore);



public:
	void Initialize();
	void Tick();
	void Stop() { m_bPlaying = false; }
	void Release();

public:
	CPlayer*	GetPlayer() { return m_pPlayer; }
	bool		IsPlaying() { return m_bPlaying; }


private:
	CPlayer*	m_pPlayer;
	bool		m_bPlaying;

};

