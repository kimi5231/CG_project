#include "header.h"

//좌표축 그리는 법 미리 써놨으니 이거 참고해서 블록 틀 만들기

//셰이터 프로그램 객체
extern GLuint shaderProgramID;

//좌표축 VAO, VBO
GLuint VAO_coord;
GLuint VBO_coord_position;
GLuint VBO_coord_color;

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

	//사용할 VAO 객체 바인딩
	glBindVertexArray(VAO_coord);
	//좌표축 그리기
	glDrawArrays(GL_LINES, 0, 6);
}