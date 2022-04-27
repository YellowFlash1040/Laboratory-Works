#define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable : 4996)

#include "Task7A.h"
#include <windows.h>
#include <iostream>

using namespace std;

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
		ClearCharArray(number, 15);

		fprintf(dataFile, itoa(array[i], number, 10));
		fprintf(dataFile, " ");

		delete[] number;
		number = nullptr;
	}
	fprintf(dataFile, "\n");

	fclose(dataFile);
	dataFile = nullptr;
}

void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

int* ReadArrayFromFile(char filePath[])
{
	int length = 10;
	int* array = new int[length];

	FILE* dataFile = fopen(filePath, "r");

	char* bufer = new char[4];
	ClearCharArray(bufer, 4);

	for (int i = 0; i < length; i++)
	{
		fscanf(dataFile, "%s", bufer);
		array[i] = atoi(bufer);
	}

	delete[] bufer;
	bufer = nullptr;

	fclose(dataFile);
	dataFile = nullptr;

	return array;
}

int ReadNumberFromFileWithNumber(char filePath[], int number)
{
	FILE* dataFile = fopen(filePath, "r");

	char* bufer = new char[4];

	for (int i = 0; i < number; i++)
	{
		fscanf(dataFile, "%s", bufer);
	}

	fclose(dataFile);
	dataFile = nullptr;

	int num = atoi(bufer);

	delete[] bufer;
	bufer = nullptr;

	return num;
}

void StartTask()
{
	srand(time(0));
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
	mas2 = ReadArrayFromFile(filePath);
	delete[] filePath;
	filePath = new char[] {"f2.txt"};
	WriteArrayInToTheFile(mas2, length2, filePath);
	cout << "mas2: ";
	PrintArray(mas2, length2);

	int x;
	for (int i = 0; i < length2; i++)
	{
		x = ReadNumberFromFileWithNumber(filePath, i + 1);
		cout << "x = " << x << '\n';
	}

	delete[] filePath;
	filePath = nullptr;
	delete[] mas1;
	mas1 = nullptr;
	delete[] mas2;
	mas2 = nullptr;
}