//=============================================================================
//
// Polygon処理
//
//=============================================================================
#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "scene2D.h"
class CTexture;

class CPolygon : public CScene2D
{

public:

	CPolygon(OBJTYPE nPriority = OBJTYPE_POLYGON);		//コンストラクタ
	~CPolygon();									//デストラクタ

	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CPolygon *Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, CTexture::Type texture, D3DXCOLOR col = {1.0,1.0,1.0,1.0},int nPriority = OBJTYPE_POLYGON);
	void SetPos(D3DXVECTOR3 pos);
	void SetAngle(float fAngle);
	float GetAngle() { return m_fAngle; }
	D3DXVECTOR3 GetPos() { return m_pos; }
	void SetScale(D3DXVECTOR3 scale);
	D3DXVECTOR3 GetScale() { return m_Scale; }
	void SetDraw(bool bDraw) { m_bDraw = bDraw; }
	D3DXCOLOR GetCol() { return m_col; }
	void SetCol(D3DXCOLOR col);
private:
	D3DXVECTOR3 m_Scale;
	float m_fAngle;
	CTexture::Type m_Tex;
	bool m_bDraw;
};

#endif // _POLYGON_H_
