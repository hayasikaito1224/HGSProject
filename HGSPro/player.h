//=============================================================================
//
// プレイヤー処理
//
//=============================================================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "scene.h"

class CPolygon;

class CPlayer : public CScene
{
public:

	static const int NumPlayer = 2;

	enum class STATE
	{
		NORMAL = 0,
		PLAYER_1_PREDOMINANT1,//プレイヤー1優勢１段階
		PLAYER_1_PREDOMINANT2,//プレイヤー1優勢２段階
		PLAYER_2_PREDOMINANT1,//プレイヤー2優勢１段階
		PLAYER_2_PREDOMINANT2,//プレイヤー2優勢２段階

	};

	CPlayer(OBJTYPE nPriority = OBJTYPE_POLYGON);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CPlayer *Create();
	void DebugTextDraw();
	void PushTrigger(int nKey,int nPlayer);
	void PushCntDeduction();//プレイヤーの押下数の差し引き
	int *GetPushCnt() { return m_nPushCounter; }
	void SetPlay(bool bPlay) { m_bPlay = bPlay; }
private:
	int m_nPushCounter[NumPlayer];
	bool m_bPlay;
	CPolygon *m_pPolygon;
	STATE m_State;
};



#endif