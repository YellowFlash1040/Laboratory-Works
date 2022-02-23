#define _CRT_SECURE_NO_WARNINGS
#include "Task1.h"
#include <windows.h>
//#define DEBUG

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
#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("PrintTable");
#endif // DEBUG


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

#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("PrintTable");
#endif // DEBUG
}

void SortArray()
{
#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("SortArray");
#endif // DEBUG

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

#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("SortArray");
#endif // DEBUG
}

void RandomInput()
{
#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("RandomInput");
#endif // DEBUG

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

#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("RandomInput");
#endif // DEBUG
}

void UserInput()
{
#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("UserInput");
#endif // DEBUG

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

#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("UserInput");
#endif // DEBUG
}

void ShowMenu()
{
#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("ShowMenu");
#endif // DEBUG

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

#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("ShowMenu");
#endif // DEBUG
}

void SetRussianLanguage()
{
#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("SetRussianLanguage");
#endif // DEBUG

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("SetRussianLanguage");
#endif // DEBUG
}

void ShowMenuWithOnlyUserInput()
{
#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("ShowMenuWithOnlyUserInput");
#endif // DEBUG

	int answer = 0;
	while (answer != 4)
	{
		cout << "Выберите действие:\nВвод с экрана(1)\nСортировка массива(2)\nПечать таблицы(3)\nВыход из программы(4)\n\n";
		cout << "Ввод >";
		cin >> answer;
		cout << endl;

		if (answer == 1)
		{
			UserInput();
		}
		else if (answer == 2)
		{
			SortArray();
		}
		else if (answer == 3)
		{
			PrintTable();
		}
	}

#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("ShowMenuWithOnlyUserInput");
#endif // DEBUG
}

void ShowMenuWithOnlyRandomInput()
{
#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("ShowMenuWithOnlyRandomInput");
#endif // DEBUG

	int answer = 0;
	while (answer != 4)
	{
		cout << "Выберите действие:\nЗаполнение массива случайным образом(1)\nСортировка массива(2)\nПечать таблицы(3)\nВыход из программы(4)\n\n";
		cout << "Ввод >";
		cin >> answer;
		cout << endl;

		if (answer == 1)
		{
			RandomInput();
		}
		else if (answer == 2)
		{
			SortArray();
		}
		else if (answer == 3)
		{
			PrintTable();
		}
	}

#ifdef DEBUG
	PrintCurrentTimeAndDate();
	PrintCurrentFileNameAndFunctionName("ShowMenuWithOnlyRandomInput");
#endif // DEBUG
}

void PrintCurrentTimeAndDate()
{
	/*int timee = time(0);
	int hour = timee / 3600 - 457102;
	int minutes = timee % 3600 / 60;
	int seconds = timee % 3600 % 60;
	cout << hour << ":" << minutes << ":" << seconds << endl;*/

	/*time_t seconds = time(0);
	tm* timeinfo = localtime(&seconds);
	cout << asctime(timeinfo) << endl;*/

	char buffer[80];
	time_t seconds = time(0);
	tm* timeinfo = localtime(&seconds);
	const char* format = "Data: %A, %B %d, %Y\nTime: %I:%M:%S";
	strftime(buffer, 80, format, timeinfo);
	cout << buffer << endl;
}

void PrintCurrentFileNameAndFunctionName(string FunctionName)
{
	cout << "Current file name: Task1.cpp" << endl << "Current function name: " << FunctionName << endl << endl;
}