#include "Task5.h"
#include <windows.h>
#include <iostream>

using namespace std;

//#define Array

void SetRussianLanguage()
{
	SetConsoleOutputCP(1251);
}

void FillMatrixWithRandomNumbersFromZeroToTen(int** matrix, int length_0, int length_1)
{
	for (int i = 0; i < length_0; i++)
	{
		*(matrix + i) = new int[length_1];
		for (int j = 0; j < length_1; j++)
		{
			*(*(matrix + i) + j) = rand() % 10;
		}
	}
}

void FillMatrixWithRandomNumbersFromZeroToTen(int* matrix, int length_0, int length_1)
{
	for (int i = 0; i < length_0; i++)
	{
		for (int j = 0; j < length_1; j++)
		{
			*(matrix + i * length_1 + j) = rand() % 10;
		}
	}
}

int GetCountOfRowsFromUser()
{
	int countOfRows;
	cout << "¬ведите количество строк матрицы > ";
	cin >> countOfRows;
	return countOfRows;
}

int GetCountOfColumnsFromUser()
{
	int countOfColumns;
	cout << "¬ведите количество столбцов матрицы > ";
	cin >> countOfColumns;
	return countOfColumns;
}

int* GetSizeOfMatrixFromUser()
{
	return new int[]{ GetCountOfRowsFromUser(), GetCountOfColumnsFromUser() };
}

void CompleteTask9(int** matrix, int length_0, int length_1)
{
	int temp;
	for (int i = 0; i < length_0; i++)
	{
		temp = *(*(matrix + i) + i);
		*(*(matrix + i) + i) = *(*(matrix + i) + length_1 - 1 - i);
		*(*(matrix + i) + length_1 - 1 - i) = temp;
	}
}

void CompleteTask9(int* matrix, int length_0, int length_1)
{
	int temp;
	for (int i = 0; i < length_0; i++)
	{
		temp = *(matrix + i * length_1 + i);
		*(matrix + i * length_1 + i) = *(matrix + i * length_1 + length_1 - 1 - i);
		*(matrix + i * length_1 + length_1 - 1 - i) = temp;
	}
}

void PrintMatrix(int** matrix, int length_0, int length_1)
{
	for (int i = 0; i < length_0; i++)
	{
		for (int j = 0; j < length_1; j++)
		{
			cout << *(*(matrix + i) + j) << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void PrintMatrix(int* matrix, int length_0, int length_1)
{
	for (int i = 0; i < length_0; i++)
	{
		for (int j = 0; j < length_1; j++)
		{
			cout << *(matrix + i * length_1 + j) << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void StartTask()
{
	srand(time(0));
	SetRussianLanguage();

	int* lengthAndWidthOfMatrix = GetSizeOfMatrixFromUser();

#ifdef Array
	int** matrix = new int* [*lengthAndWidthOfMatrix];
#else
	int* matrix = new int[*lengthAndWidthOfMatrix * *(lengthAndWidthOfMatrix + 1)];
#endif // Array

	FillMatrixWithRandomNumbersFromZeroToTen(matrix, *lengthAndWidthOfMatrix, *(lengthAndWidthOfMatrix + 1));
	PrintMatrix(matrix, *lengthAndWidthOfMatrix, *(lengthAndWidthOfMatrix + 1));
	CompleteTask9(matrix, *lengthAndWidthOfMatrix, *(lengthAndWidthOfMatrix + 1));
	PrintMatrix(matrix, *lengthAndWidthOfMatrix, *(lengthAndWidthOfMatrix + 1));

#ifdef Array
	for (int i = 0; i < *(lengthAndWidthOfMatrix + 0); i++)
	{
		delete[] * (matrix + i);
	}

	delete[] matrix;
#else
	delete[] matrix;
#endif // Array
}