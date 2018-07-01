#include "linearplot.h"

//#include <GL/glew.h>
#include <glad/glad.h>
#include <vector>

#include "color.h"
#include "linearprimitive.h"

#define STEP_SIZE 6

LinearPlot::LinearPlot()
{
	xScale = 1.0;
	yScale = 1.0;
	screenWidth = 480;
	screenHeight = 480;
}

void LinearPlot::createGrid(GLfloat vertex[], int vertexNumber)
{
	LinearPrimitive gridConstruction;
	GLint verticalSize;
	GLint horizontalSize;
	int totalCount;
	GLfloat aspectRatio;
	GLfloat globalScaling;
	GLfloat horizontalScaling;
	GLfloat verticalScaling;
	Position<float> startPosition;
	Position<float> endPosition;
	Color<float> gridColor;
	Color<float> backgroundColor;

	aspectRatio = static_cast<float>(screenHeight) / static_cast<float>(screenWidth);
	gridConstruction.setVertices(vertex);
	totalCount = 0;

	verticalSize = yGridEnd - yGridStart;
	horizontalSize = xGridEnd - xGridStart;
	globalScaling = ((horizontalSize > verticalSize) ? horizontalSize : verticalSize);
	globalScaling = 1 / globalScaling;

	horizontalScaling = globalScaling * aspectRatio;
	horizontalScaling *= xScale;
	verticalScaling = globalScaling;
	verticalScaling *= yScale;

	verticalSize = (yGridEnd - yGridStart) / yGridResolution;
	horizontalSize = (xGridEnd - xGridStart) / xGridResolution;

	gridColor.setColor(0.75f, 0.75f, 0.75f);
	backgroundColor.setColor(0.25f, 0.25f, 0.25f, 0.0f);
	gridConstruction.setElementColor(gridColor);
	gridConstruction.setBackgroundColor(backgroundColor);
	// draw box outline

	// draw grid
	for (int i = 0; i < verticalSize; i++) {
		startPosition.setX(horizontalScaling * (xGridStart));
		startPosition.setY(verticalScaling * (i * yGridResolution));
		startPosition.setZ(0);
		endPosition.setX(horizontalScaling * (xGridEnd));
		endPosition.setY(verticalScaling * (i * yGridResolution));
		endPosition.setZ(0);
		gridConstruction.line(startPosition, endPosition);
	}
	for (int i = 0; i < horizontalSize; i++) {
		startPosition.setX(horizontalScaling * (i * xGridResolution));
		startPosition.setY(verticalScaling * (yGridStart));
		startPosition.setZ(0);
		endPosition.setX(horizontalScaling * (i * xGridResolution));
		endPosition.setY(verticalScaling * (yGridEnd));
		endPosition.setZ(0);
		gridConstruction.line(startPosition, endPosition);
	}
}

void LinearPlot::createGraph(GLfloat vertex[], int vertexNumber)
{

}

void LinearPlot::createGrid()
{
	GLint verticalSize;
	GLint horizontalSize;
	int totalCount;
	GLfloat aspectRatio;
	GLfloat globalScaling;
	GLfloat horizontalScaling;
	GLfloat verticalScaling;
	Position<float> startPosition;
	Position<float> endPosition;
	Color<float> gridColor;
	Color<float> backgroundColor;

	aspectRatio = static_cast<float>(screenHeight) / static_cast<float>(screenWidth);
	linearPrimitive.setVertices(vertices);
	totalCount = 0;

	verticalSize = yGridEnd - yGridStart;
	horizontalSize = xGridEnd - xGridStart;
	globalScaling = ((horizontalSize > verticalSize) ? horizontalSize : verticalSize);
	globalScaling = 1 / globalScaling;

	horizontalScaling = globalScaling * aspectRatio;
	horizontalScaling *= xScale;
	verticalScaling = globalScaling;
	verticalScaling *= yScale;

	verticalSize = (yGridEnd - yGridStart) / yGridResolution;
	horizontalSize = (xGridEnd - xGridStart) / xGridResolution;

	gridColor.setColor(0.75f, 0.75f, 0.75f);
	backgroundColor.setColor(0.25f, 0.25f, 0.25f, 0.0f);
	linearPrimitive.setElementColor(gridColor);
	linearPrimitive.setBackgroundColor(backgroundColor);
	// draw box outline
	startPosition.setX(horizontalScaling * xGridStart);
	startPosition.setY(verticalScaling * yGridStart);
	startPosition.setZ(0);
	endPosition.setX(horizontalScaling * xGridEnd);
	endPosition.setY(verticalScaling * yGridStart);
	endPosition.setZ(0);
	linearPrimitive.line(startPosition, endPosition);

	startPosition.setX(horizontalScaling * xGridEnd);
	startPosition.setY(verticalScaling * yGridStart);
	startPosition.setZ(0);
	endPosition.setX(horizontalScaling * xGridEnd);
	endPosition.setY(verticalScaling * yGridEnd);
	endPosition.setZ(0);
	linearPrimitive.line(startPosition, endPosition);

	endPosition.setX(horizontalScaling * xGridEnd);
	endPosition.setY(verticalScaling * yGridEnd);
	endPosition.setZ(0);
	startPosition.setX(horizontalScaling * xGridStart);
	startPosition.setY(verticalScaling * yGridEnd);
	startPosition.setZ(0);
	linearPrimitive.line(endPosition, startPosition);

	startPosition.setX(horizontalScaling * xGridStart);
	startPosition.setY(verticalScaling * yGridEnd);
	startPosition.setZ(0);
	endPosition.setX(horizontalScaling * xGridStart);
	endPosition.setY(verticalScaling * yGridStart);
	endPosition.setZ(0);
	linearPrimitive.line(startPosition, endPosition);

	// draw grid
	for (int i = 0; i < verticalSize; i++) {
		startPosition.setX(horizontalScaling * (xGridStart));
		startPosition.setY(verticalScaling * (i * yGridResolution));
		startPosition.setZ(0);
		endPosition.setX(horizontalScaling * (xGridEnd));
		endPosition.setY(verticalScaling * (i * yGridResolution));
		endPosition.setZ(0);
		linearPrimitive.line(startPosition, endPosition);
	}
	for (int i = 0; i < horizontalSize; i++) {
		startPosition.setX(horizontalScaling * (i * xGridResolution));
		startPosition.setY(verticalScaling * (yGridStart));
		startPosition.setZ(0);
		endPosition.setX(horizontalScaling * (i * xGridResolution));
		endPosition.setY(verticalScaling * (yGridEnd));
		endPosition.setZ(0);
		linearPrimitive.line(startPosition, endPosition);
	}
}

void LinearPlot::createGraph()
{

}

int LinearPlot::getScreenHeight() { return screenHeight; }
int LinearPlot::getScreenWidth() { return screenWidth; }
GLfloat *LinearPlot::getVertices() { return vertices; }
void LinearPlot::setScreenHeight(int input) { screenHeight = input; }
void LinearPlot::setScreenWidth(int input) { screenWidth = input; }
void LinearPlot::setVertices(GLfloat *input) { vertices = input; }