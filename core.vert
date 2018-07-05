#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec4 aColor;

out vec4 myColor;

uniform mat4 model;

void main()
{
	gl_Position = model * vec4(aPosition.x, aPosition.y, aPosition.z, 1.0);
	myColor = aColor;
}