#include "stdafx.h"
#include "CollisionMgr.h"


CCollisonMgr::CCollisonMgr()
{
}


CCollisonMgr::~CCollisonMgr()
{
}

void CCollisonMgr::Collision_Rect(list<CObj*> Dst, list<CObj*> Src)
{
	RECT rc;
	for (auto& Dest : Dst)
	{
		for (auto& Sour : Src)
		{
			if (IntersectRect(&rc, &Dest->Get_Rect(), &Sour->Get_Rect()))
			{
				Dest->OnCollision(Sour);
				Sour->OnCollision(Dest);
			}
		}
	}
}

void CCollisonMgr::Collision_Sphere(list<CObj*> Dst, list<CObj*> Src)
{
	for (auto& Dest : Dst)
	{
		for (auto& Sour : Src)
		{
			if (Check_Sphere(Dest, Sour))
			{
				Dest->OnCollision(Sour);
				Sour->OnCollision(Dest);
			}
		}
	}
}

bool CCollisonMgr::Check_Sphere(CObj * pDst, CObj * pSrc)
{
	float fWidth = fabs(pDst->Get_Info().fX - pSrc->Get_Info().fX);
	float fHeight = fabs(pDst->Get_Info().fY - pSrc->Get_Info().fY);

	float fDiagonal = sqrt(pow(fWidth, 2) + pow(fHeight, 2));
	float fRadius = (pDst->Get_Info().fCX + pSrc->Get_Info().fCX) * 0.5f;

	return fDiagonal <= fRadius;
}
