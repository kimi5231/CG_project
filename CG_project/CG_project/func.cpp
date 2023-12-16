#include "header.h"

//셰이터 프로그램 객체
extern GLuint shaderProgramID;

//block
extern BlockSeat blockseat[7][7];
extern Block block[7][7];

int count = 0;
int i = 7;

bool make = true;
bool del = false;

//select
extern GLfloat transX_select;
extern GLfloat transY_select;

extern int save_select_block_inform[2][2];
int select_block_count = 0;

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
			if (blockseat[i][j].fill)
			{
				InitBlockBuffer(i, j);
				drawBlock(block[i][j].transX, block[i][j].transY);
			}
		}
	}

	drawSelect();
	
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

	InitSelectBuffer();
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

//특수키 입력 콜백함수
void SpecialKeyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		transX_select -= 0.2f;
		break;
	case GLUT_KEY_LEFT:
		transX_select += 0.2f;
		break;
	case GLUT_KEY_UP:
		transY_select += 0.2f;
		break;
	case GLUT_KEY_DOWN:
		transY_select -= 0.2f;
		break;
	case GLUT_KEY_F1:
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (blockseat[i][j].transX == transX_select && blockseat[i][j].transY == transY_select)
				{
					save_select_block_inform[select_block_count][0] = i;
					save_select_block_inform[select_block_count][1] = j;
				}
			}
		}
		select_block_count++;
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
	if (make)
	{
		CheckEmptySeat(i);
		if (i == 0)
			i = 7;
		i--;
		MoveBlock();
	}

	if (del)
	{
		CheckDelBlock();
		del = false;
		make = true;
	}

	if (select_block_count == 2)
	{
		Block temp = block[save_select_block_inform[0][0]][save_select_block_inform[0][1]];
		block[save_select_block_inform[0][0]][save_select_block_inform[0][1]] = block[save_select_block_inform[1][0]][save_select_block_inform[1][1]];
		block[save_select_block_inform[1][0]][save_select_block_inform[1][1]] = temp;
		temp.transX = block[save_select_block_inform[0][0]][save_select_block_inform[0][1]].transX;
		temp.transY = block[save_select_block_inform[0][0]][save_select_block_inform[0][1]].transY;
		block[save_select_block_inform[0][0]][save_select_block_inform[0][1]].transX = block[save_select_block_inform[1][0]][save_select_block_inform[1][1]].transX;
		block[save_select_block_inform[0][0]][save_select_block_inform[0][1]].transY = block[save_select_block_inform[1][0]][save_select_block_inform[1][1]].transY;
		block[save_select_block_inform[1][0]][save_select_block_inform[1][1]].transX = temp.transX;
		block[save_select_block_inform[1][0]][save_select_block_inform[1][1]].transY = temp.transY;
		select_block_count = 0;
		del = true;
		make = false;
	}

	//타이머 함수 재호출
	glutTimerFunc(10, Timer, 1);

	//그리기 콜백함수 재호출
	glutPostRedisplay();
}