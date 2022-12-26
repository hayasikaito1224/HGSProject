//--------------------------------------
//�}�l�[�W���[�̏���
//--------------------------------------
#ifndef _MANAGER_H
#define _MANAGER_H
#include "main.h"

//�O���錾
class CInputKeyBoard;
class CRenderer;
class CTexture;
class CPlayer;
class CTitle;
class CGame;
class CFade;
class CResult;
class CSound;

static int ClearTime = 5;

class CManager
{
public:
	typedef enum
	{
		MODE_TITLE=0,			//�^�C�g�����
		MODE_GAME,				//�Q�[�����
		MODE_RESULT,			//���U���g���
		MODE_MAX
	}MODE;

	CManager();
	~CManager();
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, bool bWindow);
	void Uninit();
	void Update();
	void Draw();
	static CRenderer *GetRenderer();
	static CInputKeyBoard *GetInputKeyboard();
	static CTexture *GetTexture();
	static CFade *GetFade(){ return m_Fade; }
	static CGame *GetGame(){ return m_pGame; }
	static void SetMode(MODE mode);						//���[�h�̐ݒ�
	static MODE GetMode();
	static bool GetPause() { return m_bPause; }
	static void SetPause(bool bPause, bool bStop = false) {
		m_bPause = bPause;
		m_bStop = bStop;
	}
	static void SetGameStop(bool bStop) { m_bStop = bStop; }

	static void SetEnd(bool bEnd)							{ m_bEnd = bEnd;}
	static CSound *GetSound()							{ return m_pSound; }
	static bool GetClear()								{ return m_bClear; }
	static void SetClear(bool bClear)						{ m_bClear = bClear; }
	static HWND GethWnd() { return m_hWnd; }
	static int GetGameTimeMinut() { return m_nGameTimeMinut; }
	static int GetGameTimeSecond() { return m_nGameTimeSecond; }
	static void SetGameTimeMinut(int nTime) { m_nGameTimeMinut = nTime; }
	static void SetGameTimeSecond(int nTime) { m_nGameTimeSecond = nTime; }

private:
	static HWND m_hWnd;//���̃v���O�������g���Ă���E�B���h�E�̃n���h��
	static CRenderer		*m_pRenderer;
	static CInputKeyBoard	*m_pInputKeyboard;
	static CTexture			*m_pTexture;
	static bool				m_bStop;
	static bool				m_bPause;
	static bool				m_bEnd;
	static CPlayer			*m_pPlayer;
	static CTitle			*m_pTitle;
	static CGame			*m_pGame;
	static CResult			*m_pResult;
	static MODE				m_Mode;				//���݂̃��[�h
	static CFade			*m_Fade;
	static CSound			*m_pSound;
	static bool	m_bClear;					//�N���A�������̔���
	static float m_fTimer;
	static int m_nGameTimeMinut;//����
	static int m_nGameTimeSecond;//�b��


};


#endif //_MANAGER_H