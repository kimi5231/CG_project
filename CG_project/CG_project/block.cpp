#include "header.h"

//���̴� ���α׷� ��ü
extern GLuint shaderProgramID;

//block VAO, VBO
GLuint VAO_block;
GLuint VBO_block_position;
GLuint VBO_block_color;

//select VAO, VBO
GLuint VAO_select;
GLuint VBO_select_position;
GLuint VBO_select_color;

//��ȯ ���
extern glm::mat4 model;

//block
BlockSeat blockseat[7][7];

Block block[7][7];

int save_Wblock_inform[7];
int save_Lblock_inform[7];
int Wblockcount = 0;
int Lblockcount = 0;

extern bool make;
extern bool del;

const GLfloat blockPos[] = {
	-0.5f, 0.7f, -0.1f,
	-0.5f, 0.5f, -0.1f,
	-0.7f, 0.7f, -0.1f,
	-0.7f, 0.5f, -0.1f,	// �ո�

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.5f, 0.1f,
	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.5f, 0.1f,	// �޸�

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.7f, -0.1f,
	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.7f, -0.1f,	// ����

	-0.5f, 0.5f, 0.1f,
	-0.5f, 0.5f, -0.1f,
	-0.7f, 0.5f, 0.1f,
	-0.7f, 0.5f, -0.1f,	// �Ʒ���

	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.5f, 0.1f,
	-0.7f, 0.7f, -0.1f,
	-0.7f, 0.5f, -0.1f,	// ������

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.5f, 0.1f,
	-0.5f, 0.7f, -0.1f,
	-0.5f, 0.5f, -0.1f,	// ������
};

const float blockColor1[] = {
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float blockColor2[] = {
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float blockColor3[] = {
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float blockColor4[] = {
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float blockColor5[] = {
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float blockColor6[] = {
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float blockColor7[] = {
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float boomColor1[] = {
	0.5f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float boomColor2[] = {
	0.5f, 0.5f, 0.0f,
	0.5f, 0.5f, 0.0f,
	0.5f, 0.5f, 0.0f,
	0.5f, 0.5f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float boomColor3[] = {
	0.5f, 0.0f, 0.5f,
	0.5f, 0.0f, 0.5f,
	0.5f, 0.0f, 0.5f,
	0.5f, 0.0f, 0.5f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float boomColor4[] = {
	0.0f, 0.5f, 0.0f,
	0.0f, 0.5f, 0.0f,
	0.0f, 0.5f, 0.0f,
	0.0f, 0.5f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float boomColor5[] = {
	0.0f, 0.5f, 0.5f,
	0.0f, 0.5f, 0.5f,
	0.0f, 0.5f, 0.5f,
	0.0f, 0.5f, 0.5f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float boomColor6[] = {
	0.0f, 0.0f, 0.5f,
	0.0f, 0.0f, 0.5f,
	0.0f, 0.0f, 0.5f,
	0.0f, 0.0f, 0.5f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float boomColor7[] = {
	0.5f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

const float randomColor[] = {
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

//select
Select select;

const GLfloat selectPos[] = {
	-0.5f, 0.7f, -0.15f,
	-0.5f, 0.5f, -0.15f,

	-0.5f, 0.7f, -0.15f,
	-0.7f, 0.7f, -0.15f,

	-0.5f, 0.5f, -0.15f,
	-0.7f, 0.5f, -0.15f,

	-0.7f, 0.7f, -0.15f,
	-0.7f, 0.5f, -0.15f
};

const float selectColor[] = {
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f
};

//��� �� ��� �ڸ� ���� �ʱ�ȭ
void InitBlockInformation(void)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			blockseat[i][j].transX = j * 0.2;
			blockseat[i][j].transY = i * -0.2;
			blockseat[i][j].fill = false;
			block[i][j].transX = j * 0.2;
		}
	}
}

//���� �������̽� �ʱ�ȭ
void InitSelect(void)
{
	select.x = 0;
	select.y = 0;
	select.count = 0;
}

//��� ���� �ʱ�ȭ
void InitBlockBuffer(int i, int j)
{
	//VAO ��ü ���� �� ���ε�
	glGenVertexArrays(1, &VAO_block);
	glBindVertexArray(VAO_block);

	//���ؽ� ��ġ VBO ��ü ����
	glGenBuffers(1, &VBO_block_position);

	//���ؽ� ��ġ VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_block_position);
	//���ؽ� ��ġ ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(blockPos), blockPos, GL_STATIC_DRAW);
	//���ؽ� ��ġ ������ �迭 ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ��ġ �迭 ���
	glEnableVertexAttribArray(0);

	//���ؽ� ���� VBO ��ü ����
	glGenBuffers(1, &VBO_block_color);

	//���ؽ� ���� VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_block_color);
	//���ؽ� ���� ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(block[i][j].texture), block[i][j].texture, GL_STATIC_DRAW);
	//���ؽ� ���� ������ �迭 ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ���� �迭 ���
	glEnableVertexAttribArray(1);
}

//��� �׸���
void drawBlock(float x, float y)
{
	//����� ���̴� ���α׷� ����
	glUseProgram(shaderProgramID);

	//��ȯ ��� ���� ��ķ� �ʱ�ȭ
	model = glm::mat4(1.0f);
	//x���� �������� -30����ŭ ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//y���� �������� -30����ŭ ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//0.9 ũ��� ������
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	//�̵�
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	//��ȯ ��� �����ϱ�
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	VeiwAndProjectionTransform();

	//����� VAO ��ü ���ε�
	glBindVertexArray(VAO_block);
	//��� �׸���
	for (int i = 0; i < 24; i += 4)
	{
		glDrawArrays(GL_TRIANGLES, i, 3);
		glDrawArrays(GL_TRIANGLES, i + 1, 3);
	}
}

//��� �ڸ��� ����ִ��� Ȯ��
void CheckEmptySeat(int i)
{
	for (int j = 6; j >= 0; j--)
	{
		if (blockseat[i][j].fill == false)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				if (blockseat[k][j].fill == true)
				{
					block[i][j] = block[k][j];
					blockseat[k][j].fill = false;
					blockseat[i][j].fill = true;
					return;
				}
			}
			MakeBlock(i, j);
		}
	}
}

//��� ����
void MakeBlock(int i, int j)
{
	block[i][j].transY = 0.2;
	block[i][j].type = rand() % 7 + 1;
	if (block[i][j].type == 1)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = blockColor1[k];
	}
	else if (block[i][j].type == 2)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = blockColor2[k];
	}
	else if (block[i][j].type == 3)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = blockColor3[k];
	}
	else if (block[i][j].type == 4)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = blockColor4[k];
	}
	else if (block[i][j].type == 5)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = blockColor5[k];
	}
	else if (block[i][j].type == 6)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = blockColor6[k];
	}
	else if (block[i][j].type == 7)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = blockColor7[k];
	}
	block[i][j].special = 1;
	blockseat[i][j].fill = true;
}

//��� �̵�
void MoveBlock(void)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (blockseat[i][j].fill && block[i][j].transY > blockseat[i][j].transY)
				block[i][j].transY -= 0.01;
			else
				block[i][j].transY = blockseat[i][j].transY;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (blockseat[i][j].fill && block[i][j].transY != blockseat[i][j].transY)
				return;
		}
	}

	make = false;
	del = true;
}

//�ı��� ��� Ȯ��
void CheckDelBlock(void)
{
	for (int k = 1; k < 8; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			//���� �ı� ���� üũ
			for (int j = 0; j < 7; j++)
			{
				if (block[i][j].type == k && Wblockcount == 0)
				{
					save_Wblock_inform[Wblockcount] = j;
					Wblockcount++;
				}
				else if (j > 0 && block[i][j].type == k && block[i][j - 1].type == k)
				{
					save_Wblock_inform[Wblockcount] = j;
					Wblockcount++;
				}
				else if (block[i][j].type != k && Wblockcount < 3)
					Wblockcount = 0;
				else if (block[i][j].type != k && Wblockcount == 3)
				{
					if (block[i][j + 1].type == k && block[i][j + 2].type == k && block[i][j + 3].type == k)
					{
						for (int l = j+1; l < 7; l++)
						{
							save_Wblock_inform[Wblockcount] = l;
							Wblockcount++;
						}
					}
					break;
				}
			}

			//���� �ı� ���� üũ
			for (int j = 0; j < 7; j++)
			{
				if (block[j][i].type == k && Lblockcount == 0)
				{
					save_Lblock_inform[Lblockcount] = j;
					Lblockcount++;
				}
				else if (j > 0 && block[j][i].type == k && block[j - 1][i].type == k)
				{
					save_Lblock_inform[Lblockcount] = j;
					Lblockcount++;
				}
				else if (block[j][i].type != k && Lblockcount < 3)
					Lblockcount = 0;
				else if (block[j][i].type != k && Lblockcount == 3)
				{
					if (block[j + 1][i].type == k && block[j + 2][i].type == k && block[j + 3][i].type == k)
					{
						for (int l = j+1; l < 7; l++)
						{
							save_Lblock_inform[Lblockcount] = l;
							Lblockcount++;
						}
					}
					break;
				}
			}

			//���� ��� �ı�
			if (Wblockcount >= 3)
			{
				for (int j = 0; j < Wblockcount; j++)
				{
					if (block[i][save_Wblock_inform[j]].type == k)
						DelBlock(i, save_Wblock_inform[j]);
				}
			}

			//���� ��� �ı�
			if (Lblockcount >= 3)
			{
				for (int j = 0; j < Lblockcount; j++)
				{
					if (block[save_Lblock_inform[j]][i].type == k)
						DelBlock(save_Lblock_inform[j], i);
				}
			}

			//��ź�� ����
			if (Wblockcount == 4)
				MakeBoomPang(i, save_Wblock_inform[0]);

			if (Lblockcount == 4)
				MakeBoomPang(save_Lblock_inform[0], i);

			//������ ����
			if (Wblockcount == 5)
				MakeRandomPang(i, save_Wblock_inform[0]);

			if (Lblockcount == 5)
				MakeRandomPang(save_Lblock_inform[0], i);

			Wblockcount = 0;
			Lblockcount = 0;
		}
	}
}

//��� �ı�
void DelBlock(int i, int j)
{
	blockseat[i][j].fill = false;
	MakeEffect(i, j);
}

//���� �������̽� ���� �ʱ�ȭ
void InitSelectBuffer(void)
{
	//VAO ��ü ���� �� ���ε�
	glGenVertexArrays(1, &VAO_select);
	glBindVertexArray(VAO_select);

	//���ؽ� ��ġ VBO ��ü ����
	glGenBuffers(1, &VBO_select_position);

	//���ؽ� ��ġ VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_select_position);
	//���ؽ� ��ġ ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(selectPos), selectPos, GL_STATIC_DRAW);
	//���ؽ� ��ġ ������ �迭 ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ��ġ �迭 ���
	glEnableVertexAttribArray(0);

	//���ؽ� ���� VBO ��ü ����
	glGenBuffers(1, &VBO_select_color);

	//���ؽ� ���� VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_select_color);
	//���ؽ� ���� ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(selectColor), selectColor, GL_STATIC_DRAW);
	//���ؽ� ���� ������ �迭 ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ���� �迭 ���
	glEnableVertexAttribArray(1);
}

//���� �������̽� �׸���
void drawSelect(void)
{
	//����� ���̴� ���α׷� ����
	glUseProgram(shaderProgramID);

	//��ȯ ��� ���� ��ķ� �ʱ�ȭ
	model = glm::mat4(1.0f);
	//x���� �������� -30����ŭ ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//y���� �������� -30����ŭ ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//0.9 ũ��� ������
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	//�̵�
	model = glm::translate(model, glm::vec3(blockseat[select.x][select.y].transX, blockseat[select.x][select.y].transY, 0.0f));
	//��ȯ ��� �����ϱ�
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	VeiwAndProjectionTransform();

	//����� VAO ��ü ���ε�
	glBindVertexArray(VAO_select);
	//���� �������̽� �׸���
	glDrawArrays(GL_LINES, 0, 8);
}

//��� ��ȯ
void ChangeBlock(void)
{
	Block temp = block[select.i[0]][select.j[0]];
	block[select.i[0]][select.j[0]] = block[select.i[1]][select.j[1]];
	block[select.i[1]][select.j[1]] = temp;
	temp.transX = block[select.i[0]][select.j[0]].transX;
	temp.transY = block[select.i[0]][select.j[0]].transY;
	block[select.i[0]][select.j[0]].transX = block[select.i[1]][select.j[1]].transX;
	block[select.i[0]][select.j[0]].transY = block[select.i[1]][select.j[1]].transY;
	block[select.i[1]][select.j[1]].transX = temp.transX;
	block[select.i[1]][select.j[1]].transY = temp.transY;
	select.count = 0;
	del = true;
	make = false;
}

//��ź�� ����
void MakeBoomPang(int i, int j)
{
	if (block[i][j].type == 1)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = boomColor1[k];
	}
	else if (block[i][j].type == 2)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = boomColor2[k];
	}
	else if (block[i][j].type == 3)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = boomColor3[k];
	}
	else if (block[i][j].type == 4)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = boomColor4[k];
	}
	else if (block[i][j].type == 5)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = boomColor5[k];
	}
	else if (block[i][j].type == 6)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = boomColor6[k];
	}
	else if (block[i][j].type == 7)
	{
		for (int k = 0; k < 72; k++)
			block[i][j].texture[k] = boomColor7[k];
	}
	block[i][j].special = 2;
	blockseat[i][j].fill = true;
}

//������ ����
void MakeRandomPang(int i, int j)
{
	for (int k = 0; k < 72; k++)
		block[i][j].texture[k] = randomColor[k];
	block[i][j].special = 3;
	blockseat[i][j].fill = true;
}

//��� ����
void SelectBlock(void)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (select.x == i && select.y == j)
			{
				if (block[i][j].special == 2)
					CrashBoomPang(i, j);
				else if (block[i][j].special == 3)
					CrashRandomPang(i, j);
				else
				{
					select.i[select.count] = i;
					select.j[select.count++] = j;
					if (select.count == 2)
					{
						ChangeBlock();
						return;
					}
				}
			}
		}
	}
}

//��ź�� �ı�
void CrashBoomPang(int i, int j)
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	if (i == 0)
	{
		x1 = i;
		x2 = i + 2;
	}
	else if (i == 7)
	{
		x1 = i - 1;
		x2 = i;
	}
	else
	{
		x1 = i - 1;
		x2 = i + 2;
	}

	if (j == 0)
	{
		y1 = j;
		y2 = j + 2;
	}
	else if (j == 7)
	{
		y1 = j - 1;
		y2 = j;
	}
	else
	{
		y1 = j - 1;
		y2 = j + 2;
	}

	for (int k = x1; k < x2; k++)
	{
		for (int l = y1; l < y2; l++)
			DelBlock(k, l);
	}
}

//������ �ı�
void CrashRandomPang(int x, int y)
{
	int type = rand() % 7 + 1;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (block[i][j].type == type)
				DelBlock(i, j);
		}
	}

	DelBlock(x, y);
}