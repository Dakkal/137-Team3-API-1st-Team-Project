#pragma once
#include "Boss.h"
class CBossMissile_Pot :
	public CBoss
{
public:
	explicit CBossMissile_Pot(CBoss* _pOwner);
	virtual ~CBossMissile_Pot();

public:
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Late_Update() override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release() override;
	virtual void	OnCollision(CObj * _pObj) override;

public:
	CBoss*		m_pOwner;
	float		m_fSpeed;

};

