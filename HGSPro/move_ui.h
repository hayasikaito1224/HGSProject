//=============================================================================
//
// 動きが付くUI処理 [move_ui.h]
// Author : 林海斗
//
//=============================================================================
#ifndef _MOVE_UI_H_
#define _MOVE_UI_H_

//*****************************************************************************
// ヘッダファイルのインクルード
//*****************************************************************************
#include "main.h"
#include "scene.h"
#include "texture.h"
//*****************************************************************************
// 前方宣言
//*****************************************************************************
class CPolygon;
class CTexture;
//*****************************************************************************
// クラス定義
//*****************************************************************************
class CMove_UI : public CScene
{
public:
	enum class UI_Type
	{
		Type_Start = 0,
		Type_Target,//目的
		Type_Finish,
		Type_PushStart,
		Type_Commendation,//勝ちか負けのUIの時
		Type_ResultPlayerPop,
		Type_Max
	};

	enum class State
	{
		ImmediatelyAfterPop = 0,//出現直後
		Normal,
		End,
		StateMax
	};

	CMove_UI(OBJTYPE nPriority = OBJTYPE_POLYGON);	// デフォルトコンストラクタ
	~CMove_UI();	// デフォルトデストラクタ
	HRESULT Init(void);	// ポリゴンの初期化
	void Uninit(void);	// ポリゴンの終了
	void Update(void);	// ポリゴンの更新
	void Draw(void);	// ポリゴンの描画
	void FadeIn(void);//画像のフェードイン
	void FadeOut(void);//画像のフェードアウト
	void FadeInOut(void);
	void Flash(void);
	void Move(void);
	void Pop(void);
	void SetState(CMove_UI::State state) { m_state = state; }
	// 生成(位置、サイズ、出現持続時間、フェードインアウトの時間)
	static CMove_UI *Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale,
		int nPopTime, int nFadeTime, CTexture::Type Tex, UI_Type type);
	D3DXVECTOR3 GetPos(void) { return m_pos; }	// ゲッダー
	D3DXVECTOR3 GetRot(void) { return m_rot; }	// ゲッダー
	void SetCol(D3DXCOLOR col); 
private:
	void SizeUp(void);//ちょっとした動きの処理
	void Start(void);//スタートUIの処理
	void LastSpurt(void);//lastspurtUIの処理
	void Finisj(void);//フィニッシュUIの処理
	void PushStart(void);//フィニッシュUIの処理
	CPolygon *m_pUI;
	State m_state;//状態
	UI_Type m_Type; //UIの種類
	D3DXVECTOR3 m_pos;	// 位置
	D3DXVECTOR3 m_origin_pos;	// 位置
	D3DXVECTOR3 m_rot;	// 向き
	D3DXVECTOR3 m_scale;	// スケール
	D3DXVECTOR3 m_origin_scale;	// スケール
	D3DXVECTOR3 m_next_scale;	// スケール
	D3DXVECTOR3 m_addspeed;	// スケール
	int m_nTimer;
	int m_nMaxPopTime;//出現時間
	int m_nMaxFadeTime;//フェードインアウトの時間
	float m_fFadeSpeed;
	bool m_bUninit;
	bool m_bFadeState;
	bool m_bFlash;
};

#endif