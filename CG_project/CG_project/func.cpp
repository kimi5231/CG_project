#include "header.h"

//������ ���α׷� ��ü
extern GLuint shaderProgramID;

//block
extern BlockSeat blockseat[7][7];
extern Block block[7][7];

int count = 7;

bool make = true;
bool del = false;

//select
extern Select select;
extern GLfloat transX_select;
extern GLfloat transY_select;

//effect
extern Effect effect[7][7][8];

// ī�޶� ����
extern GLfloat cam_radiansY;
extern GLfloat cam_radiansX;

extern GLfloat cam_x;
extern GLfloat cam_y;

//�׸��� �ݹ� �Լ�
GLvoid Display(GLvoid)
{
	//�ʱ� ���� ����
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//������ ������ ��ü ĥ�ϱ�
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Frame �׸���
	drawFrame();

	//��� �׸���
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (blockseat[i][j].fill)
			{
				InitBlockBuffer(i, j);
				drawBlock(block[i][j].transX, block[i][j].transY);
			}
		}
	}

	drawSelect();

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (effect[i][j][k].show == true)
					drawEffect(effect[i][j][k].transX, effect[i][j][k].transY, effect[i][j][k].transZ);
			}
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

//�ʱ�ȭ
void Init(void)
{
	//��� ���� �ʱ�ȭ
	InitBlockInformation();
	//���� �������̽� �ʱ�ȭ
	InitSelect();
	//����Ʈ �ʱ�ȭ
	InitEffect();

	//���� �ʱ�ȭ
	InitBuffer();
}

//���� �ʱ�ȭ
void InitBuffer(void)
{
	InitCoordBuffer();

	InitFrameBuffer();

	InitSelectBuffer();

	InitEffectBuffer();
}

//Ű���� �Է� �ݹ��Լ�
void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		SelectBlock();
		break;
	default:
		break;
	}

	//�׸��� �ݹ��Լ� ��ȣ��
	glutPostRedisplay();
}

//Ư��Ű �Է� �ݹ��Լ�
void SpecialKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		if(select.y > 0)
			select.y--;
		break;
	case GLUT_KEY_LEFT:
		if (select.y < 6)
			select.y++;
		break;
	case GLUT_KEY_UP:
		if (select.x > 0)
			select.x--;
		break;
	case GLUT_KEY_DOWN:
		if (select.x < 6)
			select.x++;
		break;
	default:
		break;
	}

	//�׸��� �ݹ��Լ� ��ȣ��
	glutPostRedisplay();
}

//Ÿ�̸� �ݹ��Լ�
void Timer(int value)
{
	cam_radiansY += 1.0f;

	cam_x += 0.1f;
	cam_y += 0.1f;

	//Play();

	if (make)
	{
		CheckEmptySeat(count);
		if (count == 0)
			count = 7;
		count--;
		MoveBlock();
	}

	if (del)
	{
		CheckDelBlock();
		del = false;
		make = true;
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (effect[i][j][k].show == true)
					MoveEffect(i, j);
			}
		}
	}

	//Ÿ�̸� �Լ� ��ȣ��
	glutTimerFunc(10, Timer, 1);

	//�׸��� �ݹ��Լ� ��ȣ��
	glutPostRedisplay();
}