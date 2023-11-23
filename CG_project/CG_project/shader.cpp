#include "header.h"

//버텍스 셰이더 객체
GLuint vertexShader;
//프래그먼트 셰이더 객체
GLuint fragmentShader;

//텍스트 문자열 저장 함수
char* filetobuf(const char* file)
{
	FILE* fptr;
	long length;
	char* buf;
	fptr = fopen(file, "rb"); // Open file for reading 
	if (!fptr) // Return NULL on failure 
		return NULL;
	fseek(fptr, 0, SEEK_END); // Seek to the end of the file 
	length = ftell(fptr); // Find out how many bytes into the file we are 
	buf = (char*)malloc(length + 1); // Allocate a buffer for the entire length of the file and a null terminator 
	fseek(fptr, 0, SEEK_SET); // Go back to the beginning of the file 
	fread(buf, length, 1, fptr); // Read the contents of the file in to the buffer 
	fclose(fptr); // Close the file 
	buf[length] = 0; // Null terminator 
	return buf; // Return the buffer 
}

//버텍스 셰이더 생성 함수
void MakeVertexShader(void)
{
	GLchar* vertexSource;
	GLint result;
	GLchar errorLog[512];

	//버텍스 셰이더 읽어오기
	vertexSource = filetobuf("vertex.glsl");
	//버텍스 셰이더 객체 생성
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//버텍스 셰이더 객체에 소스코드 연결
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	//버텍스 셰이더 객체 컴파일
	glCompileShader(vertexShader);
	//버텍스 셰이더 객체 컴파일 확인
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
	//컴파일 실패 시
	if (!result)
	{
		//오류 메세지 확인 후 저장
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		//오류 메세지 출력
		fprintf(stderr, "ERROR: vertex shader 컴파일 실패\n%s\n", errorLog);
		return;
	}
}

//프래그먼트 셰이더 생성 함수
void MakeFragmentShader(void)
{
	GLchar* fragmentSource;
	GLint result;
	GLchar errorLog[512];

	//프래그먼트 셰이더 읽어오기
	fragmentSource = filetobuf("fragment.glsl");
	//프래그먼트 셰이더 객체 생성
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//프래그먼트 셰이더 객체에 소스코드 연결
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	//프래그먼트 셰이더 객체 컴파일
	glCompileShader(fragmentShader);
	//프래그먼트 셰이더 객체 컴파일 확인
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
	//컴파일 실패 시
	if (!result)
	{
		//오류 메세지 확인 후 저장
		glGetShaderInfoLog(fragmentShader, 512, NULL, errorLog);
		//오류 메세지 출력
		fprintf(stderr, "ERROR: fragment shader 컴파일 실패\n%s\n", errorLog);
		return;
	}
}

//셰이더 프로그램 생성 함수
GLuint MakeShaderProgram(void)
{
	GLuint shaderID;
	GLint result;
	GLchar errorLog[512];

	//버텍스 셰이더 생성
	MakeVertexShader();
	//프래그먼트 셰이더 생성
	MakeFragmentShader();

	//셰이더 프로그램 객체 생성
	shaderID = glCreateProgram();
	//셰이더 프로그램에 버텍스 셰이더 붙이기
	glAttachShader(shaderID, vertexShader);
	//셰이더 프로그램에 프래그먼트 셰이더 붙이기
	glAttachShader(shaderID, fragmentShader);
	//셰이더 프로그램 링크
	glLinkProgram(shaderID);
	//버텍스 셰이더 객체 삭제
	glDeleteShader(vertexShader);
	//프래그먼트 셰이더 객체 삭제
	glDeleteShader(fragmentShader);
	//셰이터 프로그램 링크 연결 확인
	glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
	//연결 실패 시
	if (!result)
	{
		//오류 메세지 확인 후 저장
		glGetProgramInfoLog(shaderID, 512, NULL, errorLog);
		//오류 메세지 출력
		fprintf(stderr, "ERROR: shader program 연결 실패\n%s\n", errorLog);
		return false;
	}
	//생성된 셰이더 프로그램 사용하기
	glUseProgram(shaderID);
	//셰이더 프로그램 객체 반환
	return shaderID;
}