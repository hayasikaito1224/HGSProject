//--------------------------------------
//マネージャーの処理
//--------------------------------------
#include "manager.h"
#include "Renderer.h"
#include "scene.h"
#include "scene2D.h"
#include "keyboard.h"
#include "texture.h"
#include "player.h"
#include "title.h"
#include "game.h"
#include "result.h"
#include "fade.h"
#include "sound.h"

#include <random>
//静的メンバ変数宣言
CInputKeyBoard	*CManager::m_pInputKeyboard = NULL;
CRenderer		*CManager::m_pRenderer = NULL;
CTexture		*CManager::m_pTexture = NULL;
CPlayer			*CManager::m_pPlayer = NULL;
CGame			*CManager::m_pGame = NULL;
CTitle			*CManager::m_pTitle = NULL;
CResult			*CManager::m_pResult = NULL;
CFade			*CManager::m_Fade = NULL;
CManager::MODE	 CManager::m_Mode = MODE_GAME;		// 初期モード
CSound			*CManager::m_pSound = NULL;
HWND	CManager::m_hWnd = 0;
float	CManager::m_fTimer = 0.0f;
int	CManager::m_nGameTimeMinut = 0;
int	CManager::m_nGameTimeSecond = 0;
bool			CManager::m_bPause = false;
bool			CManager::m_bStop = false;
bool			CManager::m_bEnd = false;
bool			CManager::m_bClear = true;

int g_nTimer = 0;

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CManager::CManager()
{
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CManager::~CManager()
{
}
//--------------------------------------------
// 初期化
//--------------------------------------------
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
	//ウィンドウハンドルの保存
	m_hWnd = hWnd;
	// レンダラーの生成
	if (m_pRenderer == NULL)
	{
		m_pRenderer = new CRenderer;
	}

	// テクスチャの生成
	if (m_pTexture == NULL)
	{
		//インスタンス生成
		m_pTexture = new CTexture;
	}

	// レンダラーの初期化
	if (m_pRenderer != NULL)
	{
		if (FAILED(m_pRenderer->Init(hInstance, hWnd, bWindow)))
		{
			return-1;
		}

		// テクスチャの読み込み
		m_pTexture->Init();
	}
	// サウンドの生成
	if (m_pSound == NULL)
	{
		m_pSound = new CSound;
		m_pSound->InitSound();
	}

	//フェードの生成
	if (m_Fade == NULL)
	{
		m_Fade = CFade::Create(CTexture::Test, m_Mode);

		SetMode(m_Mode);

		//モードの設定
	}

	// キーボードの生成
	if (m_pInputKeyboard == NULL)
	{
		m_pInputKeyboard = new CInputKeyBoard;
		if (m_pInputKeyboard != NULL)
		{
			m_pInputKeyboard->Init(hInstance, hWnd);
		}
	}

	return S_OK;
}
//--------------------------------------------
// 終了
//--------------------------------------------
void CManager::Uninit(void)
{
	//キーボードの破棄
	if (m_pInputKeyboard != NULL)
	{
		m_pInputKeyboard->Uninit();
		delete m_pInputKeyboard;
		m_pInputKeyboard = NULL;
	}

	// シーンの破棄
	CScene::Delete();

	// テクスチャの破棄
	if (m_pTexture != NULL)
	{
		m_pTexture->Uniinit();
		m_pTexture = NULL;
	}
	// フェードの破棄
	if (m_Fade != NULL)
	{
		m_Fade->Uninit();
		m_Fade = NULL;
	}

	// レンダラーの破棄
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = NULL;
	}

	// サウンドの破棄
	if (m_pSound != NULL)
	{
		m_pSound->UninitSound();
		delete m_pSound;
		m_pSound = NULL;
	}
}
//--------------------------------------------
// 更新
//--------------------------------------------
void CManager::Update(void)
{
	// レンダラーの更新
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Update();
	}

	//キーボードの更新
	if (m_pInputKeyboard != NULL)
	{
		m_pInputKeyboard->Update();
	}

	// モード毎の更新
	switch (m_Mode)
	{
	case MODE_TITLE:		//タイトル画面
		if (m_pTitle != NULL)
		{
			m_pTitle->Update();
		}
		break;

	case MODE_GAME:			//ゲーム画面
		if (m_pGame != NULL)
		{
			
			m_pGame->Update();
		}
		break;

	case MODE_RESULT:		//リザルト画面
		if (m_pResult != NULL)
		{
			m_pResult->Update();
		}
		break;
	}
}
//--------------------------------------------
// 描画
//--------------------------------------------
void CManager::Draw(void)
{

	// レンダラーの描画
	if (m_pRenderer != NULL)
	{
		m_pRenderer->Draw();
	}

}

//-----------------------------------------------------------------------------
// Renderer取得処理
//-----------------------------------------------------------------------------
CRenderer *CManager::GetRenderer(void)
{
	return m_pRenderer;
}

//-----------------------------------------------------------------------------
// キーボードのインスタンス取得処理
//-----------------------------------------------------------------------------
CInputKeyBoard *CManager::GetInputKeyboard(void)
{
	return m_pInputKeyboard;
}

//-----------------------------------------------------------------------------
// テクスチャのインスタンス取得処理
//-----------------------------------------------------------------------------
CTexture *CManager::GetTexture(void)
{
	return m_pTexture;
}

//-----------------------------------------------------------------------------
// モードの処理
//-----------------------------------------------------------------------------
CManager::MODE CManager::GetMode(void)
{
	return m_Mode;
}

//-----------------------------------------------------------------------------
// モードの処理
//-----------------------------------------------------------------------------
void CManager::SetMode(MODE mode)
{
	m_bEnd = false;
	m_bStop = false;
	m_bPause = false;
	switch (m_Mode)
	{
	case MODE_TITLE:		//タイトル画面
		if (m_pTitle != NULL)
		{
			//m_pSound->StopSound(m_pSound->SOUND_LABEL_BGM_TITLE);
			m_pTitle->Uninit();
			m_pTitle = NULL;
		}
		break;
	case MODE_GAME:			//ゲーム画面
		if (m_pGame != NULL)
		{
			//m_pSound->StopSound(m_pSound->SOUND_LABEL_BGM_GAME);
			m_pGame->Uninit();
			m_pGame = NULL;

		}
		break;

	case MODE_RESULT:		//リザルト画面
		if (m_pResult != NULL)
		{
			//m_pSound->StopSound(m_pSound->SOUND_LABEL_SE_WIN);
			m_pResult->Uninit();
			m_pResult = NULL;
		}
		break;
	}

	//現在選択しているモードの削除+そのモードで生成したオブジェクトの削除
	CScene::Delete();

	//次に移行するモードの生成
	switch (mode)
	{
	case MODE_TITLE:		//タイトル画面
		if (m_pTitle == NULL)
		{

			m_bClear = false;
			m_nGameTimeSecond = 0;
			m_nGameTimeMinut = 0;
			m_pTitle = new CTitle;
			m_pTitle->Init();
			//m_pSound->PlaySound(m_pSound->SOUND_LABEL_BGM_TITLE);	// タイトルサウンド
			//m_pSound->ControllVoice(m_pSound->SOUND_LABEL_BGM_TITLE,0.1f);	// タイトルサウンド

		}
		break;

	case MODE_GAME:			//ゲーム画面
		if (m_pGame == NULL)
		{
			m_pGame = new CGame;
			m_pGame->Init();
			m_pSound->PlaySound(m_pSound->SOUND_LABEL_BGM_GAME);	// タイトルサウンド
			m_pSound->ControllVoice(m_pSound->SOUND_LABEL_BGM_GAME, 0.3f);
		}
		break;
	case MODE_RESULT:		//リザルト画面
		if (m_pResult == NULL)
		{
			m_pResult = new CResult;
			m_pResult->Init();
			//m_pSound->PlaySound(m_pSound->SOUND_LABEL_SE_WIN);	// リザルトサウンド
			//m_pSound->ControllVoice(m_pSound->SOUND_LABEL_SE_WIN,0.1f);	// タイトルサウンド

		}
		break;
	}
	//次のモードを現在のモードに上書き
	m_Mode = mode;
}