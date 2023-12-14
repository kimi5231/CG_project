#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec4 vColor;
out vec4 outColor;

uniform mat4 model;

void main()
{
	gl_Position = model * vec4(vPos, 1.0);
	outColor = vColor;
}