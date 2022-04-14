#include "Task5B.h"
#include <iostream>
#include <windows.h>

using namespace std;

int Sum(int* array, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(array + i) > 0)
		{
			sum += *(array + i);
		}
	}

	return sum;
}

int Product(int* array, int length)
{
	int product = 1;
	for (int i = 0; i < length; i++)
	{
		if (*(array + i) < 0)
		{
			product *= *(array + i);
		}
	}

	return product;
}

void StartTask()
{
	srand(time(0));
	SetConsoleOutputCP(1251);

	int(*pointer)(int* array, int length);
	pointer = Sum;
	//pointer = Product;

	int length = rand() % 8 + 3;
	int* array = new int[length];
	cout << "Сгенерированный массив: ";
	for (int i = 0; i < length; i++)
	{
		*(array + i) = rand() % 21 - 10;
		cout << *(array + i) << " ";
	}
	cout << "\n";

	cout << "Результат: " << pointer(array, length) << "\n\n";
}