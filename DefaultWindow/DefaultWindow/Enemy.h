#pragma once
#include "Obj.h"
class CEnemy :
	public CObj
{
public:
	explicit CEnemy();
	virtual ~CEnemy();

public:
	// CObj을(를) 통해 상속됨
	virtual void	Initialize()	override;
	virtual int		Update()		override;
	virtual void	Late_Update()	override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release()		override;

	virtual void	OnCollision(CObj* _pObj)	override;


public :
	void Update_Rect2();
	void Update_Rect3();
	CObj* Create_Bullet();

private:
	INFO			m_tInfo2;
	RECT			m_tRect2;

	INFO			m_tInfo3;
	RECT			m_tRect3;
};

