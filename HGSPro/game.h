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

class CGame
{
public:
	CGame();
	~CGame();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	//static CPlayer *GetPlayer() { return m_Player; }
private:
	static CBg			*m_pBg;
	bool m_bNextMode;

};


#endif //_RESULT_H