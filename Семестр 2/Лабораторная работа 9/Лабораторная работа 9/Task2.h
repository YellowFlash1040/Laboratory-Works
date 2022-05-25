#pragma once
#pragma warning(disable : 4996)

#include <iostream>

struct mon
{
	mon()
	{
		int lengthOfName = 15;
		name = new char[lengthOfName];
		for (int i = 0; i < lengthOfName; i++)
		{
			name[i] = NULL;
		}
	}
	char* name;
	char type;
	int square;
	int urozhaj;

	char* ToString()
	{
		char* word = new char[30];
		for (int i = 0; i < 30; i++)
		{
			word[i] = NULL;
		}
		int j = 0;
		int index = 0;
		while (name[index] != '\0')
		{
			word[j] = name[index];
			j++;
			index++;
		}
		word[j] = ' ';
		j++;
		index = 0;
		word[j] = type;
		j++;
		word[j] = ' ';
		j++;
		char* bufer = new char[6];
		itoa(square, bufer, 10);
		while (bufer[index] != '\0')
		{
			word[j] = bufer[index];
			index++;
			j++;
		}
		word[j] = ' ';
		j++;
		index = 0;
		itoa(urozhaj, bufer, 10);
		while (bufer[index] != '\0')
		{
			word[j] = bufer[index];
			index++;
			j++;
		}
		word[j] = '\n';
		j++;

		delete[] bufer;
		bufer = nullptr;

		return word;
	}
};

void UserInput(mon* m);
void RandomInput(mon* m);
void SetRussianLanguage();