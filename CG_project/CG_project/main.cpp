#include "header.h"

//������ ���α׷� ��ü
GLuint shaderProgramID;

//������ ���� �� �ݹ��Լ� ����
void main(int argc, char** argv)
{
	//glut �ʱ�ȭ
	glutInit(&argc, argv);
	//���÷��� ��� ����
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	//������ ��ġ ����
	glutInitWindowPosition(50, 50);
	//������ ũ�� ����
	glutInitWindowSize(600, 600);
	//������ ���� �� �̸� ����
	glutCreateWindow("AniPang");

	//GLEW �ʱ�ȭ
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("Unable to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("GLEW Initialized\n");

	//���� ����
	glEnable(GL_DEPTH_TEST);

	//���̴� ���α׷� ����
	shaderProgramID = MakeShaderProgram();

	InitBlock();

	//���� �ʱ�ȭ
	InitBuffer();

	//�ݹ��Լ� ����
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(10, Timer, 1);
	//�̺�Ʈ ó�� ����
	glutMainLoop();
}