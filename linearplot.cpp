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
}

void LinearPlot::createGrid(GLfloat vertices[], int vertexNumber)
{
	LinearPrimitive gridConstruction;
	int verticalSize;
	int horizontalSize;
	int totalCount;
	GLfloat aspectRatio;
	GLfloat horizontalScaling;
	GLfloat verticalScaling;
	Position<float> startPosition;
	Position<float> endPosition;
	Color<float> gridColor;
	Color<float> backgroundColor;

	gridConstruction.setVertices(vertices);
	totalCount = 0;
	verticalSize = (yGridEnd - yGridStart) / yGridResolution;
	horizontalSize = (xGridEnd - xGridStart) / xGridResolution;

	aspectRatio = static_cast<float>(screenHeight) / static_cast<float>(screenWidth);
	horizontalScaling = 1.0 / static_cast<float>(horizontalSize * xGridResolution);
	horizontalScaling *= xScale;
	horizontalScaling *= aspectRatio;
	verticalScaling = 1.0 / static_cast<float>(verticalSize * yGridResolution);
	verticalScaling *= yScale;

	gridColor.setColor(0.75f, 0.75f, 0.75f);
	backgroundColor.setColor(0.25f, 0.25f, 0.25f, 0.0f);
	gridConstruction.setElementColor(gridColor);
	gridConstruction.setBackgroundColor(backgroundColor);
	for (int i = 0; i < verticalSize; i += 2) {
		startPosition.setX(horizontalScaling * (xGridStart));
		startPosition.setY(verticalScaling * (i * yGridResolution));
		startPosition.setZ(0);
		endPosition.setX(horizontalScaling * (xGridEnd));
		endPosition.setY(verticalScaling * (i * yGridResolution));
		endPosition.setZ(0);
		gridConstruction.line(startPosition, endPosition);
	}
	totalCount = verticalSize;
	for (int i = totalCount; i < totalCount + horizontalSize; i += 2) {
		startPosition.setX(horizontalScaling * (i * xGridResolution));
		startPosition.setY(verticalScaling * (yGridStart));
		startPosition.setZ(0);
		endPosition.setX(horizontalScaling * (i * xGridResolution));
		endPosition.setY(verticalScaling * (yGridEnd));
		endPosition.setZ(0);
		gridConstruction.line(startPosition, endPosition);
	}
	totalCount += horizontalSize;
}

/*
void LinearPlot::createGrid(GLfloat vertices[], int vertexNumber)
{
	int verticalSize;
	int horizontalSize;
	int totalCount;
	GLfloat aspectRatio;
	GLfloat horizontalScaling;
	GLfloat verticalScaling;
	
	totalCount = 0;
	verticalSize = (yGridEnd - yGridStart) / yGridResolution;
	horizontalSize = (xGridEnd - xGridStart) / xGridResolution;

	aspectRatio = static_cast<float>(screenHeight) / static_cast<float>(screenWidth);
	horizontalScaling = 1.0 / static_cast<float>(horizontalSize * xGridResolution);
	horizontalScaling *= xScale;
	horizontalScaling *= aspectRatio;
	verticalScaling = 1.0 / static_cast<float>(verticalSize * yGridResolution);
	verticalScaling *= yScale;

	for (int i = 0; i < verticalSize; i += 2) {
		vertices[i * STEP_SIZE + 0] = horizontalScaling * (xGridStart);
		vertices[i * STEP_SIZE + 1] = verticalScaling * (i * yGridResolution);
		vertices[i * STEP_SIZE + 2] = 0;
		vertices[i * STEP_SIZE + 3] = 1.0;
		vertices[i * STEP_SIZE + 4] = 1.0;
		vertices[i * STEP_SIZE + 5] = 1.0;
		vertices[(i + 1) * STEP_SIZE + 0] = horizontalScaling * (xGridEnd);
		vertices[(i + 1) * STEP_SIZE + 1] = verticalScaling * (i * yGridResolution);
		vertices[(i + 1) * STEP_SIZE + 2] = 0;
		vertices[(i + 1) * STEP_SIZE + 3] = 1.0;
		vertices[(i + 1) * STEP_SIZE + 4] = 1.0;
		vertices[(i + 1) * STEP_SIZE + 5] = 1.0;
	}
	totalCount = verticalSize;
	for (int i = totalCount; i < totalCount + horizontalSize; i += 2) {
		vertices[i * STEP_SIZE + 0] = horizontalScaling * (i * xGridResolution);
		vertices[i * STEP_SIZE + 1] = verticalScaling * (yGridStart);
		vertices[i * STEP_SIZE + 2] = 0;
		vertices[i * STEP_SIZE + 3] = 1.0;
		vertices[i * STEP_SIZE + 4] = 1.0;
		vertices[i * STEP_SIZE + 5] = 1.0;
		vertices[(i + 1) * STEP_SIZE + 0] = horizontalScaling * (i * xGridResolution);
		vertices[(i + 1) * STEP_SIZE + 1] = verticalScaling * (yGridEnd);
		vertices[(i + 1) * STEP_SIZE + 2] = 0;
		vertices[(i + 1) * STEP_SIZE + 3] = 1.0;
		vertices[(i + 1) * STEP_SIZE + 4] = 1.0;
		vertices[(i + 1) * STEP_SIZE + 5] = 1.0;
	}
	totalCount += horizontalSize;
}
*/

void LinearPlot::createGraph(GLfloat vertices[], int vertexNumber)
{

}