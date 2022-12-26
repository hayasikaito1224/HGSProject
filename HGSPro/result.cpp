//--------------------------------------
//リザルト画面の処理
//--------------------------------------
#include "result.h"
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "fade.h"
#include "Polygon.h"
#include "sound.h"

CBg *CResult::m_pBg = NULL;

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CResult::CResult()
{
	m_bNextMode = false;
}
//--------------------------------------------
//デストラクタ
//--------------------------------------------
CResult::~CResult()
{
}
//--------------------------------------------
//初期化
//--------------------------------------------
HRESULT CResult::Init(void)
{
	m_bNextMode = false;
	m_pBg = CBg::Create(CTexture::None, CScene::OBJTYPE_BG, false);	//背景

	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------

void CResult::Uninit(void)
{
	if (m_pBg != NULL)
	{
		m_pBg->Uninit();
		m_pBg = NULL;
	}
}
//--------------------------------------------
//更新
//--------------------------------------------
void CResult::Update(void)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();

	if (!m_bNextMode&&pKey->GetTrigger(DIK_SPACE))
	{
		m_bNextMode = true;
		// メニューシーンへ行く
		CFade::SetFade(CManager::MODE_TITLE);
	}
}
//--------------------------------------------
//描画
//--------------------------------------------

void CResult::Draw(void)
{

}

