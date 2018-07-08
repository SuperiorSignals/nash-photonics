#include "filereader.h"

#include <fstream>
#include <iostream>
#include <string>

FileReader::FileReader()
{
	isFileNameSet = false;
	isFileLoaded = false;
	currentComponent = 0;
	currentElement = 0;
}

FileReader::FileReader(std::string input)
{
	fileName = input;
	isFileNameSet = true;
	isFileLoaded = false;
	currentComponent = 0;
	currentElement = 0;
}

void FileReader::loadFile()
{
	unsigned int offset;

	if (isFileNameSet) {
		inputFile.open(fileName.c_str());
		if (inputFile.is_open()) {
			inputFile >> componentNumber;
			componentOffsets.clear();
			for (int i = 0; i < componentNumber; i++) {
				inputFile >> offset;
				componentOffsets.push_back(offset);
			}
			inputFile >> elementNumber;
			inputFile >> arrayNumber;
		} else {
			std::cout << "ERROR [void FileReader::loadFile()]: ";
			std::cout << "Unable to open file ";
			std::cout << fileName;
			std::cout << std::endl;
		}
	} else {
		std::cout << "ERROR [void FileReader::loadFile()]: ";
		std::cout << "Filename has not been set.";
		std::cout << std::endl;
	}
}