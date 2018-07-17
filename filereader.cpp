#include "filereader.h"

#include <fstream>
#include <iostream>
#include <string>

FileReader::FileReader()
{
	isFileNameSet = false;
	isFileLoaded = false;
	currentArray = 0;
	currentComponent = 0;
	currentElement = 0;
}

FileReader::FileReader(std::string input)
{
	fileName = input;
	isFileNameSet = true;
	isFileLoaded = false;
	currentArray = 0;
	currentComponent = 0;
	currentElement = 0;
}

void FileReader::fillArray(double output[][512])
{
	unsigned int offset;
	double trashCan;
	double value;

	if (isFileNameSet) {
		inputFile.open(fileName.c_str());
		if (inputFile.is_open()) {
			inputFile >> numberOfComponents;
			componentOffsets.clear();
			for (int i = 0; i < numberOfComponents; i++) {
				inputFile >> offset;
				componentOffsets.push_back(offset);
			}
			inputFile >> numberOfElements;
			inputFile >> numberOfArrays;

			currentArray = 0;
			if (numberOfArrays > 0) {
				for (int i = 0; i < numberOfArrays; i++) {
					for (int j = 0; j < numberOfElements; j++) {
						if (!inputFile.eof()) {
							inputFile >> value;
							if (j < 512) {
								output[i][j] = value;
							}
						}
					}
					++currentArray;
				}
				if (currentArray > numberOfArrays - 1) {
					currentArray = 0;
				}
			}
		} else {
			std::cout << "ERROR [void FileReader::fillArray(double output[][512])]: ";
			std::cout << "Unable to open file ";
			std::cout << fileName;
			std::cout << std::endl;
		}
		inputFile.close();
	} else {
		std::cout << "ERROR [void FileReader::fillArray(double output[][512])]: ";
		std::cout << "Filename has not been set.";
		std::cout << std::endl;
	}
}

std::vector<double> FileReader::getArray()
{
	std::vector<double> output;
	unsigned int offset;
	double trashCan;
	double value;

	if (isFileNameSet) {
		inputFile.open(fileName.c_str());
		if (inputFile.is_open()) {
			inputFile >> numberOfComponents;
			componentOffsets.clear();
			for (int i = 0; i < numberOfComponents; i++) {
				inputFile >> offset;
				componentOffsets.push_back(offset);
			}
			inputFile >> numberOfElements;
			inputFile >> numberOfArrays;

			if (numberOfArrays > 0) {
				for (int i = 0; i < currentArray; i++) {
					for (int j = 0; j < numberOfElements; j++) {
						if (!inputFile.eof()) {
							inputFile >> trashCan;
						}
					}
				}
				for (int j = 0; j < numberOfElements; j++) {
					if (!inputFile.eof()) {
						inputFile >> value;
						output.push_back(value);
					}
				}
				++currentArray;
				if (currentArray > numberOfArrays - 1) {
					currentArray = 0;
				}
			}
		} else {
			std::cout << "ERROR [std::vector<double> FileReader::getArray()]: ";
			std::cout << "Unable to open file ";
			std::cout << fileName;
			std::cout << std::endl;
		}
		inputFile.close();
	} else {
		std::cout << "ERROR [std::vector<double> FileReader::getArray()]: ";
		std::cout << "Filename has not been set.";
		std::cout << std::endl;
	}

	return output;
}

std::vector<double> FileReader::getArray(int input)
{
	std::vector<double> output;
	unsigned int offset;
	double trashCan;
	double value;

	if (isFileNameSet) {
		inputFile.open(fileName.c_str());
		if (inputFile.is_open()) {
			inputFile >> numberOfComponents;
			componentOffsets.clear();
			for (int i = 0; i < numberOfComponents; i++) {
				inputFile >> offset;
				componentOffsets.push_back(offset);
			}
			inputFile >> numberOfElements;
			inputFile >> numberOfArrays;

			if (numberOfArrays > 0) {
				for (int i = 0; i < currentArray; i++) {
					for (int j = 0; j < numberOfElements; j++) {
						if (!inputFile.eof()) {
							inputFile >> trashCan;
						}
					}
				}
				for (int j = 0; j < numberOfElements; j++) {
					if (!inputFile.eof()) {
						inputFile >> value;
						output.push_back(value);
					}
				}
				++currentArray;
				if (currentArray > numberOfArrays - 1) {
					currentArray = 0;
				}
			}
		} else {
			std::cout << "ERROR [std::vector<double> FileReader::getArray(int)]: ";
			std::cout << "Unable to open file ";
			std::cout << fileName;
			std::cout << std::endl;
		}
		inputFile.close();
	} else {
		std::cout << "ERROR [std::vector<double> FileReader::getArray(int)]: ";
		std::cout << "Filename has not been set.";
		std::cout << std::endl;
	}

	return output;
}

void FileReader::loadFile()
{
	unsigned int offset;

	if (isFileNameSet) {
		inputFile.open(fileName.c_str());
		if (inputFile.is_open()) {
			inputFile >> numberOfComponents;
			componentOffsets.clear();
			for (int i = 0; i < numberOfComponents; i++) {
				inputFile >> offset;
				componentOffsets.push_back(offset);
			}
			inputFile >> numberOfElements;
			inputFile >> numberOfArrays;
		} else {
			std::cout << "ERROR [void FileReader::loadFile()]: ";
			std::cout << "Unable to open file ";
			std::cout << fileName;
			std::cout << std::endl;
		}
		inputFile.close();
	} else {
		std::cout << "ERROR [void FileReader::loadFile()]: ";
		std::cout << "Filename has not been set.";
		std::cout << std::endl;
	}
}

unsigned int FileReader::getCurrentArray()
{
	return currentArray;
}

unsigned int FileReader::getCurrentComponent()
{
	return currentComponent;
}

unsigned int FileReader::getCurrentElement()
{
	return currentElement;
}

unsigned int FileReader::getNumberOfArrays()
{
	return numberOfArrays;
}

unsigned int FileReader::getNumberOfComponents()
{
	return numberOfComponents;
}

unsigned int FileReader::getNumberOfElements()
{
	return numberOfElements;
}

std::string FileReader::getFileName()
{
	return fileName;
}

void FileReader::setFileName(std::string input)
{
	fileName = input;
	isFileNameSet = true;
}