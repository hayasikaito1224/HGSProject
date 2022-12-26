//--------------------------------------
//�^�C�g���̏���
//--------------------------------------
#ifndef _RESULT_H
#define _RESULT_H
#include "main.h"
#include "scene.h"

//�O���錾
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
	bool				m_bNextMode;//���̃��[�h�ɍs�����߂�

};


#endif //_RESULT_H