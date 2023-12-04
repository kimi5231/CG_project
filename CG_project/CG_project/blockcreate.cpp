#include "header.h"

//셰이터 프로그램 객체
extern GLuint shaderProgramID;

// Block VAO, VBO
GLuint VAO_block;
GLuint VBO_block_position;
GLuint VBO_block_color;

//변환 행렬
extern glm::mat4 model;

//block
extern Block block[7][7];

const GLfloat blockPos[] = {
	-0.5f, 0.7f, -0.1f,
	-0.5f, 0.5f, -0.1f,
	-0.7f, 0.7f, -0.1f,
	-0.7f, 0.5f, -0.1f,	// 앞면

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.5f, 0.1f,
	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.5f, 0.1f,	// 뒷면

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.7f, -0.1f,
	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.7f, -0.1f,	// 윗면

	-0.5f, 0.5f, 0.1f,
	-0.5f, 0.5f, -0.1f,
	-0.7f, 0.5f, 0.1f,
	-0.7f, 0.5f, -0.1f,	// 아랫면

	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.5f, 0.1f,
	-0.7f, 0.7f, -0.1f,
	-0.7f, 0.5f, -0.1f,	// 우측면

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.5f, 0.1f,
	-0.5f, 0.7f, -0.1f,
	-0.5f, 0.5f, -0.1f,	// 좌측면
};

const float blockColor[] = {
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 0.0f,

	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f,

	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

//블록 정보 조기화
void InitBlockInformation(void)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			block[i][j].transX = j * 0.2;
			block[i][j].transY = i * -0.2;
		}
	}
}

//블록 버퍼 초기화
void InitBlockBuffer(void)
{
	//VAO 객체 생성 및 바인딩
	glGenVertexArrays(1, &VAO_block);
	glBindVertexArray(VAO_block);

	//버텍스 위치 VBO 객체 생성
	glGenBuffers(1, &VBO_block_position);

	//버텍스 위치 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_block_position);
	//버텍스 위치 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(blockPos), blockPos, GL_STATIC_DRAW);
	//버텍스 위치 데이터 배열 정의
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 위치 배열 사용
	glEnableVertexAttribArray(0);

	//버텍스 색상 VBO 객체 생성
	glGenBuffers(1, &VBO_block_color);

	//버텍스 색상 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_block_color);
	//버텍스 색상 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(blockColor), blockColor, GL_STATIC_DRAW);
	//버텍스 색상 데이터 배열 정의
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 색상 배열 사용
	glEnableVertexAttribArray(1);
}

//블록 그리기
void drawBlock(float x, float y)
{
	//사용할 셰이더 프로그램 지정
	glUseProgram(shaderProgramID);

	//변환 행렬 단위 행렬로 초기화
	model = glm::mat4(1.0f);
	//x축을 기준으로 -30도만큼 회전
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//y축을 기준으로 -30도만큼 회전
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//0.9 크기로 스케일
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	//이동
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	//변환 행렬 적용하기
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	//사용할 VAO 객체 바인딩
	glBindVertexArray(VAO_block);
	//블록 그리기
	for (int i = 0; i < 24; i += 4)
	{
		glDrawArrays(GL_TRIANGLES, i, 3);
		glDrawArrays(GL_TRIANGLES, i + 1, 3);
	}
}