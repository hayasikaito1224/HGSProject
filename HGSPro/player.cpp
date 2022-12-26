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
#include "sound.h"
static const int VibTimeMax = 30;
static const float VibFrame = 2.0f;
static const float VibWidth = 5.0f;

static const D3DXVECTOR3 ButtonPosA = { 250.0f,300.0f,0.0f };
static const D3DXVECTOR3 ButtonPosD = { 450.0f,300.0f,0.0f };
static const D3DXVECTOR3 ButtonPosL = { 850.0f,300.0f,0.0f };
static const D3DXVECTOR3 ButtonPosR = { 1050.0f,300.0f,0.0f };

static const D3DXVECTOR3 ButtonSizeA = { 70.0f,70.0f,0.0f };
static const D3DXVECTOR3 ButtonSizeD = { 70.0f,70.0f,0.0f };
static const D3DXVECTOR3 ButtonSizeL = { 70.0f,70.0f,0.0f };
static const D3DXVECTOR3 ButtonSizeR = { 70.0f,70.0f,0.0f };

static const D3DXVECTOR3 Player01Pos = { 490.0f,500.0f,0.0f };
static const D3DXVECTOR3 Player02Pos = { 810.0f,500.0f,0.0f };
static const D3DXVECTOR3 PlayerSize = { 100.0f,120.0f,0.0f };

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
	for (int nPut = 0; nPut < MaxPut; nPut++)
	{
		for (int nKey = 0; nKey  < MaxKey; nKey ++)
		{
			m_pKeyUI[nPut][nKey] = nullptr;
		}
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
	m_pKeyUI[0][0] = CPolygon::Create(ButtonPosA, ButtonSizeA, CTexture::ButtonA);
	m_pKeyUI[1][0] = CPolygon::Create(ButtonPosD, ButtonSizeD, CTexture::ButtonD);
	m_pKeyUI[2][0] = CPolygon::Create(ButtonPosL, ButtonSizeL, CTexture::ButtonL);
	m_pKeyUI[3][0] = CPolygon::Create(ButtonPosR, ButtonSizeR, CTexture::ButtonR);

	m_pKeyUI[0][1] = CPolygon::Create(ButtonPosA, ButtonSizeA, CTexture::ButtonA_Put);
	m_pKeyUI[1][1] = CPolygon::Create(ButtonPosD, ButtonSizeD, CTexture::ButtonD_Put);
	m_pKeyUI[2][1] = CPolygon::Create(ButtonPosL, ButtonSizeL, CTexture::ButtonL_Put);
	m_pKeyUI[3][1] = CPolygon::Create(ButtonPosR, ButtonSizeR, CTexture::ButtonR_Put);
	m_pKeyUI[0][1]->SetDraw(false);
	m_pKeyUI[1][1]->SetDraw(false);
	m_pKeyUI[2][1]->SetDraw(false);
	m_pKeyUI[3][1]->SetDraw(false);

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
	for (int nPut = 0; nPut < MaxPut; nPut++)
	{
		for (int nKey = 0; nKey < MaxKey; nKey++)
		{
			m_pKeyUI[nKey][nPut]->Uninit();
			m_pKeyUI[nKey][nPut] = nullptr;
		}
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
		PushTrigger(DIK_LEFT, 1);
		PushTrigger(DIK_RIGHT, 1);

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
		CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_CLICK);	// タイトルサウンド

		m_nPushCounter[nPlayer]++;
		m_nVibTime[nPlayer] = VibTimeMax;
		switch (nKey)
		{
		case DIK_A:
			m_pKeyUI[0][0]->SetDraw(false);
			m_pKeyUI[0][1]->SetDraw(true);

			break;
		case DIK_D:
			m_pKeyUI[1][0]->SetDraw(false);
			m_pKeyUI[1][1]->SetDraw(true);

			break;
		case DIK_LEFT:
			m_pKeyUI[2][0]->SetDraw(false);
			m_pKeyUI[2][1]->SetDraw(true);

			break;
		case DIK_RIGHT:
			m_pKeyUI[3][0]->SetDraw(false);
			m_pKeyUI[3][1]->SetDraw(true);

			break;
		}
	}
	else
	{
		switch (nKey)
		{
		case DIK_A:
			m_pKeyUI[0][0]->SetDraw(true);
			m_pKeyUI[0][1]->SetDraw(false);

			break;
		case DIK_D:
			m_pKeyUI[1][0]->SetDraw(true);
			m_pKeyUI[1][1]->SetDraw(false);

			break;
		case DIK_LEFT:
			m_pKeyUI[2][0]->SetDraw(true);
			m_pKeyUI[2][1]->SetDraw(false);

			break;
		case DIK_RIGHT:
			m_pKeyUI[3][0]->SetDraw(true);
			m_pKeyUI[3][1]->SetDraw(false);

			break;
		}
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



