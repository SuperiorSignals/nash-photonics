#include "linearprimitive.h"


LinearPrimitive::LinearPrimitive()
{
	counter = 0;
	stride = ELEMENT_SIZE;
	backgroundColor.setA(0.0f);
}

Color<float> LinearPrimitive::getBackgroundColor() { return backgroundColor; }
int LinearPrimitive::getCounter() { return counter; }
Color<float> LinearPrimitive::getElementColor() { return elementColor; }
int LinearPrimitive::getStride() { return stride; }
GLfloat *LinearPrimitive::getVertices() { return vertices; }

void LinearPrimitive::setBackgroundColor(float r, float g, float b)
{
	backgroundColor.setColor(r, g, b);
}

void LinearPrimitive::setBackgroundColor(Color<float> input) { backgroundColor = input; }
void LinearPrimitive::setCounter(int input) { counter = input; }

void LinearPrimitive::setElementColor(float r, float g, float b)
{
	elementColor.setColor(r, g, b);
}

void LinearPrimitive::setElementColor(Color<float> input) { elementColor = input; }

void LinearPrimitive::setStride(int input) { stride = input; }
void LinearPrimitive::setVertices(float *input) { vertices = input; }

void LinearPrimitive::line(Position<float> start, Position<float> end)
{
	vertices[stride * counter + 0] = start.getX();
	vertices[stride * counter + 1] = start.getY();
	vertices[stride * counter + 2] = start.getZ();
	vertices[stride * counter + 3] = backgroundColor.getR();
	vertices[stride * counter + 4] = backgroundColor.getG();
	vertices[stride * counter + 5] = backgroundColor.getB();
	vertices[stride * counter + 6] = backgroundColor.getA();
	++counter;
	vertices[stride * counter + 0] = start.getX();
	vertices[stride * counter + 1] = start.getY();
	vertices[stride * counter + 2] = start.getZ();
	vertices[stride * counter + 3] = elementColor.getR();
	vertices[stride * counter + 4] = elementColor.getG();
	vertices[stride * counter + 5] = elementColor.getB();
	vertices[stride * counter + 6] = elementColor.getA();
	++counter;
	vertices[stride * counter + 0] = end.getX();
	vertices[stride * counter + 1] = end.getY();
	vertices[stride * counter + 2] = end.getZ();
	vertices[stride * counter + 3] = elementColor.getR();
	vertices[stride * counter + 4] = elementColor.getG();
	vertices[stride * counter + 5] = elementColor.getB();
	vertices[stride * counter + 6] = elementColor.getA();
	++counter;
	vertices[stride * counter + 0] = end.getX();
	vertices[stride * counter + 1] = end.getY();
	vertices[stride * counter + 2] = end.getZ();
	vertices[stride * counter + 3] = backgroundColor.getR();
	vertices[stride * counter + 4] = backgroundColor.getG();
	vertices[stride * counter + 5] = backgroundColor.getB();
	vertices[stride * counter + 6] = backgroundColor.getA();
	++counter;
}