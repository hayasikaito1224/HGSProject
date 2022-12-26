//========================================
// 時間を表示/数える処理
// Author:林
//========================================
#ifndef _TIMER_H_
#define _TIMER_H_
#include "scene.h"
#define SECONDNUMBERS_MAX (2)
class CPolygon;
class C2DNumber;

class CTimer : public CScene
{
public:
	enum class STATE
	{
		ADD = 0,//加算
		SUB,//減算
		MAX
	};
	//------------------------------------
	// コンストラクタ、デストラクタ
	//------------------------------------
	CTimer(OBJTYPE nPriority = CScene::OBJTYPE_TIME);
	~CTimer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void TimeNumbers();
	void TimeCount();
	int GetSecond() { return m_nSecondCnt; }
	void AddMinute(int nMinute);
	void SetCanCount(bool bCan) { m_bCanCount = bCan; }
	static CTimer *Create(const D3DXVECTOR3 pos, const D3DXCOLOR col,const STATE state,const int MaxTime = 0, const bool& CanCount = true);
private:
	C2DNumber *m_pSecond[SECONDNUMBERS_MAX];//秒
	CPolygon *pPolygon[SECONDNUMBERS_MAX];
	D3DXVECTOR3 m_pos;
	D3DXCOLOR m_col;
	STATE m_State;
	int m_nSecondCnt;//秒数を数えるやつ
	int m_nCommaCnt;//こんまを数えるやつ
	bool m_bUninit;
	bool m_bCanCount;
};
#endif _TIMER_H_