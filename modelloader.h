#pragma once
#ifndef _MODELLOADER_H_
#define _MODELLOADER_H_

#include "version.h"

#ifdef WORK_VERSION
	#include <GL/glew.h>
#else
	#include <glad/glad.h>
#endif // WORK_VERSION
#include <functional>



class ModelLoader {
public:
	int getCurrent();
	int getModel(GLfloat *vertices, int modelNumber);
	int getModel(GLfloat *vertices);
	int getTotal();
	bool isModelRemaining();
	void setCallbackFunction(std::function<void(GLfloat *, int)> input);
	void setCurrent(int input);
	void setTotal(int input);

private:
	int total;
	int current;
	std::function<void(GLfloat *, int)> callbackFunction;
};

#endif // !_MODELLOADER_H_
