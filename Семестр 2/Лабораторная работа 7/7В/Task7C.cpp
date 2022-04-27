#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable : 4996)

#include "Task7C.h"
#include <iostream>

using namespace std;

int GetRandomNumber()
{
	return rand() % 21 - 10;
}

void WriteNumberToFile(int number, char filePath[])
{
	FILE* dataFile = fopen(filePath, "a+");

	char* number_String = new char[15];
	itoa(number, number_String, 10);
	int countOfSymbols = 0;
	while (number_String[countOfSymbols] != '\0')
	{
		countOfSymbols++;
	}
	fwrite(number_String, 1, countOfSymbols, dataFile);
	fwrite(" ", 1, 1, dataFile);

	fclose(dataFile);
	dataFile = nullptr;
}

void ClearCharArray(char* word, int length)
{
	for (int i = 0; i < length; i++)
	{
		word[i] = NULL;
	}
}

int ReadOneNumberFromFileWithNumber(char filePath[], int numberOfNumber)
{
	FILE* dataFile = fopen(filePath, "r");

	char* number = new char[15];
	ClearCharArray(number, 15);
	int index;
	for (int i = 0; i < numberOfNumber; i++)
	{
		char* bufer = new char[4];
		ClearCharArray(bufer, 4);
		fread(bufer, 1, 1, dataFile);
		index = 0;
		while (bufer[0] != ' ')
		{
			number[index] = bufer[0];
			index++;
			fread(bufer, 1, 1, dataFile);
		}
	}
	char* Num = new char[index];
	for (int i = 0; i < index; i++)
	{
		Num[i] = number[i];
	}
	int num = atoi(Num);

	delete[] number;
	number = nullptr;
	delete[] Num;
	Num = nullptr;

	fclose(dataFile);
	dataFile = nullptr;

	return num;
}

int FindIndexOfMinimalNumber(int* array, int length)
{
	int indexOfMinimalNumber = 0;
	for (int i = 1; i < length; i++)
	{
		if (array[i] < array[indexOfMinimalNumber])
		{
			indexOfMinimalNumber = i;
		}
	}

	return indexOfMinimalNumber;
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

FILE* CreateFileForData(char filePath[])
{
	FILE* dataFile;
	dataFile = fopen(filePath, "w");
	fclose(dataFile);

	return dataFile;
}

void WriteNumberInfileAtPosition(char* filePath, int number, int position)
{
	char* newFilePath = new char[256];
	ClearCharArray(newFilePath, 256);

	int index = 0;
	while (filePath[index] != '.')
	{
		newFilePath[index] = filePath[index];
		index++;
	}

	newFilePath[index] = '1';
	newFilePath[index + 1] = '.';
	newFilePath[index + 2] = 't';
	newFilePath[index + 3] = 'x';
	newFilePath[index + 4] = 't';
	index += 4;

	CreateFileForData(newFilePath);

	for (int i = 0; i < 20; i++)
	{
		if (i + 1 == position)
		{
			WriteNumberToFile(number, newFilePath);
		}
		else
		{
			int num = ReadOneNumberFromFileWithNumber(filePath, i + 1);
			WriteNumberToFile(num, newFilePath);
		}
	}

	remove(filePath);
	rename(newFilePath, filePath);

	delete[] newFilePath;
	newFilePath = nullptr;
}

void StartTask()
{
	srand(time(0));

	int number;
	int length = 20;
	char* filePath = new char[] {"f1.txt"};

	FILE* dataFile = fopen(filePath, "w");
	fclose(dataFile);
	dataFile = nullptr;

	for (int i = 0; i < length; i++)
	{
		number = GetRandomNumber();
		WriteNumberToFile(number, filePath);
	}

	int numbers[3];

	numbers[0] = ReadOneNumberFromFileWithNumber(filePath, 2);
	numbers[1] = ReadOneNumberFromFileWithNumber(filePath, 5);
	numbers[2] = ReadOneNumberFromFileWithNumber(filePath, 9);

	cout << "Second number = " << numbers[0] << "\n";
	cout << "Fifth number = " << numbers[1] << "\n";
	cout << "Nineth number = " << numbers[2] << "\n";

	int sum = FindSumOfElementsInArray(numbers, 3);
	int indexOfMinimalElement = FindIndexOfMinimalNumber(numbers, 3);
	cout << "Sum = " << sum << '\n';
	cout << "Minimal = " << numbers[indexOfMinimalElement] << '\n';

	if (indexOfMinimalElement == 0)
	{
		indexOfMinimalElement = 2;
	}
	else if (indexOfMinimalElement == 1)
	{
		indexOfMinimalElement = 5;
	}
	else if (indexOfMinimalElement == 2)
	{
		indexOfMinimalElement = 9;
	}

	WriteNumberInfileAtPosition(filePath, 999, indexOfMinimalElement);
}