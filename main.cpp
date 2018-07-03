// Author: Stewart Nash
// Year: 2018
// File: main.cpp
// Description: Defines the entry point for the console application.

#include "stdafx.h"
//#include "version.h"

#include <cmath>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <iomanip>
#include <iostream>

#include "linearplot.h"
#include "shader.h"

#define POSITION_VECTOR_SIZE 3 
#define COLOR_VECTOR_SIZE 4
#define STRIDE (POSITION_VECTOR_SIZE + COLOR_VECTOR_SIZE)

const int ARRAY_SIZE = 9;

int displayGraphics(float *vertices, size_t size, int count);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
std::vector<Position<GLfloat>> populateGraph(GLfloat xLow, GLfloat xHigh);
void processInput(GLFWwindow *window);

int main(int argc, char *argv[])
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const int SAMPLE_COUNT = 500 * STRIDE;
	const int STEP = STRIDE;
	//const float BACKGROUND_RED = 0.2;
	//const float BACKGROUND_GREEN = 0.3;
	//const float BACKGROUND_BLUE = 0.3;
	int exitStatus;
	LinearPlot linearPlot;
	GLfloat vertices[SAMPLE_COUNT];
	std::vector<Position<GLfloat>> graph;

	for (int i = 0; i < SAMPLE_COUNT; i++) {
		vertices[i] = 0;
	}
	graph = populateGraph(0.0f, 100.0f);
	linearPlot.setGraph(graph);
	linearPlot.setVertices(vertices);
	linearPlot.setScreenWidth(WIDTH);
	linearPlot.setScreenHeight(HEIGHT);
	linearPlot.xGridStart = 0;
	linearPlot.xGridEnd = 102;
	linearPlot.xGridResolution = 10;
	linearPlot.yGridStart = 0;
	linearPlot.yGridEnd = 50;
	linearPlot.yGridResolution = 10;
	linearPlot.createGrid();
	linearPlot.createGraph();
	for (int i = 0; i < SAMPLE_COUNT; i++) {
		if (i % STRIDE == 0) {
			std::cout << std::endl;
		}
		std::cout << std::setprecision(3) << vertices[i] << "\t";
	}
	std::cout << std::endl;
	std::cout << "Number of vertices: " << SAMPLE_COUNT / STEP;
	std::cout << std::endl;
	//displayGraphics(vertices, static_cast<GLsizei>(SAMPLE_COUNT / STEP));
	//displayGraphics(vertices, sizeof(vertices), static_cast<GLsizei>(SAMPLE_COUNT/ STEP));
	exitStatus = displayGraphics(vertices, sizeof(vertices), SAMPLE_COUNT / STEP);

    return exitStatus;
}

int displayGraphics(float *vertices, size_t size, int count)
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	GLFWwindow *window;
	unsigned int VAO;
	unsigned int VBO;
	/*
	int vertexShader;
	int fragmentShader;
	int shaderProgram;
	int success;
	char infoLog[512];
	*/	

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Photonics Sample", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
#ifdef WORK_VERSION
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
#else
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
#endif

#ifdef WORK_VERSION
	Shader myShader("C:/Users/Stewart/Documents/Visual Studio 2017/Projects/photonics_sample_6/photonics_sample_6/core.vert",
		"C:/Users/Stewart/Documents/Visual Studio 2017/Projects/photonics_sample_6/photonics_sample_6/core.frag");
#else
	Shader myShader("C:/Users/Stewart/source/repos/photonics_sample_4/photonics_sample_4/core.vert",
		"C:/Users/Stewart/source/repos/photonics_sample_4/photonics_sample_4/core.frag");
#endif WORK_VERSION
	

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, POSITION_VECTOR_SIZE, GL_FLOAT, GL_FALSE, STRIDE * sizeof(GLfloat), (void *)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, COLOR_VECTOR_SIZE, GL_FLOAT, GL_FALSE, STRIDE * sizeof(GLfloat), (void *)(POSITION_VECTOR_SIZE * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	while (!glfwWindowShouldClose(window)) {
		/*
		processInput(window);
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		glfwPollEvents();
		*/
		myShader.use();
		//myShader.setFloat("someUniform", 1.0f);
		processInput(window);
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glDrawArrays(GL_LINE_STRIP, 0, count);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

std::vector<Position<GLfloat>> populateGraph(GLfloat xLow, GLfloat xHigh)
{
	const GLfloat RESOLUTION = 200;
	GLfloat increment;
	std::vector<Position<GLfloat>> output;
	Position<GLfloat> position;

	if (xHigh > xLow) {
		
	} else {
		GLfloat temporary = xHigh;
		xHigh = xLow;
		xLow = temporary;
	}	
	increment = (xHigh - xLow) / RESOLUTION;
	for (GLfloat i = xLow; i < xHigh; i += increment) {
		position.setX(i);
		position.setY(static_cast<GLfloat>(sqrt(i)));
		position.setZ(0);
		output.push_back(position);
	}

	return output;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}