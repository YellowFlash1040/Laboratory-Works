#include "Task7C.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

void WriteNumberInFile(string filePath, int number)
{
	ofstream StreamWriter(filePath, ios::app);
	StreamWriter << number << '\n';
	StreamWriter.close();
}

int ConvertStringToNumber(string line)
{
	char* number = new char[line.length()];
	for (int i = 0; i < line.length(); i++)
	{
		number[i] = line[i];
	}

	int num = atoi(number);
	delete[] number;
	number = nullptr;

	return num;
}

int ReadNumberFromFile(string filePath, int indexOfNumber)
{
	ifstream StreamReader(filePath);
	string line;
	for (int i = 0; i < indexOfNumber; i++)
	{
		getline(StreamReader, line);
	}
	StreamReader.close();

	return ConvertStringToNumber(line);
}

int FindIndexOfMinimalElementInArray(int* array, int length)
{
	int indexOfMinElement = 0;
	for (int i = 1; i < length; i++)
	{
		if (array[i] < array[indexOfMinElement])
		{
			indexOfMinElement = i;
		}
	}

	return indexOfMinElement;
}

void WriteNumberInfileAtPosition(string filePath, int number, int position)
{
	ifstream StreamReader(filePath);
	string line;
	int index = 0;

	string NewFilePath = filePath;
	NewFilePath.insert(filePath.length() - 4, "1");

	while (getline(StreamReader, line))
	{
		index++;
		if (index == position)
		{
			WriteNumberInFile(NewFilePath, number);
		}
		else
		{
			WriteNumberInFile(NewFilePath, ConvertStringToNumber(line));
		}
	}
	StreamReader.close();

	int OldPathLength = filePath.length() + 1;
	char* OldPath = new char[OldPathLength];
	for (int i = 0; i < OldPathLength; i++)
	{
		OldPath[i] = NULL;
	}
	for (int i = 0; i < OldPathLength; i++)
	{
		OldPath[i] = filePath[i];
	}
	remove(OldPath);

	int NewPathLength = NewFilePath.length() + 1;
	char* NewPath = new char[NewPathLength];
	for (int i = 0; i < NewPathLength; i++)
	{
		NewPath[i] = NULL;
	}
	for (int i = 0; i < NewPathLength; i++)
	{
		NewPath[i] = NewFilePath[i];
	}
	rename(NewPath, OldPath);

	delete[] OldPath;
	OldPath = nullptr;
	delete[] NewPath;
	NewPath = nullptr;
}

int FindSumOfElementsInArray(int* array, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += array[i];
	}

	return sum;
}

void StartTask()
{
	srand(time(0));

	string dataFileName = "data.txt";
	int number;
	int length = 20;
	for (int i = 0; i < length; i++)
	{
		number = rand() % 21 - 10;
		cout << number << " ";
		WriteNumberInFile(dataFileName, number);
	}

	int* numbers = new int[3];
	numbers[0] = ReadNumberFromFile(dataFileName, 2);
	numbers[1] = ReadNumberFromFile(dataFileName, 5);
	numbers[2] = ReadNumberFromFile(dataFileName, 9);
	
	int sum = FindSumOfElementsInArray(numbers, 3);
	int index = FindIndexOfMinimalElementInArray(numbers, 3);
	if (index == 0)
	{
		index = 2;
	}
	else if (index == 1)
	{
		index = 5;
	}
	else if (index == 2)
	{
		index = 9;
	}

	WriteNumberInfileAtPosition(dataFileName, 999, index);
}