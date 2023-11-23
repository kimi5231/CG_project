#include "header.h"

//셰이터 프로그램 객체
GLuint shaderProgramID;

//윈도우 생성 및 콜백함수 지정
void main(int argc, char** argv)
{
	//glut 초기화
	glutInit(&argc, argv);
	//디스플레이 모드 설정
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	//윈도우 위치 지정
	glutInitWindowPosition(50, 50);
	//윈도우 크기 지정
	glutInitWindowSize(600, 600);
	//윈도우 생성 및 이름 지정
	glutCreateWindow("실습1-18");

	//GLEW 초기화
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("Unable to initialize GLEW\n");
		exit(EXIT_FAILURE);
	}
	else
		printf("GLEW Initialized\n");

	//은면 제거
	glEnable(GL_DEPTH_TEST);

	//셰이더 프로그램 생성
	shaderProgramID = MakeShaderProgram();

	//버퍼 초기화
	InitBuffer();

	//콜백함수 지정
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(10, Timer, 1);
	//이벤트 처리 시작
	glutMainLoop();
}