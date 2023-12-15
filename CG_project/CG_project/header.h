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
void InitBlockBuffer(void);
//��� �׸���
void drawBlock(float, float);

void CheckEmptySeat(void);
void MakeBlock(int i, int j);
void MoveBlock(void);

//��� ����ü
typedef struct Block
{
	//GLfloat pos[72];
	GLfloat transX;
	GLfloat transY;
	int type;
	int special;
}Block;

typedef struct BlockSeat
{
	GLfloat transX;
	GLfloat transY;
	bool fill;
}BlockSeat;