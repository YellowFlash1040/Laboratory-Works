#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int lengthOfArray;
	std::cout << "Введите размер массива > ";
	std::cin >> lengthOfArray;
	int Array[10000];
	printf("\n");
	printf("Начальный массив :\n");
	for (int i = 0; i < lengthOfArray; i++)
	{
		Array[i] = i + 1;
		printf("#%d. %d\n", i + 1, Array[i]);
	}
	printf("\n");

	char answer[2];
	do
	{
		std::cout << "Что вы хотите сделать? :\n";
		std::cout << "- Вставить k елементов в массив(i)\n";
		std::cout << "- Удалить k елементов из массива(d)\n";
		std::cout << "- Завершить программу(e)\n\n";
		std::cout << "Ваш выбор > ";
		std::cin >> answer;

		if (strcmp(answer, "i") == 0)
		{
			int num = 0;
			printf("\nВведите елемент который вы хотите добавить > ");
			int first_scan = scanf("%d", &num);

			int Length = 0;
			do
			{
				printf("Введите количество елементов которое вы хотите добавить > ");
				int first_scan = scanf("%d", &Length);
				if (Length > 10000 - lengthOfArray)
				{
					printf("\nИзвините, нельзя добавить %d елементов. Максимальное количество елементов которое можно добавить : %d\n\n", Length, 10000 - lengthOfArray);
				}
				if (Length < 1)
				{
					printf("\nИзвините, минимальное число элементов которое можно добавить : 1. Повторите ввод :\n\n");
				}
			} while (Length > 10000 - lengthOfArray || Length < 1);

			int numberOfStart = 0;
			do
			{
				printf("Введите номер \"начальной ячейки\" > ");
				int first_scan = scanf("%d", &numberOfStart);
				if (numberOfStart > 10000 - Length)
				{
					printf("\nИзвините, нельзя вставить %d елементов с %d позиции. Максимально возможная позиция : %d\n\n", Length, numberOfStart, 10000 - Length);
				}
				if (numberOfStart - 1 > lengthOfArray)
				{
					printf("\nИзвините, номер \"начальной ячейки\" не может быть больше %d.\n\n", lengthOfArray + 1);
				}
				else if (numberOfStart - 1 < 0)
				{
					printf("\nИзвините, номер \"начальной ячейки\" не может быть меньше 1. Повторите ввод :\n\n");
				}
			} while (numberOfStart > 10000 - Length || numberOfStart - 1 > lengthOfArray || numberOfStart - 1 < 0);

			int copyOfArray[10000];
			for (int i = 0; i < 10000; i++)
			{
				copyOfArray[i] = Array[i];
			}

			lengthOfArray += Length;

			numberOfStart--;
			int numberOfEnd = numberOfStart + Length;
			int indexOfCopy = 0;
			for (int i = 0; i < 10000; i++)
			{
				if (i >= numberOfStart && i < numberOfEnd)
				{
					Array[i] = num;
				}
				else
				{
					Array[i] = copyOfArray[indexOfCopy];
					indexOfCopy++;
				}
			}


			printf("\nРезультат : \n");
			for (int index = 0; index < lengthOfArray; index++)
			{
				printf("#%d. %d\n", index + 1, Array[index]);
			}

			printf("\n");
		}
		else if (strcmp(answer, "d") == 0)
		{
			if (lengthOfArray == 0)
			{
				printf("\nМассив пустой. Сначала добавьте в него что-нибудь и потом повторите попытку.\n\n");
			}
			else
			{
				int numberOfStart = 0;
				int Length = 0;
				do
				{
					printf("\nВведите количество елементов, которое вы хотите удалить > ");
					std::cin >> Length;
					if (Length > lengthOfArray)
					{
						printf("\nКоличество елементов для удаления не может превышать размер массива(%d).\n", lengthOfArray);
						printf("Пожалуйста, повторите ввод :\n");
					}
					else if (Length < 1)
					{
						printf("\nКоличество елементов для удаления не может быть меньше 1\n");
						printf("Пожалуйста, повторите ввод :\n");
					}
				} while (Length > lengthOfArray || Length < 1);
				do
				{
					printf("\nВведите номер \"начальной ячейки\" > ");
					std::cin >> numberOfStart;
					numberOfStart--;
					if (numberOfStart > lengthOfArray - Length)
					{
						printf("\nНомер начальной ячейки не может превышать %d.\n", lengthOfArray - Length + 1);
						printf("Пожалуйста повторите ввод :\n");
					}
					else if (numberOfStart < 0)
					{
						printf("\nНомер начальной ячейки не может быть меньше 1.\n");
						printf("Пожалуйста повторите ввод :\n");
					}
				} while (numberOfStart > lengthOfArray - Length || numberOfStart < 0);

				int copyOfArray[10000];
				for (int i = 0; i < lengthOfArray; i++)
				{
					copyOfArray[i] = Array[i];
				}

				lengthOfArray -= Length;

				int numberOfEnd = Length + numberOfStart;

				int indexOf = 0;
				for (int i = 0; i < lengthOfArray + Length; i++)
				{
					if (i == 10)
					{
						int a = 8;
					}
					if (i >= numberOfStart && i < numberOfEnd)
					{
						continue;
					}
					else
					{
						Array[indexOf] = copyOfArray[i];
						indexOf++;
					}
				}

				printf("\nРезультат : \n");
				for (int index = 0; index < lengthOfArray; index++)
				{
					printf("#%d. %d\n", index + 1, Array[index]);
				}

				if (lengthOfArray == 0)
				{
					printf("Теперь массив пуст.\n");
				}

				printf("\n");
			}
		}
		else if (strcmp(answer, "e") == 0)
		{
			break;
		}
		else
		{
			printf("\nНеобрабатываемый ввод. Пожалуйста, повторите попытку :\n\n");
		}
	} while (true);
}