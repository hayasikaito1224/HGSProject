//=============================================-
//プレイヤーのクラス
//=============================================
#ifndef _PLAYER_H_
#define _PLAYER_H_
#define MAX_ASSISTCRYSTAL (2)
#define MAX_HEAL_LEVEL (5)
class CEnemy;
class CSword;
class CGuard;
class CMissile;
class CAssistCrystal;
class CAssistCrystal_Model;

class CPlayer : public CScene
{
public:

	CPlayer(OBJTYPE nPriority = CScene::OBJTYPE_NONE);
	~CPlayer();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
	static CPlayer *Create();
private:

};

#endif // !_PLAYER_H_

