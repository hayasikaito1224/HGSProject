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
#include "timer.h"
#include "Polygon.h"
#include "move_ui.h"

//静的メンバ変数宣言
CBg		*CGame::m_pBg = nullptr;
CPlayer *CGame::m_pPlayer = nullptr;
CTimer *CGame::m_pTimer = nullptr;
//定数定義
static const int MaxGameTime = 30;//制限時間
static const float MaxFallDown = 90.0f;
static const D3DXVECTOR3 TimerPos = { SCREEN_WIDTH / 2.0f,100.0f,0.0f };
static const D3DXVECTOR3 TargetUIPos = { SCREEN_WIDTH / 2.0f,300.0f,0.0f };
static const D3DXVECTOR3 StartUIPos = { SCREEN_WIDTH / 2.0f,SCREEN_HEIGHT/2.0f ,0.0f };
static const D3DXVECTOR3 TargetUISize = { 500.0f,100.0f,0.0f };
static const D3DXVECTOR3 StartUISize = { 300.0f,100.0f,0.0f };
static const D3DXVECTOR3 WinUIPos01 = { 200.0f,100.0f,0.0f };
static const D3DXVECTOR3 WinUIPos02 = { 800.0f,100.0f,0.0f };
static const D3DXVECTOR3 LoseUIPos01 = { 200.0f,100.0f,0.0f };
static const D3DXVECTOR3 LoseUIPos02 = { 800.0f,100.0f,0.0f };
static const D3DXVECTOR3 WinUISize = { 100.0f,80.0f,0.0f };
static const D3DXVECTOR3 LoseUISize = { 100.0f,80.0f,0.0f };

static const int StartUIPop = 80;
static const int TimerPop = 120;
static const int FinishUIPop = 120 + (60* MaxGameTime);
static const int ResultPop = 120 + (60 * MaxGameTime)+60;

//--------------------------------------------
//コンストラクタ
//--------------------------------------------
CGame::CGame()
{
	m_bStartTimer = false;
	m_bNextMode = false;
	m_pBg = nullptr;
	m_pPlayer = nullptr;
	m_pTimer = nullptr;
	m_pTargetUI = nullptr;
	m_pLoseUI = nullptr;
	m_pFinishUI = nullptr;
	m_pTutorial = nullptr;
	m_pBg02 = nullptr;
	m_pTower = nullptr;
	m_bResult = false;
	m_nUITimer = 0;
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
	m_State = CGame::STATE::START;
	if (!m_pTutorial)
	{
		m_pTutorial = CPolygon::Create({ SCREEN_WIDTH / 2.0f,400.0f,0.0 }, { 200.0f,250.0f,0.0f }, CTexture::Test, { 1.0,1.0,1.0,1.0 }, CScene::OBJTYPE::OBJTYPE_FADE);
	}

	if (!m_pBg02)
	{
		m_pBg02 = CBg::Create(CTexture::Type::FADE,CScene::OBJTYPE::OBJTYPE_FADE);
		m_pBg02->SetCol({ 1.0,1.0,1.0,0.5f });
	}


	if (!m_pTimer)
	{
		m_pTimer = CTimer::Create(TimerPos, { 1.0,1.0,1.0,1.0 }, CTimer::STATE::SUB, MaxGameTime, false);
	}
	if (!m_pPlayer)
	{
		m_pPlayer = CPlayer::Create();
	}
	if (!m_pTower)
	{
		m_pTower = CPolygon::Create({ SCREEN_WIDTH / 2.0f,600.0f,0.0f }, { 120.0f,200.0f,0.0f }, CTexture::Type::TOWER);
	}
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CGame::Uninit(void)
{
	if (m_pTower)
	{
		m_pTower->Uninit();
		m_pTower = nullptr;
	}
	if (m_pTutorial)
	{
		m_pTutorial->Uninit();
		m_pTutorial = nullptr;
	}
	if (m_pBg02)
	{
		m_pBg02->Uninit();
		m_pBg02 = nullptr;
	}
	if (m_pBg)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}
	if (m_pTimer)
	{
		m_pTimer->Uninit();
		m_pTimer = nullptr;
	}
	if (m_pPlayer)
	{
		m_pPlayer->Uninit();
		m_pPlayer = nullptr;
	}
	if (m_pTargetUI)
	{
		m_pTargetUI->Uninit();
		m_pTargetUI = nullptr;
	}
	if (m_pLoseUI)
	{
		m_pLoseUI->Uninit();
		m_pLoseUI = nullptr;
	}
	if (m_pWinUI)
	{
		m_pWinUI->Uninit();
		m_pWinUI = nullptr;
	}
	if (m_pFinishUI)
	{
		m_pFinishUI->Uninit();
		m_pFinishUI = nullptr;
	}
	if (m_pStartUI)
	{
		m_pStartUI->Uninit();
		m_pStartUI = nullptr;
	}
}
//--------------------------------------------
//更新
//--------------------------------------------
void CGame::Update(void)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();
	int nDifference01 =0;
	int nDifference02 =0;

	switch (m_State)
	{
	case CGame::STATE::START:
		if (pKey->GetTrigger(DIK_SPACE))
		{
			m_State = CGame::STATE::NORMAL;
			if (m_pTutorial)
			{
				m_pTutorial->Uninit();
				m_pTutorial = nullptr;
			}
			if (m_pBg02)
			{
				m_pBg02->Uninit();
				m_pBg02 = nullptr;
			}
			if (!m_pTargetUI)
			{
				m_pTargetUI = CMove_UI::Create(TargetUIPos, TargetUISize, 20, 10, CTexture::Type::Test, CMove_UI::UI_Type::Type_Target);
			}
		}
		break;
	case CGame::STATE::NORMAL:

		if (m_pTower)
		{
			//カウンターの差分
			int nDifference01 = m_pPlayer->GetPushCnt()[0] - m_pPlayer->GetPushCnt()[1];

			m_pTower->SetAngle(D3DXToRadian(nDifference01));
		}
		m_nUITimer++;
		if (m_nUITimer >= StartUIPop)
		{
			if (!m_pStartUI)
			{
				m_pStartUI = CMove_UI::Create(StartUIPos, StartUISize, 10, 10, CTexture::Type::Test, CMove_UI::UI_Type::Type_Start);
			}
		}
		if (m_nUITimer >= TimerPop && !m_bStartTimer)
		{
			m_pPlayer->SetPlay(true);
			m_bStartTimer = true;
			m_pTimer->SetCanCount(true);
		}
		//時間切れ
		if (m_nUITimer >= FinishUIPop)
		{

			if (!m_pFinishUI)
			{
				m_pFinishUI = CMove_UI::Create(StartUIPos, StartUISize, 30, 10, CTexture::Type::Test, CMove_UI::UI_Type::Type_Start);
			}
			m_pTimer->SetCanCount(false);

		}
		//勝敗のUIの表示
		if (m_nUITimer >= ResultPop && !m_bResult)
		{
			m_State = CGame::STATE::END;
			m_bResult = true;
			m_pPlayer->SetPlay(false);
		}


		break;
	case CGame::STATE::END:
		//カウンターの差分
		nDifference01 = m_pPlayer->GetPushCnt()[0] - m_pPlayer->GetPushCnt()[1];
		nDifference02 = m_pPlayer->GetPushCnt()[1] - m_pPlayer->GetPushCnt()[0];
		//１Pのほうが多かったら
		if (nDifference01 > nDifference02)
		{
			m_bEnd_FallDownR = true;
		}
		else if (nDifference01 < nDifference02)
		{
			m_bEnd_FallDownR = false;
		}
		if (m_bEnd_FallDownR)
		{
			if (m_pTower)
			{
				//カウンターの差分
				int Angle = m_pTower->GetAngle();
				Angle++;
				m_pTower->SetAngle(D3DXToRadian(Angle));
				if (Angle >= MaxFallDown)
				{
					m_State = CGame::STATE::END;
				}
			}
		}
		else
		{
			if (m_pTower)
			{
				//カウンターの差分
				int Angle = m_pTower->GetAngle();
				Angle--;
				m_pTower->SetAngle(D3DXToRadian(Angle));
				if (Angle <= -MaxFallDown)
				{
					m_State = CGame::STATE::END;
				}

			}
		}
		break;
	case CGame::STATE::RESULT:
		//カウンターの差分
		nDifference01 = m_pPlayer->GetPushCnt()[0] - m_pPlayer->GetPushCnt()[1];
		nDifference02 = m_pPlayer->GetPushCnt()[1] - m_pPlayer->GetPushCnt()[0];
		//１Pのほうが多かったら
		if (nDifference01 > nDifference02)
		{
			if (!m_pWinUI)
			{
				m_pWinUI = CMove_UI::Create(WinUIPos01, WinUISize, 0, 10, CTexture::WIN, CMove_UI::UI_Type::Type_Commendation);
			}
			if (!m_pLoseUI)
			{
				m_pLoseUI = CMove_UI::Create(LoseUIPos02, LoseUISize, 0, 10, CTexture::LOSE, CMove_UI::UI_Type::Type_Commendation);
			}
		}
		else if (nDifference01 < nDifference02)
		{
			if (!m_pWinUI)
			{
				m_pWinUI = CMove_UI::Create(WinUIPos02, WinUISize, 0, 10, CTexture::WIN, CMove_UI::UI_Type::Type_Commendation);
			}
			if (!m_pLoseUI)
			{
				m_pLoseUI = CMove_UI::Create(LoseUIPos01, LoseUISize, 0, 10, CTexture::LOSE, CMove_UI::UI_Type::Type_Commendation);
			}
		}

		//勝負の結果が表示されてたら
		if (m_bResult)
		{
			if (pKey->GetTrigger(DIK_SPACE))
			{
				Reset();

			}
		}

		break;
	}



}

//--------------------------------------------
//描画
//--------------------------------------------
void CGame::Draw()
{
}

void CGame::Reset()
{
	m_nUITimer = 0;
	m_bStartTimer = false;
	m_bResult = false;
	if (m_pTower)
	{
		m_pTower->Uninit();
		m_pTower = nullptr;
	}
	if (m_pBg)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}
	if (m_pTimer)
	{
		m_pTimer->Uninit();
		m_pTimer = nullptr;
	}
	if (m_pPlayer)
	{
		m_pPlayer->Uninit();
		m_pPlayer = nullptr;
	}
	if (m_pTargetUI)
	{
		m_pTargetUI = nullptr;
	}
	if (m_pLoseUI)
	{
		m_pLoseUI->Uninit();
		m_pLoseUI = nullptr;
	}
	if (m_pWinUI)
	{
		m_pWinUI->Uninit();
		m_pWinUI = nullptr;
	}
	if (m_pFinishUI)
	{
		m_pFinishUI = nullptr;
	}
	if (m_pStartUI)
	{
		m_pStartUI = nullptr;
	}
	if (m_pTutorial)
	{
		m_pTutorial->Uninit();
		m_pTutorial = nullptr;
	}
	if (m_pBg02)
	{
		m_pBg02->Uninit();
		m_pBg02 = nullptr;
	}
	CScene::Delete();
	Init();
}


