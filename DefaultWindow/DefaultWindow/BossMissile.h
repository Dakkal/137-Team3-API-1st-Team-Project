#pragma once
#include "Boss.h"
class CBossMissile :
	public CBoss
{
public:
	explicit CBossMissile();
	virtual ~CBossMissile();

public:
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnCollision(CObj * _pObj) override;

private:
	CObj*	m_pOwner;
	int		iCount;
};

