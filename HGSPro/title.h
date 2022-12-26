//--------------------------------------
//タイトルの処理
//--------------------------------------
#ifndef _TITLE_H
#define _TITLE_H

#include "main.h"
#include "scene.h"

//前方宣言
class CBg;
class CPolygon;
class CSound;
class CTitle
{
public:

	CTitle();
	~CTitle();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void NextMode(bool bNextMode) { m_bNextMode = bNextMode; }

private:
	CBg		*m_pBg;

	bool m_bNextMode;
};

#endif //_TITLE_H