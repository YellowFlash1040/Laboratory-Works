#include "Task9.h"
#include <windows.h>

int CompareStrings(char* firstString, char* secondString)
{
	int index = 0;
	while (firstString[index] == secondString[index])
	{
		if (firstString[index] != '\0')
		{
			index++;
		}
		else
		{
			return 0;
		}
	}
	if (firstString[index] != '\0')
	{
		if (secondString[index] != '\0')
		{
			if (firstString[index] > secondString[index])
			{
				return -1;
			}
		}

		return 1;
	}
	else
	{
		return -1;
	}
}

int EqualFunction(Element a, Element b)
{
	return CompareStrings(a.a.name, b.a.name);
}

void PrintMenu()
{
	cout << "Выберите действие:\n";
	cout << "1. Создать список\n";
	cout << "2. Распечатать список(с начала)\n";
	cout << "3. Распечатать список(с конца)\n";
	cout << "4. Поиск по критерию(с начала списка)\n";
	cout << "5. Поиск по критерию(с конца списка)\n";
	cout << "6. Добавить элемент\n";
	cout << "7. Удалить элемент\n";
	cout << "8. Отсортировать список\n";
	cout << "9. Записать список в файл\n";
	cout << "10. Создать список из файла\n";
	cout << "11. Выйти из программы\n\n";
}

int GetAnswerFromUser()
{
	cout << "Ввод > ";
	int answer;
	cin >> answer;
	cout << "\n";

	return answer;
}

Criterion GetCriteriumFromUser()
{
	cout << "Выберите критерий:\n";
	cout << "1. Название сорта зерна\n";
	cout << "2. Тип зерна\n";
	cout << "3. Площадь\n";
	cout << "4. Урожайность\n\n";

	int answer = GetAnswerFromUser();
	if (answer == 1)
	{
		return name;
	}
	else if (answer == 2)
	{
		return type;
	}
	else if (answer == 3)
	{
		return urozhaj;
	}
	else if (answer == 4)
	{
		return square;
	}
}

void ShowMenu()
{
	List* list = new List();
	delete list;
	PrintMenu();
	int answer = GetAnswerFromUser();
	while (answer >= 1 && answer < 11)
	{
		if (answer == 1)
		{
			list = new List();
		}
		else if (answer == 2)
		{
			list->Print();
		}
		else if (answer == 4)
		{
			list->SearchByCriterion(GetCriteriumFromUser());
		}
		else if (answer == 6)
		{
			mon m;
			RandomInput(&m);
			cout << "Введите номер позиции на которую вы хотите добавить элемент:\n";
			int answer = GetAnswerFromUser();
			list->Insert(new Element(m), answer - 1);
		}
		else if (answer == 7)
		{
			cout << "Введите номер элемента который хотите удалить:\n";
			answer = GetAnswerFromUser();
			list->Remove(answer - 1);
		}
		else if (answer == 8)
		{
			list->Sort(EqualFunction);
		}
		else if (answer == 9)
		{
			char filePath[] = "data.txt";
			list->WriteListIntoTheTXTFile(filePath);
		}
		else if (answer == 10)
		{
			char filePath[] = "data.txt";
			list->ReadListFromTXTFile(filePath);
		}
		else if (answer == 3)
		{
			list->PrintFromTheEnd();
		}
		else if (answer == 5)
		{
			list->SearchByCriterionFromTheEnd(GetCriteriumFromUser());
		}

		PrintMenu();
		answer = GetAnswerFromUser();
	}
}

void StartTask()
{
	SetRussianLanguage();
	ShowMenu();
}