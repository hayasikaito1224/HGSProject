//--------------------------------------
//���U���g��ʂ̏���
//--------------------------------------
#include "result.h"
#include "bg.h"
#include "texture.h"
#include "manager.h"
#include "keyboard.h"
#include "fade.h"
#include "Polygon.h"
#include "sound.h"

CBg *CResult::m_pBg = NULL;

//--------------------------------------------
//�R���X�g���N�^
//--------------------------------------------
CResult::CResult()
{
	m_bNextMode = false;
}
//--------------------------------------------
//�f�X�g���N�^
//--------------------------------------------
CResult::~CResult()
{
}
//--------------------------------------------
//������
//--------------------------------------------
HRESULT CResult::Init(void)
{
	m_bNextMode = false;
	m_pBg = CBg::Create(CTexture::None, CScene::OBJTYPE_BG, false);	//�w�i

	return S_OK;
}
//--------------------------------------------
//�I��
//--------------------------------------------

void CResult::Uninit(void)
{
	if (m_pBg != NULL)
	{
		m_pBg->Uninit();
		m_pBg = NULL;
	}
}
//--------------------------------------------
//�X�V
//--------------------------------------------
void CResult::Update(void)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();

	if (!m_bNextMode&&pKey->GetTrigger(DIK_SPACE))
	{
		m_bNextMode = true;
		// ���j���[�V�[���֍s��
		CFade::SetFade(CManager::MODE_TITLE);
	}
}
//--------------------------------------------
//�`��
//--------------------------------------------

void CResult::Draw(void)
{

}

