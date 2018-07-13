#pragma once
#ifndef _ACCESSORY_H_
#define _ACCESSORY_H_

#include <GLFW/glfw3.h>
#include <vector>

#include "position.h"

int access_model(GLfloat *vertices, int model); // prototype for ModelLoader class
int displayGraphics(GLfloat *vertices, size_t size); // uses ModelLoader class
int displayGraphics(GLfloat *vertices, size_t size, int count);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
std::vector<Position<GLfloat>> populateGraph(GLfloat xLow, GLfloat xHigh);
void processInput(GLFWwindow *window);

#endif // !_ACCESSORY_H_

