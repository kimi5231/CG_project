#include "header.h"

//셰이터 프로그램 객체
extern GLuint shaderProgramID;

//좌표축 VAO, VBO
GLuint VAO_coord;
GLuint VBO_coord_position;
GLuint VBO_coord_color;

// Frame VAO, VBO
GLuint VAO_frame;
GLuint VBO_frame_position;
GLuint VBO_frame_color;

//변환 행렬
glm::mat4 model;

//좌표축 각도
GLfloat radiansY = -30.0f;

//좌표축
const GLfloat coord[] = {
	-1.0f, 0.0f, 0.0f,		//x, y, z
	1.0f, 0.0f, 0.0f,
	0.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, -1.0f,
	0.0f, 0.0f, 1.0f
};

const float coordColor[] = {
	0.0f, 1.0f, 0.0f,		//r, g, b
	0.0f, 1.0f, 0.0f,

	1.0f, 0.0f, 0.0f,
	1.0f, 0.0f, 0.0f,

	0.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f
};

// Frame
const GLfloat frame[][3] = {
	//{-0.7f, 0.7f, -0.1f},
	//{0.7f, 0.7f, -0.1f},
	//{-0.7f, -0.7f, -0.1f},
	//{0.7f, -0.7f, -0.1f},	// 앞면

	//{-0.7f, 0.7f, 0.1f},
	//{0.7f, 0.7f, 0.1f},
	//{-0.7f, -0.7f, 0.1f},
	//{0.7f, -0.7f, 0.1f},	// 뒷면

	{-0.8f, -0.7f, -0.1f},
	{-0.8f, -0.7f, 0.1f},
	{0.8f, -0.7f, -0.1f},
	{0.8f, -0.7f, 0.1f},	// 아랫면_안

	{-0.8f, -0.8f, -0.1f},
	{-0.8f, -0.8f, 0.1f},
	{0.8f, -0.8f, -0.1f},
	{0.8f, -0.8f, 0.1f},	// 아랫면_밖

	{-0.7f, -0.8f, -0.1f},
	{0.7f, -0.8f, -0.1f},
	{-0.7f, -0.7f, -0.1f},
	{0.7f, -0.7f, -0.1f},	// 아랫면_앞

	{-0.7f, -0.8f, 0.1f},
	{0.7f, -0.8f, 0.1f},
	{-0.7f, -0.7f, 0.1f},
	{0.7f, -0.7f, 0.1f},	// 아랫면_뒤

	{0.7f, 0.7f, 0.1f},
	{0.7f, 0.7f, -0.1f},
	{0.7f, -0.7f, 0.1f},
	{0.7f, -0.7f, -0.1f},	// 우측면_안

	{0.8f, 0.7f, 0.1f},
	{0.8f, 0.7f, -0.1f},
	{0.8f, -0.8f, 0.1f},
	{0.8f, -0.8f, -0.1f},	// 우측면_밖

	{0.7f, 0.7f, 0.1f},
	{0.8f, 0.7f, 0.1f},
	{0.7f, 0.7f, -0.1f},
	{0.8f, 0.7f, -0.1f},	// 우측면_위

	{0.7f, 0.7f, -0.1f},
	{0.8f, 0.7f, -0.1f},
	{0.7f, -0.8f, -0.1f},
	{0.8f, -0.8f, -0.1f},	// 우측면_앞

	{0.7f, 0.7f, 0.1f},
	{0.8f, 0.7f, 0.1f},
	{0.7f, -0.8f, 0.1f},
	{0.8f, -0.8f, 0.1f},	// 우측면_뒤

	{-0.7f, 0.7f, 0.1f},
	{-0.7f, 0.7f, -0.1f},
	{-0.7f, -0.7f, 0.1f},
	{-0.7f, -0.7f, -0.1f},	// 좌측면_안

	{-0.8f, 0.7f, 0.1f},
	{-0.8f, 0.7f, -0.1f},
	{-0.8f, -0.8f, 0.1f},
	{-0.8f, -0.8f, -0.1f},	// 좌측면_밖

	{-0.7f, 0.7f, 0.1f},
	{-0.8f, 0.7f, 0.1f},
	{-0.7f, 0.7f, -0.1f},
	{-0.8f, 0.7f, -0.1f},	// 좌측면_위

	{-0.7f, 0.7f, -0.1f},
	{-0.8f, 0.7f, -0.1f},
	{-0.7f, -0.8f, -0.1f},
	{-0.8f, -0.8f, -0.1f},	// 좌측면_앞

	{-0.7f, 0.7f, 0.1f},
	{-0.8f, 0.7f, 0.1f},
	{-0.7f, -0.8f, 0.1f},
	{-0.8f, -0.8f, 0.1f},	// 좌측면_뒤
};

const float frameColor[][3] = {
	{ 1.0f, 0.0f, 1.0f },
	{ 1.0f, 0.0f, 1.0f },
	{ 1.0f, 0.0f, 1.0f },
	{ 1.0f, 0.0f, 1.0f },	// 아랫면_안

	{ 0.5f, 0.0f, 1.0f },
	{ 0.5f, 0.0f, 1.0f },
	{ 0.5f, 0.0f, 1.0f },
	{ 0.5f, 0.0f, 1.0f },	// 아랫면_밖

	{ 1.0f, 1.0f, 0.0f },
	{ 1.0f, 1.0f, 0.0f },
	{ 1.0f, 1.0f, 0.0f },
	{ 1.0f, 1.0f, 0.0f },	// 아랫면_앞

	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },	// 아랫면_뒤

	{ 1.0f, 1.0f, 0.5f },
	{ 1.0f, 1.0f, 0.5f },
	{ 1.0f, 1.0f, 0.5f },
	{ 1.0f, 1.0f, 0.5f },	// 우측면_안

	{ 1.0f, 0.5f, 0.5f },
	{ 1.0f, 0.5f, 0.5f },
	{ 1.0f, 0.5f, 0.5f },
	{ 1.0f, 0.5f, 0.5f },	// 우측면_밖

	{ 0.8f, 0.5f, 1.0f },
	{ 0.8f, 0.5f, 1.0f },
	{ 0.8f, 0.5f, 1.0f },
	{ 0.8f, 0.5f, 1.0f },	// 우측면_위

	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },	// 우측면_앞

	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },	// 우측면_뒤

	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },	// 좌측면_안

	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },	// 좌측면_밖

	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },	// 좌측면_위

	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },	// 좌측면_앞

	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },	// 좌측면_뒤

};

//좌표축 버퍼 초기화
void InitCoordBuffer(void)
{
	//VAO 객체 생성 및 바인딩
	glGenVertexArrays(1, &VAO_coord);
	glBindVertexArray(VAO_coord);

	//버텍스 위치 VBO 객체 생성
	glGenBuffers(1, &VBO_coord_position);

	//버텍스 위치 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_coord_position);
	//버텍스 위치 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(coord), coord, GL_STATIC_DRAW);
	//버텍스 위치 데이터 배열 정의
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 위치 배열 사용
	glEnableVertexAttribArray(0);

	//버텍스 색상 VBO 객체 생성
	glGenBuffers(1, &VBO_coord_color);

	//버텍스 색상 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_coord_color);
	//버텍스 색상 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(coordColor), coordColor, GL_STATIC_DRAW);
	//버텍스 색상 데이터 배열 정의
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 색상 배열 사용
	glEnableVertexAttribArray(1);
}

//좌표축 그리기
void drawCoord(void)
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
	//변환 행렬 적용하기
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	VeiwAndProjectionTransform();

	//사용할 VAO 객체 바인딩
	glBindVertexArray(VAO_coord);
	//좌표축 그리기
	glDrawArrays(GL_LINES, 0, 6);
}

// Frame 버퍼 초기화
void InitFrameBuffer(void)
{
	//VAO 객체 생성 및 바인딩
	glGenVertexArrays(1, &VAO_frame);
	glBindVertexArray(VAO_frame);

	//버텍스 위치 VBO 객체 생성
	glGenBuffers(1, &VBO_frame_position);

	//버텍스 위치 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_frame_position);
	//버텍스 위치 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(frame), frame, GL_STATIC_DRAW);
	//버텍스 위치 데이터 배열 정의
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 위치 배열 사용
	glEnableVertexAttribArray(0);

	//버텍스 색상 VBO 객체 생성
	glGenBuffers(1, &VBO_frame_color);

	//버텍스 색상 VBO 객체 바인딩
	glBindBuffer(GL_ARRAY_BUFFER, VBO_frame_color);
	//버텍스 색상 데이터 입력
	glBufferData(GL_ARRAY_BUFFER, sizeof(frameColor), frameColor, GL_STATIC_DRAW);
	//버텍스 색상 데이터 배열 정의
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//버텍스 색상 배열 사용
	glEnableVertexAttribArray(1);
}

// Frame 그리기
void drawFrame(void)
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
	//변환 행렬 적용하기
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	VeiwAndProjectionTransform();

	//사용할 VAO 객체 바인딩
	glBindVertexArray(VAO_frame);
	//Frame 그리기
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawArrays(GL_TRIANGLES, 1, 3);

	glDrawArrays(GL_TRIANGLES, 4, 3);
	glDrawArrays(GL_TRIANGLES, 5, 3);

	glDrawArrays(GL_TRIANGLES, 8, 3);
	glDrawArrays(GL_TRIANGLES, 9, 3);

	glDrawArrays(GL_TRIANGLES, 12, 3);
	glDrawArrays(GL_TRIANGLES, 13, 3);

	glDrawArrays(GL_TRIANGLES, 16, 3);
	glDrawArrays(GL_TRIANGLES, 17, 3);

	glDrawArrays(GL_TRIANGLES, 20, 3);
	glDrawArrays(GL_TRIANGLES, 21, 3);

	glDrawArrays(GL_TRIANGLES, 24, 3);
	glDrawArrays(GL_TRIANGLES, 25, 3);

	glDrawArrays(GL_TRIANGLES, 28, 3);
	glDrawArrays(GL_TRIANGLES, 29, 3);

	glDrawArrays(GL_TRIANGLES, 32, 3);
	glDrawArrays(GL_TRIANGLES, 33, 3);

	glDrawArrays(GL_TRIANGLES, 36, 3);
	glDrawArrays(GL_TRIANGLES, 37, 3);

	glDrawArrays(GL_TRIANGLES, 40, 3);
	glDrawArrays(GL_TRIANGLES, 41, 3);

	glDrawArrays(GL_TRIANGLES, 44, 3);
	glDrawArrays(GL_TRIANGLES, 45, 3);

	glDrawArrays(GL_TRIANGLES, 48, 3);
	glDrawArrays(GL_TRIANGLES, 49, 3);

	glDrawArrays(GL_TRIANGLES, 52, 3);
	glDrawArrays(GL_TRIANGLES, 53, 3);
}