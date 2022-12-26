//--------------------------------------
//�Q�[����ʂ̏���
//--------------------------------------
#include "game.h"
#include "Renderer.h"//��ŏ���
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "player.h"
#include "fade.h"
#include "time.h"
#include "Polygon.h"

//�ÓI�����o�ϐ��錾
CBg		*CGame::m_pBg = nullptr;
CPlayer *CGame::m_pPlayer = nullptr;
//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CGame::CGame()
{
	m_bNextMode = false;
	m_pBg = nullptr;
	m_pPlayer = nullptr;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CGame::~CGame()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CGame::Init(void)
{
	//if (!m_pBg)
	//{
	//	m_pBg = CBg::Create(CTexture::Type::TIME);
	//}
	if (!m_pPlayer)
	{
		m_pPlayer = CPlayer::Create();
	}
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CGame::Uninit(void)
{
	if (m_pBg)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}
	if (m_pPlayer)
	{
		m_pPlayer->Uninit();
		m_pPlayer = nullptr;
	}
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CGame::Update(void)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();

	if (!m_bNextMode&&pKey->GetTrigger(DIK_SPACE))
	{
		m_bNextMode = true;
		// ���j���[�V�[���֍s��
		CFade::SetFade(CManager::MODE_RESULT);
	}

}

//--------------------------------------------
//�`��
//--------------------------------------------
void CGame::Draw()
{
}

