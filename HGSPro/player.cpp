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
#include "vibrationPolygon.h"

static const int CntLeaveMax_1 = 100;
static const int CntLeaveMax_2 = 200;
static const int VibTimeMax = 30;
static const float VibFrame = 2.0f;
static const float VibWidth = 5.0f;

static const D3DXVECTOR3 Player01Pos = { 200.0f,500.0f,0.0f };
static const D3DXVECTOR3 Player02Pos = { 700.0f,500.0f,0.0f };
static const D3DXVECTOR3 PlayerSize = { 100.0f,60.0f,0.0f };

CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	m_State = CPlayer::STATE::NORMAL;
	m_pPolygon = nullptr;
	m_bPlay = false;
	for (int nCnt = 0; nCnt < NumPlayer; nCnt++)
	{
		m_nVibTime[nCnt] = 0;
		m_pPlayer[nCnt] = nullptr;
		m_nPushCounter[nCnt] = 0;

	}
}

CPlayer::~CPlayer()
{
}
//=============================================================================
//初期化
//=============================================================================
HRESULT CPlayer::Init()
{

	if (!m_pPlayer[0])
	{
		m_pPlayer[0] = CVibrationPolygon::Create(Player01Pos, PlayerSize, CTexture::Type::PLAYER01);
		m_pPlayer[0]->SetVibesWidth(VibWidth);
		m_pPlayer[0]->SetVibseFrame(VibFrame);
		m_pPlayer[0]->SetVibration(false);


	}
	if (!m_pPlayer[1])
	{
		m_pPlayer[1] = CVibrationPolygon::Create(Player02Pos, PlayerSize, CTexture::Type::PLAYER02);
		m_pPlayer[1]->SetVibesWidth(VibWidth);
		m_pPlayer[1]->SetVibseFrame(VibFrame);
		m_pPlayer[1]->SetVibration(false);


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
	for (int nCnt = 0; nCnt < NumPlayer; nCnt++)
	{
		m_pPlayer[nCnt]->Uninit();
		m_pPlayer[nCnt] = nullptr;
	}
}

//=============================================================================
//更新
//=============================================================================
void CPlayer::Update()
{

	if (m_bPlay)
	{
		PushTrigger(DIK_A, 0);
		PushTrigger(DIK_D, 0);
		PushTrigger(DIK_SEMICOLON, 1);
		PushTrigger(DIK_RBRACKET, 1);

	}
	else
	{
		for (int nCnt = 0; nCnt < NumPlayer; nCnt++)
		{
			m_pPlayer[nCnt]->SetVibration(false);
		}
	}
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
	int nDifference01 = m_nPushCounter[0] - m_nPushCounter[1];
	int nDifference02 = m_nPushCounter[1] - m_nPushCounter[0];

	nNum += sprintf(&str[nNum], " [PushCnt{player1}] %d\n", m_nPushCounter[0]);
	nNum += sprintf(&str[nNum], " [PushCnt{player2}] %d\n", m_nPushCounter[1]);
	nNum += sprintf(&str[nNum], " [Difference{player1}] %d\n", nDifference01);
	nNum += sprintf(&str[nNum], " [Difference{player2}] %d\n", nDifference02);

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
		m_nVibTime[nPlayer] = VibTimeMax;
	}
	else
	{
		m_nVibTime[nPlayer]--;
		if (m_nVibTime[nPlayer] <= 0)
		{
			m_nVibTime[nPlayer] = 0;
		}
	}
	if (m_nVibTime[nPlayer] > 0)
	{
		m_pPlayer[nPlayer]->SetVibration(true);
	}
	else
	{
		m_pPlayer[nPlayer]->SetVibration(false);
	}
}
//=============================================================================
//プレイヤーの押下数の差し引き
//=============================================================================
void CPlayer::PushCntDeduction()
{
	//プレイヤー1の差
	int nDifference01 = m_nPushCounter[0] - m_nPushCounter[1];
	int nDifference02 = m_nPushCounter[1] - m_nPushCounter[0];

	switch (nDifference01)
	{
	case CntLeaveMax_1:
		//塔のテクスチャアニメーションを優勢一段階目にする
		break;
	case CntLeaveMax_2:
		//塔のテクスチャアニメーションを優勢二段階目にする
		break;
	}
	switch (nDifference02)
	{
	case CntLeaveMax_1:
		//塔のテクスチャアニメーションを優勢一段階目にする
		break;
	case CntLeaveMax_2:
		//塔のテクスチャアニメーションを優勢二段階目にする
		break;
	}
}
