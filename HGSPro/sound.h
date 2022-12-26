//�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{
// �T�E���h���� [sound.h]
// Author : �ъC�l
//�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{�{
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//===========================================================
// �T�E���h�N���X
//===========================================================
class CSound
{
public:
	CSound();
	~CSound();

	//=================================
	// �T�E���h�t�@�C��
	//=================================
	typedef enum
	{
		//--------------------------
		// �a�f�l
		//--------------------------
		SOUND_LABEL_BGM_TITLE = 0,			// �^�C�g����BGM
		SOUND_LABEL_BGM_GAME,				// �Q�[����BGM

		//--------------------------
		// �r�d
		//--------------------------
		SOUND_LABEL_SE_ENTER,				// ���艹
		SOUND_LABEL_SE_CLICK,				// �v���C���[�A�ŉ�

		SOUND_LABEL_SE_GAMESTART,			// �Q�[���J�n��
		SOUND_LABEL_SE_GAMEFINISH,			// �Q�[���I����
		SOUND_LABEL_SE_RESULT,				// ���ʔ��\��

		SOUND_LABEL_SE_CRASH01,				// �|��(�|�ꒆ)
		SOUND_LABEL_SE_CRASH02,				// �|��(�Y�h��)

		SOUND_LABEL_MAX

	} SOUND_LABEL;

	//=============================================================================
	// �v���g�^�C�v�錾
	//=============================================================================
	HRESULT InitSound(void);
	void UninitSound(void);
	HRESULT PlaySound(SOUND_LABEL label);
	void StopSound(SOUND_LABEL label);
	void StopSound(void);
	void ControllVoice(SOUND_LABEL label, float fVolume) { m_apSourceVoice[label]->SetVolume(fVolume); }

private:
	//=============================================================================
	// �p�����[�^�\���̒�`
	//=============================================================================
	typedef struct
	{
		char *filename;		// �t�@�C����
		int nCntLoop;		// ���[�v�J�E���g
	} PARAM;

	// �e���f�ނ̃p�����[�^
	static PARAM m_aParam[SOUND_LABEL_MAX];

	//=============================================================================
	// �v���g�^�C�v�錾
	//=============================================================================
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

	//=============================================================================
	// �O���[�o���ϐ�
	//=============================================================================
	IXAudio2 *m_pXAudio2 = NULL;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice = NULL;			// �}�X�^�[�{�C�X
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// �\�[�X�{�C�X
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^�T�C�Y

};
#endif
