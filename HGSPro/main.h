//=============================================================================
//
// ���C������ [main.h]
// Author : 
//
//=============================================================================
#ifndef _MAIN_H_
#define _MAIN_H_
#define _CRT_SECURE_NO_WARNINGS

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

#include "d3dx9.h"
#define DIRECTINPUT_VERSION (0x0800)//DirectInput�̃o�[�W�����w��
#include "dinput.h"//���͏����ɕK�v
#include "xaudio2.h"//XAudio�Q�֘A�̃w�b�_�[
using namespace std;
//*****************************************************************************
// ���C�u�����t�@�C���̃����N
//*****************************************************************************
#pragma comment(lib,"d3d9.lib")//�`��ɕK�v
#pragma comment(lib,"d3dx9.lib")//[d3d9.lib]�̊g�����C�u����
#pragma comment(lib,"dxguid.lib")//DirectX�R���|�[�l���g�i���i�j�g�p�ɕK�v
#pragma comment(lib,"dinput8.lib")//���͏����ɕK�v
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"xinput.lib")//���͏����ɕK�v

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define SCREEN_WIDTH (1280)//�E�B���h�E�̕�
#define SCREEN_HEIGHT (720)//�E�B���h�E�̍���

class CRenderer;
//�v���g�^�C�v�錾
int GetFps(void);
#endif