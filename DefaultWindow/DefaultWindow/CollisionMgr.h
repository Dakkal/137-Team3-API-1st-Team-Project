#pragma once
#include "Obj.h"
class CCollisonMgr
{
	SINGLETON(CCollisonMgr);

public:
	static void	Collision_Rect(list<CObj*> Dst, list<CObj*> Src);
	static void	Collision_Sphere(list<CObj*> Dst, list<CObj*> Src);
	static bool Check_Sphere(CObj* pDst, CObj* pSrc);
};

