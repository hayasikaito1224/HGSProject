//=============================================================================
//
// Polygon処理
//
//=============================================================================
#include "Polygon.h"
#include "manager.h"
#include "Renderer.h"
#include "scene2D.h"

//=============================================================================
//コンストラクタ
//=============================================================================
CPolygon::CPolygon(OBJTYPE nPriority) : CScene2D(nPriority)
{
	m_fAngle = 0.0f;
	m_bDraw = true;
}

//=============================================================================
//デストラクタ
//=============================================================================
CPolygon::~CPolygon()
{

}
//------------------------------------------------------------
//頂点座標の設定
//------------------------------------------------------------
void CPolygon::SetPos(D3DXVECTOR3 pos)
{
	CScene::SetPos(pos);
	m_pos = pos;
	D3DXVECTOR3 posOrigin[4];
	D3DXVECTOR3 Rotatepos[4];

	//スケールサイズ込みの４頂点
	posOrigin[0].x = -m_Scale.x;
	posOrigin[1].x = m_Scale.x;
	posOrigin[2].x = -m_Scale.x;
	posOrigin[3].x = m_Scale.x;
	posOrigin[0].y = -m_Scale.y;
	posOrigin[1].y = -m_Scale.y;
	posOrigin[2].y = m_Scale.y;
	posOrigin[3].y = m_Scale.y;
	//回転の計算
	Rotatepos[0].x = (posOrigin[0].x*cosf(m_fAngle)) - (posOrigin[0].y*sinf(m_fAngle));
	Rotatepos[1].x = (posOrigin[1].x*cosf(m_fAngle)) - (posOrigin[1].y*sinf(m_fAngle));
	Rotatepos[2].x = (posOrigin[2].x*cosf(m_fAngle)) - (posOrigin[2].y*sinf(m_fAngle));
	Rotatepos[3].x = (posOrigin[3].x*cosf(m_fAngle)) - (posOrigin[3].y*sinf(m_fAngle));

	Rotatepos[0].y = (posOrigin[0].x*sinf(m_fAngle)) + (posOrigin[0].y*cosf(m_fAngle));
	Rotatepos[1].y = (posOrigin[1].x*sinf(m_fAngle)) + (posOrigin[1].y*cosf(m_fAngle));
	Rotatepos[2].y = (posOrigin[2].x*sinf(m_fAngle)) + (posOrigin[2].y*cosf(m_fAngle));
	Rotatepos[3].y = (posOrigin[3].x*sinf(m_fAngle)) + (posOrigin[3].y*cosf(m_fAngle));

	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(m_pos.x + Rotatepos[0].x, m_pos.y + Rotatepos[0].y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + Rotatepos[1].x, m_pos.y + Rotatepos[1].y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x + Rotatepos[2].x, m_pos.y + Rotatepos[2].y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + Rotatepos[3].x, m_pos.y + Rotatepos[3].y, 0.0f);

	m_pVtxBuff->Unlock();

}
void CPolygon::SetAngle(float fAngle)
{
	m_fAngle = fAngle;
	D3DXVECTOR3 posOrigin[4];
	D3DXVECTOR3 Rotatepos[4];

	//スケールサイズ込みの４頂点
	posOrigin[0].x = -m_Scale.x;
	posOrigin[1].x = m_Scale.x;
	posOrigin[2].x = -m_Scale.x;
	posOrigin[3].x = m_Scale.x;
	posOrigin[0].y = -m_Scale.y;
	posOrigin[1].y = -m_Scale.y;
	posOrigin[2].y = m_Scale.y;
	posOrigin[3].y = m_Scale.y;
	//回転の計算
	Rotatepos[0].x = (posOrigin[0].x*cosf(m_fAngle)) - (posOrigin[0].y*sinf(m_fAngle));
	Rotatepos[1].x = (posOrigin[1].x*cosf(m_fAngle)) - (posOrigin[1].y*sinf(m_fAngle));
	Rotatepos[2].x = (posOrigin[2].x*cosf(m_fAngle)) - (posOrigin[2].y*sinf(m_fAngle));
	Rotatepos[3].x = (posOrigin[3].x*cosf(m_fAngle)) - (posOrigin[3].y*sinf(m_fAngle));

	Rotatepos[0].y = (posOrigin[0].x*sinf(m_fAngle)) + (posOrigin[0].y*cosf(m_fAngle));
	Rotatepos[1].y = (posOrigin[1].x*sinf(m_fAngle)) + (posOrigin[1].y*cosf(m_fAngle));
	Rotatepos[2].y = (posOrigin[2].x*sinf(m_fAngle)) + (posOrigin[2].y*cosf(m_fAngle));
	Rotatepos[3].y = (posOrigin[3].x*sinf(m_fAngle)) + (posOrigin[3].y*cosf(m_fAngle));

	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(m_pos.x + Rotatepos[0].x, m_pos.y + Rotatepos[0].y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + Rotatepos[1].x, m_pos.y + Rotatepos[1].y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x + Rotatepos[2].x, m_pos.y + Rotatepos[2].y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + Rotatepos[3].x, m_pos.y + Rotatepos[3].y, 0.0f);

	m_pVtxBuff->Unlock();


}
//------------------------------------------------------------
//サイズの設定
//------------------------------------------------------------
void CPolygon::SetScale(D3DXVECTOR3 scale)
{
	m_Scale = scale;
	D3DXVECTOR3 posOrigin[4];
	D3DXVECTOR3 Rotatepos[4];

	//スケールサイズ込みの４頂点
	posOrigin[0].x = -m_Scale.x;
	posOrigin[1].x = m_Scale.x;
	posOrigin[2].x = -m_Scale.x;
	posOrigin[3].x = m_Scale.x;
	posOrigin[0].y = -m_Scale.y;
	posOrigin[1].y = -m_Scale.y;
	posOrigin[2].y = m_Scale.y;
	posOrigin[3].y = m_Scale.y;
	//回転の計算
	Rotatepos[0].x = (posOrigin[0].x*cosf(m_fAngle)) - (posOrigin[0].y*sinf(m_fAngle));
	Rotatepos[1].x = (posOrigin[1].x*cosf(m_fAngle)) - (posOrigin[1].y*sinf(m_fAngle));
	Rotatepos[2].x = (posOrigin[2].x*cosf(m_fAngle)) - (posOrigin[2].y*sinf(m_fAngle));
	Rotatepos[3].x = (posOrigin[3].x*cosf(m_fAngle)) - (posOrigin[3].y*sinf(m_fAngle));

	Rotatepos[0].y = (posOrigin[0].x*sinf(m_fAngle)) + (posOrigin[0].y*cosf(m_fAngle));
	Rotatepos[1].y = (posOrigin[1].x*sinf(m_fAngle)) + (posOrigin[1].y*cosf(m_fAngle));
	Rotatepos[2].y = (posOrigin[2].x*sinf(m_fAngle)) + (posOrigin[2].y*cosf(m_fAngle));
	Rotatepos[3].y = (posOrigin[3].x*sinf(m_fAngle)) + (posOrigin[3].y*cosf(m_fAngle));


	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(m_pos.x + Rotatepos[0].x, m_pos.y + Rotatepos[0].y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(m_pos.x + Rotatepos[1].x, m_pos.y + Rotatepos[1].y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(m_pos.x + Rotatepos[2].x, m_pos.y + Rotatepos[2].y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(m_pos.x + Rotatepos[3].x, m_pos.y + Rotatepos[3].y, 0.0f);

	m_pVtxBuff->Unlock();

}
//=============================================================================
//色の設定
//=============================================================================
void CPolygon::SetCol(D3DXCOLOR col)
{
	m_col = col;
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	m_pVtxBuff->Unlock();

}
//=============================================================================
//初期化
//=============================================================================
HRESULT CPolygon::Init()
{
	CScene2D::BindTexture(m_Tex);
	CScene2D::Init();
	CScene2D::SetPos(m_pos, m_Scale);
	CScene2D::SetCol(m_col);
	return S_OK;
}
//=============================================================================
//終了
//=============================================================================
void CPolygon::Uninit()
{
	CScene2D::Uninit();
}

//=============================================================================
//更新
//=============================================================================
void CPolygon::Update()
{
	CScene2D::Update();
}

//=============================================================================
//描画
//=============================================================================
void CPolygon::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ
	if (m_bDraw == true)
	{
		CScene2D::Draw();
	}
}

//=============================================================================
//クリエイト
//=============================================================================
CPolygon *CPolygon::Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, CTexture::Type texture, D3DXCOLOR col, int nPriority)
{
	//インスタンス生成
	CPolygon *pPolygon = new CPolygon((CScene::OBJTYPE)nPriority);

	pPolygon->m_pos = pos;
	pPolygon->m_Scale = scale;
	pPolygon->m_Tex = texture;
	pPolygon->m_col = col;

	if (pPolygon != NULL)
	{
		pPolygon->Init();
	}

	return pPolygon;
}