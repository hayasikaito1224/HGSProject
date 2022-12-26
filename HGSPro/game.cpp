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
#include "sound.h"

//静的メンバ変数宣言
CBg		*CGame::m_pBg = nullptr;
CPlayer *CGame::m_pPlayer = nullptr;
CTimer *CGame::m_pTimer = nullptr;
//定数定義
static const int MaxGameTime = 10;//制限時間
static const float MaxFallDown = 90.0f;
static const D3DXVECTOR3 TimerPos = { SCREEN_WIDTH / 2.0f - 40.0f,100.0f,0.0f };
static const D3DXVECTOR3 TargetUIPos = { SCREEN_WIDTH / 2.0f,300.0f,0.0f };
static const D3DXVECTOR3 StartUIPos = { SCREEN_WIDTH / 2.0f,SCREEN_HEIGHT/2.0f ,0.0f };
static const D3DXVECTOR3 TargetUISize = { 500.0f,100.0f,0.0f };
static const D3DXVECTOR3 StartUISize = { 500.0f,100.0f,0.0f };
static const D3DXVECTOR3 WinUIPos01 = { 300.0f,100.0f,0.0f };
static const D3DXVECTOR3 WinUIPos02 = { 1000.0f,100.0f,0.0f };
static const D3DXVECTOR3 LoseUIPos01 = { 300.0f,100.0f,0.0f };
static const D3DXVECTOR3 LoseUIPos02 = { 1000.0f,100.0f,0.0f };
static const D3DXVECTOR3 WinUISize = { 150.0f,80.0f,0.0f };
static const D3DXVECTOR3 LoseUISize = { 150.0f,80.0f,0.0f };

static const int StartUIPop = 80;
static const int TimerPop = 120;
static const int FinishUIPop = 120 + (60* MaxGameTime);
static const int ResultPop = 120 + (60 * MaxGameTime)+60;
static const int CntLeaveMax = 30;
static const int DispositionMax = 50;

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
	m_pPushSpace = nullptr;
	m_pTower = nullptr;
	m_pTitleLogo = nullptr;
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
	m_pDanger[0] = nullptr;
	m_pDanger[1] = nullptr;

	m_bEnd_FallDownR = false;
	m_bSettlement = false;
	m_State = CGame::STATE::START;
	if (!m_pBg)
	{
		m_pBg = CBg::Create(CTexture::Type::BG);
		m_pBg->SetCol({ 1.0,1.0,0.3f,1.0 });
	}
	if (!m_pBg02)
	{
		m_pBg02 = CBg::Create(CTexture::Type::FADE, CScene::OBJTYPE::OBJTYPE_UI);
		m_pBg02->SetCol({ 1.0,1.0,1.0,0.5f });
	}
	if (!m_pTimer)
	{
		m_pTimer = CTimer::Create(TimerPos, { 1.0,1.0,1.0,1.0 }, CTimer::STATE::SUB, MaxGameTime, false);
	}

	if (!m_pTutorial)
	{
		m_pTutorial = CPolygon::Create({ SCREEN_WIDTH / 2.0f,450.0f,0.0 }, { 400.0f,250.0f,0.0f }, CTexture::Type::Rule, { 1.0,1.0,1.0,1.0 }, CScene::OBJTYPE::OBJTYPE_FADE);
	}
	if (!m_pTitleLogo)
	{
		m_pTitleLogo = CPolygon::Create({ SCREEN_WIDTH / 2.0f,100.0f,0.0f }, { 300.0f,100.0f,0.0 }, CTexture::Type::TitleLogo, { 1.0,1.0,1.0,1.0 }, CScene::OBJTYPE::OBJTYPE_FADE);
	}
	if (!m_pDanger[0])
	{
		m_pDanger[0] = CPolygon::Create({ 350,350.0f,0.0 }, { 50.0f,50.0f,0.0f }, CTexture::Type::Denger, { 1.0,1.0,1.0,1.0 }, CScene::OBJTYPE::OBJTYPE_PLAYER);

	}
	if (!m_pDanger[1])
	{
		m_pDanger[1] = CPolygon::Create({ 940,350.0f,0.0 }, { 50.0f,50.0f,0.0f }, CTexture::Type::Denger, { 1.0,1.0,1.0,1.0 }, CScene::OBJTYPE::OBJTYPE_PLAYER);

	}

	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		m_pDanger[nCnt]->SetDraw(false);
	}


	if (!m_pPlayer)
	{
		m_pPlayer = CPlayer::Create();
	}
	if (!m_pTower)
	{
		m_pTower = CPolygon::Create({ SCREEN_WIDTH / 2.0f,600.0f,0.0f }, { 200.0f,300.0f,0.0f }, CTexture::Type::TOWER);
	}
	return S_OK;
}
//--------------------------------------------
//終了
//--------------------------------------------
void CGame::Uninit(void)
{
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (!m_pDanger[nCnt])
		{
			m_pDanger[nCnt]->Uninit();
			m_pDanger[nCnt] = nullptr;
		}

	}
	if (m_pTitleLogo)
	{
		m_pTitleLogo->Uninit();
		m_pTitleLogo = nullptr;
	}
	if (m_pPushSpace)
	{
		m_pPushSpace->Uninit();
		m_pPushSpace = nullptr;
	}
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
			CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_ENTER);	// タイトルサウンド

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
			if (m_pTitleLogo)
			{
				m_pTitleLogo->Uninit();
				m_pTitleLogo = nullptr;
			}
			if (!m_pTargetUI)
			{
				m_pTargetUI = CMove_UI::Create(TargetUIPos, TargetUISize, 20, 10, CTexture::Type::Target, CMove_UI::UI_Type::Type_Target);
			}
		}
		break;
	case CGame::STATE::NORMAL:

		if (m_pTower)
		{
			//カウンターの差分
			nDifference01 = m_pPlayer->GetPushCnt()[0] - m_pPlayer->GetPushCnt()[1];
			nDifference02 = m_pPlayer->GetPushCnt()[1] - m_pPlayer->GetPushCnt()[0];
			if (nDifference01 >= CntLeaveMax)
			{
				m_pDanger[1]->SetDraw(true);

			}
			else
			{
				m_pDanger[1]->SetDraw(false);

			}
			if (nDifference02 >= CntLeaveMax)
			{
				m_pDanger[0]->SetDraw(true);

			}
			else
			{
				m_pDanger[0]->SetDraw(false);

			}
			if (nDifference01 >= DispositionMax)
			{
				m_State = CGame::STATE::END;
				m_bEnd_FallDownR = true;
				CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_CRASH01);	// タイトルサウンド

				if (!m_pFinishUI)
				{
					m_pFinishUI = CMove_UI::Create(StartUIPos, {500.0f,100.0f,0.0f}, 30, 10, CTexture::Type::EndUI, CMove_UI::UI_Type::Type_Start);
					CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_GAMEFINISH);	// タイトルサウンド

				}
				m_bResult = true;
				m_pPlayer->SetPlay(false);

			}
			if (nDifference02 >= DispositionMax)
			{
				m_State = CGame::STATE::END;
				m_bEnd_FallDownR = false;
				CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_CRASH01);	// タイトルサウンド

				if (!m_pFinishUI)
				{
					m_pFinishUI = CMove_UI::Create(StartUIPos, { 500.0f,100.0f,0.0f }, 30, 10, CTexture::Type::EndUI, CMove_UI::UI_Type::Type_Start);
					CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_GAMEFINISH);	// タイトルサウンド

				}
				m_bResult = true;
				m_pPlayer->SetPlay(false);

			}
			m_pTower->SetAngle(D3DXToRadian(nDifference01));
		}
		m_nUITimer++;
		if (m_nUITimer >= StartUIPop)
		{
			if (!m_pStartUI)
			{
				m_pStartUI = CMove_UI::Create(StartUIPos, StartUISize, 10, 10, CTexture::Type::Start, CMove_UI::UI_Type::Type_Start);
				
				CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_GAMESTART);	// タイトルサウンド

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
				m_pFinishUI = CMove_UI::Create(StartUIPos, { 500.0f,100.0f,0.0f }, 30, 10, CTexture::Type::EndUI, CMove_UI::UI_Type::Type_Start);
				CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_GAMEFINISH);	// タイトルサウンド

			}

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
		m_pTimer->SetCanCount(false);

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
				float Angle = m_pTower->GetAngle();
				Angle+=0.05f;
				m_pTower->SetAngle(Angle);
				if (Angle >=D3DXToRadian(MaxFallDown) )
				{
					m_State = CGame::STATE::RESULT;
					CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_CRASH02);	// タイトルサウンド

				}
			}
		}
		else
		{
			if (m_pTower)
			{
				//カウンターの差分
				float Angle = m_pTower->GetAngle();
				Angle-=0.05f;
				m_pTower->SetAngle(Angle);
				float fd = D3DXToRadian(-MaxFallDown);
				if (Angle <= fd)
				{
					CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_CRASH02);	// タイトルサウンド

					m_State = CGame::STATE::RESULT;
				}

			}
		}
		break;
	case CGame::STATE::RESULT:
		if (!m_pPushSpace)
		{
			m_pPushSpace = CPolygon::Create({ SCREEN_WIDTH / 2.0f,550.0f,0.0f }, { 300.0f,50.0f,0.0f }, CTexture::PushSpace);
		}
		//カウンターの差分
		nDifference01 = m_pPlayer->GetPushCnt()[0] - m_pPlayer->GetPushCnt()[1];
		nDifference02 = m_pPlayer->GetPushCnt()[1] - m_pPlayer->GetPushCnt()[0];
		//１Pのほうが多かったら
		if (nDifference01 > nDifference02)
		{
			if (!m_pWinUI)
			{
				CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_RESULT);	// タイトルサウンド

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
				CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_RESULT);	// タイトルサウンド

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
				CManager::GetSound()->PlaySound(CManager::GetSound()->SOUND_LABEL_SE_ENTER);	// タイトルサウンド

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
	for (int nCnt = 0; nCnt < 2; nCnt++)
	{
		if (!m_pDanger[nCnt])
		{
			m_pDanger[nCnt]->Uninit();
			m_pDanger[nCnt] = nullptr;
		}

	}
	if (m_pTitleLogo)
	{
		m_pTitleLogo->Uninit();
		m_pTitleLogo = nullptr;
	}
	if (m_pPushSpace)
	{
		m_pPushSpace->Uninit();
		m_pPushSpace = nullptr;
	}

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


