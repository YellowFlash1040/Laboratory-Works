#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable : 4996)

#include "Task7C.h"
#include <iostream>

using namespace std;

int GetRandomNumber(int min, int max)
{
	if (min > max)
	{
		int temp = max;
		max = min;
		min = temp;
	}

	return rand() % (max - min + 1) + min;
}

void WriteOneElementInTheEndOfFile(int element, char* filePath)
{
	FILE* dataFile = fopen(filePath, "ab");
	fwrite(&element, sizeof(element), 1, dataFile);
	fclose(dataFile);
	dataFile = nullptr;
}

int ReadNumberFromFileWithNumber(char* filePath, int numberOfNumber)
{
	numberOfNumber--;

	FILE* dataFile = fopen(filePath, "rb");
	fseek(dataFile, numberOfNumber * sizeof(int), SEEK_SET);
	int number;
	fread(&number, sizeof(int), 1, dataFile);
	fclose(dataFile);
	dataFile = nullptr;

	return number;
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

void WriteNumberInFileAtPosition(char* filePath, int number, int position)
{
	position--;
	FILE* dataFile = fopen(filePath, "rb+");
	fseek(dataFile, position * sizeof(number), SEEK_SET);
	fwrite(&number, sizeof(number), 1, dataFile);
	fclose(dataFile);
	dataFile = nullptr;
}

void StartTask()
{
	srand(time(0));

	char* filePath = new char[] {"f1"};

	int length = 20;
	int* mas1 = new int[length];

	cout << "Array: ";
	for (int i = 0; i < length; i++)
	{
		mas1[i] = GetRandomNumber(-10, 10);
		WriteOneElementInTheEndOfFile(mas1[i], filePath);
		cout << mas1[i] << " ";
	}
	cout << "\n\n";

	int* numbers = new int[3];
	numbers[0] = ReadNumberFromFileWithNumber(filePath, 2);
	numbers[1] = ReadNumberFromFileWithNumber(filePath, 5);
	numbers[2] = ReadNumberFromFileWithNumber(filePath, 9);

	cout << "Second number = " << numbers[0] << '\n';
	cout << "Fifth number = " << numbers[1] << '\n';
	cout << "Nineth number = " << numbers[2] << '\n';

	int sum = FindSumOfElementsInArray(numbers, 3);
	cout << "Sum = " << sum << '\n';
	int index = FindIndexOfMinimalElementInArray(numbers, 3);
	cout << "Minimal number = " << numbers[index] << '\n';
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

	WriteNumberInFileAtPosition(filePath, 999, index);

	cout << "\n";
	cout << "New Array: ";
	for (int i = 0; i < length; i++)
	{
		cout << ReadNumberFromFileWithNumber(filePath, i + 1) << " ";
	}
	cout << "\n\n";


	delete[] numbers;
	numbers = nullptr;
	delete[] mas1;
	mas1 = nullptr;

	remove(filePath);

	delete[] filePath;
	filePath = nullptr;
}