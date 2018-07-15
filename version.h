#pragma once
#ifndef _VERSION_H_
#define _VERSION_H_

#define WORK_VERSION
//#define HOME_VERSION

// WORK_VERSION uses glew
// HOME_VERSION uses glad

// HOME_VERSION uses pre-compiled headers for main.cpp
// HOME_VERSION not yet implemented, just comment out WORK_VERSION!

/*
Home Directories
----------------
Project >> Properties >> Configuration Properties

General >> Windows SDK Version

10.0.16299.0

C/C++ >> General >> Additional Include Directories

C:\glew-2.1.0\include
C:\glfw-3.2.1.bin.WIN32\include
C:\glm-0.9.9-a2\glm

Linker >> General >> Additional Library Directories

C:\glew-2.1.0\lib\Release\Win32
C:\glfw-3.2.1.bin.WIN32\lib-vc2015

Linker >> Input >> Additional Dependencies

opengl32.lib
glew32.lib
glfw3.lib
*/

/*
Work Directories
----------------
Project >> Properties >> Configuration Properties

General >> Windows SDK Version

10.0.15063.0

C/C++ >> General >> Additional Include Directories

C:\glew-2.0.0\include
C:\glfw-3.2.1.bin.WIN32\include
C:\glm\glm

Linker >> General >> Additional Library Directories

C:\glew-2.0.0\lib\Release\Win32
C:\glfw-3.2.1.bin.WIN32\lib-vc2015

Linker >> Input >> Additional Dependencies

opengl32.lib
glew32.lib
glfw3.lib
*/


#endif // !_VERSION_H_

