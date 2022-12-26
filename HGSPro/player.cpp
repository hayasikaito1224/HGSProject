//=============================================================================
//
// プレイヤー処理
//
//=============================================================================
#include "player.h"
#include "Polygon.h"
#include "keyboard.h"
#include "Renderer.h"
#include "manager.h"

CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pPolygon = nullptr;
}

CPlayer::~CPlayer()
{
}
//=============================================================================
//初期化
//=============================================================================
HRESULT CPlayer::Init()
{
	if (!m_pPolygon)
	{
		m_pPolygon = CPolygon::Create({ SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f,0.0 }, { 100.0f,100.0f,0.0 }, CTexture::Type::Test, {1.0,1.0,1.0,1.0},CScene::OBJTYPE_PLAYER);
	}
	return S_OK;
}

//=============================================================================
//終了
//=============================================================================
void CPlayer::Uninit()
{
	if (m_pPolygon)
	{
		m_pPolygon->Uninit();
		m_pPolygon = nullptr;
	}
}

//=============================================================================
//更新
//=============================================================================
void CPlayer::Update()
{
	PushTrigger(DIK_A, 0);
	PushTrigger(DIK_D, 0);
	PushTrigger(DIK_SEMICOLON, 1);
	PushTrigger(DIK_RBRACKET, 1);

}

//=============================================================================
//描画
//=============================================================================
void CPlayer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//デバイスのポインタ
	DebugTextDraw();
}
//=============================================================================
//描画
//=============================================================================
void CPlayer::DebugTextDraw()
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[3000];
	int nNum = 0;

	nNum = sprintf(&str[0], "\n\n 情報 \n");

	nNum += sprintf(&str[nNum], " [PushCnt{player1}] %d\n", m_nPushCounter[0]);
	nNum += sprintf(&str[nNum], " [PushCnt{player2}] %d\n", m_nPushCounter[1]);

	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// テキスト描画
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}
//=============================================================================
//インスタンス生成処理
//=============================================================================
CPlayer *CPlayer::Create()
{
	CPlayer *pPlayer = new CPlayer();
	if (pPlayer)
	{
		pPlayer->Init();
	}
	return pPlayer;
}
//=============================================================================
//連打する処理
//=============================================================================
void CPlayer::PushTrigger(int nKey, int nPlayer)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();

	//特定のキーを押すとカウントが増加
	if(pKey->GetTrigger(nKey))
	{
		m_nPushCounter[nPlayer]++;
	}
}
