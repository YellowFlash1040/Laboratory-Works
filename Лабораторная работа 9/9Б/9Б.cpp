#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	srand(time(0));

	int countOfStringsInFirstMatrix;
	int countOfColumnsInFirstMatrix;

	int countOfStringsInSecondMatrix;
	int countOfColumnsInSecondMatrix;

	do
	{
		cout << "Введите количество строк первой матрицы> ";
		cin >> countOfStringsInFirstMatrix;
		cout << "Введите количество колонок первой матрицы > ";
		cin >> countOfColumnsInFirstMatrix;

		cout << "Введите количество строк второй матрицы> ";
		cin >> countOfStringsInSecondMatrix;
		cout << "Введите количество колонок второй матрицы > ";
		cin >> countOfColumnsInSecondMatrix;

		if (countOfColumnsInFirstMatrix != countOfStringsInSecondMatrix)
		{
			cout << "\nИзвините, матрицы с такими размерами нельзя умножать. Пожалуйста введите другие размеры :\n\n";
		}
	} while (countOfColumnsInFirstMatrix != countOfStringsInSecondMatrix);
	cout << "\n";

	cout << "Первая матрица :\n";
	int** FirstMatrix = new int* [countOfStringsInFirstMatrix];
	for (int i = 0; i < countOfStringsInFirstMatrix; i++)
	{
		FirstMatrix[i] = new int[countOfColumnsInFirstMatrix];
		for (int j = 0; j < countOfColumnsInFirstMatrix; j++)
		{
			FirstMatrix[i][j] = rand() % 11;
			printf("%2d ", FirstMatrix[i][j]);
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "Вторая матрица :\n";
	int** SecondMatrix = new int* [countOfStringsInSecondMatrix];
	for (int i = 0; i < countOfStringsInSecondMatrix; i++)
	{
		SecondMatrix[i] = new int[countOfColumnsInSecondMatrix];
		for (int j = 0; j < countOfColumnsInSecondMatrix; j++)
		{
			SecondMatrix[i][j] = rand() % 11;
			printf("%2d ", SecondMatrix[i][j]);
		}
		cout << endl;
	}
	cout << endl << endl;

	
	int** ResultMatrix = new int* [countOfColumnsInFirstMatrix];
	for (int i = 0; i < countOfStringsInSecondMatrix; i++)
	{
		ResultMatrix[i] = new int[countOfStringsInSecondMatrix];
	}
	for (int i = 0; i < countOfColumnsInFirstMatrix; i++)
	{
		for (int j = 0; j < countOfStringsInSecondMatrix; j++)
		{
			ResultMatrix[i][j] = 0;
		}
	}

	cout << "Матрица-результат умножения :\n";
	for (int row = 0; row < countOfStringsInFirstMatrix; row++) 
	{
		for (int col = 0; col < countOfColumnsInSecondMatrix; col++) 
		{
			for (int inner = 0; inner < countOfColumnsInFirstMatrix; inner++) 
			{
				ResultMatrix[row][col] += FirstMatrix[row][inner] * SecondMatrix[inner][col];
			}
			cout << ResultMatrix[row][col] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}
