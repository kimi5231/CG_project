#include "header.h"

//���̴� ���α׷� ��ü
extern GLuint shaderProgramID;

// Block VAO, VBO
GLuint VAO_block;
GLuint VBO_block_position;
GLuint VBO_block_color;

//��ȯ ���
extern glm::mat4 model;

//block
BlockSeat blockseat[7][7];

Block block[7][7];

int save_block_inform[7];
int blockcount = 0;

extern bool make;
extern bool del;

const GLfloat blockPos[] = {
	-0.5f, 0.7f, -0.1f,
	-0.5f, 0.5f, -0.1f,
	-0.7f, 0.7f, -0.1f,
	-0.7f, 0.5f, -0.1f,	// �ո�

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.5f, 0.1f,
	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.5f, 0.1f,	// �޸�

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.7f, -0.1f,
	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.7f, -0.1f,	// ����

	-0.5f, 0.5f, 0.1f,
	-0.5f, 0.5f, -0.1f,
	-0.7f, 0.5f, 0.1f,
	-0.7f, 0.5f, -0.1f,	// �Ʒ���

	-0.7f, 0.7f, 0.1f,
	-0.7f, 0.5f, 0.1f,
	-0.7f, 0.7f, -0.1f,
	-0.7f, 0.5f, -0.1f,	// ������

	-0.5f, 0.7f, 0.1f,
	-0.5f, 0.5f, 0.1f,
	-0.5f, 0.7f, -0.1f,
	-0.5f, 0.5f, -0.1f,	// ������
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

//��� ���� �ʱ�ȭ
void InitBlockInformation(void)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			blockseat[i][j].transX = j * 0.2;
			blockseat[i][j].transY = i * -0.2;
			blockseat[i][j].fill = false;
			block[i][j].transX = j * 0.2;
			//block[i][j].transY = i * -0.2;
			
		}
	}
}

//��� ���� �ʱ�ȭ
void InitBlockBuffer(void)
{
	//VAO ��ü ���� �� ���ε�
	glGenVertexArrays(1, &VAO_block);
	glBindVertexArray(VAO_block);

	//���ؽ� ��ġ VBO ��ü ����
	glGenBuffers(1, &VBO_block_position);

	//���ؽ� ��ġ VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_block_position);
	//���ؽ� ��ġ ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(blockPos), blockPos, GL_STATIC_DRAW);
	//���ؽ� ��ġ ������ �迭 ����
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ��ġ �迭 ���
	glEnableVertexAttribArray(0);

	//���ؽ� ���� VBO ��ü ����
	glGenBuffers(1, &VBO_block_color);

	//���ؽ� ���� VBO ��ü ���ε�
	glBindBuffer(GL_ARRAY_BUFFER, VBO_block_color);
	//���ؽ� ���� ������ �Է�
	glBufferData(GL_ARRAY_BUFFER, sizeof(blockColor), blockColor, GL_STATIC_DRAW);
	//���ؽ� ���� ������ �迭 ����
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
	//���ؽ� ���� �迭 ���
	glEnableVertexAttribArray(1);
}

//��� �׸���
void drawBlock(float x, float y)
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
	//�̵�
	model = glm::translate(model, glm::vec3(x, y, 0.0f));
	//��ȯ ��� �����ϱ�
	glUniformMatrix4fv(glGetUniformLocation(shaderProgramID, "model"), 1, GL_FALSE, glm::value_ptr(model));

	//����� VAO ��ü ���ε�
	glBindVertexArray(VAO_block);
	//��� �׸���
	for (int i = 0; i < 24; i += 4)
	{
		glDrawArrays(GL_TRIANGLES, i, 3);
		glDrawArrays(GL_TRIANGLES, i + 1, 3);
	}
}

//��� �ڸ��� ����ִ��� Ȯ��
void CheckEmptySeat(int i)
{
	for (int j = 6; j >= 0; j--)
	{
		if (blockseat[i][j].fill == false)
		{
			for (int k = i - 1; k >= 0; k--)
			{
				if (blockseat[k][j].fill == true)
				{
					block[i][j] = block[k][j];
					blockseat[k][j].fill = false;
					blockseat[i][j].fill = true;
					return;
				}
			}
			MakeBlock(i, j);
		}
	}
}

//��� ����
void MakeBlock(int i, int j)
{
	block[i][j].transY = 0.2;
	block[i][j].type = rand() % 2 + 1;
	block[i][j].special = 1;
	blockseat[i][j].fill = true;
}

//��� �̵�
void MoveBlock(void)
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (blockseat[i][j].fill && block[i][j].transY > blockseat[i][j].transY)
				block[i][j].transY -= 0.01;
			else
				block[i][j].transY = blockseat[i][j].transY;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (blockseat[i][j].fill && block[i][j].transY != blockseat[i][j].transY)
				return;
		}
	}

	make = false;
	del = true;
}

//�ı��� ��� Ȯ��
void CheckDelBlock(void)
{
	for (int k = 1; k < 8; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (block[i][j].type == k && blockcount == 0)
				{
					save_block_inform[blockcount] = j;
					blockcount++;
				}
				else if (block[i][j].type == k && block[i][j - 1].type == k)
				{
					save_block_inform[blockcount] = j;
					blockcount++;
				}
				else if (block[i][j].type != k && blockcount < 3)
					blockcount = 0;
				else if (block[i][j].type != k && blockcount == 3)
				{
					if (block[i][j + 1].type == k && block[i][j + 2].type == k && block[i][j + 3].type == k)
					{
						for (int l = 0; l < 3; l++)
						{
							blockcount ++;
							save_block_inform[blockcount] = j;
						}
					}
					break;
				}
			}

			if (blockcount >= 3)
			{
				for (int j = 0; j < blockcount; j++)
				{
					if (block[i][save_block_inform[j]].type == k)
						DelBlock(i, save_block_inform[j]);
				}
			}

			blockcount = 0;
		}
	}
}

//��� �ı�
void DelBlock(int i, int j)
{
	blockseat[i][j].fill = false;
}