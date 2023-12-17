#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <gl/glew.h>
#include <gl/freeglut.h>
#include <gl/freeglut_ext.h>
#include <gl/glm/glm.hpp>
#include <gl/glm/ext.hpp>
#include <gl/glm/gtc/matrix_transform.hpp>

//�׸��� �ݹ��Լ�
GLvoid Display(GLvoid);
//ũ�� ����� �ٽ� �׸��� �ݹ� �Լ�
GLvoid Reshape(int, int);
//Ű���� �Է� �ݹ��Լ�
void Keyboard(unsigned char, int, int);
//Ư��Ű �Է� �ݹ��Լ�
void SpecialKeyboard(int, int, int);
//Ÿ�̸� �ݹ��Լ�
void Timer(int);

//�ؽ�Ʈ ���ڿ� ����
char* filetobuf(const char* file);
//���ؽ� ���̴� ����
void MakeVertexShader(void);
//�����׸�Ʈ ���̴� ����
void MakeFragmentShader(void);
//���̴� ���α׷� ����
GLuint MakeShaderProgram(void);
//���� �ʱ�ȭ
void InitBuffer(void);
//��ǥ�� ���� �ʱ�ȭ
void InitCoordBuffer(void);
//��ǥ�� �׸���
void drawCoord(void);
// Frame ���� �ʱ�ȭ
void InitFrameBuffer(void);
// Frame �׸���
void drawFrame(void);
//��� ���� �ʱ�ȭ
void InitBlockInformation(void);
//��� ���� �ʱ�ȭ
void InitBlockBuffer(int, int);
//��� �׸���
void drawBlock(float, float);

void CheckEmptySeat(int);
void MakeBlock(int, int);
void MoveBlock(void);

void CheckDelBlock(void);
void DelBlock(int i, int j);

//���� �������̽� ���� �ʱ�ȭ
void InitSelectBuffer(void);
//���� �������̽� �׸���
void drawSelect(void);

void VeiwAndProjectionTransform(void);
//��� ��ȯ
void ChangeBlock(void);
//���� �������̽� �ʱ�ȭ
void InitSelect(void);

//��� ����ü
typedef struct Block
{
	float texture[72];
	GLfloat transX;
	GLfloat transY;
	int type;
	int special;
	bool del;
}Block;

//��� �ڸ� ����ü
typedef struct BlockSeat
{
	GLfloat transX;
	GLfloat transY;
	bool fill;
}BlockSeat;

//���� �������̽� ����ü
typedef struct Select
{
	int x;
	int y;
	int i[2];
	int j[2];
	int count;
}Select;