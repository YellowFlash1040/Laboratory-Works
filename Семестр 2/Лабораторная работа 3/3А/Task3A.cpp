#include "Task3A.h"
#include <windows.h>
#include <iostream>

using namespace std;

// Через относительный адрес
void FindCountAndSumOfNegativeElementsInArray_FirstVariant(int* array, int length)
{
	int count = 0;
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(array + i) < 0)
		{
			count++;
			sum += *(array + i);
		}
	}

	cout << "\nКоличество негативных елементов в  данном массиве > " << count << "\n";
	cout << "Сумма негативных елементов данного массива > " << sum << "\n";
}

// Через абсолютный адрес
void FindCountAndSumOfNegativeElementsInArray_SecondVariant(int* array, int length)
{
	int count = 0;
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		if (*array < 0)
		{
			count++;
			sum += *array;
		}

		array++;
	}

	cout << "\nКоличество негативных елементов в  данном массиве > " << count << "\n";
	cout << "Сумма негативных елементов данного массива > " << sum << "\n";
}

// Без индексации
void FindCountAndSumOfNegativeElementsInArray_ThirdVariant(int* array, int length)
{
	int count = 0;
	int sum = 0;

	int* array_Ptr = array;
	
	for (; array < array_Ptr + length; array++)
	{
		if (*array < 0)
		{
			count++;
			sum += *array;
		}
	}

	cout << "\nКоличество негативных елементов в  данном массиве > " << count << "\n";
	cout << "Сумма негативных елементов данного массива > " << sum << "\n";
}

// Через массив указателей
void FindCountAndSumOfNegativeElementsInArray_FourthVariant(int* array, int length)
{
	int count = 0;
	int sum = 0;

	int* array_Ptr[100];
	
	for (int i = 0; i < length; i++)
	{
		array_Ptr[i] = &array[i];
	}

	for (int i = 0; i < length; i++)
	{
		if (*array_Ptr[i] < 0)
		{
			count++;
			sum += *array_Ptr[i];
		}
	}

	cout << "\nКоличество негативных елементов в  данном массиве > " << count << "\n";
	cout << "Сумма негативных елементов данного массива > " << sum << "\n";
}

// Через указатель на указатель
void FindCountAndSumOfNegativeElementsInArray_FifthVariant(int* array, int length)
{
	int count = 0;
	int sum = 0;

	int* array_Ptr[100];

	for (int i = 0; i < length; i++)
	{
		array_Ptr[i] = &array[i];
	}

	int**array_Ptr_Ptr = array_Ptr;

	int** ptr = array_Ptr_Ptr;
	for (; array_Ptr_Ptr < ptr + length; array_Ptr_Ptr++)
	{
		if (**array_Ptr_Ptr < 0)
		{
			count++;
			sum += **array_Ptr_Ptr;
		}
	}

	cout << "\nКоличество негативных елементов в  данном массиве > " << count << "\n";
	cout << "Сумма негативных елементов данного массива > " << sum << "\n";
}

// В виде функции с параметрами указателями
void FindCountAndSumOfNegativeElementsInArray_SixthVariant(int* array, int length, int* count, int* sum)
{
	*count = 0;
	*sum = 0;
	for (int i = 0; i < length; i++)
	{
		if (*(array + i) < 0)
		{
			*count += 1;
			*sum += *(array + i);
		}
	}
}

void ShowVariantsOfTaskMenu()
{
	cout << "Выберите вариант задания: \n";
	cout << "(1) Через относительный адрес\n";
	cout << "(2) Через абсолютный адрес\n";
	cout << "(3) Без индексации\n";
	cout << "(4) Через массив указателей\n";
	cout << "(5) Через указатель на указатель\n";
	cout << "(6) В виде функции с параметрами указателями\n";
	cout << "(7) Вернуться в предыдущее меню\n";
}

void ShowMainMenu()
{
	cout << "Выберите действие: \n";
	cout << "(1) Выбрать вариант задания\n";
	cout << "(2) Завершить выполнение программы\n";
}

int GetAnswerFromUser()
{
	int numberOfTask;
	cout << "\nВаш ответ > ";
	cin >> numberOfTask;
	return numberOfTask;
}

void StartTask()
{
	SetConsoleOutputCP(1251);
	srand(time(0));

	int answer;
	do
	{
		ShowMainMenu();
		answer = GetAnswerFromUser();
		cout << "\n";

		if (answer == 1)
		{
			int numberOfTask;
			do
			{
				cout << "Сгенерированный массив: ";
				int length = rand() % 6 + 5;
				int* array = new int[length];

				for (int i = 0; i < length; i++)
				{
					*(array + i) = rand() % 21 - 10;
					cout << *(array + i) << " ";
				}
				cout << "\n\n";

				ShowVariantsOfTaskMenu();
				numberOfTask = GetAnswerFromUser();

				if (numberOfTask == 1)
				{
					FindCountAndSumOfNegativeElementsInArray_FirstVariant(array, length);
				}
				else if (numberOfTask == 2)
				{
					FindCountAndSumOfNegativeElementsInArray_SecondVariant(array, length);
				}
				else if (numberOfTask == 3)
				{
					FindCountAndSumOfNegativeElementsInArray_ThirdVariant(array, length);
				}
				else if (numberOfTask == 4)
				{
					FindCountAndSumOfNegativeElementsInArray_FourthVariant(array, length);
				}
				else if (numberOfTask == 5)
				{
					FindCountAndSumOfNegativeElementsInArray_FifthVariant(array, length);
				}
				else if (numberOfTask == 6)
				{
					int sum = 0;
					int count = 0;
					FindCountAndSumOfNegativeElementsInArray_SixthVariant(array, length, &count, &sum);

					cout << "\nКоличество негативных елементов в  данном массиве > " << count << "\n";
					cout << "Сумма негативных елементов данного массива > " << sum << "\n";
				}

				cout << "---------------------------------------------------------------\n\n";

				delete[] array;
				array = nullptr;
			} while (numberOfTask != 7);
		}
	} while (answer != 2);
}