#pragma once
#ifndef _LINEARPRIMITIVE_H_
#define _LINEARPRIMITIVE_H_

#include "version.h"

#ifdef WORK_VERSION
#include <GL/glew.h>
#else
#include <glad/glad.h>
#endif // WORK_VERSION
#include "color.h"
#include "position.h"

const int ELEMENT_SIZE = 7;

class LinearPrimitive {
public:
	LinearPrimitive();
	Color<float> getBackgroundColor();
	int getCounter();
	Color<float> getElementColor();
	int getStride();
	GLfloat *getVertices();
	void setBackgroundColor(float r, float g, float b);
	void setBackgroundColor(Color<float> input);
	void setCounter(int input);
	void setElementColor(float r, float g, float b);
	void setElementColor(Color<float> input);
	void setStride(int input);
	void setVertices(GLfloat *vertices);

	void line(Position<GLfloat> start, Position<GLfloat> end);
	void segment(Position<GLfloat> start, Position<GLfloat> end);
	void box(Position<GLfloat> start, Position<GLfloat> end);
	
private:
	GLfloat *vertices; // pointer to vertex array
	Color<float> backgroundColor;
	Color<float> elementColor;
	int counter;	// current vertex position
	int maximum;	// maximum number of elements
	int stride;
};

#endif _LINEARPRIMITIVE_H_