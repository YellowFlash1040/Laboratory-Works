#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(0));

	int Matrix[9][9];
	int CopyOfMatrix[9][9];

	printf("Начальная матрица :\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Matrix[i][j] = rand() % 101;
			printf("%3d ", Matrix[i][j]);
			CopyOfMatrix[i][j] = Matrix[i][j];
		}
		Matrix[i][8] = rand() % 101;
		printf("%3d\n", Matrix[i][8]);
		CopyOfMatrix[i][8] = Matrix[i][8];
	}
	printf("\n\n");

	int IndexOfMaxElementInString;
	int temparage;
	for (int i = 0; i < 9; i++)
	{
		IndexOfMaxElementInString = 0;
		for (int j = 1; j < 9; j++)
		{
			if (Matrix[i][j] > Matrix[i][IndexOfMaxElementInString])
			{
				IndexOfMaxElementInString = j;
			}
		}
		temparage = Matrix[i][0];
		Matrix[i][0] = Matrix[i][IndexOfMaxElementInString];
		Matrix[i][IndexOfMaxElementInString] = temparage;
	}

	printf("Измененная матрица (макс елемент в строке):\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%3d ", Matrix[i][j]);
		}
		printf("%3d\n", Matrix[i][8]);
	}
	printf("\n\n");

	printf("Начальная матрица :\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Matrix[i][j] = CopyOfMatrix[i][j];
			printf("%3d ", Matrix[i][j]);
		}
		printf("%3d\n", Matrix[i][8]);
	}
	printf("\n\n");


	int IndexOfMinElementInColumn;
	int temp;
	for (int j = 0; j < 9; j++)
	{
		IndexOfMinElementInColumn = 0;
		for (int i = 1; i < 9; i++)
		{
			if (j == 5)
			{
				int a = 5;
			}
			if (Matrix[i][j] < Matrix[IndexOfMinElementInColumn][j])
			{
				IndexOfMinElementInColumn = i;
			}
		}
		temp = Matrix[8][j];
		Matrix[8][j] = Matrix[IndexOfMinElementInColumn][j];
		Matrix[IndexOfMinElementInColumn][j] = temp;
	}

	printf("Измененная матрица (мин елемент в столбце):\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%3d ", Matrix[i][j]);
		}
		printf("%3d\n", Matrix[i][8]);
	}
	printf("\n\n");
}