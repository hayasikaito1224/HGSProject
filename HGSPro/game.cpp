//--------------------------------------
//ゲーム画面の処理
//--------------------------------------
#include "game.h"
#include "Renderer.h"//後で消す
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "player.h"
#include "fade.h"
#include "time.h"
#include "Polygon.h"

//静的メンバ変数宣言
CBg		*CGame::m_pBg = nullptr;
CPlayer *CGame::m_pPlayer = nullptr;
//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CGame::CGame()
{
	m_bNextMode = false;
	m_pBg = nullptr;
	m_pPlayer = nullptr;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CGame::~CGame()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CGame::Init(void)
{
	//if (!m_pBg)
	//{
	//	m_pBg = CBg::Create(CTexture::Type::TIME);
	//}
	if (!m_pPlayer)
	{
		m_pPlayer = CPlayer::Create();
	}
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CGame::Uninit(void)
{
	if (m_pBg)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}
	if (m_pPlayer)
	{
		m_pPlayer->Uninit();
		m_pPlayer = nullptr;
	}
}
//--------------------------------------------
//更新
//--------------------------------------------
void CGame::Update(void)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();

	if (!m_bNextMode&&pKey->GetTrigger(DIK_SPACE))
	{
		m_bNextMode = true;
		// メニューシーンへ行く
		CFade::SetFade(CManager::MODE_RESULT);
	}

}

//--------------------------------------------
//描画
//--------------------------------------------
void CGame::Draw()
{
}

