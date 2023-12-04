#include "header.h"

// 0x0 ��ǥ ����
const float block00[][3] = {
	{-0.5f, 0.7f, -0.1f},
	{-0.5f, 0.5f, -0.1f},
	{ -0.7f, 0.7f, -0.1f},
	{ -0.7f, 0.5f, -0.1f},	// �ո�

	{ -0.5f, 0.7f, 0.1f },
	{ -0.5f, 0.5f, 0.1f },
	{ -0.7f, 0.7f, 0.1f },
	{ -0.7f, 0.5f, 0.1f },	// �޸�

	{ -0.5f, 0.7f, 0.1f },
	{ -0.5f, 0.7f, -0.1f },
	{ -0.7f, 0.7f, 0.1f },
	{ -0.7f, 0.7f, -0.1f },	// ����

	{ -0.5f, 0.5f, 0.1f },
	{ -0.5f, 0.5f, -0.1f },
	{ -0.7f, 0.5f, 0.1f },
	{ -0.7f, 0.5f, -0.1f },	// �Ʒ���

	{ -0.7f, 0.7f, 0.1f },
	{ -0.7f, 0.5f, 0.1f },
	{ -0.7f, 0.7f, -0.1f },
	{ -0.7f, 0.5f, -0.1f },	// ������

	{ -0.5f, 0.7f, 0.1f },
	{ -0.5f, 0.5f, 0.1f },
	{ -0.5f, 0.7f, -0.1f },
	{ -0.5f, 0.5f, -0.1f },	// ������
};

// 0x1 ��ǥ ����
const float block01[][3] = {
	{-0.3f, 0.7f, -0.1f},
	{ -0.3f, 0.5f, -0.1f },
	{ -0.5f, 0.7f, -0.1f },
	{ -0.5f, 0.5f, -0.1f },	// �ո�

	{ -0.3f, 0.7f, 0.1f },
	{ -0.3f, 0.5f, 0.1f },
	{ -0.5f, 0.7f, 0.1f },
	{ -0.5f, 0.5f, 0.1f },	// �޸�

	{ -0.3f, 0.7f, 0.1f },
	{ -0.3f, 0.7f, -0.1f },
	{ -0.5f, 0.7f, 0.1f },
	{ -0.5f, 0.7f, -0.1f },	// ����

	{ -0.3f, 0.5f, 0.1f },
	{ -0.3f, 0.5f, -0.1f },
	{ -0.5f, 0.5f, 0.1f },
	{ -0.5f, 0.5f, -0.1f },	// �Ʒ���

	{ -0.5f, 0.7f, 0.1f },
	{ -0.5f, 0.5f, 0.1f },
	{ -0.5f, 0.7f, -0.1f },
	{ -0.5f, 0.5f, -0.1f },	// ������

	{ -0.3f, 0.7f, 0.1f },
	{ -0.3f, 0.5f, 0.1f },
	{ -0.3f, 0.7f, -0.1f },
	{ -0.3f, 0.5f, -0.1f },	// ������
};

// 0x2 ��ǥ ����
const float block02[][3] = {
	{-0.1f, 0.7f, -0.1f},
	{ -0.1f, 0.5f, -0.1f },
	{ -0.3f, 0.7f, -0.1f },
	{ -0.3f, 0.5f, -0.1f },	// �ո�

	{ -0.1f, 0.7f, 0.1f },
	{ -0.1f, 0.5f, 0.1f },
	{ -0.3f, 0.7f, 0.1f },
	{ -0.3f, 0.5f, 0.1f },	// �޸�

	{ -0.1f, 0.7f, 0.1f },
	{ -0.1f, 0.7f, -0.1f },
	{ -0.3f, 0.7f, 0.1f },
	{ -0.3f, 0.7f, -0.1f },	// ����

	{ -0.1f, 0.5f, 0.1f },
	{ -0.1f, 0.5f, -0.1f },
	{ -0.3f, 0.5f, 0.1f },
	{ -0.3f, 0.5f, -0.1f },	// �Ʒ���

	{ -0.3f, 0.7f, 0.1f },
	{ -0.3f, 0.5f, 0.1f },
	{ -0.3f, 0.7f, -0.1f },
	{ -0.3f, 0.5f, -0.1f },	// ������

	{ -0.1f, 0.7f, 0.1f },
	{ -0.1f, 0.5f, 0.1f },
	{ -0.1f, 0.7f, -0.1f },
	{ -0.1f, 0.5f, -0.1f },	// ������
};

// 0x3 ��ǥ ����
const float block03[][3] = {
	{0.1f, 0.7f, -0.1f},
	{ 0.1f, 0.5f, -0.1f },
	{ -0.1f, 0.7f, -0.1f },
	{ -0.1f, 0.5f, -0.1f },	// �ո�

	{ 0.1f, 0.7f, 0.1f },
	{ 0.1f, 0.5f, 0.1f },
	{ -0.1f, 0.7f, 0.1f },
	{ -0.1f, 0.5f, 0.1f },	// �޸�

	{ 0.1f, 0.7f, 0.1f },
	{ 0.1f, 0.7f, -0.1f },
	{ -0.1f, 0.7f, 0.1f },
	{ -0.1f, 0.7f, -0.1f },	// ����

	{ 0.1f, 0.5f, 0.1f },
	{ 0.1f, 0.5f, -0.1f },
	{ -0.1f, 0.5f, 0.1f },
	{ -0.1f, 0.5f, -0.1f },	// �Ʒ���

	{ -0.1f, 0.7f, 0.1f },
	{ -0.1f, 0.5f, 0.1f },
	{ -0.1f, 0.7f, -0.1f },
	{ -0.1f, 0.5f, -0.1f },	// ������

	{ 0.1f, 0.7f, 0.1f },
	{ 0.1f, 0.5f, 0.1f },
	{ 0.1f, 0.7f, -0.1f },
	{ 0.1f, 0.5f, -0.1f },	// ������
};

// 0x4 ��ǥ ����
const float block04[][3] = {
	{ 0.3f, 0.7f, -0.1f },
	{ 0.3f, 0.5f, -0.1f },
	{ 0.1f, 0.7f, -0.1f },
	{ 0.1f, 0.5f, -0.1f },	// �ո�

	{ 0.3f, 0.7f, 0.1f },
	{ 0.3f, 0.5f, 0.1f },
	{ 0.1f, 0.7f, 0.1f },
	{ 0.1f, 0.5f, 0.1f },	// �޸�

	{ 0.3f, 0.7f, 0.1f },
	{ 0.3f, 0.7f, -0.1f },
	{ 0.1f, 0.7f, 0.1f },
	{ 0.1f, 0.7f, -0.1f },	// ����

	{ 0.3f, 0.5f, 0.1f },
	{ 0.3f, 0.5f, -0.1f },
	{ 0.1f, 0.5f, 0.1f },
	{ 0.1f, 0.5f, -0.1f },	// �Ʒ���

	{ 0.1f, 0.7f, 0.1f },
	{ 0.1f, 0.5f, 0.1f },
	{ 0.1f, 0.7f, -0.1f },
	{ 0.1f, 0.5f, -0.1f },	// ������

	{ 0.3f, 0.7f, 0.1f },
	{ 0.3f, 0.5f, 0.1f },
	{ 0.3f, 0.7f, -0.1f },
	{ 0.3f, 0.5f, -0.1f },	// ������*/
};

// 0x5 ��ǥ ����
const float block05[][3] = {
	{ 0.5f, 0.7f, -0.1f },
	{ 0.5f, 0.5f, -0.1f },
	{ 0.3f, 0.7f, -0.1f },
	{ 0.3f, 0.5f, -0.1f },	// �ո�

	{ 0.5f, 0.7f, 0.1f },
	{ 0.5f, 0.5f, 0.1f },
	{ 0.3f, 0.7f, 0.1f },
	{ 0.3f, 0.5f, 0.1f },	// �޸�

	{ 0.5f, 0.7f, 0.1f },
	{ 0.5f, 0.7f, -0.1f },
	{ 0.3f, 0.7f, 0.1f },
	{ 0.3f, 0.7f, -0.1f },	// ����

	{ 0.5f, 0.5f, 0.1f },
	{ 0.5f, 0.5f, -0.1f },
	{ 0.3f, 0.5f, 0.1f },
	{ 0.3f, 0.5f, -0.1f },	// �Ʒ���

	{ 0.3f, 0.7f, 0.1f },
	{ 0.3f, 0.5f, 0.1f },
	{ 0.3f, 0.7f, -0.1f },
	{ 0.3f, 0.5f, -0.1f },	// ������

	{ 0.5f, 0.7f, 0.1f },
	{ 0.5f, 0.5f, 0.1f },
	{ 0.5f, 0.7f, -0.1f },
	{ 0.5f, 0.5f, -0.1f },	// ������
};

// 0x6 ��ǥ ����
const float block06[][3] = {
	{ 0.7f, 0.7f, -0.1f },
	{ 0.7f, 0.5f, -0.1f },
	{ 0.5f, 0.7f, -0.1f },
	{ 0.5f, 0.5f, -0.1f },	// �ո�

	{ 0.7f, 0.7f, 0.1f },
	{ 0.7f, 0.5f, 0.1f },
	{ 0.5f, 0.7f, 0.1f },
	{ 0.5f, 0.5f, 0.1f },	// �޸�

	{ 0.7f, 0.7f, 0.1f },
	{ 0.7f, 0.7f, -0.1f },
	{ 0.5f, 0.7f, 0.1f },
	{ 0.5f, 0.7f, -0.1f },	// ����

	{ 0.7f, 0.5f, 0.1f },
	{ 0.7f, 0.5f, -0.1f },
	{ 0.5f, 0.5f, 0.1f },
	{ 0.5f, 0.5f, -0.1f },	// �Ʒ���

	{ 0.5f, 0.7f, 0.1f },
	{ 0.5f, 0.5f, 0.1f },
	{ 0.5f, 0.7f, -0.1f },
	{ 0.5f, 0.5f, -0.1f },	// ������

	{ 0.7f, 0.7f, 0.1f },
	{ 0.7f, 0.5f, 0.1f },
	{ 0.7f, 0.7f, -0.1f },
	{ 0.7f, 0.5f, -0.1f },	// ������
};

//---------------------
// 1x0 ��ǥ ����
/*{ -0.5f, 0.5f, -0.1f },
{ -0.5f, 0.3f, -0.1f },
{ -0.7f, 0.5f, -0.1f },
{ -0.7f, 0.3f, -0.1f },	// �ո�

{ -0.5f, 0.5f, 0.1f },
{ -0.5f, 0.3f, 0.1f },
{ -0.7f, 0.5f, 0.1f },
{ -0.7f, 0.3f, 0.1f },	// �޸�

{ -0.5f, 0.5f, 0.1f },
{ -0.5f, 0.5f, -0.1f },
{ -0.7f, 0.5f, 0.1f },
{ -0.7f, 0.5f, -0.1f },	// ����

{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.3f, -0.1f },
{ -0.7f, 0.3f, 0.1f },
{ -0.7f, 0.3f, -0.1f },	// �Ʒ���

{ -0.7f, 0.5f, 0.1f },
{ -0.7f, 0.3f, 0.1f },
{ -0.7f, 0.5f, -0.1f },
{ -0.7f, 0.3f, -0.1f },	// ������

{ -0.5f, 0.5f, 0.1f },
{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.5f, -0.1f },
{ -0.5f, 0.3f, -0.1f },	// ������*/

// 1x1 ��ǥ ����
/*{ -0.3f, 0.5f, -0.1f },
{ -0.3f, 0.3f, -0.1f },
{ -0.5f, 0.5f, -0.1f },
{ -0.5f, 0.3f, -0.1f },	// �ո�

{ -0.3f, 0.5f, 0.1f },
{ -0.3f, 0.3f, 0.1f },
{ -0.5f, 0.5f, 0.1f },
{ -0.5f, 0.3f, 0.1f },	// �޸�

{ -0.3f, 0.5f, 0.1f },
{ -0.3f, 0.5f, -0.1f },
{ -0.5f, 0.5f, 0.1f },
{ -0.5f, 0.5f, -0.1f },	// ����

{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.3f, -0.1f },
{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.3f, -0.1f },	// �Ʒ���

{ -0.5f, 0.5f, 0.1f },
{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.5f, -0.1f },
{ -0.5f, 0.3f, -0.1f },	// ������

{ -0.3f, 0.5f, 0.1f },
{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.5f, -0.1f },
{ -0.3f, 0.3f, -0.1f },	// ������*/

// 1x2 ��ǥ ����
/*{-0.1f, 0.5f, -0.1f},
{ -0.1f, 0.3f, -0.1f },
{ -0.3f, 0.5f, -0.1f },
{ -0.3f, 0.3f, -0.1f },	// �ո�

{ -0.1f, 0.5f, 0.1f },
{ -0.1f, 0.3f, 0.1f },
{ -0.3f, 0.5f, 0.1f },
{ -0.3f, 0.3f, 0.1f },	// �޸�

{ -0.1f, 0.5f, 0.1f },
{ -0.1f, 0.5f, -0.1f },
{ -0.3f, 0.5f, 0.1f },
{ -0.3f, 0.5f, -0.1f },	// ����

{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.3f, -0.1f },
{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.3f, -0.1f },	// �Ʒ���

{ -0.3f, 0.5f, 0.1f },
{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.5f, -0.1f },
{ -0.3f, 0.3f, -0.1f },	// ������

{ -0.1f, 0.5f, 0.1f },
{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.5f, -0.1f },
{ -0.1f, 0.3f, -0.1f },	// ������*/

// 1x3 ��ǥ ����
/*{ 0.1f, 0.5f, -0.1f },
{ 0.1f, 0.3f, -0.1f },
{ -0.1f, 0.5f, -0.1f },
{ -0.1f, 0.3f, -0.1f },	// �ո�

{ 0.1f, 0.5f, 0.1f },
{ 0.1f, 0.3f, 0.1f },
{ -0.1f, 0.5f, 0.1f },
{ -0.1f, 0.3f, 0.1f },	// �޸�

{ 0.1f, 0.5f, 0.1f },
{ 0.1f, 0.5f, -0.1f },
{ -0.1f, 0.5f, 0.1f },
{ -0.1f, 0.5f, -0.1f },	// ����

{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.3f, -0.1f },
{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.3f, -0.1f },	// �Ʒ���

{ -0.1f, 0.5f, 0.1f },
{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.5f, -0.1f },
{ -0.1f, 0.3f, -0.1f },	// ������

{ 0.1f, 0.5f, 0.1f },
{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.5f, -0.1f },
{ 0.1f, 0.3f, -0.1f },	// ������*/

// 1x4 ��ǥ ����
/*{ 0.3f, 0.5f, -0.1f },
{ 0.3f, 0.3f, -0.1f },
{ 0.1f, 0.5f, -0.1f },
{ 0.1f, 0.3f, -0.1f },	// �ո�

{ 0.3f, 0.5f, 0.1f },
{ 0.3f, 0.3f, 0.1f },
{ 0.1f, 0.5f, 0.1f },
{ 0.1f, 0.3f, 0.1f },	// �޸�

{ 0.3f, 0.5f, 0.1f },
{ 0.3f, 0.5f, -0.1f },
{ 0.1f, 0.5f, 0.1f },
{ 0.1f, 0.5f, -0.1f },	// ����

{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.3f, -0.1f },
{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.3f, -0.1f },	// �Ʒ���

{ 0.1f, 0.5f, 0.1f },
{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.5f, -0.1f },
{ 0.1f, 0.3f, -0.1f },	// ������

{ 0.3f, 0.5f, 0.1f },
{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.5f, -0.1f },
{ 0.3f, 0.3f, -0.1f },	// ������*/

// 1x5 ��ǥ ����
/*{ 0.5f, 0.5f, -0.1f },
{ 0.5f, 0.3f, -0.1f },
{ 0.3f, 0.5f, -0.1f },
{ 0.3f, 0.3f, -0.1f },	// �ո�

{ 0.5f, 0.5f, 0.1f },
{ 0.5f, 0.3f, 0.1f },
{ 0.3f, 0.5f, 0.1f },
{ 0.3f, 0.3f, 0.1f },	// �޸�

{ 0.5f, 0.5f, 0.1f },
{ 0.5f, 0.5f, -0.1f },
{ 0.3f, 0.5f, 0.1f },
{ 0.3f, 0.5f, -0.1f },	// ����

{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.3f, -0.1f },
{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.3f, -0.1f },	// �Ʒ���

{ 0.3f, 0.5f, 0.1f },
{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.5f, -0.1f },
{ 0.3f, 0.3f, -0.1f },	// ������

{ 0.5f, 0.5f, 0.1f },
{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.5f, -0.1f },
{ 0.5f, 0.3f, -0.1f },	// ������*/

// 1x6 ��ǥ ����
/*{ 0.7f, 0.5f, -0.1f },
{ 0.7f, 0.3f, -0.1f },
{ 0.5f, 0.5f, -0.1f },
{ 0.5f, 0.3f, -0.1f },	// �ո�

{ 0.7f, 0.5f, 0.1f },
{ 0.7f, 0.3f, 0.1f },
{ 0.5f, 0.5f, 0.1f },
{ 0.5f, 0.3f, 0.1f },	// �޸�

{ 0.7f, 0.5f, 0.1f },
{ 0.7f, 0.5f, -0.1f },
{ 0.5f, 0.5f, 0.1f },
{ 0.5f, 0.5f, -0.1f },	// ����

{ 0.7f, 0.3f, 0.1f },
{ 0.7f, 0.3f, -0.1f },
{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.3f, -0.1f },	// �Ʒ���

{ 0.5f, 0.5f, 0.1f },
{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.5f, -0.1f },
{ 0.5f, 0.3f, -0.1f },	// ������

{ 0.7f, 0.5f, 0.1f },
{ 0.7f, 0.3f, 0.1f },
{ 0.7f, 0.5f, -0.1f },
{ 0.7f, 0.3f, -0.1f },	// ������*/

//---------------------
// 2x0 ��ǥ ����
/*{ -0.5f, 0.3f, -0.1f },
{ -0.5f, 0.1f, -0.1f },
{ -0.7f, 0.3f, -0.1f },
{ -0.7f, 0.1f, -0.1f },	// �ո�

{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.1f, 0.1f },
{ -0.7f, 0.3f, 0.1f },
{ -0.7f, 0.1f, 0.1f },	// �޸�

{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.3f, -0.1f },
{ -0.7f, 0.3f, 0.1f },
{ -0.7f, 0.3f, -0.1f },	// ����

{ -0.5f, 0.1f, 0.1f },
{ -0.5f, 0.1f, -0.1f },
{ -0.7f, 0.1f, 0.1f },
{ -0.7f, 0.1f, -0.1f },	// �Ʒ���

{ -0.7f, 0.3f, 0.1f },
{ -0.7f, 0.1f, 0.1f },
{ -0.7f, 0.3f, -0.1f },
{ -0.7f, 0.1f, -0.1f },	// ������

{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.1f, 0.1f },
{ -0.5f, 0.3f, -0.1f },
{ -0.5f, 0.1f, -0.1f },	// ������*/

// 2x1 ��ǥ ����
/*{ -0.3f, 0.3f, -0.1f },
{ -0.3f, 0.1f, -0.1f },
{ -0.5f, 0.3f, -0.1f },
{ -0.5f, 0.1f, -0.1f },	// �ո�

{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.1f, 0.1f },
{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.1f, 0.1f },	// �޸�

{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.3f, -0.1f },
{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.3f, -0.1f },	// ����

{ -0.3f, 0.1f, 0.1f },
{ -0.3f, 0.1f, -0.1f },
{ -0.5f, 0.1f, 0.1f },
{ -0.5f, 0.1f, -0.1f },	// �Ʒ���

{ -0.5f, 0.3f, 0.1f },
{ -0.5f, 0.1f, 0.1f },
{ -0.5f, 0.3f, -0.1f },
{ -0.5f, 0.1f, -0.1f },	// ������

{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.1f, 0.1f },
{ -0.3f, 0.3f, -0.1f },
{ -0.3f, 0.1f, -0.1f },	// ������*/

// 2x2 ��ǥ ����

// 2x2 ��ǥ ����
/*{-0.1f, 0.3f, -0.1f},
{ -0.1f, 0.1f, -0.1f },
{ -0.3f, 0.3f, -0.1f },
{ -0.3f, 0.1f, -0.1f },	// �ո�

{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.1f, 0.1f },
{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.1f, 0.1f },	// �޸�

{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.3f, -0.1f },
{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.3f, -0.1f },	// ����

{ -0.1f, 0.1f, 0.1f },
{ -0.1f, 0.1f, -0.1f },
{ -0.3f, 0.1f, 0.1f },
{ -0.3f, 0.1f, -0.1f },	// �Ʒ���

{ -0.3f, 0.3f, 0.1f },
{ -0.3f, 0.1f, 0.1f },
{ -0.3f, 0.3f, -0.1f },
{ -0.3f, 0.1f, -0.1f },	// ������

{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.1f, 0.1f },
{ -0.1f, 0.3f, -0.1f },
{ -0.1f, 0.1f, -0.1f },	// ������*/

// 2x3 ��ǥ ����
/*{0.1f, 0.3f, -0.1f},
{ 0.1f, 0.1f, -0.1f },
{ -0.1f, 0.3f, -0.1f },
{ -0.1f, 0.1f, -0.1f },	// �ո�

{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.1f, 0.1f },
{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.1f, 0.1f },	// �޸�

{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.3f, -0.1f },
{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.3f, -0.1f },	// ����

{ 0.1f, 0.1f, 0.1f },
{ 0.1f, 0.1f, -0.1f },
{ -0.1f, 0.1f, 0.1f },
{ -0.1f, 0.1f, -0.1f },	// �Ʒ���

{ -0.1f, 0.3f, 0.1f },
{ -0.1f, 0.1f, 0.1f },
{ -0.1f, 0.3f, -0.1f },
{ -0.1f, 0.1f, -0.1f },	// ������

{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.1f, 0.1f },
{ 0.1f, 0.3f, -0.1f },
{ 0.1f, 0.1f, -0.1f },	// ������*/

// 2x4 ��ǥ ����
/*{0.3f, 0.3f, -0.1f},
{ 0.3f, 0.1f, -0.1f },
{ 0.1f, 0.3f, -0.1f },
{ 0.1f, 0.1f, -0.1f },	// �ո�

{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.1f, 0.1f },
{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.1f, 0.1f },	// �޸�

{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.3f, -0.1f },
{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.3f, -0.1f },	// ����

{ 0.3f, 0.1f, 0.1f },
{ 0.3f, 0.1f, -0.1f },
{ 0.1f, 0.1f, 0.1f },
{ 0.1f, 0.1f, -0.1f },	// �Ʒ���

{ 0.1f, 0.3f, 0.1f },
{ 0.1f, 0.1f, 0.1f },
{ 0.1f, 0.3f, -0.1f },
{ 0.1f, 0.1f, -0.1f },	// ������

{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.1f, 0.1f },
{ 0.3f, 0.3f, -0.1f },
{ 0.3f, 0.1f, -0.1f },	// ������*/

// 2x5 ��ǥ ����
/*{0.5f, 0.3f, -0.1f},
{ 0.5f, 0.1f, -0.1f },
{ 0.3f, 0.3f, -0.1f },
{ 0.3f, 0.1f, -0.1f },	// �ո�

{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.1f, 0.1f },
{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.1f, 0.1f },	// �޸�

{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.3f, -0.1f },
{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.3f, -0.1f },	// ����

{ 0.5f, 0.1f, 0.1f },
{ 0.5f, 0.1f, -0.1f },
{ 0.3f, 0.1f, 0.1f },
{ 0.3f, 0.1f, -0.1f },	// �Ʒ���

{ 0.3f, 0.3f, 0.1f },
{ 0.3f, 0.1f, 0.1f },
{ 0.3f, 0.3f, -0.1f },
{ 0.3f, 0.1f, -0.1f },	// ������

{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.1f, 0.1f },
{ 0.5f, 0.3f, -0.1f },
{ 0.5f, 0.1f, -0.1f },	// ������*/

// 2x6 ��ǥ ����
/*{0.7f, 0.3f, -0.1f},
{ 0.7f, 0.1f, -0.1f },
{ 0.5f, 0.3f, -0.1f },
{ 0.5f, 0.1f, -0.1f },	// �ո�

{ 0.7f, 0.3f, 0.1f },
{ 0.7f, 0.1f, 0.1f },
{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.1f, 0.1f },	// �޸�

{ 0.7f, 0.3f, 0.1f },
{ 0.7f, 0.3f, -0.1f },
{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.3f, -0.1f },	// ����

{ 0.7f, 0.1f, 0.1f },
{ 0.7f, 0.1f, -0.1f },
{ 0.5f, 0.1f, 0.1f },
{ 0.5f, 0.1f, -0.1f },	// �Ʒ���

{ 0.5f, 0.3f, 0.1f },
{ 0.5f, 0.1f, 0.1f },
{ 0.5f, 0.3f, -0.1f },
{ 0.5f, 0.1f, -0.1f },	// ������

{ 0.7f, 0.3f, 0.1f },
{ 0.7f, 0.1f, 0.1f },
{ 0.7f, 0.3f, -0.1f },
{ 0.7f, 0.1f, -0.1f },	// ������*/

//---------------------
// 3x0 ��ǥ ����
/*{ -0.5f, 0.1f, -0.1f },
{ -0.5f, -0.1f, -0.1f },
{ -0.7f, 0.1f, -0.1f },
{ -0.7f, -0.1f, -0.1f },	// �ո�

{ -0.5f, 0.1f, 0.1f },
{ -0.5f, -0.1f, 0.1f },
{ -0.7f, 0.1f, 0.1f },
{ -0.7f, -0.1f, 0.1f },	// �޸�

{ -0.5f, 0.1f, 0.1f },
{ -0.5f, 0.1f, -0.1f },
{ -0.7f, 0.1f, 0.1f },
{ -0.7f, 0.1f, -0.1f },	// ����

{ -0.5f, -0.1f, 0.1f },
{ -0.5f, -0.1f, -0.1f },
{ -0.7f, -0.1f, 0.1f },
{ -0.7f, -0.1f, -0.1f },	// �Ʒ���

{ -0.7f, 0.1f, 0.1f },
{ -0.7f, -0.1f, 0.1f },
{ -0.7f, 0.1f, -0.1f },
{ -0.7f, -0.1f, -0.1f },	// ������

{ -0.5f, 0.1f, 0.1f },
{ -0.5f, -0.1f, 0.1f },
{ -0.5f, 0.1f, -0.1f },
{ -0.5f, -0.1f, -0.1f },	// ������*/

// 3x1 ��ǥ ����
/*{-0.3f, 0.1f, -0.1f },
{ -0.3f, -0.1f, -0.1f },
{ -0.5f, 0.1f, -0.1f },
{ -0.5f, -0.1f, -0.1f },	// �ո�

{ -0.3f, 0.1f, 0.1f },
{ -0.3f, -0.1f, 0.1f },
{ -0.5f, 0.1f, 0.1f },
{ -0.5f, -0.1f, 0.1f },	// �޸�

{ -0.3f, 0.1f, 0.1f },
{ -0.3f, 0.1f, -0.1f },
{ -0.5f, 0.1f, 0.1f },
{ -0.5f, 0.1f, -0.1f },	// ����

{ -0.3f, -0.1f, 0.1f },
{ -0.3f, -0.1f, -0.1f },
{ -0.5f, -0.1f, 0.1f },
{ -0.5f, -0.1f, -0.1f },	// �Ʒ���

{ -0.5f, 0.1f, 0.1f },
{ -0.5f, -0.1f, 0.1f },
{ -0.5f, 0.1f, -0.1f },
{ -0.5f, -0.1f, -0.1f },	// ������

{ -0.3f, 0.1f, 0.1f },
{ -0.3f, -0.1f, 0.1f },
{ -0.3f, 0.1f, -0.1f },
{ -0.3f, -0.1f, -0.1f },	// ������*/

// 3x2 ��ǥ ����
/*{-0.1f, 0.1f, -0.1f },
{ -0.1f, -0.1f, -0.1f },
{ -0.3f, 0.1f, -0.1f },
{ -0.3f, -0.1f, -0.1f },	// �ո�

{ -0.1f, 0.1f, 0.1f },
{ -0.1f, -0.1f, 0.1f },
{ -0.3f, 0.1f, 0.1f },
{ -0.3f, -0.1f, 0.1f },	// �޸�

{ -0.1f, 0.1f, 0.1f },
{ -0.1f, 0.1f, -0.1f },
{ -0.3f, 0.1f, 0.1f },
{ -0.3f, 0.1f, -0.1f },	// ����

{ -0.1f, -0.1f, 0.1f },
{ -0.1f, -0.1f, -0.1f },
{ -0.3f, -0.1f, 0.1f },
{ -0.3f, -0.1f, -0.1f },	// �Ʒ���

{ -0.3f, 0.1f, 0.1f },
{ -0.3f, -0.1f, 0.1f },
{ -0.3f, 0.1f, -0.1f },
{ -0.3f, -0.1f, -0.1f },	// ������

{ -0.1f, 0.1f, 0.1f },
{ -0.1f, -0.1f, 0.1f },
{ -0.1f, 0.1f, -0.1f },
{ -0.1f, -0.1f, -0.1f },	// ������*/

// 3x3 ��ǥ ����
/*{ 0.1f, 0.1f, -0.1f },
{ 0.1f, -0.1f, -0.1f },
{ -0.1f, 0.1f, -0.1f },
{ -0.1f, -0.1f, -0.1f },	// �ո�

{ 0.1f, 0.1f, 0.1f },
{ 0.1f, -0.1f, 0.1f },
{ -0.1f, 0.1f, 0.1f },
{ -0.1f, -0.1f, 0.1f },	// �޸�

{ 0.1f, 0.1f, 0.1f },
{ 0.1f, 0.1f, -0.1f },
{ -0.1f, 0.1f, 0.1f },
{ -0.1f, 0.1f, -0.1f },	// ����

{ 0.1f, -0.1f, 0.1f },
{ 0.1f, -0.1f, -0.1f },
{ -0.1f, -0.1f, 0.1f },
{ -0.1f, -0.1f, -0.1f },	// �Ʒ���

{ -0.1f, 0.1f, 0.1f },
{ -0.1f, -0.1f, 0.1f },
{ -0.1f, 0.1f, -0.1f },
{ -0.1f, -0.1f, -0.1f },	// ������

{ 0.1f, 0.1f, 0.1f },
{ 0.1f, -0.1f, 0.1f },
{ 0.1f, 0.1f, -0.1f },
{ 0.1f, -0.1f, -0.1f },	// ������*/

// 3x4 ��ǥ ����
/*{0.3f, 0.1f, -0.1f },
{ 0.3f, -0.1f, -0.1f },
{ 0.1f, 0.1f, -0.1f },
{ 0.1f, -0.1f, -0.1f },	// �ո�

{ 0.3f, 0.1f, 0.1f },
{ 0.3f, -0.1f, 0.1f },
{ 0.1f, 0.1f, 0.1f },
{ 0.1f, -0.1f, 0.1f },	// �޸�

{ 0.3f, 0.1f, 0.1f },
{ 0.3f, 0.1f, -0.1f },
{ 0.1f, 0.1f, 0.1f },
{ 0.1f, 0.1f, -0.1f },	// ����

{ 0.3f, -0.1f, 0.1f },
{ 0.3f, -0.1f, -0.1f },
{ 0.1f, -0.1f, 0.1f },
{ 0.1f, -0.1f, -0.1f },	// �Ʒ���

{ 0.1f, 0.1f, 0.1f },
{ 0.1f, -0.1f, 0.1f },
{ 0.1f, 0.1f, -0.1f },
{ 0.1f, -0.1f, -0.1f },	// ������

{ 0.3f, 0.1f, 0.1f },
{ 0.3f, -0.1f, 0.1f },
{ 0.3f, 0.1f, -0.1f },
{ 0.3f, -0.1f, -0.1f },	// ������*/

// 3x5 ��ǥ ����
/*{0.5f, 0.1f, -0.1f },
{ 0.5f, -0.1f, -0.1f },
{ 0.3f, 0.1f, -0.1f },
{ 0.3f, -0.1f, -0.1f },	// �ո�

{ 0.5f, 0.1f, 0.1f },
{ 0.5f, -0.1f, 0.1f },
{ 0.3f, 0.1f, 0.1f },
{ 0.3f, -0.1f, 0.1f },	// �޸�

{ 0.5f, 0.1f, 0.1f },
{ 0.5f, 0.1f, -0.1f },
{ 0.3f, 0.1f, 0.1f },
{ 0.3f, 0.1f, -0.1f },	// ����

{ 0.5f, -0.1f, 0.1f },
{ 0.5f, -0.1f, -0.1f },
{ 0.3f, -0.1f, 0.1f },
{ 0.3f, -0.1f, -0.1f },	// �Ʒ���

{ 0.3f, 0.1f, 0.1f },
{ 0.3f, -0.1f, 0.1f },
{ 0.3f, 0.1f, -0.1f },
{ 0.3f, -0.1f, -0.1f },	// ������

{ 0.5f, 0.1f, 0.1f },
{ 0.5f, -0.1f, 0.1f },
{ 0.5f, 0.1f, -0.1f },
{ 0.5f, -0.1f, -0.1f },	// ������*/

// 3x6 ��ǥ ����
/*{0.7f, 0.1f, -0.1f },
{ 0.7f, -0.1f, -0.1f },
{ 0.5f, 0.1f, -0.1f },
{ 0.5f, -0.1f, -0.1f },	// �ո�

{ 0.7f, 0.1f, 0.1f },
{ 0.7f, -0.1f, 0.1f },
{ 0.5f, 0.1f, 0.1f },
{ 0.5f, -0.1f, 0.1f },	// �޸�

{ 0.7f, 0.1f, 0.1f },
{ 0.7f, 0.1f, -0.1f },
{ 0.5f, 0.1f, 0.1f },
{ 0.5f, 0.1f, -0.1f },	// ����

{ 0.7f, -0.1f, 0.1f },
{ 0.7f, -0.1f, -0.1f },
{ 0.5f, -0.1f, 0.1f },
{ 0.5f, -0.1f, -0.1f },	// �Ʒ���

{ 0.5f, 0.1f, 0.1f },
{ 0.5f, -0.1f, 0.1f },
{ 0.5f, 0.1f, -0.1f },
{ 0.5f, -0.1f, -0.1f },	// ������

{ 0.7f, 0.1f, 0.1f },
{ 0.7f, -0.1f, 0.1f },
{ 0.7f, 0.1f, -0.1f },
{ 0.7f, -0.1f, -0.1f },	// ������*/

//---------------------
// 4x0 ��ǥ ����
/*{ -0.5f, -0.1f, -0.1f },
{ -0.5f, -0.3f, -0.1f },
{ -0.7f, -0.1f, -0.1f },
{ -0.7f, -0.3f, -0.1f },	// �ո�

{ -0.5f, -0.1f, 0.1f },
{ -0.5f, -0.3f, 0.1f },
{ -0.7f, -0.1f, 0.1f },
{ -0.7f, -0.3f, 0.1f },	// �޸�

{ -0.5f, -0.1f, 0.1f },
{ -0.5f, -0.1f, -0.1f },
{ -0.7f, -0.1f, 0.1f },
{ -0.7f, -0.1f, -0.1f },	// ����

{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.3f, -0.1f },
{ -0.7f, -0.3f, 0.1f },
{ -0.7f, -0.3f, -0.1f },	// �Ʒ���

{ -0.7f, -0.1f, 0.1f },
{ -0.7f, -0.3f, 0.1f },
{ -0.7f, -0.1f, -0.1f },
{ -0.7f, -0.3f, -0.1f },	// ������

{ -0.5f, -0.1f, 0.1f },
{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.1f, -0.1f },
{ -0.5f, -0.3f, -0.1f },	// ������*/

// 4x1 ��ǥ ����
/*{-0.3f, -0.1f, -0.1f },
{ -0.3f, -0.3f, -0.1f },
{ -0.5f, -0.1f, -0.1f },
{ -0.5f, -0.3f, -0.1f },	// �ո�

{ -0.3f, -0.1f, 0.1f },
{ -0.3f, -0.3f, 0.1f },
{ -0.5f, -0.1f, 0.1f },
{ -0.5f, -0.3f, 0.1f },	// �޸�

{ -0.3f, -0.1f, 0.1f },
{ -0.3f, -0.1f, -0.1f },
{ -0.5f, -0.1f, 0.1f },
{ -0.5f, -0.1f, -0.1f },	// ����

{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.3f, -0.1f },
{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.3f, -0.1f },	// �Ʒ���

{ -0.5f, -0.1f, 0.1f },
{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.1f, -0.1f },
{ -0.5f, -0.3f, -0.1f },	// ������

{ -0.3f, -0.1f, 0.1f },
{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.1f, -0.1f },
{ -0.3f, -0.3f, -0.1f },	// ������*/

// 4x2 ��ǥ ����
/*{-0.1f, -0.1f, -0.1f },
{ -0.1f, -0.3f, -0.1f },
{ -0.3f, -0.1f, -0.1f },
{ -0.3f, -0.3f, -0.1f },	// �ո�

{ -0.1f, -0.1f, 0.1f },
{ -0.1f, -0.3f, 0.1f },
{ -0.3f, -0.1f, 0.1f },
{ -0.3f, -0.3f, 0.1f },	// �޸�

{ -0.1f, -0.1f, 0.1f },
{ -0.1f, -0.1f, -0.1f },
{ -0.3f, -0.1f, 0.1f },
{ -0.3f, -0.1f, -0.1f },	// ����

{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.3f, -0.1f },
{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.3f, -0.1f },	// �Ʒ���

{ -0.3f, -0.1f, 0.1f },
{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.1f, -0.1f },
{ -0.3f, -0.3f, -0.1f },	// ������

{ -0.1f, -0.1f, 0.1f },
{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.1f, -0.1f },
{ -0.1f, -0.3f, -0.1f },	// ������*/

// 4x3 ��ǥ ����
/*{0.1f, -0.1f, -0.1f },
{ 0.1f, -0.3f, -0.1f },
{ -0.1f, -0.1f, -0.1f },
{ -0.1f, -0.3f, -0.1f },	// �ո�

{ 0.1f, -0.1f, 0.1f },
{ 0.1f, -0.3f, 0.1f },
{ -0.1f, -0.1f, 0.1f },
{ -0.1f, -0.3f, 0.1f },	// �޸�

{ 0.1f, -0.1f, 0.1f },
{ 0.1f, -0.1f, -0.1f },
{ -0.1f, -0.1f, 0.1f },
{ -0.1f, -0.1f, -0.1f },	// ����

{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.3f, -0.1f },
{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.3f, -0.1f },	// �Ʒ���

{ -0.1f, -0.1f, 0.1f },
{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.1f, -0.1f },
{ -0.1f, -0.3f, -0.1f },	// ������

{ 0.1f, -0.1f, 0.1f },
{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.1f, -0.1f },
{ 0.1f, -0.3f, -0.1f },	// ������*/

// 4x4 ��ǥ ����
/*{0.3f, -0.1f, -0.1f },
{ 0.3f, -0.3f, -0.1f },
{ 0.1f, -0.1f, -0.1f },
{ 0.1f, -0.3f, -0.1f },	// �ո�

{ 0.3f, -0.1f, 0.1f },
{ 0.3f, -0.3f, 0.1f },
{ 0.1f, -0.1f, 0.1f },
{ 0.1f, -0.3f, 0.1f },	// �޸�

{ 0.3f, -0.1f, 0.1f },
{ 0.3f, -0.1f, -0.1f },
{ 0.1f, -0.1f, 0.1f },
{ 0.1f, -0.1f, -0.1f },	// ����

{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.3f, -0.1f },
{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.3f, -0.1f },	// �Ʒ���

{ 0.1f, -0.1f, 0.1f },
{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.1f, -0.1f },
{ 0.1f, -0.3f, -0.1f },	// ������

{ 0.3f, -0.1f, 0.1f },
{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.1f, -0.1f },
{ 0.3f, -0.3f, -0.1f },	// ������*/

// 4x5 ��ǥ ����
/*{ 0.5f, -0.1f, -0.1f },
{ 0.5f, -0.3f, -0.1f },
{ 0.3f, -0.1f, -0.1f },
{ 0.3f, -0.3f, -0.1f },	// �ո�

{ 0.5f, -0.1f, 0.1f },
{ 0.5f, -0.3f, 0.1f },
{ 0.3f, -0.1f, 0.1f },
{ 0.3f, -0.3f, 0.1f },	// �޸�

{ 0.5f, -0.1f, 0.1f },
{ 0.5f, -0.1f, -0.1f },
{ 0.3f, -0.1f, 0.1f },
{ 0.3f, -0.1f, -0.1f },	// ����

{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.3f, -0.1f },
{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.3f, -0.1f },	// �Ʒ���

{ 0.3f, -0.1f, 0.1f },
{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.1f, -0.1f },
{ 0.3f, -0.3f, -0.1f },	// ������

{ 0.5f, -0.1f, 0.1f },
{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.1f, -0.1f },
{ 0.5f, -0.3f, -0.1f },	// ������*/

// 4x6 ��ǥ ����
/*{0.7f, -0.1f, -0.1f },
{ 0.7f, -0.3f, -0.1f },
{ 0.5f, -0.1f, -0.1f },
{ 0.5f, -0.3f, -0.1f },	// �ո�

{ 0.7f, -0.1f, 0.1f },
{ 0.7f, -0.3f, 0.1f },
{ 0.5f, -0.1f, 0.1f },
{ 0.5f, -0.3f, 0.1f },	// �޸�

{ 0.7f, -0.1f, 0.1f },
{ 0.7f, -0.1f, -0.1f },
{ 0.5f, -0.1f, 0.1f },
{ 0.5f, -0.1f, -0.1f },	// ����

{ 0.7f, -0.3f, 0.1f },
{ 0.7f, -0.3f, -0.1f },
{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.3f, -0.1f },	// �Ʒ���

{ 0.5f, -0.1f, 0.1f },
{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.1f, -0.1f },
{ 0.5f, -0.3f, -0.1f },	// ������

{ 0.7f, -0.1f, 0.1f },
{ 0.7f, -0.3f, 0.1f },
{ 0.7f, -0.1f, -0.1f },
{ 0.7f, -0.3f, -0.1f },	// ������*/

//---------------------
// 5x0 ��ǥ ����
/*{ -0.5f, -0.3f, -0.1f },
{ -0.5f, -0.5f, -0.1f },
{ -0.7f, -0.3f, -0.1f },
{ -0.7f, -0.5f, -0.1f },	// �ո�

{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.5f, 0.1f },
{ -0.7f, -0.3f, 0.1f },
{ -0.7f, -0.5f, 0.1f },	// �޸�

{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.3f, -0.1f },
{ -0.7f, -0.3f, 0.1f },
{ -0.7f, -0.3f, -0.1f },	// ����

{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.5f, -0.1f },
{ -0.7f, -0.5f, 0.1f },
{ -0.7f, -0.5f, -0.1f },	// �Ʒ���

{ -0.7f, -0.3f, 0.1f },
{ -0.7f, -0.5f, 0.1f },
{ -0.7f, -0.3f, -0.1f },
{ -0.7f, -0.5f, -0.1f },	// ������

{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.3f, -0.1f },
{ -0.5f, -0.5f, -0.1f },	// ������*/

// 5x1 ��ǥ ����
/*{-0.3f, -0.3f, -0.1f },
{ -0.3f, -0.5f, -0.1f },
{ -0.5f, -0.3f, -0.1f },
{ -0.5f, -0.5f, -0.1f },	// �ո�

{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.5f, 0.1f },
{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.5f, 0.1f },	// �޸�

{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.3f, -0.1f },
{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.3f, -0.1f },	// ����

{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.5f, -0.1f },
{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.5f, -0.1f },	// �Ʒ���

{ -0.5f, -0.3f, 0.1f },
{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.3f, -0.1f },
{ -0.5f, -0.5f, -0.1f },	// ������

{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.3f, -0.1f },
{ -0.3f, -0.5f, -0.1f },	// ������*/

// 5x2 ��ǥ ����
/*{-0.1f, -0.3f, -0.1f },
{ -0.1f, -0.5f, -0.1f },
{ -0.3f, -0.3f, -0.1f },
{ -0.3f, -0.5f, -0.1f },	// �ո�

{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.5f, 0.1f },
{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.5f, 0.1f },	// �޸�

{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.3f, -0.1f },
{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.3f, -0.1f },	// ����

{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.5f, -0.1f },
{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.5f, -0.1f },	// �Ʒ���

{ -0.3f, -0.3f, 0.1f },
{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.3f, -0.1f },
{ -0.3f, -0.5f, -0.1f },	// ������

{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.3f, -0.1f },
{ -0.1f, -0.5f, -0.1f },	// ������*/

// 5x3 ��ǥ ����
/*{0.1f, -0.3f, -0.1f },
{ 0.1f, -0.5f, -0.1f },
{ -0.1f, -0.3f, -0.1f },
{ -0.1f, -0.5f, -0.1f },	// �ո�

{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.5f, 0.1f },
{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.5f, 0.1f },	// �޸�

{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.3f, -0.1f },
{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.3f, -0.1f },	// ����

{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.5f, -0.1f },
{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.5f, -0.1f },	// �Ʒ���

{ -0.1f, -0.3f, 0.1f },
{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.3f, -0.1f },
{ -0.1f, -0.5f, -0.1f },	// ������

{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.3f, -0.1f },
{ 0.1f, -0.5f, -0.1f },	// ������*/

// 5x4 ��ǥ ����
/*{0.3f, -0.3f, -0.1f },
{ 0.3f, -0.5f, -0.1f },
{ 0.1f, -0.3f, -0.1f },
{ 0.1f, -0.5f, -0.1f },	// �ո�

{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.5f, 0.1f },
{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.5f, 0.1f },	// �޸�

{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.3f, -0.1f },
{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.3f, -0.1f },	// ����

{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.5f, -0.1f },
{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.5f, -0.1f },	// �Ʒ���

{ 0.1f, -0.3f, 0.1f },
{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.3f, -0.1f },
{ 0.1f, -0.5f, -0.1f },	// ������

{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.3f, -0.1f },
{ 0.3f, -0.5f, -0.1f },	// ������*/

// 5x6 ��ǥ ����x5 ��ǥ ����
/*{0.5f, -0.3f, -0.1f },
{ 0.5f, -0.5f, -0.1f },
{ 0.3f, -0.3f, -0.1f },
{ 0.3f, -0.5f, -0.1f },	// �ո�

{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.5f, 0.1f },
{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.5f, 0.1f },	// �޸�

{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.3f, -0.1f },
{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.3f, -0.1f },	// ����

{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.5f, -0.1f },
{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.5f, -0.1f },	// �Ʒ���

{ 0.3f, -0.3f, 0.1f },
{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.3f, -0.1f },
{ 0.3f, -0.5f, -0.1f },	// ������

{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.3f, -0.1f },
{ 0.5f, -0.5f, -0.1f },	// ������*/

// 5
/*{0.7f, -0.3f, -0.1f },
{ 0.7f, -0.5f, -0.1f },
{ 0.5f, -0.3f, -0.1f },
{ 0.5f, -0.5f, -0.1f },	// �ո�

{ 0.7f, -0.3f, 0.1f },
{ 0.7f, -0.5f, 0.1f },
{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.5f, 0.1f },	// �޸�

{ 0.7f, -0.3f, 0.1f },
{ 0.7f, -0.3f, -0.1f },
{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.3f, -0.1f },	// ����

{ 0.7f, -0.5f, 0.1f },
{ 0.7f, -0.5f, -0.1f },
{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.5f, -0.1f },	// �Ʒ���

{ 0.5f, -0.3f, 0.1f },
{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.3f, -0.1f },
{ 0.5f, -0.5f, -0.1f },	// ������

{ 0.7f, -0.3f, 0.1f },
{ 0.7f, -0.5f, 0.1f },
{ 0.7f, -0.3f, -0.1f },
{ 0.7f, -0.5f, -0.1f },	// ������*/

//---------------------
// 6x0 ��ǥ ����
/*{ -0.5f, -0.5f, -0.1f },
{ -0.5f, -0.7f, -0.1f },
{ -0.7f, -0.5f, -0.1f },
{ -0.7f, -0.7f, -0.1f },	// �ո�

{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.7f, 0.1f },
{ -0.7f, -0.5f, 0.1f },
{ -0.7f, -0.7f, 0.1f },	// �޸�

{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.5f, -0.1f },
{ -0.7f, -0.5f, 0.1f },
{ -0.7f, -0.5f, -0.1f },	// ����

{ -0.5f, -0.7f, 0.1f },
{ -0.5f, -0.7f, -0.1f },
{ -0.7f, -0.7f, 0.1f },
{ -0.7f, -0.7f, -0.1f },	// �Ʒ���

{ -0.7f, -0.5f, 0.1f },
{ -0.7f, -0.7f, 0.1f },
{ -0.7f, -0.5f, -0.1f },
{ -0.7f, -0.7f, -0.1f },	// ������

{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.7f, 0.1f },
{ -0.5f, -0.5f, -0.1f },
{ -0.5f, -0.7f, -0.1f },	// ������*/

// 6x1 ��ǥ ����
/*{-0.3f, -0.5f, -0.1f },
{ -0.3f, -0.7f, -0.1f },
{ -0.5f, -0.5f, -0.1f },
{ -0.5f, -0.7f, -0.1f },	// �ո�

{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.7f, 0.1f },
{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.7f, 0.1f },	// �޸�

{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.5f, -0.1f },
{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.5f, -0.1f },	// ����

{ -0.3f, -0.7f, 0.1f },
{ -0.3f, -0.7f, -0.1f },
{ -0.5f, -0.7f, 0.1f },
{ -0.5f, -0.7f, -0.1f },	// �Ʒ���

{ -0.5f, -0.5f, 0.1f },
{ -0.5f, -0.7f, 0.1f },
{ -0.5f, -0.5f, -0.1f },
{ -0.5f, -0.7f, -0.1f },	// ������

{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.7f, 0.1f },
{ -0.3f, -0.5f, -0.1f },
{ -0.3f, -0.7f, -0.1f },	// ������*/

// 6x2 ��ǥ ����
/*{-0.1f, -0.5f, -0.1f },
{ -0.1f, -0.7f, -0.1f },
{ -0.3f, -0.5f, -0.1f },
{ -0.3f, -0.7f, -0.1f },	// �ո�

{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.7f, 0.1f },
{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.7f, 0.1f },	// �޸�

{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.5f, -0.1f },
{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.5f, -0.1f },	// ����

{ -0.1f, -0.7f, 0.1f },
{ -0.1f, -0.7f, -0.1f },
{ -0.3f, -0.7f, 0.1f },
{ -0.3f, -0.7f, -0.1f },	// �Ʒ���

{ -0.3f, -0.5f, 0.1f },
{ -0.3f, -0.7f, 0.1f },
{ -0.3f, -0.5f, -0.1f },
{ -0.3f, -0.7f, -0.1f },	// ������

{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.7f, 0.1f },
{ -0.1f, -0.5f, -0.1f },
{ -0.1f, -0.7f, -0.1f },	// ������*/

// 6x3 ��ǥ ����
/*{0.1f, -0.5f, -0.1f },
{ 0.1f, -0.7f, -0.1f },
{ -0.1f, -0.5f, -0.1f },
{ -0.1f, -0.7f, -0.1f },	// �ո�

{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.7f, 0.1f },
{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.7f, 0.1f },	// �޸�

{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.5f, -0.1f },
{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.5f, -0.1f },	// ����

{ 0.1f, -0.7f, 0.1f },
{ 0.1f, -0.7f, -0.1f },
{ -0.1f, -0.7f, 0.1f },
{ -0.1f, -0.7f, -0.1f },	// �Ʒ���

{ -0.1f, -0.5f, 0.1f },
{ -0.1f, -0.7f, 0.1f },
{ -0.1f, -0.5f, -0.1f },
{ -0.1f, -0.7f, -0.1f },	// ������

{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.7f, 0.1f },
{ 0.1f, -0.5f, -0.1f },
{ 0.1f, -0.7f, -0.1f },	// ������*/

// 6x4 ��ǥ ����
/*{0.3f, -0.5f, -0.1f },
{ 0.3f, -0.7f, -0.1f },
{ 0.1f, -0.5f, -0.1f },
{ 0.1f, -0.7f, -0.1f },	// �ո�

{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.7f, 0.1f },
{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.7f, 0.1f },	// �޸�

{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.5f, -0.1f },
{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.5f, -0.1f },	// ����

{ 0.3f, -0.7f, 0.1f },
{ 0.3f, -0.7f, -0.1f },
{ 0.1f, -0.7f, 0.1f },
{ 0.1f, -0.7f, -0.1f },	// �Ʒ���

{ 0.1f, -0.5f, 0.1f },
{ 0.1f, -0.7f, 0.1f },
{ 0.1f, -0.5f, -0.1f },
{ 0.1f, -0.7f, -0.1f },	// ������

{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.7f, 0.1f },
{ 0.3f, -0.5f, -0.1f },
{ 0.3f, -0.7f, -0.1f },	// ������*/

// 6x5 ��ǥ ����
/*{0.5f, -0.5f, -0.1f },
{ 0.5f, -0.7f, -0.1f },
{ 0.3f, -0.5f, -0.1f },
{ 0.3f, -0.7f, -0.1f },	// �ո�

	{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.7f, 0.1f },
{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.7f, 0.1f },	// �޸�

{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.5f, -0.1f },
{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.5f, -0.1f },	// ����

{ 0.5f, -0.7f, 0.1f },
{ 0.5f, -0.7f, -0.1f },
{ 0.3f, -0.7f, 0.1f },
{ 0.3f, -0.7f, -0.1f },	// �Ʒ���

{ 0.3f, -0.5f, 0.1f },
{ 0.3f, -0.7f, 0.1f },
{ 0.3f, -0.5f, -0.1f },
{ 0.3f, -0.7f, -0.1f },	// ������

{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.7f, 0.1f },
{ 0.5f, -0.5f, -0.1f },
{ 0.5f, -0.7f, -0.1f },	// ������*/

// 6x6 ��ǥ ����
/*{0.7f, -0.5f, -0.1f },
{ 0.7f, -0.7f, -0.1f },
{ 0.5f, -0.5f, -0.1f },
{ 0.5f, -0.7f, -0.1f },	// �ո�

{ 0.7f, -0.5f, 0.1f },
{ 0.7f, -0.7f, 0.1f },
{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.7f, 0.1f },	// �޸�

{ 0.7f, -0.5f, 0.1f },
{ 0.7f, -0.5f, -0.1f },
{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.5f, -0.1f },	// ����

{ 0.7f, -0.7f, 0.1f },
{ 0.7f, -0.7f, -0.1f },
{ 0.5f, -0.7f, 0.1f },
{ 0.5f, -0.7f, -0.1f },	// �Ʒ���

{ 0.5f, -0.5f, 0.1f },
{ 0.5f, -0.7f, 0.1f },
{ 0.5f, -0.5f, -0.1f },
{ 0.5f, -0.7f, -0.1f },	// ������

{ 0.7f, -0.5f, 0.1f },
{ 0.7f, -0.7f, 0.1f },
{ 0.7f, -0.5f, -0.1f },
{ 0.7f, -0.7f, -0.1f },	// ������*/