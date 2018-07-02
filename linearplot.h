#pragma once
#ifndef _LINEARPLOT_H_
#define _LINEARPLOT_H_

#include "plot.h"
#include "version.h"

#ifdef WORK_VERSION
	#include <GL/glew.h>
#else
	#include <glad/glad.h>
#endif // WORK_VERSION
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
	Color<GLfloat> getBackroundColor();
	std::vector<Position<GLfloat>> getGraph();
	Color<GLfloat> getGraphColor();
	Color<GLfloat> getGridColor();
	int getScreenHeight();
	int getScreenWidth();
	GLfloat *getVertices();
	void setBackgroundColor(Color<GLfloat> input);
	void setGraph(std::vector<Position<GLfloat>> input);
	void setGraphColor(Color<GLfloat> input);
	void setGridColor(Color<GLfloat> input);
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

private:
	LinearPrimitive linearPrimitive;
	GLfloat *vertices;
	std::vector<Position<GLfloat>> graph;
	int vertexSize;
	Color<GLfloat> backgroundColor;
	Color<GLfloat> gridColor;
	Color<GLfloat> graphColor;
};

#endif // !_LINEARPLOT_H_

