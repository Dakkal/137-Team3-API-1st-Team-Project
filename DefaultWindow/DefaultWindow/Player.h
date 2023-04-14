#pragma once
#include "Obj.h"
class CPlayer :	public CObj
{
public:
	explicit CPlayer();
	virtual ~CPlayer();

public:
	// CObj을(를) 통해 상속됨
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release()		override;

public:
	virtual void	OnCollision(CObj* _pObj)	override;

private:
	void			Key_Input();


private:
	float			m_fAngle;
	float			m_fAccTime;			// 흐른시간
	float			m_fInvinTime;		// 무적시간
	POINT			m_ptShotPoint;
};

