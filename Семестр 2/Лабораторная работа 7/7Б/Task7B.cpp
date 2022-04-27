#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable : 4996)

#include "Task7B.h"
#include <iostream>
#include <windows.h>

using namespace std;

void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

void ClearCharArray(char* word, int length)
{
	for (int i = 0; i < length; i++)
	{
		word[i] = NULL;
	}
}

void WriteArrayInToTheFile(int* array, int length, char filePath[])
{
	FILE* dataFile = fopen(filePath, "w");

	for (int i = 0; i < length; i++)
	{
		char* number = new char[15];
		number = itoa(array[i], number, 10);
		int countOfSymbols = 0;
		while (number[countOfSymbols] != '\0')
		{
			countOfSymbols++;
		}

		fwrite(number, 1, countOfSymbols, dataFile);
		fwrite(" ", 1, 1, dataFile);

		delete[] number;
		number = nullptr;
	}
	fwrite("\n", 1, 1, dataFile);

	fclose(dataFile);
	dataFile = nullptr;
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

	return num;
}

int FindCountOfPour(int* array, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 == 0)
		{
			count++;
		}
	}

	return count;
}

void StartTask()
{
	srand(time(0));

	SetConsoleOutputCP(1251);

	int length = 10;
	int* mas1 = new int[length];
	for (int i = 0; i < length; i++)
	{
		*(mas1 + i) = rand() % 21 - 10;
	}

	char* filePath = new char[] {"f1.txt"};
	cout << "mas1: ";
	PrintArray(mas1, length);
	WriteArrayInToTheFile(mas1, length, filePath);

	int length2 = length;
	int* mas2 = new int[length2];
	for (int i = 0; i < length2; i++)
	{
		mas2[i] = ReadOneNumberFromFileWithNumber(filePath, i + 1);
	}

	int countOfPour = FindCountOfPour(mas2, length2);
	cout << " оличество парных чисел в данном массиве: " << countOfPour << "\n\n";
}