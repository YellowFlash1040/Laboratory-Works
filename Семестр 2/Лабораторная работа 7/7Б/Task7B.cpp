#include "Task7B.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

int ReadNumberFromArrayFromFile(string filePath, int numberOfNumber)
{
	ifstream StreamReader(filePath);
	string line;
	getline(StreamReader, line);
	StreamReader.close();

	int count = 0;
	int length = 4;
	char* number = new char[length];
	for (int i = 0; i < length; i++)
	{
		number[i] = NULL;
	}

	int j = 0;
	if (numberOfNumber == 1)
	{
		while (line[j] != ' ')
		{
			number[j] = line[j];
			j++;
		}

		int num = atoi(number);

		delete[] number;
		number = nullptr;

		return num;
	}

	for (int i = j; i < line.length(); i++)
	{
		if (line[i] == ' ')
		{
			count++;
			if (count + 1 == numberOfNumber)
			{
				int index = i + 1;
				int k = 0;
				while(line[index] != ' ')
				{
					number[k] = line[index];
					index++;
					k++;
				}

				break;
			}
		}
	}

	int num = atoi(number);

	delete[] number;
	number = nullptr;

	return num;
}

int FindSumOfEvenNumbersInArray(int* array, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		if (array[i] % 2 == 0)
		{
			sum += array[i];
		}
	}

	return sum;
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
	PrintArray(mas1, length);

	int length2 = length;
	int* mas2 = new int[length2];
	for (int i = 0; i < length; i++)
	{
		mas2[i] = ReadNumberFromArrayFromFile("f1.txt", i + 1);
	}

	cout << "Sum of even = " << FindSumOfEvenNumbersInArray(mas2, length) << '\n';
	PrintArray(mas2, length2);

	delete[] mas1;
	mas1 = nullptr;
	delete[] mas2;
	mas2 = nullptr;
}