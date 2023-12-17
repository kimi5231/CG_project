#include "header.h"

//셰이터 프로그램 객체
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

// 카메라 각도
extern GLfloat cam_radiansY;
extern GLfloat cam_radiansX;

extern GLfloat cam_x;
extern GLfloat cam_y;

//그리기 콜백 함수
GLvoid Display(GLvoid)
{
	//초기 색깔 지정
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//설정된 색으로 전체 칠하기
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Frame 그리기
	drawFrame();

	//블록 그리기
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
	
	//화면에 출력하기
	glutSwapBuffers();
}

//크기 변경시 다시 그리기 콜백 함수
GLvoid Reshape(int w, int h)
{
	//openGL 뷰포트 설정
	glViewport(0, 0, w, h);
}

//초기화
void Init(void)
{
	//블록 정보 초기화
	InitBlockInformation();
	//선택 인터페이스 초기화
	InitSelect();
	//이펙트 초기화
	InitEffect();

	//버퍼 초기화
	InitBuffer();
}

//버퍼 초기화
void InitBuffer(void)
{
	InitCoordBuffer();

	InitFrameBuffer();

	InitSelectBuffer();

	InitEffectBuffer();
}

//키보드 입력 콜백함수
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

	//그리기 콜백함수 재호출
	glutPostRedisplay();
}

//특수키 입력 콜백함수
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

	//그리기 콜백함수 재호출
	glutPostRedisplay();
}

//타이머 콜백함수
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

	//타이머 함수 재호출
	glutTimerFunc(10, Timer, 1);

	//그리기 콜백함수 재호출
	glutPostRedisplay();
}