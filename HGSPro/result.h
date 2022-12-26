//--------------------------------------
//タイトルの処理
//--------------------------------------
#ifndef _RESULT_H
#define _RESULT_H
#include "main.h"
#include "scene.h"

//前方宣言
class CBg;
class CPolygon;
class CResult
{
public:

	CResult();
	~CResult();
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void NextMode(bool bNextMode) { m_bNextMode = bNextMode; }
private:
	static CBg			*m_pBg;
	bool				m_bNextMode;//次のモードに行くための

};


#endif //_RESULT_H