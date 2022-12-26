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

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CGame::CGame()
{
	m_bNextMode = false;
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
	if (!m_pBg)
	{
		m_pBg = CBg::Create(CTexture::Type::TIME);
	}
	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CGame::Uninit(void)
{
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

