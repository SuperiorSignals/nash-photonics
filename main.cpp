// Author: Stewart Nash
// Year: 2018
// File: main.cpp
// Description: Defines the entry point for the console application.

#include "stdafx.h"
//#include "version.h"
#include "accessory.h"

#include <cmath>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <iomanip>
#include <iostream>

#include "fdtd.h"
#include "linearplot.h"
#include "shader.h"
#include "test.h"

const int ARRAY_SIZE = 9;

int main(int argc, char *argv[])
{
	return main_function_6(argc, argv);
}

/*
int displayGraphics(GLfloat *vertices, size_t size)
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	GLFWwindow *window;
	unsigned int VAO;
	unsigned int VBO;
	int counter;
	glm::mat4 model;
	glm::vec3 firstPosition(0.0f, 0.0f, 0.0f);
	glm::vec3 secondPosition(0.0f, 0.05f, 0.0f);

	int totalRenders;
	std::ofstream outputFile;

	std::cout << "diplaygraphics() vertices: " << vertices;
	std::cout << std::endl;
	outputFile.open("photonics_output.txt");
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

	totalRenders = 0;
	while (!glfwWindowShouldClose(window)) {
		myShader.use();
		processInput(window);
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		model = glm::mat4(1.0f);
		int i = 0;

		//do {
		//	counter = access_model(vertices, i);
		//	for (int i = 0; i < 200; i++) {
		//		std::cout << " " << vertices[i];
		//	}
		//	counter = 200;
		//	model = glm::translate(model, firstPosition);
		//	myShader.setMat4("model", model);
		//	glDrawArrays(GL_LINE_STRIP, 0, counter);
		//	++i;
		//	if (outputFile.is_open()) {
		//		if (totalRenders < 2) {
		//			outputFile << "Render #: " << totalRenders;
		//			outputFile << std::endl;
		//			for (int j = 0; j < 200; j++) {
		//				if (j % STRIDE == 0) {
		//					outputFile << std::endl;
		//				}
		//				outputFile << std::setprecision(3) << vertices[j] << "\t";
		//			}
		//			++totalRenders;
		//		}
		//	}
		//} while (i < 2);

		counter = access_model(vertices, 0);
		model = glm::translate(model, firstPosition);
		myShader.setMat4("model", model);
		glDrawArrays(GL_LINE_STRIP, 0, counter);

		glfwSwapBuffers(window);
		glfwPollEvents();
		//system("pause");
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	if (outputFile.is_open()) {

		for (int j = 0; j < size; j++) {
			if (j % STRIDE == 0) {
				outputFile << std::endl;
			}
			outputFile << std::setprecision(3) << vertices[j] << "\t";
		}
	}

	glfwTerminate();
	outputFile.close();
	return 0;
}
*/


int displayGraphics(GLfloat *vertices, size_t size)
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	GLFWwindow *window;
	unsigned int VAO;
	unsigned int VBO;
	int counter;
	glm::mat4 model;
	glm::vec3 firstPosition(0.0f, 0.0f, 0.0f);
	glm::vec3 secondPosition(0.0f, 0.05f, 0.0f);

	int totalRenders;
	std::ofstream outputFile;

	std::cout << "diplaygraphics() vertices: " << vertices;
	std::cout << std::endl;
	outputFile.open("photonics_output.txt");
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

	totalRenders = 0;
	while (!glfwWindowShouldClose(window)) {
		myShader.use();
		processInput(window);
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		model = glm::mat4(1.0f);
		int i = 0;

		counter = access_model(vertices, 0);
		model = glm::translate(model, firstPosition);
		myShader.setMat4("model", model);
		glDrawArrays(GL_LINE_STRIP, 0, counter);

		glfwSwapBuffers(window);
		glfwPollEvents();
		//system("pause");
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);


	if (outputFile.is_open()) {

		for (int j = 0; j < size; j++) {
			if (j % STRIDE == 0) {
				outputFile << std::endl;
			}
			outputFile << std::setprecision(3) << vertices[j] << "\t";
		}
	}

	glfwTerminate();
	outputFile.close();
	return 0;
}

int displayGraphics(GLfloat *vertices, size_t size, int count)
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	GLFWwindow *window;
	unsigned int VAO;
	unsigned int VBO;
	glm::mat4 model;
	glm::vec3 firstPosition(0.0f, 0.0f, 0.0f);
	glm::vec3 secondPosition(0.0f, 0.05f, 0.0f);
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
		myShader.use();
		processInput(window);
		glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glBindVertexArray(VAO);
		model = glm::mat4(1.0f);
		model = glm::translate(model, firstPosition);
		myShader.setMat4("model", model);
		glDrawArrays(GL_LINE_STRIP, 0, count);
		//model = glm::translate(model, secondPosition);
		//myShader.setMat4("model", model);
		//glDrawArrays(GL_LINE_STRIP, 0, 100);
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

int access_model(GLfloat *vertices, int model)
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const int SAMPLE_COUNT = MULTIPLIER * STRIDE;
	const int STEP = STRIDE;
	LinearPlot linearPlot;
	std::vector<Position<GLfloat>> graph;
	int counter;
	GLfloat copy[SAMPLE_COUNT];

	counter = 0;
	if (model == 0) {
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
		counter = linearPlot.getCounter();
		/*
			for (int i = 0; i < SAMPLE_COUNT; i++) {
			if (i % STRIDE == 0) {
				std::cout << std::endl;
			}
			std::cout << std::setprecision(3) << vertices[i] << "\t";
		}
		std::cout << std::endl;
		std::cout << "Number of vertices: " << SAMPLE_COUNT / STEP;
		std::cout << std::endl;
		std::cout << "Vertex count: " << counter;
		std::cout << std::endl;	
		*/
	} else if (model == 1) {
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
		linearPlot.createGraph();
		counter = linearPlot.getCounter();
		/*
				for (int i = 0; i < SAMPLE_COUNT; i++) {
			if (i % STRIDE == 0) {
				std::cout << std::endl;
			}
			std::cout << std::setprecision(3) << vertices[i] << "\t";
		}
		std::cout << std::endl;
		std::cout << "Number of vertices: " << SAMPLE_COUNT / STEP;
		std::cout << std::endl;
		std::cout << "Vertex count: " << counter;
		std::cout << std::endl;
		*/
	} else if (model == 2) {
		counter = 0;
	} else {
		counter = 0;
	}
	for (int i = 0; i < 200; i++) {
		std::cout << " " << vertices[i];
	}

	return counter;
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

/*
TO DO:
1. Pass array size into LinearPlot class as maximum number
2. Change grid drawing scheme of LinearPlot class
3. Read information from file into dynamic array
*/