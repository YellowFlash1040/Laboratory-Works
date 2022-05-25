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
	cout << "�������� ��������:\n";
	cout << "1. ������� ������\n";
	cout << "2. ����������� ������(� ������)\n";
	cout << "3. ����������� ������(� �����)\n";
	cout << "4. ����� �� ��������(� ������ ������)\n";
	cout << "5. ����� �� ��������(� ����� ������)\n";
	cout << "6. �������� �������\n";
	cout << "7. ������� �������\n";
	cout << "8. ������������� ������\n";
	cout << "9. �������� ������ � ����\n";
	cout << "10. ������� ������ �� �����\n";
	cout << "11. ����� �� ���������\n\n";
}

int GetAnswerFromUser()
{
	cout << "���� > ";
	int answer;
	cin >> answer;
	cout << "\n";

	return answer;
}

Criterion GetCriteriumFromUser()
{
	cout << "�������� ��������:\n";
	cout << "1. �������� ����� �����\n";
	cout << "2. ��� �����\n";
	cout << "3. �������\n";
	cout << "4. �����������\n\n";

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
			cout << "������� ����� ������� �� ������� �� ������ �������� �������:\n";
			int answer = GetAnswerFromUser();
			list->Insert(new Element(m), answer - 1);
		}
		else if (answer == 7)
		{
			cout << "������� ����� �������� ������� ������ �������:\n";
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