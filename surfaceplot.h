#pragma once
#ifndef _SURFACEPLOT_H_
#define _SURFACEPLOT_H_

#include "plot.h"
#include "version.h"

#ifdef WORK_VERSION
	#include <GL/glew.h>
#else
	#include <glad/glad.h>
#endif // WORK_VERSION

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

