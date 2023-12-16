#include "header.h"

extern GLuint shaderProgramID;

void drawScene()
{
	glUseProgram(shaderProgramID);

	// ���� ������ȯ
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	projection = glm::translate(projection, glm::vec3(0.0, 0.0, -2.0));

	unsigned int projectionLocation = glGetUniformLocation(shaderProgramID, "projectionTransform");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &projection[0][0]);

	// ī�޶� ��ġ
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, -1.0f);
	// ī�޶� �ٶ󺸴� ����
	glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 1.0f);
	// ī�޶� ���� ����
	glm::vec3 camerUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 view = glm::mat4(1.0f);

	view = glm::lookAt(cameraPos, cameraDirection, camerUp);
	// ���� ��ȯ ����
	unsigned int viewLocation = glGetUniformLocation(shaderProgramID, "viewTransform");
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
}