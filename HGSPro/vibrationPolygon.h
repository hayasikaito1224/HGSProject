//=============================================================================
//
// Polygon����
//
//=============================================================================
#ifndef _VIBRATIONPOLYGON_H_
#define _VIBRATIONPOLYGON_H_

#include "scene2D.h"
class CTexture;

class CVibrationPolygon : public CScene2D
{

public:

	CVibrationPolygon(OBJTYPE nPriority = OBJTYPE_POLYGON);	//�R���X�g���N�^
	~CVibrationPolygon();									//�f�X�g���N�^

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CVibrationPolygon *Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, CTexture::Type texture, D3DXCOLOR col = { 1.0,1.0,1.0,1.0 }, int nPriority = OBJTYPE_POLYGON);
	void SetPos(D3DXVECTOR3 pos);
	D3DXVECTOR3 GetPos() { return m_pos; }
	D3DXVECTOR3 GetScale() { return m_Scale; }
	void SetDraw(bool bDraw) { m_bDraw = bDraw; }
	D3DXCOLOR GetColor() { return m_col; }
	void SetCol(D3DXCOLOR col);

	// �U������ݒ�
	void SetVibesWidth(float vibration);
	// �U���t���[����ݒ�
	void SetVibseFrame(float vibration);
	// �U�������邩�ݒ�
	void SetVibration(bool vibration);

private:
	D3DXVECTOR3 m_Scale;
	CTexture::Type m_Tex;
	bool m_bDraw;

	// �t���[���J�E���g
	int m_framecount;

	// �U����
	float m_vibesWidth;
	// �U���X�s�[�h
	float m_vibesSpeed;
	// �؂�ւ�
	bool m_bSwitch;

	// �U���ݒ�
	bool m_bVibration;

};

#endif // _POLYGON_H_
