#include <iostream>
#include <windows.h>

using namespace std;

int FindTheNumberOfPositiveElementsInTheMatrix(int (*matrix)[100], int countOfColumns, int numberOfTheRow)
{
	int count = 0;
	for (int i = 0; i < countOfColumns; i++)
	{
		if (matrix[numberOfTheRow][i] > 0)
		{
			count++;
		}
	}
	return count;
}

void FillMatrix(int (*matrix)[100], int countOfRows, int countOfColumns)
{
	srand(time(0));
	int randomChar;
	for (int i = 0; i < countOfRows; i++)
	{
		for (int j = 0; j < countOfColumns; j++)
		{
			randomChar = (rand() % 2) % 2 == 1 ? -1 : 1;
			matrix[i][j] = rand() % 100 * randomChar;
		}
	}
}

void PrintTheMatrix(int (*matrix)[100], int countOfRows, int countOfColumns)
{
	for (int i = 0; i < countOfRows; i++)
	{
		for (int j = 0; j < countOfColumns; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
		cout << "\n";
	}
}

int main()
{
	SetConsoleOutputCP(1251);

	int countOfRows, countOfColumns;
	do
	{
		cout << "Введите количество строк матрицы > ";
		cin >> countOfRows;

		if (countOfRows > 100)
		{
			cout << "\nИзвините, количество строк не может превышать 100. Повторите ввод :\n\n";
		}
	} while (countOfRows > 100);
	do
	{
		cout << "Введите количество колонок матрицы > ";
		cin >> countOfColumns;

		if (countOfColumns > 100)
		{
			cout << "\nИзвините, количество колонок не может превышать 100. Повторите ввод :\n\n";
		}
	} while (countOfColumns > 100);
	

	int matrix[100][100];
	
	FillMatrix(matrix, countOfRows, countOfColumns);
	cout << "\n";
	PrintTheMatrix(matrix, countOfRows, countOfColumns);
	cout << "\n";

	int count;
	for (int i = 0; i < countOfRows; i++)
	{
		count = FindTheNumberOfPositiveElementsInTheMatrix(matrix, countOfColumns, i);

		int number = count % 100;
		int secondNumber = number % 10;
		if (number >= 5 && number <= 20)
		{
			cout << "В " << i + 1 << " строке " << count << " положительных элементов\n";
		}
		else if (secondNumber == 1)
		{
			cout << "В " << i + 1 << " строке " << count << " положительный элемент\n";
		}
		else if (secondNumber >= 2 && secondNumber <= 4)
		{
			cout << "В " << i + 1 << " строке " << count << " положительных элемента\n";
		}
		else
		{
			cout << "В " << i + 1 << " строке " << count << " положительных элементов\n";
		}
	}
	cout << "\n\n";
}