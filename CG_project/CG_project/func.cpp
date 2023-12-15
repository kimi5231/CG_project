#include "header.h"

//셰이터 프로그램 객체
extern GLuint shaderProgramID;

//block
extern BlockSeat blockseat[7][7];
extern Block block[7][7];

int count = 0;
int i = 6;

bool make = true;
bool del = false;

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

	//블록 그리기
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if(blockseat[i][j].fill)
				drawBlock(block[i][j].transX, block[i][j].transY);
		}
	}
	
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

	InitBlockBuffer();
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

	//타이머 함수 재호출
	glutTimerFunc(10, Timer, 1);

	//그리기 콜백함수 재호출
	glutPostRedisplay();
}