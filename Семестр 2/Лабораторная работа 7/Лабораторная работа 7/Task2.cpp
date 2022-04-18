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
		strcpy(m->name, "Чумиза");
		m->type = 'З';
	}
	else if (nam == 1)
	{
		strcpy(m->name, "Соя");
		m->type = 'Б';
	}
	else if (nam == 2)
	{
		strcpy(m->name, "Рис");
		m->type = 'З';
	}

	m->square = rand() % 25651;
	m->urozhaj = rand() % 100;
}

void UserInput(mon* m)
{
	printf("Введите: наименование, тип, посевная площадь(га), урожайность(ц/га) > ");

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