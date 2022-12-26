//=============================================================================
//
// テクスチャ処理 [texture.cpp]
// Author : 羽鳥太一作
//
//=============================================================================
//=============================================================================
// インクルード
//=============================================================================
#include "texture.h"
#include "Renderer.h"
#include "manager.h"

//=============================================================================
// デフォルトコンストラクタ
//=============================================================================
CTexture::CTexture()
{

}

//=============================================================================
// デフォルトデストラクタ
//=============================================================================
CTexture::~CTexture()
{

}

//=============================================================================
// テクスチャの生成
//=============================================================================
void CTexture::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice; //デバイスのポインタ
	pDevice = CManager::GetRenderer()->GetDevice();	//デバイスを取得する

	m_pTexture[None] = nullptr;

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/text_texture.png",//仮テクスチャ
		&m_pTexture[Test]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/number000.png",//数字
		&m_pTexture[TIME]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/fade.png",//数字
		&m_pTexture[FADE]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/fade.png",//数字
		&m_pTexture[WIN]);
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/fade.png",//数字
		&m_pTexture[LOSE]);

	//============================================================
	//タイトル
	//============================================================
	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Title000.png",//タイトル背景
		&m_pTexture[Title]);

}

//=============================================================================
// 終了
//=============================================================================
void CTexture::Uniinit(void)
{
	for (int nCntTexture = 0; nCntTexture < Max; nCntTexture++)
	{
		//テクスチャの破棄
		if (m_pTexture[nCntTexture] != NULL)
		{
			m_pTexture[nCntTexture]->Release();
			m_pTexture[nCntTexture] = NULL;
		}
	}
}