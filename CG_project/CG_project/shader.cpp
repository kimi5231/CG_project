#include "header.h"

//���ؽ� ���̴� ��ü
GLuint vertexShader;
//�����׸�Ʈ ���̴� ��ü
GLuint fragmentShader;

//�ؽ�Ʈ ���ڿ� ���� �Լ�
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

//���ؽ� ���̴� ���� �Լ�
void MakeVertexShader(void)
{
	GLchar* vertexSource;
	GLint result;
	GLchar errorLog[512];

	//���ؽ� ���̴� �о����
	vertexSource = filetobuf("vertex.glsl");
	//���ؽ� ���̴� ��ü ����
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//���ؽ� ���̴� ��ü�� �ҽ��ڵ� ����
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	//���ؽ� ���̴� ��ü ������
	glCompileShader(vertexShader);
	//���ؽ� ���̴� ��ü ������ Ȯ��
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
	//������ ���� ��
	if (!result)
	{
		//���� �޼��� Ȯ�� �� ����
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		//���� �޼��� ���
		fprintf(stderr, "ERROR: vertex shader ������ ����\n%s\n", errorLog);
		return;
	}
}

//�����׸�Ʈ ���̴� ���� �Լ�
void MakeFragmentShader(void)
{
	GLchar* fragmentSource;
	GLint result;
	GLchar errorLog[512];

	//�����׸�Ʈ ���̴� �о����
	fragmentSource = filetobuf("fragment.glsl");
	//�����׸�Ʈ ���̴� ��ü ����
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//�����׸�Ʈ ���̴� ��ü�� �ҽ��ڵ� ����
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	//�����׸�Ʈ ���̴� ��ü ������
	glCompileShader(fragmentShader);
	//�����׸�Ʈ ���̴� ��ü ������ Ȯ��
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
	//������ ���� ��
	if (!result)
	{
		//���� �޼��� Ȯ�� �� ����
		glGetShaderInfoLog(fragmentShader, 512, NULL, errorLog);
		//���� �޼��� ���
		fprintf(stderr, "ERROR: fragment shader ������ ����\n%s\n", errorLog);
		return;
	}
}

//���̴� ���α׷� ���� �Լ�
GLuint MakeShaderProgram(void)
{
	GLuint shaderID;
	GLint result;
	GLchar errorLog[512];

	//���ؽ� ���̴� ����
	MakeVertexShader();
	//�����׸�Ʈ ���̴� ����
	MakeFragmentShader();

	//���̴� ���α׷� ��ü ����
	shaderID = glCreateProgram();
	//���̴� ���α׷��� ���ؽ� ���̴� ���̱�
	glAttachShader(shaderID, vertexShader);
	//���̴� ���α׷��� �����׸�Ʈ ���̴� ���̱�
	glAttachShader(shaderID, fragmentShader);
	//���̴� ���α׷� ��ũ
	glLinkProgram(shaderID);
	//���ؽ� ���̴� ��ü ����
	glDeleteShader(vertexShader);
	//�����׸�Ʈ ���̴� ��ü ����
	glDeleteShader(fragmentShader);
	//������ ���α׷� ��ũ ���� Ȯ��
	glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
	//���� ���� ��
	if (!result)
	{
		//���� �޼��� Ȯ�� �� ����
		glGetProgramInfoLog(shaderID, 512, NULL, errorLog);
		//���� �޼��� ���
		fprintf(stderr, "ERROR: shader program ���� ����\n%s\n", errorLog);
		return false;
	}
	//������ ���̴� ���α׷� ����ϱ�
	glUseProgram(shaderID);
	//���̴� ���α׷� ��ü ��ȯ
	return shaderID;
}