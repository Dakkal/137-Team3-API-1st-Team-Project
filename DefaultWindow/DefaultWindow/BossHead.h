#pragma once
#include "Boss.h"
class CBossHead :
	public CBoss
{
public:
	explicit CBossHead(CBoss* _pOwner);
	virtual ~CBossHead();

public:
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnCollision(CObj * _pObj) override;



private:
	DWORD	dwCollisionTime;
	LONG	m_lRecoverTime;
	CBoss*	m_pOwner;
};

