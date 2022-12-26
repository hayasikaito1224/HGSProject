//--------------------------------------
//�}�l�[�W���[�̏���
//--------------------------------------
#include "title.h"
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "fade.h"
#include "Polygon.h"
#include "sound.h"
//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CTitle::CTitle()
{
	m_pBg = nullptr;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CTitle::~CTitle()
{

}

//--------------------------------------------
//������
//--------------------------------------------
HRESULT CTitle::Init(void)
{
	m_pBg = CBg::Create(CTexture::Title);	// �^�C�g�����S
	m_bNextMode = false;

	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------
void CTitle::Uninit(void)
{
	CManager::GetSound()->StopSound(CSound::SOUND_LABEL_BGM_TITLE);
	if (m_pBg)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CTitle::Update(void)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();

	if (!m_bNextMode&&pKey->GetTrigger(DIK_SPACE))
	{
		m_bNextMode = true;
		// ���j���[�V�[���֍s��
		CFade::SetFade(CManager::MODE_GAME);
	}
}
//--------------------------------------------
//�`��
//--------------------------------------------
void CTitle::Draw(void)
{

}

