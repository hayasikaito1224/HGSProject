//=============================================================================
//
// Polygon処理
//
//=============================================================================
#ifndef _VIBRATIONPOLYGON_H_
#define _VIBRATIONPOLYGON_H_

#include "scene2D.h"
class CTexture;

class CVibrationPolygon : public CScene2D
{

public:

	CVibrationPolygon(OBJTYPE nPriority = OBJTYPE_POLYGON);	//コンストラクタ
	~CVibrationPolygon();									//デストラクタ

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

	// 振動幅を設定
	void SetVibesWidth(float vibration);
	// 振動フレームを設定
	void SetVibseFrame(float vibration);
	// 振動させるか設定
	void SetVibration(bool vibration);

private:
	D3DXVECTOR3 m_Scale;
	CTexture::Type m_Tex;
	bool m_bDraw;

	// フレームカウント
	int m_framecount;

	// 振動幅
	float m_vibesWidth;
	// 振動スピード
	float m_vibesSpeed;
	// 切り替え
	bool m_bSwitch;

	// 振動設定
	bool m_bVibration;

};

#endif // _POLYGON_H_
