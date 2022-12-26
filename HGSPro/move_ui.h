//=============================================================================
//
// �������t��UI���� [move_ui.h]
// Author : �ъC�l
//
//=============================================================================
#ifndef _MOVE_UI_H_
#define _MOVE_UI_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "main.h"
#include "scene.h"
#include "texture.h"
//*****************************************************************************
// �O���錾
//*****************************************************************************
class CPolygon;
class CTexture;
//*****************************************************************************
// �N���X��`
//*****************************************************************************
class CMove_UI : public CScene
{
public:
	enum class UI_Type
	{
		Type_Start = 0,
		Type_Target,//�ړI
		Type_Finish,
		Type_PushStart,
		Type_Commendation,//������������UI�̎�
		Type_ResultPlayerPop,
		Type_Max
	};

	enum class State
	{
		ImmediatelyAfterPop = 0,//�o������
		Normal,
		End,
		StateMax
	};

	CMove_UI(OBJTYPE nPriority = OBJTYPE_POLYGON);	// �f�t�H���g�R���X�g���N�^
	~CMove_UI();	// �f�t�H���g�f�X�g���N�^
	HRESULT Init(void);	// �|���S���̏�����
	void Uninit(void);	// �|���S���̏I��
	void Update(void);	// �|���S���̍X�V
	void Draw(void);	// �|���S���̕`��
	void FadeIn(void);//�摜�̃t�F�[�h�C��
	void FadeOut(void);//�摜�̃t�F�[�h�A�E�g
	void FadeInOut(void);
	void Flash(void);
	void Move(void);
	void Pop(void);
	void SetState(CMove_UI::State state) { m_state = state; }
	// ����(�ʒu�A�T�C�Y�A�o���������ԁA�t�F�[�h�C���A�E�g�̎���)
	static CMove_UI *Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale,
		int nPopTime, int nFadeTime, CTexture::Type Tex, UI_Type type);
	D3DXVECTOR3 GetPos(void) { return m_pos; }	// �Q�b�_�[
	D3DXVECTOR3 GetRot(void) { return m_rot; }	// �Q�b�_�[
	void SetCol(D3DXCOLOR col); 
private:
	void SizeUp(void);//������Ƃ��������̏���
	void Start(void);//�X�^�[�gUI�̏���
	void LastSpurt(void);//lastspurtUI�̏���
	void Finisj(void);//�t�B�j�b�V��UI�̏���
	void PushStart(void);//�t�B�j�b�V��UI�̏���
	CPolygon *m_pUI;
	State m_state;//���
	UI_Type m_Type; //UI�̎��
	D3DXVECTOR3 m_pos;	// �ʒu
	D3DXVECTOR3 m_origin_pos;	// �ʒu
	D3DXVECTOR3 m_rot;	// ����
	D3DXVECTOR3 m_scale;	// �X�P�[��
	D3DXVECTOR3 m_origin_scale;	// �X�P�[��
	D3DXVECTOR3 m_next_scale;	// �X�P�[��
	D3DXVECTOR3 m_addspeed;	// �X�P�[��
	int m_nTimer;
	int m_nMaxPopTime;//�o������
	int m_nMaxFadeTime;//�t�F�[�h�C���A�E�g�̎���
	float m_fFadeSpeed;
	bool m_bUninit;
	bool m_bFadeState;
	bool m_bFlash;
};

#endif