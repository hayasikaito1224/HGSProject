//-------------------
//背景の処理
//---------------------------------------------------
#include "timer.h"
#include "manager.h"
#include "Renderer.h"
#include "scene2D.h"
#include "2Dnumber.h"
#include <math.h>
#include "Polygon.h"
static const int MaxTime = 20;
static const D3DXVECTOR3 Scale = { 20.0f,30.0f,0.0 };
//--------------------------
//コンストラクト
//----------------------------
CTimer::CTimer(OBJTYPE nPriority) :CScene(nPriority)
{
	m_nCommaCnt = 0;
	m_nSecondCnt = 0;
	m_bCanCount = true;
	memset(m_pSecond, NULL, sizeof(m_pSecond));
	memset(pPolygon, NULL, sizeof(pPolygon));

}

//--------------------------
//デストラクト
//----------------------------
CTimer::~CTimer()
{

}

//--------------------------
//初期化
//----------------------------
HRESULT CTimer::Init()
{
	//秒を生成
	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		//ナンバーの桁数分生成
		m_pSecond[nCnt] = C2DNumber::Create(D3DXVECTOR3(((Scale.x * 2)* nCnt) + m_pos.x, m_pos.y, 0.0f), Scale);
		m_pSecond[nCnt]->SetCol(m_col);

	}
	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		//ナンバーの桁数分生成
		pPolygon[nCnt] = CPolygon::Create({ m_pos.x - (Scale.x + 8.0f), m_pos.y + (-10.0f + (20.0f*nCnt)), 0.0f }, { 5.0f,5.0f,0.0f }, CTexture::None);
		pPolygon[nCnt]->SetCol({ 0.0f,0.0f,0.0f,1.0 });

	}
	//スコアの数値を更新し続ける
	TimeNumbers();

	return S_OK;

}

//--------------------------
//終了
//----------------------------
void CTimer::Uninit()
{
	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		if (m_pSecond[nCnt])
		{
			m_pSecond[nCnt]->Uninit();
			m_pSecond[nCnt] = nullptr;
		}

	}
	Release();
}

//--------------------------
//更新
//----------------------------
void CTimer::Update()
{
	if (m_bCanCount)
	{
		TimeCount();
	}
	TimeNumbers();
	if (m_bUninit)
	{
		Uninit();
	}

}

//--------------------------
//描画
//----------------------------
void CTimer::Draw()
{

	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		if (m_pSecond[nCnt] != NULL)
		{
			m_pSecond[nCnt]->Draw();
		}
	}

}
void CTimer::TimeNumbers()
{
	int nSecondPoly[SECONDNUMBERS_MAX];

	for (int nCnt = 0; nCnt < SECONDNUMBERS_MAX; nCnt++)
	{
		if (m_pSecond[nCnt] != NULL)
		{
			//10の累乗の計算
			int Number = pow(10.0, (SECONDNUMBERS_MAX - (nCnt)));
			int Number2 = pow(10.0, (SECONDNUMBERS_MAX - (nCnt + 1)));
			if (Number2 <= 0)
			{
				Number2 = 1;
			}
			nSecondPoly[nCnt] = m_nSecondCnt % Number / Number2;
			m_pSecond[nCnt]->SetNumber(nSecondPoly[nCnt]);
		}
	}

}
void CTimer::TimeCount()
{
	m_nCommaCnt++;
	if (m_nCommaCnt >= 60)
	{
		m_nCommaCnt = 0;
		switch (m_State)
		{
		case CTimer::STATE::ADD:
			m_nSecondCnt++;
			break;
		case CTimer::STATE::SUB:
			m_nSecondCnt--;
			break;
		}
	}

}

//---------------------------------------------------------------
//インスタンス生成処理
//---------------------------------------------------------------
CTimer *CTimer::Create(const D3DXVECTOR3 pos, const D3DXCOLOR col, const STATE state, const int MaxTime, const bool& CanCount)
{
	//インスタンス生成
	CTimer *pSmallScore = new CTimer(OBJTYPE_TIME);
	if (pSmallScore != NULL)
	{
		pSmallScore->m_pos = pos;
		pSmallScore->m_col = col;
		pSmallScore->m_bCanCount = CanCount;
		pSmallScore->m_State = state;
		pSmallScore->m_nSecondCnt = MaxTime;
		pSmallScore->Init();
	}

	return pSmallScore;
}
