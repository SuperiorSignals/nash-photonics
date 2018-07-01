#version 330 core
out vec4 fragmentColor;
in vec4 myColor;

void main()
{
	fragmentColor = vec4(myColor);
}