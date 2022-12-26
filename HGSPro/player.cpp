//=============================================================================
//
// �v���C���[����
//
//=============================================================================
#include "player.h"
#include "Polygon.h"
#include "keyboard.h"
#include "Renderer.h"
#include "manager.h"

CPlayer::CPlayer(OBJTYPE nPriority) : CScene(nPriority)
{
	m_pPolygon = nullptr;
}

CPlayer::~CPlayer()
{
}
//=============================================================================
//������
//=============================================================================
HRESULT CPlayer::Init()
{
	if (!m_pPolygon)
	{
		m_pPolygon = CPolygon::Create({ SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f,0.0 }, { 100.0f,100.0f,0.0 }, CTexture::Type::Test, {1.0,1.0,1.0,1.0},CScene::OBJTYPE_PLAYER);
	}
	return S_OK;
}

//=============================================================================
//�I��
//=============================================================================
void CPlayer::Uninit()
{
	if (m_pPolygon)
	{
		m_pPolygon->Uninit();
		m_pPolygon = nullptr;
	}
}

//=============================================================================
//�X�V
//=============================================================================
void CPlayer::Update()
{
	PushTrigger(DIK_A, 0);
	PushTrigger(DIK_D, 0);
	PushTrigger(DIK_SEMICOLON, 1);
	PushTrigger(DIK_RBRACKET, 1);

}

//=============================================================================
//�`��
//=============================================================================
void CPlayer::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = CManager::GetRenderer()->GetDevice();//�f�o�C�X�̃|�C���^
	DebugTextDraw();
}
//=============================================================================
//�`��
//=============================================================================
void CPlayer::DebugTextDraw()
{
	RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	char str[3000];
	int nNum = 0;

	nNum = sprintf(&str[0], "\n\n ��� \n");

	nNum += sprintf(&str[nNum], " [PushCnt{player1}] %d\n", m_nPushCounter[0]);
	nNum += sprintf(&str[nNum], " [PushCnt{player2}] %d\n", m_nPushCounter[1]);

	LPD3DXFONT pFont = CManager::GetRenderer()->GetFont();
	// �e�L�X�g�`��
	pFont->DrawText(NULL, str, -1, &rect, DT_LEFT, D3DCOLOR_ARGB(0xff, 0xff, 0xff, 0xff));

}
//=============================================================================
//�C���X�^���X��������
//=============================================================================
CPlayer *CPlayer::Create()
{
	CPlayer *pPlayer = new CPlayer();
	if (pPlayer)
	{
		pPlayer->Init();
	}
	return pPlayer;
}
//=============================================================================
//�A�ł��鏈��
//=============================================================================
void CPlayer::PushTrigger(int nKey, int nPlayer)
{
	CInputKeyBoard *pKey = CManager::GetInputKeyboard();

	//����̃L�[�������ƃJ�E���g������
	if(pKey->GetTrigger(nKey))
	{
		m_nPushCounter[nPlayer]++;
	}
}
