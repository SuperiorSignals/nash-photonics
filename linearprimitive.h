#pragma once
#ifndef _LINEARPRIMITIVE_H_
#define _LINEARPRIMITIVE_H_

#include <glad/glad.h>
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
	float *getVertices();
	void setBackgroundColor(float r, float g, float b);
	void setBackgroundColor(Color<float> input);
	void setCounter(int input);
	void setElementColor(float r, float g, float b);
	void setElementColor(Color<float> input);
	void setStride(int input);
	void setVertices(float *vertices);

	void line(Position<float> start, Position<float> end);
	
private:
	GLfloat *vertices; // pointer to vertex array
	Color<float> backgroundColor;
	Color<float> elementColor;
	int counter;	// current vertex position
	int maximum;	// maximum number of elements
	int stride;
};

#endif _LINEARPRIMITIVE_H_