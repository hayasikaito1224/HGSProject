//=============================================================================
//
// ÉvÉåÉCÉÑÅ[èàóù
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

	CPlayer(OBJTYPE nPriority = OBJTYPE_POLYGON);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CPlayer *Create();
	void DebugTextDraw();
	void PushTrigger(int nKey,int nPlayer);

private:
	int m_nPushCounter[NumPlayer];
	CPolygon *m_pPolygon;
};



#endif