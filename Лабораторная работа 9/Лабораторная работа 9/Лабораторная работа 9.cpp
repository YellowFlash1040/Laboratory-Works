#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(1251);

	srand(time(0));

	int matrix[9][9];

	//First variant
	/*printf("Начальная Матрица :\n\n");
	for (int i = 0; i < 9; i++)
	{
		for (int index = 0; index < 46; index++)
		{
			printf("-");
		}
		printf("\n");

		for (int j = 0; j < 8; j++)
		{
			matrix[i][j] = rand() % 100;
			printf("|%3d ", matrix[i][j]);
		}
		matrix[i][8] = rand() % 101;
		printf("|%3d |\n", matrix[i][8]);
	}
	for (int index = 0; index < 46; index++)
	{
		printf("-");
	}
	printf("\n\n");

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[j][8 - i] = matrix[i][j];
		}
	}
	for (int i = 8; i > 4; i--)
	{
		for (int j = 8; j > 4; j--)
		{
			matrix[j][8 - i] = matrix[i][j];
		}
	}

	printf("Измененная Матрица :\n\n");
	for (int i = 0; i < 9; i++)
	{
		for (int index = 0; index < 46; index++)
		{
			printf("-");
		}
		printf("\n");

		for (int j = 0; j < 8; j++)
		{
			printf("|%3d ", matrix[i][j]);
		}
		printf("|%3d |\n", matrix[i][8]);
	}
	for (int index = 0; index < 46; index++)
	{
		printf("-");
	}
	printf("\n\n");


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j != i && j != 8 - i)
			{
				matrix[i][j] = 0;
			}
		}
	}

	printf("Измененная Матрица(только главная и побочная диагонали) :\n\n");
	for (int i = 0; i < 9; i++)
	{
		for (int index = 0; index < 46; index++)
		{
			printf("-");
		}
		printf("\n");

		for (int j = 0; j < 8; j++)
		{
			printf("|%3d ", matrix[i][j]);
		}
		printf("|%3d |\n", matrix[i][8]);
	}
	for (int index = 0; index < 46; index++)
	{
		printf("-");
	}
	printf("\n\n");*/


	//Second variant
	/*printf("Начальная Матрица :\n\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			matrix[i][j] = rand() % 100;
			printf("%3d ", matrix[i][j]);
		}
		matrix[i][8] = rand() % 101;
		printf("%3d\n", matrix[i][8]);
	}
	printf("\n\n");

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[j][8 - i] = matrix[i][j];
		}
	}
	for (int i = 8; i > 4; i--)
	{
		for (int j = 8; j > 4; j--)
		{
			matrix[j][8 - i] = matrix[i][j];
		}
	}

	printf("Измененная Матрица :\n\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
		printf("%3d\n", matrix[i][8]);
	}
	printf("\n\n");

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j != i && j != 8 - i)
			{
				matrix[i][j] = 0;
			}
		}
	}

	printf("Измененная Матрица(только главная и побочная диагонали) :\n\n");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
		printf("%3d\n", matrix[i][8]);
	}
	printf("\n\n");*/
}
