#include "modelloader.h"

int ModelLoader::getCurrent() { return current; }
int ModelLoader::getModel(GLfloat *vertices, int modelNumber)
{
	int vertexNumber;

	return vertexNumber;
}

int ModelLoader::getModel(GLfloat *vertices)
{
	int vertexNumber;

	return vertexNumber;
}

int ModelLoader::getTotal() { return total; }

bool ModelLoader::isModelRemaining()
{
	if (current < total) {
		return true;
	}
	
	return false;
}

void ModelLoader::setCallbackFunction(std::function<void(GLfloat *, int)> input)
{
	callbackFunction = std::bind(input, std::placeholders::_1, std::placeholders::_2);
}

void ModelLoader::setCurrent(int input) { current = input; }
void ModelLoader::setTotal(int input) { total = input; }