#pragma once
#include "stdafx.h"

class CGameCore
{
	SINGLETON(CGameCore);

private:
	bool m_bPlaying;

public:
	void Initialize();
	void Tick();
	void Stop() { m_bPlaying = false; }

public:
	bool IsPlaying() { return m_bPlaying; }


};

