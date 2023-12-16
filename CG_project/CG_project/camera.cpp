#include "header.h"

extern GLuint shaderProgramID;

void drawScene()
{
	glUseProgram(shaderProgramID);

	// 원근 투영변환
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -2.0));

	unsigned int projectionLocation = glGetUniformLocation(shaderProgramID, "projectionTransform");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);

	// 카메라 위치
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, -1.0f);
	// 카메라 바라보는 방향
	glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 1.0f);
	// 카메라 위쪽 방향
	glm::vec3 camerUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 view = glm::mat4(1.0f);

	view = glm::lookAt(cameraPos, cameraDirection, camerUp);
	// 뷰잉 변환 설정
	unsigned int viewLocation = glGetUniformLocation(shaderProgramID, "viewTransform");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
}