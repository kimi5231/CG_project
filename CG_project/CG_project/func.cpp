#include "header.h"

//������ ���α׷� ��ü
extern GLuint shaderProgramID;

//block
extern BlockSeat blockseat[7][7];
extern Block block[7][7];

int count = 0;
int i = 6;

bool make = true;
bool del = false;

//�׸��� �ݹ� �Լ�
GLvoid Display(GLvoid)
{
	//�ʱ� ���� ����
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//������ ������ ��ü ĥ�ϱ�
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//��ǥ�� �׸���
	drawCoord();

	// Frame �׸���
	drawFrame();

	//��� �׸���
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if(blockseat[i][j].fill)
				drawBlock(block[i][j].transX, block[i][j].transY);
		}
	}
	
	//ȭ�鿡 ����ϱ�
	glutSwapBuffers();
}

//ũ�� ����� �ٽ� �׸��� �ݹ� �Լ�
GLvoid Reshape(int w, int h)
{
	//openGL ����Ʈ ����
	glViewport(0, 0, w, h);
}

//���� �ʱ�ȭ
void InitBuffer(void)
{
	InitCoordBuffer();

	InitFrameBuffer();

	InitBlockBuffer();
}

//Ű���� �Է� �ݹ��Լ�
void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	default:
		break;
	}

	//�׸��� �ݹ��Լ� ��ȣ��
	glutPostRedisplay();
}

//Ÿ�̸� �ݹ��Լ�
void Timer(int value)
{
	if (make)
	{
		CheckEmptySeat(i);
		if (i == 0)
		{
			make = false;
			del = true;
			i = 6;
		}
		i--;
	}

	if (del)
	{
		CheckDelBlock();
	}

	if (count == 5)
	{
		
		count = 0;
	}

	MoveBlock();

	count++;

	//Ÿ�̸� �Լ� ��ȣ��
	glutTimerFunc(10, Timer, 1);

	//�׸��� �ݹ��Լ� ��ȣ��
	glutPostRedisplay();
}