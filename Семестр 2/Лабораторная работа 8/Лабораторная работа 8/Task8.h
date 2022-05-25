#pragma once
#pragma warning(disable : 4996)

#include "Task2.h"
#include <iostream>

using namespace std;

void StartTask();

enum Criterion
{
	name, 
	type,
	square,
	urozhaj
};

struct Element
{
	Element* nextElement;

	mon a;

	Element(mon m)
	{
		a = m;
	}
};

struct List
{
	Element* firstElement;

	List()
	{
		Count = 0;
	}

	int Count;

	void Add(Element* newElement)
	{
		Insert(newElement, Count);
	}

	void Insert(Element* newElement, int position)
	{
		if (position > 0)
		{
			Element* element = GetElementWithNumber(position - 1);
			Element* secondElement = GetElementWithNumber(position);
			element->nextElement = newElement;
			newElement->nextElement = secondElement;

			element = nullptr;
			secondElement = nullptr;
		}
		else
		{
			Element* temp = firstElement;
			firstElement = newElement;
			firstElement->nextElement = temp;
		}

		Count++;
	}

	void Print()
	{
		Element* element = NULL;
		for (int i = 0; i < Count; i++)
		{
			element = GetElementWithNumber(i);
			cout << element->a.ToString();
		}
		cout << '\n';
	}

	char* ToString()
	{
		int lengthOfElement = 30;
		int lengthOfWord = lengthOfElement * Count;
		char* word = new char[lengthOfWord];
		for (int i = 0; i < lengthOfWord; i++)
		{
			word[i] = NULL;
		}

		int index = 0;
		char* bufer = new char;
		for (int i = 0; i < Count; i++)
		{
			int buferIndex = 0;
			bufer = GetElementWithNumber(i)->a.ToString();
			while (bufer[buferIndex] != '\n')
			{
				word[index] = bufer[buferIndex];
				index++;
				buferIndex++;
			}
			word[index] = '\n';
			index++;
		}

		delete[] bufer;
		bufer = nullptr;

		return word;
	}

	void Remove(int position, int count = 1)
	{
		if (position > 0)
		{
			Element* PreviousElement = GetElementWithNumber(position - 1);
			Element* NextElement = GetElementWithNumber(position + count);
			PreviousElement->nextElement = NextElement;

			PreviousElement = nullptr;
			NextElement = nullptr;
		}
		else
		{
			firstElement = GetElementWithNumber(position + count - 1)->nextElement;
		}
		Count -= count;
	}

	Element* GetElementWithNumber(int numberOfElement)
	{
		Element* element = firstElement;
		for (int i = 0; i < numberOfElement; i++)
		{
			element = element->nextElement;
		}

		return element;
	}

	void ChangeElementsWithNumbers(int firstElementPosition, int secondElementPosition)
	{
		Element* element = GetElementWithNumber(firstElementPosition);
		Element* secondElement = GetElementWithNumber(secondElementPosition);
		mon temp = element->a;
		element->a = secondElement->a;
		secondElement->a = temp;
	}

	void Sort(int (*EqualFunction)(Element a, Element b))
	{
		for (int j = 0; j < Count; j++)
		{
			int indexOfMinElement = j;
			for (int i = j; i < Count; i++)
			{
				if (EqualFunction(*GetElementWithNumber(i), *GetElementWithNumber(indexOfMinElement)) >= 0)
				{
					indexOfMinElement = i;
				}
			}

			ChangeElementsWithNumbers(j, indexOfMinElement);
		}
	}

	void WriteListIntoTheTXTFile(char* FilePath)
	{
		FILE* dataFile = fopen(FilePath, "a");
		fprintf(dataFile, this->ToString());
		fclose(dataFile);
		dataFile = nullptr;
	}

	void ReadListFromTXTFile(char* FilePath) 
	{
		if (Count != 0)
		{
			Remove(0, Count);
		}

		FILE* dataFile = fopen(FilePath, "r");
		int lengthOfBufer = 30;
		char* bufer = new char[lengthOfBufer];
		
		cout << '\n';
		mon m;
		int index = 1;
		while (fscanf(dataFile, "%s", bufer) != EOF)
		{
			if (index == 1)
			{
				int i = 0;
				while (bufer[i] != '\0')
				{
					m.name[i] = bufer[i];
					i++;
				}
				index = 2;
			}
			else if (index == 2)
			{
				m.type = bufer[0];
				index = 3;
			}
			else if (index == 3)
			{
				m.square = atoi(bufer);
				index = 4;
			}
			else if (index == 4)
			{
				m.urozhaj = atoi(bufer);
				Add(new Element(m));
				m.name = new char[7];
				int i = 0;
				while (m.name[i] != '\0')
				{
					m.name[i] = NULL;
					i++;
				}
				index = 1;
			}
		}

		fclose(dataFile);
		dataFile = nullptr;
		delete[] bufer;
		bufer = nullptr;
	}

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

	void SearchByCriterion(Criterion criterion)
	{
		if (criterion == name)
		{
			cout << "¬ведите название сорта зерна дл€ поиска:\n";
			cout << "¬вод > ";
			char* word = new char[5];
			cin >> word;
			cout << "\n";
			for (int i = 0; i < Count; i++)
			{
				mon mo = GetElementWithNumber(i)->a;
				int result = CompareStrings(mo.name, word);
				if (result == 0)
				{
					cout << mo.ToString();
				}
			}

			delete[] word;
			word = nullptr;
		}
		else if (criterion == type)
		{
			cout << "¬ведите название типа зерна дл€ поиска:\n";
			cout << "¬вод > ";
			char* word = new char[2];
			cin >> word;
			cout << "\n";
			for (int i = 0; i < Count; i++)
			{
				mon mo = GetElementWithNumber(i)->a;
				if (mo.type == word[0])
				{
					cout << mo.ToString();
				}
			}

			delete[] word;
			word = nullptr;
		}
		else if (criterion == square)
		{
			cout << "¬ведите площадь дл€ поиска:\n";
			cout << "¬вод > ";
			char* word = new char[7];
			cin >> word;
			cout << "\n";
			for (int i = 0; i < Count; i++)
			{
				mon mo = GetElementWithNumber(i)->a;
				if (mo.square == atoi(word))
				{
					cout << mo.ToString();
				}
			}

			delete[] word;
			word = nullptr;
		}
		else if (criterion == urozhaj)
		{
			cout << "¬ведите урожай дл€ поиска:\n";
			cout << "¬вод > ";
			char* word = new char[7];
			cin >> word;
			cout << "\n";
			for (int i = 0; i < Count; i++)
			{
				mon mo = GetElementWithNumber(i)->a;
				if (mo.urozhaj == atoi(word))
				{
					cout << mo.ToString();
				}
			}

			delete[] word;
			word = nullptr;
		}
		cout << '\n';
	}
};