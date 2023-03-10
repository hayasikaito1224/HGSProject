//=============================================================================
//
// テクスチャ処理 [texture.h]
// Author : 羽鳥太一
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// クラス定義
//*****************************************************************************
class CTexture
{
public:
	CTexture();	// デフォルトコンストラクタ
	~CTexture();// デフォルトデストラクタ
	typedef enum
	{
		None = -1,		// テクスチャ無し
		Test,			// 仮テクスチャ
		BG,
		TIME,			// タイムナンバー
		TimeSecond,
		TitleLogo,
		FADE,			
		Title,			//タイトル背景
		ButtonA,
		ButtonD,
		ButtonL,
		ButtonR,
		ButtonA_Put,
		ButtonD_Put,
		ButtonL_Put,
		ButtonR_Put,
		UI_1P,
		UI_2P,
		Rule,
		Target,
		Start,
		EndUI,
		TOWER,
		Denger,
		PushSpace,
		WIN,
		LOSE,
		PLAYER01,
		PLAYER02,
		Max,			// テクスチャの最大数
	} Type;

	void Init(void);	// テクスチャの生成
	LPDIRECT3DTEXTURE9 GetTexture(Type Type) { return m_pTexture[Type]; }	// テクスチャの割り当て(テクスチャの種類) { return 選んだテクスチャを返す }
	void Uniinit(void);	// 終了

private:
	LPDIRECT3DTEXTURE9	m_pTexture[Max];	//テクスチャ
};

#endif