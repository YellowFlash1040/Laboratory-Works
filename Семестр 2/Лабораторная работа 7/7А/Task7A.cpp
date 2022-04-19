#include "Task7A.h"
#include <iostream>
#include <fstream>

void WriteArrayInToTheFile(int* array, int length, string filePath)
{
	ofstream StreamWriter(filePath);
	for (int i = 0; i < length; i++)
	{
		StreamWriter << *(array + i) << " ";
	}
	StreamWriter << "\n";
	StreamWriter.close();
}

int GetCountOfNumbersInLine(string filePath, int numberOfLine)
{
	ifstream StreamReader(filePath);
	string line;
	for (size_t i = 0; i < numberOfLine; i++)
	{
		getline(StreamReader, line);
	}
	StreamReader.close();
	int count = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ')
		{
			count++;
		}
	}

	return count;
}

int* ReadArrayFromFile(string filePath)
{
	int length = GetCountOfNumbersInLine(filePath, 1);
	int* array = new int[length];
	ifstream StreamReader(filePath);
	string line;
	getline(StreamReader, line);
	StreamReader.close();
	string* numbersInStringForm = new string[length];
	for (int i = 0, index = 0; i < line.length(); i++)
	{
		if (line[i] != ' ')
		{
			numbersInStringForm[index] = numbersInStringForm[index] + line[i];
		}
		else
		{
			index++;
		}
	}
	char* number;
	for (int i = 0; i < length; i++)
	{
		number = new char[numbersInStringForm[i].length()];
		for (int k = 0; k < numbersInStringForm[i].length(); k++)
		{
			number[k] = numbersInStringForm[i][k];
		}
		array[i] = atoi(number);
		delete[] number;
	}

	delete[] numbersInStringForm;

	return array;
}

void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << *(array + i) << " ";
	}
	cout << '\n';
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
	WriteArrayInToTheFile(mas1, length, "f1.txt");

	int length2 = length;
	int* mas2 = new int[length2];
	mas2 = ReadArrayFromFile("f1.txt");
	WriteArrayInToTheFile(mas2, length2, "f2.txt");
	PrintArray(mas2, length2);

	delete[] mas1;
	mas1 = nullptr;
	delete[] mas2;
	mas2 = nullptr;
}