#pragma once
#include "Obj.h"
class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();
public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void	Key_Input(void);
};

