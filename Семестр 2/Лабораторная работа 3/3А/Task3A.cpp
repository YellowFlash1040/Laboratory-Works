#include "Task3A.h"
#include <windows.h>
#include <iostream>

using namespace std;

#define FirstVariant
//#define SecondVariant
//#define ThirdVariant

// Через относительный адрес
int* FindCountAndSumOfNegativeElementsInArray_FirstVariant(int* array, int length)
{
	int* countAndSumOfNegativeElements = new int[2];
	*countAndSumOfNegativeElements = 0;
	*(countAndSumOfNegativeElements + 1) = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(array + i) < 0)
		{
			*countAndSumOfNegativeElements += 1;
			*(countAndSumOfNegativeElements + 1) += *(array + i);
		}
	}

	return countAndSumOfNegativeElements;
}

// Через абсолютный адрес
int* FindCountAndSumOfNegativeElementsInArray_SecondVariant(int* array, int length)
{
	int* countAndSumOfNegativeElements = new int[2];
	*countAndSumOfNegativeElements = 0;
	*(countAndSumOfNegativeElements + 1) = 0;
	for (int i = 0; i < length; i++)
	{
		if (*array < 0)
		{
			*countAndSumOfNegativeElements += 1;
			*(countAndSumOfNegativeElements + 1) += *array;
		}

		array++;
	}

	return countAndSumOfNegativeElements;
}

// Без индексации
int* FindCountAndSumOfNegativeElementsInArray_ThirdVariant(int* array, int length)
{
	int* countAndSumOfNegativeElements = new int[2];
	int* array_Ptr = array;
	*countAndSumOfNegativeElements = 0;
	*(countAndSumOfNegativeElements + 1) = 0;
	for (; array < array_Ptr + length; array++)
	{
		if (*array < 0)
		{
			*countAndSumOfNegativeElements += 1;
			*(countAndSumOfNegativeElements + 1) += *array;
		}
	}

	return countAndSumOfNegativeElements;
}

void StartTask()
{
	SetConsoleOutputCP(1251);
	srand(time(0));

	int length = rand() % 9 + 2;
	int* array = new int[length];

	for (int i = 0; i < length; i++)
	{
		*(array + i) = rand() % 21 - 10;
		cout << *(array + i) << " ";
	}
	cout << "\n";

#ifdef FirstVariant
	int* countAndSumOfNegativeElementsInArray = FindCountAndSumOfNegativeElementsInArray_FirstVariant(array, length);
#endif
#ifdef SecondVariant
	int* countAndSumOfNegativeElementsInArray = FindCountAndSumOfNegativeElementsInArray_SecondVariant(array, length);
#endif
#ifdef ThirdVariant
	int* countAndSumOfNegativeElementsInArray = FindCountAndSumOfNegativeElementsInArray_ThirdVariant(array, length);
#endif

	cout << "\nКоличество негативных елементов в  данном массиве > " << *countAndSumOfNegativeElementsInArray << "\n";
	cout << "Сумма негативных елементов данного массива > " << *(countAndSumOfNegativeElementsInArray + 1) << "\n";

	delete[] array;
	array = nullptr;
}