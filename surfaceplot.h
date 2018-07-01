#pragma once
#ifndef _SURFACEPLOT_H_
#define _SURFACEPLOT_H_

#include "plot.h"

//#include <GL/glew.h>
#include <glad/glad.h>

class SurfacePlot : public Plot {
public:
	GLfloat xGridStart;
	GLfloat xGridEnd;
	GLfloat xGridResolution;
	GLfloat yGridStart;
	GLfloat yGridEnd;
	GLfloat yGridResolution;
	GLfloat zGridStart;
	GLfloat zGridEnd;
	GLfloat zGridResolution;
	GLfloat xOriginLocation;
	GLfloat xScale;
	GLfloat yOriginLocation;
	GLfloat yScale;
	GLfloat zOriginLocation;
	GLfloat zScale;

	int screenWidth;
	int screenHeight;
};

#endif // !_SURFACEPLOT_H_

