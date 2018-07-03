// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#include "version.h"
#ifdef WORK_VERSION
	// WORK_VERSION does not use pre-compiled headers
	#include <GL/glew.h>
#else
	#include "targetver.h"

	#include <stdio.h>
	#include <tchar.h>

	#define GLFW_INCLUDE_NONE
	#include <glad/glad.h>
#endif // WORK_VERSION

// TODO: reference additional headers your program requires here
