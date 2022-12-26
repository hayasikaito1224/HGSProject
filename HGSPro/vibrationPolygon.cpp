//=============================================================================
//
// Polygon処理
//
//=============================================================================
#include "vibrationPolygon.h"
#include "manager.h"
#include "Renderer.h"
#include "scene2D.h"

//=============================================================================
//コンストラクタ
//=============================================================================
CVibrationPolygon::CVibrationPolygon(OBJTYPE nPriority) : CScene2D(nPriority)
{
	m_bDraw = true;

	// フレームカウント
	m_framecount = 0;

	// 振動幅
	m_vibesWidth = 0.0f;
	// 振動スピード
	m_vibesSpeed = 0.0f;
	// 切り替え
	m_bSwitch = false;

	// 振動させるか
	m_bVibration = true;
}

//=============================================================================
//デストラクタ
//=============================================================================
CVibrationPolygon::~CVibrationPolygon()
{

}
//------------------------------------------------------------
//頂点座標の設定
//------------------------------------------------------------

void CVibrationPolygon::SetPos(D3DXVECTOR3 pos)
{
	CScene::SetPos(pos);
	m_pos = pos;
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//バッファの生成
	pVtx[0].pos = D3DXVECTOR3(pos.x - m_Scale.x, pos.y - m_Scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + m_Scale.x, pos.y - m_Scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - m_Scale.x, pos.y + m_Scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + m_Scale.x, pos.y + m_Scale.y, 0.0f);

	m_pVtxBuff->Unlock();

}
//=============================================================================
//色の設定
//=============================================================================
void CVibrationPolygon::SetCol(D3DXCOLOR col)
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
// 振動幅を設定
//=============================================================================
void CVibrationPolygon::SetVibesWidth(float vibration)
{
	m_vibesWidth = vibration;
}

//=============================================================================
// 振動スピードを設定	(値が小さいほど、スピードが速い)
//=============================================================================
void CVibrationPolygon::SetVibseFrame(float vibration)
{
	m_vibesSpeed = vibration;
}

//=============================================================================
// 振動させるか設定		true → 振動ON	false → 振動OFF
//=============================================================================
void CVibrationPolygon::SetVibration(bool vibration)
{
	m_bVibration = vibration;
}

//=============================================================================
//初期化
//=============================================================================
HRESULT CVibrationPolygon::Init()
{
	CScene2D::BindTexture(m_Tex);
	CScene2D::Init();
	CScene2D::SetPos(m_pos, m_Scale);
	CScene2D::SetCol(m_col);

	// 幅
	m_vibesWidth = 100.0f;
	// スピード(小さいほど速い)
	m_vibesSpeed = 1.0f;

	return S_OK;
}

//=============================================================================
//終了
//=============================================================================
void CVibrationPolygon::Uninit()
{
	CScene2D::Uninit();
}

//=============================================================================
//更新
//=============================================================================
void CVibrationPolygon::Update()
{
	if (m_bVibration)
	{
		// フレームカウント
		m_framecount++;

		// 位置を取得
		D3DXVECTOR3 myPos = CScene2D::GetPos();
		// サイズを取得
		D3DXVECTOR3 mySize = CScene2D::GetScale();

		// m_move.x = sinf(m_framecount * (D3DX_PI / m_vibesSpeed)) * m_vibesWidth/**/;

		// フレーム数で切り替え
		if (m_framecount >= m_vibesSpeed)
		{
			m_bSwitch = !m_bSwitch;
			m_framecount = 0;
		}

		// 揺らす
		if (m_bSwitch)
		{
			myPos.x -= (m_vibesWidth / m_vibesSpeed);
		}
		else
		{
			myPos.x += (m_vibesWidth / m_vibesSpeed);
		}

		// 位置を設定
		CScene2D::SetPos(D3DXVECTOR3(myPos.x, myPos.y, myPos.z), mySize);
	}

	CScene2D::Update();
}

//=============================================================================
//描画
//=============================================================================
void CVibrationPolygon::Draw()
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
CVibrationPolygon *CVibrationPolygon::Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, CTexture::Type texture, D3DXCOLOR col, int nPriority)
{
	//インスタンス生成
	CVibrationPolygon *pPolygon = new CVibrationPolygon((CScene::OBJTYPE)nPriority);

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