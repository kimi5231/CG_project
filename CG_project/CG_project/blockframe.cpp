#include "header.h"

//��ǥ�� �׸��� �� �̸� ������� �̰� �����ؼ� ��� Ʋ �����

//������ ���α׷� ��ü
extern GLuint shaderProgramID;

//��ǥ�� VAO, VBO
GLuint VAO_coord;
GLuint VBO_coord_position;
GLuint VBO_coord_color;

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

	//����� VAO ��ü ���ε�
	glBindVertexArray(VAO_coord);
	//��ǥ�� �׸���
	glDrawArrays(GL_LINES, 0, 6);
}