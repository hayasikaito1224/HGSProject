//=============================================================================
//
// �e�N�X�`������ [texture.h]
// Author : �H������
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CTexture
{
public:
	CTexture();	// �f�t�H���g�R���X�g���N�^
	~CTexture();// �f�t�H���g�f�X�g���N�^
	typedef enum
	{
		None = -1,		// �e�N�X�`������
		Test,			// ���e�N�X�`��
		BG,
		TIME,			// �^�C���i���o�[
		TimeSecond,
		TitleLogo,
		FADE,			
		Title,			//�^�C�g���w�i
		ButtonA,
		ButtonD,
		ButtonL,
		ButtonR,
		ButtonA_Put,
		ButtonD_Put,
		ButtonL_Put,
		ButtonR_Put,
		UI_1P,
		UI_2P,
		Rule,
		Target,
		Start,
		EndUI,
		TOWER,
		Denger,
		PushSpace,
		WIN,
		LOSE,
		PLAYER01,
		PLAYER02,
		Max,			// �e�N�X�`���̍ő吔
	} Type;

	void Init(void);	// �e�N�X�`���̐���
	LPDIRECT3DTEXTURE9 GetTexture(Type Type) { return m_pTexture[Type]; }	// �e�N�X�`���̊��蓖��(�e�N�X�`���̎��) { return �I�񂾃e�N�X�`����Ԃ� }
	void Uniinit(void);	// �I��

private:
	LPDIRECT3DTEXTURE9	m_pTexture[Max];	//�e�N�X�`��
};

#endif