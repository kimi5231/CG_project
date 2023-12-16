#include "header.h"

//������ ���α׷� ��ü
extern GLuint shaderProgramID;

//��ǥ�� VAO, VBO
GLuint VAO_coord;
GLuint VBO_coord_position;
GLuint VBO_coord_color;

// Frame VAO, VBO
GLuint VAO_frame;
GLuint VBO_frame_position;
GLuint VBO_frame_color;

//��ȯ ���
glm::mat4 model;

//��ǥ�� ����
GLfloat radiansY = -30.0f;

//��ǥ��
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
	//{0.7f, -0.7f, -0.1f},	// �ո�

	//{-0.7f, 0.7f, 0.1f},
	//{0.7f, 0.7f, 0.1f},
	//{-0.7f, -0.7f, 0.1f},
	//{0.7f, -0.7f, 0.1f},	// �޸�

	{-0.8f, -0.7f, -0.1f},
	{-0.8f, -0.7f, 0.1f},
	{0.8f, -0.7f, -0.1f},
	{0.8f, -0.7f, 0.1f},	// �Ʒ���_��

	{-0.8f, -0.8f, -0.1f},
	{-0.8f, -0.8f, 0.1f},
	{0.8f, -0.8f, -0.1f},
	{0.8f, -0.8f, 0.1f},	// �Ʒ���_��

	{-0.7f, -0.8f, -0.1f},
	{0.7f, -0.8f, -0.1f},
	{-0.7f, -0.7f, -0.1f},
	{0.7f, -0.7f, -0.1f},	// �Ʒ���_��

	{-0.7f, -0.8f, 0.1f},
	{0.7f, -0.8f, 0.1f},
	{-0.7f, -0.7f, 0.1f},
	{0.7f, -0.7f, 0.1f},	// �Ʒ���_��

	{0.7f, 0.7f, 0.1f},
	{0.7f, 0.7f, -0.1f},
	{0.7f, -0.7f, 0.1f},
	{0.7f, -0.7f, -0.1f},	// ������_��

	{0.8f, 0.7f, 0.1f},
	{0.8f, 0.7f, -0.1f},
	{0.8f, -0.8f, 0.1f},
	{0.8f, -0.8f, -0.1f},	// ������_��

	{0.7f, 0.7f, 0.1f},
	{0.8f, 0.7f, 0.1f},
	{0.7f, 0.7f, -0.1f},
	{0.8f, 0.7f, -0.1f},	// ������_��

	{0.7f, 0.7f, -0.1f},
	{0.8f, 0.7f, -0.1f},
	{0.7f, -0.8f, -0.1f},
	{0.8f, -0.8f, -0.1f},	// ������_��

	{0.7f, 0.7f, 0.1f},
	{0.8f, 0.7f, 0.1f},
	{0.7f, -0.8f, 0.1f},
	{0.8f, -0.8f, 0.1f},	// ������_��

	{-0.7f, 0.7f, 0.1f},
	{-0.7f, 0.7f, -0.1f},
	{-0.7f, -0.7f, 0.1f},
	{-0.7f, -0.7f, -0.1f},	// ������_��

	{-0.8f, 0.7f, 0.1f},
	{-0.8f, 0.7f, -0.1f},
	{-0.8f, -0.8f, 0.1f},
	{-0.8f, -0.8f, -0.1f},	// ������_��

	{-0.7f, 0.7f, 0.1f},
	{-0.8f, 0.7f, 0.1f},
	{-0.7f, 0.7f, -0.1f},
	{-0.8f, 0.7f, -0.1f},	// ������_��

	{-0.7f, 0.7f, -0.1f},
	{-0.8f, 0.7f, -0.1f},
	{-0.7f, -0.8f, -0.1f},
	{-0.8f, -0.8f, -0.1f},	// ������_��

	{-0.7f, 0.7f, 0.1f},
	{-0.8f, 0.7f, 0.1f},
	{-0.7f, -0.8f, 0.1f},
	{-0.8f, -0.8f, 0.1f},	// ������_��
};

const float frameColor[][3] = {
	{ 1.0f, 0.0f, 1.0f },
	{ 1.0f, 0.0f, 1.0f },
	{ 1.0f, 0.0f, 1.0f },
	{ 1.0f, 0.0f, 1.0f },	// �Ʒ���_��

	{ 0.5f, 0.0f, 1.0f },
	{ 0.5f, 0.0f, 1.0f },
	{ 0.5f, 0.0f, 1.0f },
	{ 0.5f, 0.0f, 1.0f },	// �Ʒ���_��

	{ 1.0f, 1.0f, 0.0f },
	{ 1.0f, 1.0f, 0.0f },
	{ 1.0f, 1.0f, 0.0f },
	{ 1.0f, 1.0f, 0.0f },	// �Ʒ���_��

	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },	// �Ʒ���_��

	{ 1.0f, 1.0f, 0.5f },
	{ 1.0f, 1.0f, 0.5f },
	{ 1.0f, 1.0f, 0.5f },
	{ 1.0f, 1.0f, 0.5f },	// ������_��

	{ 1.0f, 0.5f, 0.5f },
	{ 1.0f, 0.5f, 0.5f },
	{ 1.0f, 0.5f, 0.5f },
	{ 1.0f, 0.5f, 0.5f },	// ������_��

	{ 0.8f, 0.5f, 1.0f },
	{ 0.8f, 0.5f, 1.0f },
	{ 0.8f, 0.5f, 1.0f },
	{ 0.8f, 0.5f, 1.0f },	// ������_��

	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },	// ������_��

	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },	// ������_��

	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },	// ������_��

	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },
	{ 0.5f, 0.5f, 1.0f },	// ������_��

	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },	// ������_��

	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },	// ������_��

	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },	// ������_��

};

//��ǥ�� ���� �ʱ�ȭ
void InitCoordBuffer(void)
{
	//VAO ��ü ���� �� ���ε�
	glGenVertexArrays(1, &VAO_coord);
	glBindVertexArray(VAO_coord);

	//���ؽ� ��ġ VBO ��ü ����
	glGenBuffers(1, &VBO_coord_position);

	//���ؽ� ��ġ VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_coord_position);
	//���ؽ� ��ġ ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(coord), coord, GL_STATIC_DRAW);
	//���ؽ� ��ġ ������ �迭 ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ��ġ �迭 ���
	glEnableVertexAttribArray(0);

	//���ؽ� ���� VBO ��ü ����
	glGenBuffers(1, &VBO_coord_color);

	//���ؽ� ���� VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_coord_color);
	//���ؽ� ���� ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(coordColor), coordColor, GL_STATIC_DRAW);
	//���ؽ� ���� ������ �迭 ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ���� �迭 ���
	glEnableVertexAttribArray(1);
}

//��ǥ�� �׸���
void drawCoord(void)
{
	//����� ���̴� ���α׷� ����
	glUseProgram(shaderProgramID);

	//��ȯ ��� ���� ��ķ� �ʱ�ȭ
	model = glm::mat4(1.0f);
	//x���� �������� -30����ŭ ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//y���� �������� -30����ŭ ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//0.9 ũ��� ������
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	//��ȯ ��� �����ϱ�
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	VeiwAndProjectionTransform();

	//����� VAO ��ü ���ε�
	glBindVertexArray(VAO_coord);
	//��ǥ�� �׸���
	glDrawArrays(GL_LINES, 0, 6);
}

// Frame ���� �ʱ�ȭ
void InitFrameBuffer(void)
{
	//VAO ��ü ���� �� ���ε�
	glGenVertexArrays(1, &VAO_frame);
	glBindVertexArray(VAO_frame);

	//���ؽ� ��ġ VBO ��ü ����
	glGenBuffers(1, &VBO_frame_position);

	//���ؽ� ��ġ VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_frame_position);
	//���ؽ� ��ġ ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(frame), frame, GL_STATIC_DRAW);
	//���ؽ� ��ġ ������ �迭 ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ��ġ �迭 ���
	glEnableVertexAttribArray(0);

	//���ؽ� ���� VBO ��ü ����
	glGenBuffers(1, &VBO_frame_color);

	//���ؽ� ���� VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_frame_color);
	//���ؽ� ���� ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(frameColor), frameColor, GL_STATIC_DRAW);
	//���ؽ� ���� ������ �迭 ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ���� �迭 ���
	glEnableVertexAttribArray(1);
}

// Frame �׸���
void drawFrame(void)
{
	//����� ���̴� ���α׷� ����
	glUseProgram(shaderProgramID);

	//��ȯ ��� ���� ��ķ� �ʱ�ȭ
	model = glm::mat4(1.0f);
	//x���� �������� -30����ŭ ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//y���� �������� -30����ŭ ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	//0.9 ũ��� ������
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	//��ȯ ��� �����ϱ�
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	VeiwAndProjectionTransform();

	//����� VAO ��ü ���ε�
	glBindVertexArray(VAO_frame);
	//Frame �׸���
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