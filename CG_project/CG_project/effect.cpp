#include "header.h"

//���̴� ���α׷� ��ü
extern GLuint shaderProgramID;

//��ȯ ���
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
	0.05f, -0.05f, -0.05f, // �ո�

	-0.05f, 0.05f, 0.05f,
	0.05f, 0.05f, 0.05f,
	-0.05f, -0.05f, 0.05f,
	0.05f, -0.05f, 0.05f, // �޸�

	-0.05f, 0.05f, 0.05f,
	0.05f, 0.05f, 0.05f,
	-0.05f, 0.05f, -0.05f,
	0.05f, 0.05f, -0.05f,	// ����

	-0.05f, -0.05f, 0.05f,
	0.05f, -0.05f, 0.05f,
	-0.05f, -0.05f, -0.05f,
	0.05f, -0.05f, -0.05f,	// �Ʒ���

	0.05f, 0.05f, -0.05f,
	0.05f, 0.05f, 0.05f,
	0.05f, -0.05f, -0.05f,
	0.05f, -0.05f, 0.05f,	// ������

	-0.05f, 0.05f, -0.05f,
	-0.05f, 0.05f, 0.05f,
	-0.05f, -0.05f, -0.05f,
	-0.05f, -0.05f, 0.05f	// ������
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

//����Ʈ �ʱ�ȭ
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

//����Ʈ ���� �ʱ�ȭ
void InitEffectBuffer(void)
{
	//VAO ��ü ���� �� ���ε�
	glGenVertexArrays(1, &VAO_effect);
	glBindVertexArray(VAO_effect);

	//���ؽ� ��ġ VBO ��ü ����
	glGenBuffers(1, &VBO_effect_position);

	//���ؽ� ��ġ VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_effect_position);
	//���ؽ� ��ġ ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(effectPos), effectPos, GL_STATIC_DRAW);
	//���ؽ� ��ġ ������ �迭 ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ��ġ �迭 ���
	glEnableVertexAttribArray(0);

	//���ؽ� ���� VBO ��ü ����
	glGenBuffers(1, &VBO_effect_color);

	//���ؽ� ���� VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_effect_color);
	//���ؽ� ���� ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(effectColor), effectColor, GL_STATIC_DRAW);
	//���ؽ� ���� ������ �迭 ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ���� �迭 ���
	glEnableVertexAttribArray(1);
}

//����Ʈ �׸���
void drawEffect(float x, float y, float z)
{
	//����� ���̴� ���α׷� ����
	glUseProgram(shaderProgramID);

	//��ȯ ��� ���� ��ķ� �ʱ�ȭ
	model = glm::mat4(1.0f);
	//0.9 ũ��� ������
	model = glm::scale(model, glm::vec3(0.9f, 0.9f, 0.9f));
	//ȸ��
	model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	//�̵�
	model = glm::translate(model, glm::vec3(x, y, z));
	//��ȯ ��� �����ϱ�
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	VeiwAndProjectionTransform();

	//����� VAO ��ü ���ε�
	glBindVertexArray(VAO_effect);
	//��� �׸���
	for (int i = 0; i < 24; i += 4)
	{
		glDrawArrays(GL_TRIANGLES, i, 3);
		glDrawArrays(GL_TRIANGLES, i + 1, 3);
	}
}

//����Ʈ ����
void MakeEffect(int i, int j)
{
	for(int k=0; k<8; k++)
		effect[i][j][k].show = true;
}

//����Ʈ �̵�
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

//����Ʈ ����
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