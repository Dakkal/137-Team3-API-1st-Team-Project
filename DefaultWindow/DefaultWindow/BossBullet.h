#pragma once
#include "Obj.h"
class CBossBullet :
	public CObj
{
public:
	CBossBullet();
	virtual ~CBossBullet();

	// Inherited via CObj
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;
	virtual void OnCollision(CObj * _pObj) override;

public:
	void	Fast_Pattern();
	void	FireWork_Pattern();
	void    Follow_Pattern();
	void	Random_Pattern();
	void    Rage_Pattern();
	void	Screw_Pattern();

	int		Keep_Pattern();


private:
	int				m_iCheckPattern;
	bool			m_bRageCheck;

	DIR_TYPE		m_eDirType;

	// È¸¿À¸®ÅºÀ» À§ÇÑ ¸â¹öº¯¼ö
	POINT			m_tCenter;
	float			m_fBullRotAngle;
	float			m_fBullRotSpeed;
	bool			m_bStart;

	// À¯µµÅºÀ» À§ÇÑ ¸â¹öº¯¼ö
	float			m_fDiagonal;
	float			m_fWidth;
	float			m_fHeigth;
};

