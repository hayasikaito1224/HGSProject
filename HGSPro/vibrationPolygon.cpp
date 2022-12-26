//=============================================================================
//
// Polygon����
//
//=============================================================================
#include "vibrationPolygon.h"
#include "manager.h"
#include "Renderer.h"
#include "scene2D.h"

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CVibrationPolygon::CVibrationPolygon(OBJTYPE nPriority) : CScene2D(nPriority)
{
	m_bDraw = true;

	// �t���[���J�E���g
	m_framecount = 0;

	// �U����
	m_vibesWidth = 0.0f;
	// �U���X�s�[�h
	m_vibesSpeed = 0.0f;
	// �؂�ւ�
	m_bSwitch = false;

	// �U�������邩
	m_bVibration = true;
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CVibrationPolygon::~CVibrationPolygon()
{

}
//------------------------------------------------------------
//���_���W�̐ݒ�
//------------------------------------------------------------

void CVibrationPolygon::SetPos(D3DXVECTOR3 pos)
{
	CScene::SetPos(pos);
	m_pos = pos;
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�o�b�t�@�̐���
	pVtx[0].pos = D3DXVECTOR3(pos.x - m_Scale.x, pos.y - m_Scale.y, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(pos.x + m_Scale.x, pos.y - m_Scale.y, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(pos.x - m_Scale.x, pos.y + m_Scale.y, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(pos.x + m_Scale.x, pos.y + m_Scale.y, 0.0f);

	m_pVtxBuff->Unlock();

}
//=============================================================================
//�F�̐ݒ�
//=============================================================================
void CVibrationPolygon::SetCol(D3DXCOLOR col)
{
	m_col = col;
	VERTEX_2D *pVtx;

	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	//�o�b�t�@�̐���
	pVtx[0].col = m_col;
	pVtx[1].col = m_col;
	pVtx[2].col = m_col;
	pVtx[3].col = m_col;

	m_pVtxBuff->Unlock();

}

//=============================================================================
// �U������ݒ�
//=============================================================================
void CVibrationPolygon::SetVibesWidth(float vibration)
{
	m_vibesWidth = vibration;
}

//=============================================================================
// �U���X�s�[�h��ݒ�	(�l���������قǁA�X�s�[�h������)
//=============================================================================
void CVibrationPolygon::SetVibseFrame(float vibration)
{
	m_vibesSpeed = vibration;
}

//=============================================================================
// �U�������邩�ݒ�		true �� �U��ON	false �� �U��OFF
//=============================================================================
void CVibrationPolygon::SetVibration(bool vibration)
{
	m_bVibration = vibration;
}

//=============================================================================
//������
//=============================================================================
HRESULT CVibrationPolygon::Init()
{
	CScene2D::BindTexture(m_Tex);
	CScene2D::Init();
	CScene2D::SetPos(m_pos, m_Scale);
	CScene2D::SetCol(m_col);

	// ��
	m_vibesWidth = 100.0f;
	// �X�s�[�h(�������قǑ���)
	m_vibesSpeed = 1.0f;

	return S_OK;
}

//=============================================================================
//�I��
//=============================================================================
void CVibrationPolygon::Uninit()
{
	CScene2D::Uninit();
}

//=============================================================================
//�X�V
//=============================================================================
void CVibrationPolygon::Update()
{
	if (m_bVibration)
	{
		// �t���[���J�E���g
		m_framecount++;

		// �ʒu���擾
		D3DXVECTOR3 myPos = CScene2D::GetPos();
		// �T�C�Y���擾
		D3DXVECTOR3 mySize = CScene2D::GetScale();

		// m_move.x = sinf(m_framecount * (D3DX_PI / m_vibesSpeed)) * m_vibesWidth/**/;

		// �t���[�����Ő؂�ւ�
		if (m_framecount >= m_vibesSpeed)
		{
			m_bSwitch = !m_bSwitch;
			m_framecount = 0;
		}

		// �h�炷
		if (m_bSwitch)
		{
			myPos.x -= (m_vibesWidth / m_vibesSpeed);
		}
		else
		{
			myPos.x += (m_vibesWidth / m_vibesSpeed);
		}

		// �ʒu��ݒ�
		CScene2D::SetPos(D3DXVECTOR3(myPos.x, myPos.y, myPos.z), mySize);
	}

	CScene2D::Update();
}

//=============================================================================
//�`��
//=============================================================================
void CVibrationPolygon::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
	if (m_bDraw == true)
	{
		CScene2D::Draw();
	}
}

//=============================================================================
//�N���G�C�g
//=============================================================================
CVibrationPolygon *CVibrationPolygon::Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, CTexture::Type texture, D3DXCOLOR col, int nPriority)
{
	//�C���X�^���X����
	CVibrationPolygon *pPolygon = new CVibrationPolygon((CScene::OBJTYPE)nPriority);

	pPolygon->m_pos = pos;
	pPolygon->m_Scale = scale;
	pPolygon->m_Tex = texture;
	pPolygon->m_col = col;

	if (pPolygon != NULL)
	{
		pPolygon->Init();
	}

	return pPolygon;
}