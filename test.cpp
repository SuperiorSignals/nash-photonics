#include "test.h"

#include "version.h"

#include <cstdlib>
#ifdef WORK_VERSION
	#include <GL/glew.h>
#else
	#include <glad/glad.h>
#endif // WORK_VERSION
#include <iomanip>
#include <iostream>
#include <vector>

#include "accessory.h"
#include "fdtd.h"
#include "filereader.h"
#include "linearplot.h"

int main_function_1(int argc, char *argv[])
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
	exitStatus = displayGraphics(vertices, sizeof(vertices), SAMPLE_COUNT / STEP);

	return exitStatus;
}

int main_function_2(int argc, char *argv[])
{
	const int SAMPLE_COUNT = MULTIPLIER * STRIDE;
	int exitStatus;
	GLfloat vertices[SAMPLE_COUNT];

	exitStatus = displayGraphics(vertices, sizeof(vertices));

	return exitStatus;
}

int main_function_3(int argc, char *argv[])
{
	const int SAMPLE_COUNT = MULTIPLIER * STRIDE;
	int exitStatus;
	GLfloat vertices[SAMPLE_COUNT];

	exitStatus = displayGraphics(vertices, sizeof(vertices));

	std::cout << "main() vertices: " << vertices;
	std::cout << std::endl;

	return exitStatus;
}

int main_function_4(int argc, char *argv[])
{
	int exitStatus;

	fdtdSixFiveNine(5E14);
	exitStatus = 0;

	return exitStatus;
}

int main_function_5(int argc, char *argv[])
{
	int exitStatus;
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const int SAMPLE_COUNT = 1024 * STRIDE;
	const int STEP = STRIDE;
	double deltaX;
	std::vector<double> information;
	Position<double> temporary;
	GLfloat vertices[SAMPLE_COUNT];
	std::vector<Position<double>> graph;
	FileReader fileReader;
	LinearPlot linearPlot;

	exitStatus = 0;
	fdtdSixFiveNine(5E14);
	fileReader.setFileName("fdtd_5_69.txt");
	information = fileReader.getArray();
	std::cout << "Number of Arrays: " << fileReader.getNumberOfArrays();
	std::cout << std::endl;
	std::cout << "Number of Components: " << fileReader.getNumberOfComponents();
	std::cout << std::endl;
	std::cout << "Number of Elements: " << fileReader.getNumberOfElements();
	std::cout << std::endl;
	std::cout << "Information size: " << information.size();
	std::cout << std::endl;

	deltaX = 102.0 / static_cast<double>(information.size());
	//for (int i = 0; i < 200; i++) {
	//	information.pop_back();
	//}
	for (int i = 0; i < information.size(); i++) {
		temporary.setX(deltaX * static_cast<double>(i));
		temporary.setY(information[i]);
		temporary.setZ(0.0);
		graph.push_back(temporary);
	}
	for (int i = 0; i < SAMPLE_COUNT; i++) {
		vertices[i] = 0;
	}
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
	//for (int i = 0; i < SAMPLE_COUNT; i++) {
	//	if (i % STRIDE == 0) {
	//		std::cout << std::endl;
	//	}
	//	std::cout << std::setprecision(3) << vertices[i] << "\t";
	//}
	//std::cout << std::endl;
	std::cout << "Number of vertices: " << SAMPLE_COUNT / STEP;
	std::cout << std::endl;
	exitStatus = displayGraphics(vertices, sizeof(vertices), SAMPLE_COUNT / STEP);
	
	system("pause");
	return exitStatus;
}

int main_function_6(int argc, char *argv[])
{
	const int ARRAY_SIZE = 512;
	const int ARRAY_NUMBER = 1024;
	int exitStatus;
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const int SAMPLE_COUNT = 1024 * STRIDE;
	const int STEP = STRIDE;
	double deltaX;
	double information[ARRAY_NUMBER][ARRAY_SIZE];
	Position<double> temporary;
	GLfloat vertices[SAMPLE_COUNT];
	std::vector<Position<double>> graph;
	FileReader fileReader;
	LinearPlot linearPlot;

	exitStatus = 0;
	fdtdSixFiveNine(5E14);
	fileReader.setFileName("fdtd_5_69.txt");
	fileReader.fillArray(information);
	std::cout << "Number of Arrays: " << fileReader.getNumberOfArrays();
	std::cout << std::endl;
	std::cout << "Number of Components: " << fileReader.getNumberOfComponents();
	std::cout << std::endl;
	std::cout << "Number of Elements: " << fileReader.getNumberOfElements();
	std::cout << std::endl;

	deltaX = 102.0 / static_cast<double>(ARRAY_SIZE);
	//for (int i = 0; i < 200; i++) {
	//	information.pop_back();
	//}
	for (int j = 0; j < ARRAY_SIZE; j++) {
		temporary.setX(deltaX * static_cast<double>(j));
		temporary.setY(information[0][j]);
		temporary.setZ(0.0);
		graph.push_back(temporary);
	}
	for (int i = 0; i < SAMPLE_COUNT; i++) {
		vertices[i] = 0;
	}
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
	//for (int i = 0; i < SAMPLE_COUNT; i++) {
	//	if (i % STRIDE == 0) {
	//		std::cout << std::endl;
	//	}
	//	std::cout << std::setprecision(3) << vertices[i] << "\t";
	//}
	//std::cout << std::endl;
	std::cout << "Number of vertices: " << SAMPLE_COUNT / STEP;
	std::cout << std::endl;
	exitStatus = displayGraphics(vertices, sizeof(vertices), SAMPLE_COUNT / STEP);

	system("pause");
	return exitStatus;
}

int main_function_7(int argc, char *argv[])
{
	int exitStatus;

	exitStatus = 0;

	return exitStatus;
}

int main_function_8(int argc, char *argv[])
{
	int exitStatus;

	exitStatus = 0;

	return exitStatus;
}
