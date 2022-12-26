//=============================================================================
//
// �e�N�X�`������ [texture.cpp]
// Author : �H�������
//
//=============================================================================
//=============================================================================
// �C���N���[�h
//=============================================================================
#include "texture.h"
#include "Renderer.h"
#include "manager.h"

//=============================================================================
// �f�t�H���g�R���X�g���N�^
//=============================================================================
CTexture::CTexture()
{

}

//=============================================================================
// �f�t�H���g�f�X�g���N�^
//=============================================================================
CTexture::~CTexture()
{

}

//=============================================================================
// �e�N�X�`���̐���
//=============================================================================
void CTexture::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�̃|�C���^
	pDevice = CManager::GetRenderer()->GetDevice();	//�f�o�C�X���擾����

	m_pTexture[None] = nullptr;

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/text_texture.png",//���e�N�X�`��
		&m_pTexture[Test]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/number000.png",//����
		&m_pTexture[TIME]);
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/fade.png",//����
		&m_pTexture[FADE]);

	//============================================================
	//�^�C�g��
	//============================================================
	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data/TEXTURE/Title000.png",//�^�C�g���w�i
		&m_pTexture[Title]);

}

//=============================================================================
// �I��
//=============================================================================
void CTexture::Uniinit(void)
{
	for (int nCntTexture = 0; nCntTexture < Max; nCntTexture++)
	{
		//�e�N�X�`���̔j��
		if (m_pTexture[nCntTexture] != NULL)
		{
			m_pTexture[nCntTexture]->Release();
			m_pTexture[nCntTexture] = NULL;
		}
	}
}