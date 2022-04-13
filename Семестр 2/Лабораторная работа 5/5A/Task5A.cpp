#include "Task5A.h"
#include <iostream>
#include <windows.h>

using namespace std;

int* Task5A(int** matrix, int length_0, int length_1, int* array_Min, int* array_Max, int* sum, int* product)
{
	int* sumAndProduct = new int[2];
	*sum = 0;
	*product = 1;
	int maxElement;
	int minElement;
	for (int i = 0; i < length_0; i++)
	{
		maxElement = INT_MIN;
		minElement = INT_MAX;
		for (int j = 0; j < length_1; j++)
		{
			if (j == i)
			{
				*sum += *(*(matrix + i) + j);
				if (j == length_0 - 1 - i)
				{
					*product *= *(*(matrix + i) + j);
				}
			}
			else if (j == length_0 - 1 - i)
			{
				*product *= *(*(matrix + i) + j);
			}

			if (*(*(matrix + i) + j) > maxElement)
			{
				maxElement = *(*(matrix + i) + j);
			}

			if (*(*(matrix + j) + i) < minElement)
			{
				minElement = *(*(matrix + j) + i);
			}
		}
		*(array_Max + i) = maxElement;
		*(array_Min + i) = minElement;
	}

	*sumAndProduct = *sum;
	*(sumAndProduct + 1) = *product;

	return sumAndProduct;
}

void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << *(array + i) << " ";
	}
	cout << "\n";
}

void PrintMatrix(int** matrix, int length_0, int length_1)
{
	for (int i = 0; i < length_0; i++)
	{
		for (int j = 0; j < length_1; j++)
		{
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void FillMatrix(int** matrix, int length_0, int length_1)
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

void StartTask()
{
	SetConsoleOutputCP(1251);
	srand(time(0));

	int length_0 = rand() % 6 + 2;
	int length_1 = length_0;
	int** matrix = new int* [length_0];
	int lengthOf_Array_Min = length_1;
	int* array_Min = new int[lengthOf_Array_Min];
	int lengthOf_Array_Max = length_0;
	int* array_Max = new int[lengthOf_Array_Max];
	int sum;
	int product;

	FillMatrix(matrix, length_0, length_1);
	PrintMatrix(matrix, length_0, length_1);

	int* sumAndProduct = Task5A(matrix, length_0, length_1, array_Min, array_Max, &sum, &product);

	cout << "Массив, содержащий минимальные элементы в каждом столбце: ";
	PrintArray(array_Min, lengthOf_Array_Min);
	cout << "Массив, содержащий максимальные элементы в каждой строке: ";
	PrintArray(array_Max, lengthOf_Array_Max);
	cout << "Сумма на ГД: " << sum <<"\n";
	cout << "Произведение на ПД: " << product << "\n";
	cout << "Массив, в котором находятся сумма на ГД и произведение на ПД: ";
	PrintArray(sumAndProduct, 2);

	delete[] array_Min;
	delete[] array_Max;
	for (int i = 0; i < length_0; i++)
	{
		delete[] * (matrix + i);
		*(matrix + i) = nullptr;
	}
	delete[] matrix;
	matrix = nullptr;
	delete[] sumAndProduct;
	sumAndProduct = nullptr;
}