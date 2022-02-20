#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <windows.h>

using namespace std;

struct mon
{
	char name[15];
	char type;
	int square;
	int urozhaj;
};

mon mm[10];
int length;

void PrintTable()
{
	printf("------------------------------------------------------\n");
	printf("|             Сельскохозяйственные культуры          |\n");
	printf("|----------------------------------------------------|\n");
	printf("| Наименование  |  Тип  |  Посевная   |  Урожайность |\n");
	printf("|               |       | площадь(га) |    (ц/га)    |\n");
	printf("|---------------|-------|-------------|--------------|\n");

	for (int i = 0; i < length; i++)
	{
		printf_s("| %-13s | %5c | %11d | %12d |\n", mm[i].name, mm[i].type, mm[i].square, mm[i].urozhaj);
	}
	printf("------------------------------------------------------\n");

	cout << endl;
}

void SortArray()
{
	mon temp;
	int indexOfMinElement;

	for (int i = 0; i < length; i++)
	{
		indexOfMinElement = i;
		for (int j = i + 1; j < length; j++)
		{
			if (strcmp(mm[j].name, mm[indexOfMinElement].name) <= 0)
			{
				indexOfMinElement = j;
			}
		}
		temp = mm[i];
		mm[i] = mm[indexOfMinElement];
		mm[indexOfMinElement] = temp;
	}
}

void RandomInput()
{
	srand(time(0));
	int size = rand() % 4 + 7;
	for (int i = 0; i < size; i++)
	{
		int nam = rand() % 3;
		if (nam == 0)
		{
			strcpy(mm[i].name, "Чумиза");
			mm[i].type = 'З';
		}
		else if (nam == 1)
		{
			strcpy(mm[i].name, "Соя");
			mm[i].type = 'Б';
		}
		else if (nam == 2)
		{
			strcpy(mm[i].name, "Рис");
			mm[i].type = 'З';
		}
		
		mm[i].square = rand() % 25651;
		mm[i].urozhaj = rand() % 100;
	}
	length = size;
}

void UserInput()
{
	int count;
	for (count = 0, length = 0; count < 10; count++)
	{
		printf("%d. Введите: наименование, тип, посевная площадь(га), урожайность(ц/га) >", count + 1);

		scanf_s("%s", mm[count].name, sizeof(mm[count].name));
		if (strcmp(mm[count].name, "***") == 0)//Проверка на то, хочет ли пользователь продолжать ввод. Если ввод равен "***", значит не хочет, и мы прерываем цикл
		{
			break;
		}

		scanf_s("%s", &mm[count].type, sizeof(mm[count].name));
		scanf_s("%d", &mm[count].square);
		scanf_s("%d", &mm[count].urozhaj);
	}
	length = count;

	cout << endl;
}

void ShowMenu()
{
	int answer = 0;
	while (answer != 5)
	{
		cout << "Выберите действие:\nВвод с экрана(1)\nВвод случайным образом(2)\nСортировка массива(3)\nПечать таблицы(4)\nВыход из программы(5)\n\n";
		cout << "Ввод >";
		cin >> answer;
		cout << endl;

		if (answer == 1)
		{
			UserInput();
		}
		else if (answer == 2)
		{
			RandomInput();
		}
		else if (answer == 3)
		{
			SortArray();
		}
		else if (answer == 4)
		{
			PrintTable();
		}
	}
}

int main(void) 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	ShowMenu();

	return 0;
}