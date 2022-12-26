//=============================================================================
//
// �v���C���[����
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
		PLAYER_1_PREDOMINANT1,//�v���C���[1�D���P�i�K
		PLAYER_1_PREDOMINANT2,//�v���C���[1�D���Q�i�K
		PLAYER_2_PREDOMINANT1,//�v���C���[2�D���P�i�K
		PLAYER_2_PREDOMINANT2,//�v���C���[2�D���Q�i�K

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
	void PushCntDeduction();//�v���C���[�̉������̍�������
	int *GetPushCnt() { return m_nPushCounter; }
	void SetPlay(bool bPlay) { m_bPlay = bPlay; }
private:
	int m_nPushCounter[NumPlayer];
	bool m_bPlay;
	CPolygon *m_pPolygon;
	STATE m_State;
};



#endif