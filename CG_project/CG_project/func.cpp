#include "header.h"

//셰이터 프로그램 객체
extern GLuint shaderProgramID;

//그리기 콜백 함수
GLvoid Display(GLvoid)
{
	//초기 색깔 지정
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//설정된 색으로 전체 칠하기
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//좌표축 그리기
	drawCoord();

	// Frame 그리기
	drawFrame();
	
	//화면에 출력하기
	glutSwapBuffers();
}

//크기 변경시 다시 그리기 콜백 함수
GLvoid Reshape(int w, int h)
{
	//openGL 뷰포트 설정
	glViewport(0, 0, w, h);
}

//버퍼 초기화
void InitBuffer(void)
{
	InitCoordBuffer();

	InitFrameBuffer();
}

//키보드 입력 콜백함수
void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	default:
		break;
	}

	//그리기 콜백함수 재호출
	glutPostRedisplay();
}

//타이머 콜백함수
void Timer(int value)
{
	//타이머 함수 재호출
	glutTimerFunc(10, Timer, 1);

	//그리기 콜백함수 재호출
	glutPostRedisplay();
}