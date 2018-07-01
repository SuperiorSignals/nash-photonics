#pragma once
#ifndef _LINEARPLOT_H_
#define _LINEARPLOT_H_

#include "plot.h"

//#include <GL/glew.h>
#include <glad/glad.h>
#include <vector>

#include "linearprimitive.h"
#include "position.h"

class LinearPlot : public Plot {
public:
	LinearPlot();
	void createGrid(GLfloat vertex[], int vertexNumber);
	void createGraph(GLfloat vertex[], int vertexNumber);
	void createGrid();
	void createGraph();
	int getScreenHeight();
	int getScreenWidth();
	GLfloat *getVertices();
	void setScreenHeight(int input);
	void setScreenWidth(int input);
	void setVertices(GLfloat *input);

	GLfloat xGridStart;
	GLfloat xGridEnd;
	GLfloat xGridResolution;
	GLfloat yGridStart;
	GLfloat yGridEnd;
	GLfloat yGridResolution;
	GLfloat xOriginLocation;
	GLfloat xScale;
	GLfloat yOriginLocation;
	GLfloat yScale;
	int screenHeight;
	int screenWidth;

	std::vector<Position<GLfloat>> graph;
private:
	LinearPrimitive linearPrimitive;
	GLfloat *vertices;
	int arraySize;
};

#endif // !_LINEARPLOT_H_

