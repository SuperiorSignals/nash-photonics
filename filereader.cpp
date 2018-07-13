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

std::vector<double> FileReader::getArray()
{
	std::vector<double> output;
	unsigned int offset;
	double trashCan;

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

			for (int i = 0; i < arrayNumber; i++) {
				for (int j = 0; j < componentNumber; j++) {

				}
			}

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
			inputFile >> componentNumber;
			componentOffsets.clear();
			for (int i = 0; i < componentNumber; i++) {
				inputFile >> offset;
				componentOffsets.push_back(offset);
			}
			inputFile >> elementNumber;
			inputFile >> arrayNumber;

			if (arrayNumber > 0) {
				for (int i = 0; i < currentArray; i++) {
					for (int j = 0; j < componentNumber; j++) {
						while (!inputFile.eof()) {
							inputFile >> trashCan;
						}
					}
				}
				for (int j = 0; j < componentNumber; j++) {
					while (!inputFile.eof()) {
						inputFile >> value;
						output.push_back(value);
					}
				}
				++currentArray;
				if (currentArray > arrayNumber - 1) {
					currentArray = 0;
				}
			}

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

	return output;
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
		inputFile.close();
	} else {
		std::cout << "ERROR [void FileReader::loadFile()]: ";
		std::cout << "Filename has not been set.";
		std::cout << std::endl;
	}
}