#include "header.h"

//������ ���α׷� ��ü
extern GLuint shaderProgramID;

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
	//Ÿ�̸� �Լ� ��ȣ��
	glutTimerFunc(10, Timer, 1);

	//�׸��� �ݹ��Լ� ��ȣ��
	glutPostRedisplay();
}