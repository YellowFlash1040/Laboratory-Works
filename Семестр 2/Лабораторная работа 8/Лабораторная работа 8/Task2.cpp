#define _CRT_SECURE_NO_WARNINGS
#include "Task2.h"
#include <windows.h>
#include <iostream>

using namespace std;

void RandomInput(mon* m)
{
	int nam = rand() % 3;
	if (nam == 0)
	{
		strcpy(m->name, "������");
		m->type = '�';
	}
	else if (nam == 1)
	{
		strcpy(m->name, "���");
		m->type = '�';
	}
	else if (nam == 2)
	{
		strcpy(m->name, "���");
		m->type = '�';
	}

	m->square = rand() % 25651;
	m->urozhaj = rand() % 100;
}

void UserInput(mon* m)
{
	printf("�������: ������������, ���, �������� �������(��), �����������(�/��) > ");

	cin >> m->name;
	cin >> m->type;
	cin >> m->square;
	cin >> m->urozhaj;
}

void SetRussianLanguage()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}