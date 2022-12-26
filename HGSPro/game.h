//--------------------------------------
//タイトルの処理
//--------------------------------------
#ifndef _GAME_H
#define _GAME_H
#include "main.h"
#include "scene.h"

//前方宣言
class CBg;
class CPlayer;
class CField;
class CPolygon;
class CTimer;
class CMove_UI;

class CGame
{
public:
	CGame();
	~CGame();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	void SetSettlement(bool bSettlement) { m_bSettlement = bSettlement; }
	void Reset();

	//static CPlayer *GetPlayer() { return m_Player; }
private:
	static CBg			*m_pBg;
	static CPlayer *m_pPlayer;
	static CTimer *m_pTimer;
	CMove_UI *m_pTargetUI;
	CMove_UI *m_pStartUI;
	CMove_UI *m_pFinishUI;
	CMove_UI *m_pWinUI;
	CMove_UI *m_pLoseUI;

	bool m_bNextMode;
	bool m_bSettlement;//勝負の決着がついたか
	bool m_bStartTimer;
	bool m_bResult;
	int m_nUITimer;

};


#endif //_RESULT_H