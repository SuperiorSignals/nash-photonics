#pragma once
#ifndef _LINEARPLOT_H_
#define _LINEARPLOT_H_

#include "plot.h"

//#include <GL/glew.h>
#include <glad/glad.h>
#include <vector>

#include "position.h"

class LinearPlot : public Plot {
public:
	LinearPlot();
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
	int screenWidth;
	int screenHeight;

	std::vector<Position<GLfloat>> graph;

	void createGrid(GLfloat vertices[], int vertexNumber);
	void createGraph(GLfloat vertices[], int vertexNumber);

};

#endif // !_LINEARPLOT_H_

