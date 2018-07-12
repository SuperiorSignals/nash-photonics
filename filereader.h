#pragma once
#ifndef _FILEREADER_H_
#define _FILEREADER_H_

#include <fstream>
#include <string>
#include <vector>

/*
Binary Version
--------------
1. Number of components
2. Component offsets
3. Element numbers
4. Number of Arrays

Text Version
------------
1. Number of components
2. Component offsets
3. Element numbers - element count per array
4. Number of Arrays
*/

class FileReader {
public:
	FileReader();
	FileReader(std::string file);
	void fillMatrix(double *output);
	std::vector<double> getArray();
	std::vector<double> getArray(int input);
	unsigned int getArrayNumber();
	unsigned int getComponentNumber();
	unsigned int getElementNumber();
	std::string getFileName();
	void setComponentNumber();
	void setFileName(std::string input);

private:
	unsigned int arrayNumber;
	unsigned int componentNumber;
	unsigned int currentArray;
	unsigned int currentComponent;
	unsigned int currentElement;
	unsigned int elementNumber;
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string fileName;
	std::vector<unsigned int> componentOffsets;
	bool isFileNameSet;
	bool isFileLoaded;

	void loadFile();
	
};

#endif // !_FILEREADER_H_
