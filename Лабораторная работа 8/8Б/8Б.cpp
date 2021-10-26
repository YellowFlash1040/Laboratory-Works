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
	int* Array = new int[lengthOfArray];
	printf("\n");
	for (int i = 0; i < lengthOfArray; i++)
	{
		Array[i] = 0;
	}

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
			int lengthOfInput;
			std::string usersInput;
			int countOfElements;
			do
			{
				printf("\nПожалуйста, введите елементы через \"/\" > ");
				std::cin >> usersInput;
				lengthOfInput = usersInput.size();
				countOfElements = 0;
				for (int i = 0; i < lengthOfInput; i++)
				{
					if (usersInput[i] == '/')
					{
						countOfElements++;
					}
				}
				countOfElements++;
				if (countOfElements > lengthOfArray)
				{
					printf("\nКоличество елементов не может превышать размер массива (%d). Пожалуйста, повторите ввод :\n", lengthOfArray);
				}
			} while (countOfElements > lengthOfArray);
			int* usersArray = new int[countOfElements];

			int indexOfElement = 0;
			int indexOfChar = 0;
			std::string word;
			for (int i = 0; i < lengthOfInput; i++)
			{
				if (usersInput[i] == '/')
				{
					word = usersInput.substr(indexOfChar, i - indexOfChar);
					usersArray[indexOfElement] = atoi(word.c_str());
					indexOfChar = i + 1;
					indexOfElement++;
				}
			}
			word = usersInput.substr(indexOfChar, lengthOfInput - indexOfChar);
			usersArray[indexOfElement] = atoi(word.c_str());


			/*for (int i = 0; i < countOfElements; i++)
			{
				printf("%d\n", usersArray[i]);
			}*/
			int i = 0;
			int maxIndex = lengthOfArray - countOfElements + 1;
			do
			{
				printf("\nПожалуйста введите номер \"начальной ячейки\" > ");
				int first_scan = scanf("%d", &i);
				if (i > maxIndex)
				{
					printf("\nНомер начальной ячейки не может быть больше %d. Пожалуйста, повторите ввод :\n", maxIndex);
				}
				else if (i < 1)
				{
					printf("\nНомер начальной ячейки не может быть меньше 1. Пожалуйста, повторите ввод :\n");
				}
			} while (i > maxIndex || i < 1);
			int j;
			for (j = 0, i -= 1; j < countOfElements; i++, j++)
			{
				Array[i] = usersArray[j];
			}

			printf("\nРезультат : \n");
			for (int index = 0; index < lengthOfArray; index++)
			{
				printf("%d\n", Array[index]);
			}

			printf("\n");
		}
		else if (strcmp(answer, "d") == 0)
		{
			int numberOfStart = 0;
			int numberOfElements = 0;
			do
			{
				printf("\nВведите количество елементов, которое вы хотите удалить > ");
				std::cin >> numberOfElements;
				numberOfElements--;
				if (numberOfElements > lengthOfArray)
				{
					printf("\nКоличество елементов для удаления не может превышать размер массива(%d).\n", lengthOfArray);
					printf("Пожалуйста, повторите ввод :\n");
				}
				else if (numberOfElements < 1)
				{
					printf("\nКоличество елементов для удаления не может быть меньше 1\n");
					printf("Пожалуйста, повторите ввод :\n");
				}
			} while (numberOfElements > lengthOfArray || numberOfElements < 1);
			do
			{
				printf("\nВведите номер \"начальной ячейки\" > ");
				std::cin >> numberOfStart;
				numberOfStart--;
				if (numberOfStart > lengthOfArray - numberOfElements)
				{
					printf("\nНомер начальной ячейки не может превышать %d.\n", lengthOfArray - numberOfElements);
					printf("Пожалуйста повторите ввод :\n");
				}
				else if (numberOfStart < 1)
				{
					printf("\nНомер начальной ячейки не может быть меньше 1.\n");
					printf("Пожалуйста повторите ввод :\n");
				}
			} while (numberOfStart > lengthOfArray - numberOfElements || numberOfStart < 1);

			int length = numberOfStart + numberOfElements;
			for ( ; numberOfStart <= length; numberOfStart++)
			{
				Array[numberOfStart] = 0;
			}

			printf("\nРезультат : \n");
			for (int index = 0; index < lengthOfArray; index++)
			{
				printf("%d\n", Array[index]);
			}

			printf("\n");
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