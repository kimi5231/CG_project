#include "header.h"

//셰이더 프로그램 객체
extern GLuint shaderProgramID;

//변환 행렬
extern glm::mat4 model;

//effect VAO, VBO
GLuint VAO_effect;
GLuint VBO_effect_position;
GLuint VBO_effect_color;

//effect
Effect effect[7][7][8];

//block
extern BlockSeat blockseat[7][7];

const GLfloat effectPos[] = {
	-0.05f, 0.05f, -0.05f,
	0.05f, 0.05f, -0.05f,
	-0.05f, -0.05f, -0.05f,
	0.05f, -0.05f, -0.05f, // 앞면

	-0.05f, 0.05f, 0.05f,
	0.05f, 0.05f, 0.05f,
	-0.05f, -0.05f, 0.05f,
	0.05f, -0.05f, 0.05f, // 뒷면

	-0.05f, 0.05f, 0.05f,
	0.05f, 0.05f, 0.05f,
	-0.05f, 0.05f, -0.05f,
	0.05f, 0.05f, -0.05f,	// 윗면

	-0.05f, -0.05f, 0.05f,
	0.05f, -0.05f, 0.05f,
	-0.05f, -0.05f, -0.05f,
	0.05f, -0.05f, -0.05f,	// 아랫면

	0.05f, 0.05f, -0.05f,
	0.05f, 0.05f, 0.05f,
	0.05f, -0.05f, -0.05f,
	0.05f, -0.05f, 0.05f,	// 우측면

	-0.05f, 0.05f, -0.05f,
	-0.05f, 0.05f, 0.05f,
	-0.05f, -0.05f, -0.05f,
	-0.05f, -0.05f, 0.05f	// 좌측면
};

const float effectColor[] = {
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f
};

//이펙트 초기화
void InitEffect(void)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				effect[i][j][k].transX_origin = -0.6 + 0.2 * j;
				effect[i][j][k].transY_origin = 0.6 - 0.2 * i;
				effect[i][j][k].transZ_origin = 0.0;
				effect[i][j][k].transX = -0.6 + 0.2 * j;
				effect[i][j][k].transY = 0.6 - 0.2 * i;
				effect[i][j][k].transZ = 0.0;
				effect[i][j][k].show = false;
			}
		}
	}
}

//이펙트 버퍼 초기화
void InitEffectBuffer(void)
{
	//VAO 객체 생성 및 바인딩
	glGenVertexArrays(1, &VAO_effect);
	glBindVertexArray(VAO_effect);

	//버텍스 위치 VBO 객체 생성
	glGenBuffers(1, &VBO_effect_position);

	//버텍스 위치 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_effect_position);
	//버텍스 위치 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(effectPos), effectPos, GL_STATIC_DRAW);
	//버텍스 위치 데이터 배열 정의
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 위치 배열 사용
	glEnableVertexAttribArray(0);

	//버텍스 색상 VBO 객체 생성
	glGenBuffers(1, &VBO_effect_color);

	//버텍스 색상 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_effect_color);
	//버텍스 색상 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(effectColor), effectColor, GL_STATIC_DRAW);
	//버텍스 색상 데이터 배열 정의
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 색상 배열 사용
	glEnableVertexAttribArray(1);
}

//이펙트 그리기
void drawEffect(float x, float y, float z)
{
	//사용할 셰이더 프로그램 지정
	glUseProgram(shaderProgramID);

	//변환 행렬 단위 행렬로 초기화
	model = glm::mat4(1.0f);
	//0.9 크기로 스케일
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	//회전
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	//이동
	model = glm::translate(model, glm::vec3(x, y, z));
	//변환 행렬 적용하기
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	VeiwAndProjectionTransform();

	//사용할 VAO 객체 바인딩
	glBindVertexArray(VAO_effect);
	//블록 그리기
	for (int i = 0; i < 24; i += 4)
	{
		glDrawArrays(GL_TRIANGLES, i, 3);
		glDrawArrays(GL_TRIANGLES, i + 1, 3);
	}
}

//이펙트 생성
void MakeEffect(int i, int j)
{
	for(int k=0; k<8; k++)
		effect[i][j][k].show = true;
}

//이펙트 이동
void MoveEffect(int i, int j)
{
	effect[i][j][0].transX -= 0.001;
	effect[i][j][0].transY += 0.001;
	effect[i][j][0].transZ += 0.001;

	effect[i][j][1].transX += 0.001;
	effect[i][j][1].transY += 0.001;
	effect[i][j][1].transZ += 0.001;

	effect[i][j][2].transX -= 0.001;
	effect[i][j][2].transY -= 0.001;
	effect[i][j][2].transZ += 0.001;

	effect[i][j][3].transX += 0.001;
	effect[i][j][3].transY -= 0.001;
	effect[i][j][3].transZ += 0.001;

	effect[i][j][4].transX -= 0.001;
	effect[i][j][4].transY += 0.001;
	effect[i][j][4].transZ -= 0.001;

	effect[i][j][5].transX += 0.001;
	effect[i][j][5].transY += 0.001;
	effect[i][j][5].transZ -= 0.001;

	effect[i][j][6].transX -= 0.001;
	effect[i][j][6].transY -= 0.001;
	effect[i][j][6].transZ -= 0.001;

	effect[i][j][7].transX += 0.001;
	effect[i][j][7].transY -= 0.001;
	effect[i][j][7].transZ -= 0.001;

	for (int t = 0; t < 8; t++)
	{
		effect[i][j][t].time++;
		if (effect[i][j][t].time == 800)
			DelEffect(i, j);
	}
}

//이펙트 제거
void DelEffect(int i, int j)
{
	for (int k = 0; k < 8; k++)
	{
		effect[i][j][k].transX = effect[i][j][k].transX_origin;
		effect[i][j][k].transY = effect[i][j][k].transY_origin;
		effect[i][j][k].transZ = effect[i][j][k].transZ_origin;
		effect[i][j][k].show = false;
		effect[i][j][k].time = 0;
	}
}