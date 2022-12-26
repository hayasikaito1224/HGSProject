//=============================================================================
//
// �������t��UI���� [move_ui.cpp]
// Author : �ъC�l
//
//=============================================================================
//=============================================================================
// �C���N���[�h
//=============================================================================
#include "Renderer.h"
#include "game.h"
#include "move_ui.h"
#include "player.h"
#include "manager.h"
#include "sound.h"
#include "Polygon.h"
static const int StartUIEndTime = 30;
static const int LastSpurtUIEndTime = 30;
static const int FinishUIEndTime = 30;
static const int FlashTimeMin = 2;
static const float LastSpurtMoveSpeed = 7.0f;
static const float FadeSpeed = 0.05f;
static const float TargetDifPosY = 40.0f;//�ړIUI�̏����ʒu
static const float TargetMoveSpeed = 1.0f;//�ړIUI�̈ړ����x
static const float SizeUpSpeed = 2.0f;//�ړIUI�̈ړ����x

//=============================================================================
// �f�t�H���g�R���X�g���N�^
//=============================================================================
CMove_UI::CMove_UI(OBJTYPE nPriority) : CScene(nPriority)
{
	m_bFadeState = false;
	m_origin_pos = { 0.0f,0.0f,0.0f };
	m_fFadeSpeed = 0.0f;
}

//=============================================================================
// �f�t�H���g�f�X�g���N�^
//=============================================================================
CMove_UI::~CMove_UI()
{

}

//=============================================================================
// ���f���̏���������
//=============================================================================
HRESULT CMove_UI::Init(void)
{
	m_bFlash = false;
	return S_OK;
}

//=============================================================================
// ���f���̏I������
//=============================================================================
void CMove_UI::Uninit(void)
{
	if (m_pUI)
	{
		m_pUI->Uninit();
		m_pUI = nullptr;
	}
	Release();
}

//=============================================================================
// ���f���̍X�V����
//=============================================================================
void CMove_UI::Update(void)
{
	switch (m_state)
	{
		//�����J�n��
	case CMove_UI::State::ImmediatelyAfterPop:
		switch (m_Type)
		{
		case CMove_UI::UI_Type::Type_Start:
			FadeIn();
			SizeUp();

			break;
		case CMove_UI::UI_Type::Type_Finish:
			break;
		case CMove_UI::UI_Type::Type_Commendation:
			FadeIn();
			Pop();
			break;
		case CMove_UI::UI_Type::Type_PushStart:
			m_state = CMove_UI::State::Normal;
			break;
		case CMove_UI::UI_Type::Type_Target:
			Move();
			FadeIn();

			break;
		}

		break;
		//�ʏ���
	case CMove_UI::State::Normal:
		m_nTimer++;

		switch (m_Type)
		{
		case CMove_UI::UI_Type::Type_Start:
			if (m_nTimer >= m_nMaxPopTime)
			{
				m_nTimer = 0;
				m_state = CMove_UI::State::End;
			}
			break;
		case CMove_UI::UI_Type::Type_Finish:
			break;

		case CMove_UI::UI_Type::Type_PushStart:
			FadeInOut();

			break;
		case CMove_UI::UI_Type::Type_Target:
			if (m_nTimer >= m_nMaxPopTime)
			{
				m_nTimer = 0;
				m_state = CMove_UI::State::End;
			}
			break;
		}

		break;
		//�I�����
	case CMove_UI::State::End:
		m_nTimer++;

		switch (m_Type)
		{
		case CMove_UI::UI_Type::Type_Start:
			FadeOut();

			break;
		case CMove_UI::UI_Type::Type_Finish:
			break;

		case CMove_UI::UI_Type::Type_PushStart:
			Flash();
			break;
		case CMove_UI::UI_Type::Type_Target:
			FadeOut();

			break;
		}

		break;
	}
	//�I���t���O�������Ă�����
	if (m_bUninit)
	{
		// �T�E���h�Đ�
		switch (m_Type)
		{
		case CMove_UI::UI_Type::Type_Start:
			break;

		case CMove_UI::UI_Type::Type_Finish:
			break;

		case CMove_UI::UI_Type::Type_PushStart:
			break;
		}

		Uninit();
	}
}

//=============================================================================
// ���f���̕`�揈��
//=============================================================================
void CMove_UI::Draw(void)
{
}
void CMove_UI::SetCol(D3DXCOLOR col)
{
	if (m_pUI)
	{ 
		m_pUI->SetCol(col);
	}
}
//=============================================================================
// ������Ƃ��������̏���
//=============================================================================
void CMove_UI::SizeUp(void)
{
	//�傫��������������
	m_scale.x += m_addspeed.x;
	m_scale.y += m_addspeed.y;
	//�傫�������̑傫�����炢�܂ŏ������Ȃ����瓮������߂�
	if (m_origin_scale.x <= m_scale.x&&
		m_origin_scale.y <= m_scale.y)
	{
		m_scale = m_origin_scale;
		m_state = CMove_UI::State::Normal;

	}
	m_pUI->SetScale(m_scale);
}
//=============================================================================
// �摜�̃t�F�[�h�C��
//=============================================================================
void CMove_UI::FadeIn(void)
{
	float fColA = m_pUI->GetCol().a;

	fColA += m_fFadeSpeed;

	if (fColA >= 1.0f)
	{
		fColA = 1.0f;
		switch (m_Type)
		{
		case CMove_UI::UI_Type::Type_Start:

			break;
		case CMove_UI::UI_Type::Type_Finish:
			m_state = CMove_UI::State::Normal;
			break;
		case CMove_UI::UI_Type::Type_PushStart:
			break;
		}
	}

	if (m_pUI)
	{
		m_pUI->SetCol({ 1.0,1.0,1.0,fColA });
	}
}
//=============================================================================
// �摜�̃t�F�[�h�A�E�g
//=============================================================================
void CMove_UI::FadeOut(void)
{
	float fColA = m_pUI->GetCol().a;

	fColA -= m_fFadeSpeed;

	if (fColA <= 0.0f)
	{
		fColA = 0.0f;
		m_bUninit = true;
	}

	if (m_pUI)
	{
		m_pUI->SetCol({ 1.0,1.0,1.0,fColA });
	}
}
//=============================================================================
// �摜�̃t�F�[�h�C���A�E�g
//=============================================================================
void CMove_UI::FadeInOut(void)
{
	float fColA = m_pUI->GetCol().a;
	if (!m_bFadeState)
	{
		fColA += 0.01f;
	}
	else
	{
		fColA -= 0.01f;
	}
	if (fColA <= 0.0f)
	{
		m_bFadeState = false;
	}
	if (fColA >= 1.0f)
	{
		m_bFadeState = true;
	}
	if (m_pUI)
	{
		m_pUI->SetCol({ 1.0,1.0,1.0,fColA });
	}
}
//=============================================================================
// �`�J�`�J
//=============================================================================
void CMove_UI::Flash(void)
{
	float fColA = m_pUI->GetCol().a;
	if (m_nTimer >= FlashTimeMin)
	{
		m_nTimer = 0;
		m_bFlash = !m_bFlash;
	}
	if (!m_bFlash)
	{
		fColA = 0.5f;
	}
	else
	{
		fColA = 1.0f;
	}
	if (m_pUI)
	{
		m_pUI->SetCol({ 1.0,1.0,1.0,fColA });
	}

}
//=============================================================================
// UI�̈ړ�
//=============================================================================
void CMove_UI::Move(void)
{
	m_pos.y += TargetMoveSpeed;
	//�ʒu���ړI�̈ʒu�Ɉړ�������
	if (m_pos.y >= m_origin_pos.y)
	{
		switch (m_Type)
		{
		case CMove_UI::UI_Type::Type_Start:

			break;
		case CMove_UI::UI_Type::Type_Finish:
			m_state = CMove_UI::State::Normal;
			break;
		case CMove_UI::UI_Type::Type_PushStart:
			break;
		case CMove_UI::UI_Type::Type_Target:
			m_state = CMove_UI::State::Normal;
			break;
		}
	}
	if (m_pUI)
	{
		m_pUI->SetPos(m_pos);
	}
}
void CMove_UI::Pop(void)
{
	//�傫��������������
	m_scale.x -= m_addspeed.x;
	m_scale.y -= m_addspeed.y;
	//�傫�������̑傫�����炢�܂ŏ������Ȃ����瓮������߂�
	if (m_next_scale.x >= m_scale.x&&
		m_next_scale.y >= m_scale.y)
	{
		m_scale = m_next_scale;
		m_state = CMove_UI::State::Normal;

	}
	m_pUI->SetScale(m_scale);
}
//=============================================================================
// ����(�ʒu�A�T�C�Y�A�o���������ԁA�t�F�[�h�C���A�E�g�̎���)
//=============================================================================
CMove_UI *CMove_UI::Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale,
	int nPopTime, int nFadeTime, CTexture::Type Tex, UI_Type type)
{
	// ���f���̃|�C���^
	CMove_UI *Ingredients = nullptr;
	Ingredients = new CMove_UI;

	// null�`�F�b�N
	if (Ingredients != nullptr)
	{
		// �l����
		//�ړIUI�����ʒuY��ς���
		if (type == CMove_UI::UI_Type::Type_Target)
		{
			Ingredients->m_pos = { pos.x,pos.y - TargetDifPosY,0.0f };
			Ingredients->m_origin_pos = pos;
		}
		else
		{
			Ingredients->m_pos = pos;
		}
		if (type == CMove_UI::UI_Type::Type_Start ||
			type == CMove_UI::UI_Type::Type_Finish)
		{
			Ingredients->m_scale = { scale.x / 100.0f,scale.y / 100.0f ,0.0f };
		}
		else
		{
			Ingredients->m_scale = scale;
		}
		if (type == CMove_UI::UI_Type::Type_Commendation)
		{
			Ingredients->m_scale = { scale.x * 1.5f,scale.y * 1.5f ,0.0f };
			Ingredients->m_next_scale = scale;

		}
		Ingredients->m_origin_scale = scale;

		Ingredients->m_addspeed = { scale.x / 20.0f,scale.y / 20.0f ,0.0f };
		float hoge = 1.0f / nFadeTime;
		Ingredients->m_fFadeSpeed = 1.0f / nFadeTime;
		Ingredients->m_nMaxPopTime = nPopTime;
		Ingredients->m_nMaxFadeTime = nFadeTime;
		Ingredients->m_Type = type;
		if (!Ingredients->m_pUI)
		{
			Ingredients->m_pUI = CPolygon::Create(Ingredients->m_pos, scale, Tex, {1.0,1.0,1.0,0.0},CScene::OBJTYPE::OBJTYPE_UI);
		}
		Ingredients->m_state = CMove_UI::State::ImmediatelyAfterPop;

		// ������
		Ingredients->Init();
	}
	return Ingredients;
}
//=============================================================================
// �X�^�[�gUI�̏���
//=============================================================================
void CMove_UI::Start(void)
{

}
//=============================================================================
// lastspurtUI�̏���
//=============================================================================
void CMove_UI::LastSpurt(void)
{
	if (m_pUI)
	{
		D3DXVECTOR3 pos = m_pUI->GetPos();
		pos.x -= LastSpurtMoveSpeed;
		m_pUI->SetPos(pos);
		if (pos.x <= 0.0f + m_pUI->GetScale().x / 2.0f)
		{
			m_state = CMove_UI::State::End;
		}
	}
}
//=============================================================================
// �t�B�j�b�V��UI�̏���
//=============================================================================
void CMove_UI::Finisj(void)
{
}
//=============================================================================
// �t�B�j�b�V��UI�̏���
//=============================================================================
void CMove_UI::PushStart(void)
{

}


