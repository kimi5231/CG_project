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

// ī�޶� ����
extern GLfloat cam_radiansY;
extern GLfloat cam_radiansX;

extern GLfloat cam_x;
extern GLfloat cam_y;

//�׸��� �ݹ� �Լ�
GLvoid Display(GLvoid)
{
	//�ʱ� ���� ����
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
			if (blockseat[i][j].fill)
			{
				InitBlockBuffer(i, j);
				drawBlock(block[i][j].transX, block[i][j].transY);
			}
		}
	}

	drawSelect();
	
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

	InitSelectBuffer();
}

//Ű���� �Է� �ݹ��Լ�
void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (select.x == i && select.y == j)
				{
					select.i[select.count] = i;
					select.j[select.count++] = j;
					if (select.count == 2)
					{
						ChangeBlock();
						break;
					}
				}
			}
		}
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
		select.y--;
		break;
	case GLUT_KEY_LEFT:
		select.y++;
		break;
	case GLUT_KEY_UP:
		select.x--;
		break;
	case GLUT_KEY_DOWN:
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

	//Ÿ�̸� �Լ� ��ȣ��
	glutTimerFunc(10, Timer, 1);

	//�׸��� �ݹ��Լ� ��ȣ��
	glutPostRedisplay();
}