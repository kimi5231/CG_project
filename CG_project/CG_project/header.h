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

//그리기 콜백함수
GLvoid Display(GLvoid);
//크기 변경시 다시 그리기 콜백 함수
GLvoid Reshape(int, int);
//키보드 입력 콜백함수
void Keyboard(unsigned char, int, int);
//특수키 입력 콜백함수
void SpecialKeyboard(int, int, int);
//타이머 콜백함수
void Timer(int);

//텍스트 문자열 저장
char* filetobuf(const char* file);
//버텍스 셰이더 생성
void MakeVertexShader(void);
//프래그먼트 셰이더 생성
void MakeFragmentShader(void);
//셰이더 프로그램 생성
GLuint MakeShaderProgram(void);
//버퍼 초기화
void InitBuffer(void);
//좌표축 버퍼 초기화
void InitCoordBuffer(void);
//죄표축 그리기
void drawCoord(void);
// Frame 버퍼 초기화
void InitFrameBuffer(void);
// Frame 그리기
void drawFrame(void);
//블록 정보 초기화
void InitBlockInformation(void);
//블록 버퍼 초기화
void InitBlockBuffer(int, int);
//블록 그리기
void drawBlock(float, float);

void CheckEmptySeat(int);
void MakeBlock(int, int);
void MoveBlock(void);

void CheckDelBlock(void);
void DelBlock(int i, int j);

//선택 인터페이스 버퍼 초기화
void InitSelectBuffer(void);
//선택 인터페이스 그리기
void drawSelect(void);

void VeiwAndProjectionTransform(void);
//블록 교환
void ChangeBlock(void);
//선택 인터페이스 초기화
void InitSelect(void);

//블록 구조체
typedef struct Block
{
	float texture[72];
	GLfloat transX;
	GLfloat transY;
	int type;
	int special;
	bool del;
}Block;

//블록 자리 구조체
typedef struct BlockSeat
{
	GLfloat transX;
	GLfloat transY;
	bool fill;
}BlockSeat;

//선택 인터페이스 구조체
typedef struct Select
{
	int x;
	int y;
	int i[2];
	int j[2];
	int count;
}Select;