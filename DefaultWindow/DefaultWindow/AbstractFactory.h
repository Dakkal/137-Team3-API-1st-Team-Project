#pragma once
#include "Obj.h"

template <typename T>
class CAbstractFactory
{
public:

	CAbstractFactory()
	{
	}

	~CAbstractFactory()
	{
	}

public:
	static CObj* Creat(void)
	{
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}
};

