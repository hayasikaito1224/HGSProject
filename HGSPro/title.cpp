//--------------------------------------
//マネージャーの処理
//--------------------------------------
#include "title.h"
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "fade.h"
#include "Polygon.h"
#include "sound.h"
//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CTitle::CTitle()
{
	m_pBg = nullptr;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CTitle::~CTitle()
{

}

//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CTitle::Init(void)
{
	m_pBg = CBg::Create(CTexture::Title);	// タイトルロゴ
	m_bNextMode = false;

	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CTitle::Uninit(void)
{
	CManager::GetSound()->StopSound(CSound::SOUND_LABEL_BGM_TITLE);
	if (m_pBg)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}
}
//--------------------------------------------
//更新
//--------------------------------------------
void CTitle::Update(void)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();

	if (!m_bNextMode&&pKey->GetTrigger(DIK_SPACE))
	{
		m_bNextMode = true;
		// メニューシーンへ行く
		CFade::SetFade(CManager::MODE_GAME);
	}
}
//--------------------------------------------
//描画
//--------------------------------------------
void CTitle::Draw(void)
{

}

