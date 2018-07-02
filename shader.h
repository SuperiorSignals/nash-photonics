#pragma once
#ifndef SHADER_H_
#define SHADER_H_

#include "version.h"

#include <fstream>
#ifdef WORK_VERSION
	#include <GL/glew.h>
#else
	#include <glad/glad.h>
#endif // WORK_VERSION
#include <iostream>
#include <string>
#include <sstream>

class Shader {
public:
	unsigned int ID; // program ID
	Shader(const char *vertexPath, const char *fragmentPath);
	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;
};

#endif SHADER_H_