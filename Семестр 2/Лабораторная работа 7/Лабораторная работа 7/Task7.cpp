#include "Task2.h"
#include "Task7.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include <iostream>
#include <windows.h>

using namespace std;

void ShowMenu()
{
	cout << "Выберите действие: \n";
	cout << "(1) Ввод с экрана и запись в файл\n";
	cout << "(2) Ввод случайным образом и запись в файл\n";
	cout << "(3) Добавить запись в начало файла\n";
	cout << "(4) Добавить запись в конец файла\n";
	cout << "(5) Печать одной записи из файла по номеру\n";
	cout << "(6) Чтение всех структур последовательно из файла и печать\n";
	cout << "(7) Выход из программы\n";
}

void WriteEmptyLineInConsole()
{
	cout << '\n';
}

char GetAnswerFromUser()
{
	char answer;
	cout << "Ваш ответ > ";
	cin >> answer;
	return answer;
}

void ClearFileAndWriteThereStructure(mon m, char filePath[])
{
	FILE* dataFile = fopen(filePath, "w");

	int index = 0;
	while (m.name[index] != '\0')
	{
		index++;
	}
	fwrite(m.name, 1, index, dataFile);

	fwrite(" ", 1, 1, dataFile);

	char type[2];
	type[0] = m.type;
	fwrite(type, 1, 1, dataFile);

	fwrite(" ", 1, 1, dataFile);

	index = 0;
	char square[15];
	itoa(m.square, square, 10);
	while (square[index] != '\0')
	{
		index++;
	}
	fwrite(square, 1, index, dataFile);

	fwrite(" ", 1, 1, dataFile);

	index = 0;
	char urozhaj[15];
	itoa(m.urozhaj, urozhaj, 10);
	while (urozhaj[index] != '\0')
	{
		index++;
	}
	fwrite(urozhaj, 1, index, dataFile);

	fwrite("\n", 1, 1, dataFile);

	fclose(dataFile);
	dataFile = nullptr;
}

void AddStructureToFileAtTheEnd(mon m, char filePath[])
{
	FILE* dataFile = fopen(filePath, "a+");

	int index = 0;
	while(m.name[index] != '\0')
	{
		index++;
	}
	fwrite(m.name, 1, index, dataFile);

	fwrite(" ", 1, 1, dataFile);

	char type[2];
	type[0] = m.type;
	fwrite(type, 1, 1, dataFile);

	fwrite(" ", 1, 1, dataFile);

	index = 0;
	char square[15];
	itoa(m.square, square, 10);
	while (square[index] != '\0')
	{
		index++;
	}
	fwrite(square, 1, index, dataFile);

	fwrite(" ", 1, 1, dataFile);

	index = 0;
	char urozhaj[15];
	itoa(m.urozhaj, urozhaj, 10);
	while (urozhaj[index] != '\0')
	{
		index++;
	}
	fwrite(urozhaj, 1, index, dataFile);

	fwrite("\n", 1, 1, dataFile);

	fclose(dataFile);
	dataFile = nullptr;
}

void ClearCharArray(char* word, int length)
{
	for (int i = 0; i < length; i++)
	{
		word[i] = NULL;
	}
}

void ReadStructureFromFileWithNumber(mon* m, char filePath[], int number)
{
	FILE* dataFile = fopen(filePath, "r");

	int length = 15;
	char* name = new char[length];
	char* urozhaj = new char[length];
	char* square = new char[length];
	char* type = new char[2];

	char* bufer = new char[2];

	for (int i = 0; i < number; i++)
	{
		ClearCharArray(name, length);
		ClearCharArray(urozhaj, length);
		ClearCharArray(square, length);
		ClearCharArray(type, 2);

		int indexInName = 0;
		fread(bufer, 1, 1, dataFile);
		while (bufer[0] != ' ')
		{
			name[indexInName] = bufer[0];
			indexInName++;
			fread(bufer, 1, 1, dataFile);
		}

		fread(bufer, 1, 1, dataFile);
		while (bufer[0] != ' ')
		{
			type[0] = bufer[0];
			fread(bufer, 1, 1, dataFile);
		}

		int indexInSquare = 0;
		fread(bufer, 1, 1, dataFile);
		while (bufer[0] != ' ')
		{
			square[indexInSquare] = bufer[0];
			indexInSquare++;
			fread(bufer, 1, 1, dataFile);
		}

		int indexInUrozhaj = 0;
		fread(bufer, 1, 1, dataFile);
		while (bufer[0] != '\n')
		{
			urozhaj[indexInUrozhaj] = bufer[0];
			indexInUrozhaj++;
			fread(bufer, 1, 1, dataFile);
		}
	}

	int j = 0;
	while (name[j] != '\0')
	{
		m->name[j] = name[j];
		j++;
	}
	m->name[j] = '\0';

	m->square = atoi(square);
	m->type = type[0];
	m->urozhaj = atoi(urozhaj);

	delete[] name;
	name = nullptr;
	delete[] urozhaj;
	urozhaj = nullptr;
	delete[] type;
	type = nullptr;
	delete[] square;
	square = nullptr;
	delete[] bufer;
	bufer = nullptr;

	fclose(dataFile);
	dataFile = nullptr;
}

bool FileEmpty(char filePath[])
{
	FILE* dataFile = fopen(filePath, "rb+");

	fseek(dataFile, 0, SEEK_END);
	int countOfSymbols = ftell(dataFile);

	fclose(dataFile);
	dataFile = nullptr;

	return countOfSymbols > 0 ? false : true;
}

int GetCountOfLinesInFile(char filePath[])
{
	if (FileEmpty(filePath))
	{
		return 0;
	}

	int countOfLines = 0;

	FILE* dataFile = fopen(filePath, "r");

	char* bufer = new char[2];
	fread(bufer, 1, 1, dataFile);
	int countOfSlashN = 0;
	while (true)
	{
		if (bufer[0] == '\n')
		{
			countOfSlashN++;
			if (countOfSlashN != 2)
			{
				countOfLines++;
			}
			else
			{
				break;
			}
		}
		else
		{
			countOfSlashN = 0;
		}

		fread(bufer, 1, 1, dataFile);
	}

	delete[] bufer;
	bufer = nullptr;

	fclose(dataFile);
	dataFile = nullptr;

	return countOfLines;
}

void AddStructureAtTheBeginningOfTheFile(mon m, char filePath[])
{
	char* newFilePath = new char[256];
	ClearCharArray(newFilePath, 256);

	int index = 0;
	while (filePath[index] != '.')
	{
		newFilePath[index] = filePath[index];
		index++;
	}

	newFilePath[index] = '1';
	newFilePath[index + 1] = '.';
	newFilePath[index + 2] = 't';
	newFilePath[index + 3] = 'x';
	newFilePath[index + 4] = 't';
	index += 4;

	CreateFileForData(newFilePath);

	AddStructureToFileAtTheEnd(m, newFilePath);

	int countOfLines = GetCountOfLinesInFile(filePath);
	for (int i = 0; i < countOfLines; i++)
	{
		ReadStructureFromFileWithNumber(&m, filePath, i + 1);
		AddStructureToFileAtTheEnd(m, newFilePath);
	} 

	remove(filePath);
	rename(newFilePath, filePath);

	delete[] newFilePath;
	newFilePath = nullptr;
}

int GetNumberOfStructurOfUser()
{
	cout << "Введите номер записи > ";
	int number;
	cin >> number;

	return number;
}

void WriteStructureInConsole(mon m)
{
	cout << m.name << " " << m.type << " " << m.square << " " << m.urozhaj << "\n";
}

void CompleteItemSelectedByUser(char answer, char* filePath)
{
	int length = 1;
	mon m;

	if (answer == '1')
	{
		WriteEmptyLineInConsole();
		UserInput(&m);
		ClearFileAndWriteThereStructure(m, filePath);
	}
	else if (answer == '2')
	{
		RandomInput(&m);
		ClearFileAndWriteThereStructure(m, filePath);
	}
	else if (answer == '3')
	{
		WriteEmptyLineInConsole();
		UserInput(&m);
		AddStructureAtTheBeginningOfTheFile(m, filePath);
	}
	else if (answer == '4')
	{
		UserInput(&m);
		AddStructureToFileAtTheEnd(m, filePath);
	}
	else if (answer == '5')
	{
		int count = GetCountOfLinesInFile(filePath);
		if (count != 0)
		{
			WriteEmptyLineInConsole();
			int number = GetNumberOfStructurOfUser();
			while (number < 1 || number > count)
			{
				WriteEmptyLineInConsole();
				cout << "Неверный ввод. Пожалуйста повторите попытку:\n";
				number = GetNumberOfStructurOfUser();
			}
			ReadStructureFromFileWithNumber(&m, filePath, number);
			WriteEmptyLineInConsole();
			cout << "Результат: ";
			WriteStructureInConsole(m);
		}
		else
		{
			WriteEmptyLineInConsole();
			cout << "Файл пустой. Сначала пожалуйста что-нибудь запишите\n";
		}
	}
	else if (answer == '6')
	{
		int count = GetCountOfLinesInFile(filePath);
		if (count != 0)
		{
			WriteEmptyLineInConsole();
			cout << "Результат:\n";
			for (int i = 0; i < count; i++)
			{
				ReadStructureFromFileWithNumber(&m, filePath, i + 1);
				WriteStructureInConsole(m);
			}
		}
		else
		{
			WriteEmptyLineInConsole();
			cout << "Файл пустой. Сначала пожалуйста что-нибудь запишите\n";
		}
	}
}

void PrintLine(int sizeOfLine)
{
	for (int i = 0; i < sizeOfLine; i++)
	{
		cout << '-';
	}
	cout << '\n';
}

FILE* CreateFileForData(char filePath[])
{
	FILE* dataFile;
	dataFile = fopen(filePath, "w");
	fclose(dataFile);
	
	return dataFile;
}

void StartTask()
{
	srand(time(0));

	SetRussianLanguage();

	char* filePath = new char[] {"data.txt"};

	FILE* dataFile = fopen(filePath, "r");
	if (!dataFile)
	{
		dataFile = CreateFileForData(filePath);
	}
	fclose(dataFile);
	dataFile = nullptr;

	char answer;
	do
	{
		ShowMenu();
		WriteEmptyLineInConsole();
		answer = GetAnswerFromUser();
		if (answer < '7')
		{
			CompleteItemSelectedByUser(answer, filePath);
			PrintLine(40);
			WriteEmptyLineInConsole();
		}
	} while (answer != '7');

	delete[] filePath;
	filePath = nullptr;
}