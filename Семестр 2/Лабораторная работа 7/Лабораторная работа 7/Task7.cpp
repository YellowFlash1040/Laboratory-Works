#include "Task7.h"
#include <fstream>
#include <string>
#include <windows.h>

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

char GetAnswerFromUser()
{
	char answer;
	cout << "Ваш ответ > ";
	cin >> answer;
	return answer;
}

void WriteDataToFile(mon m, string filePath)
{
	ofstream StreamWriter(filePath, ios::app);
	StreamWriter << m.name << " " << m.type << " " << m.square << " " << m.urozhaj << "\n";
	StreamWriter.close();
}

void WriteEmptyLineToFile(string filePath)
{
	ofstream StreamWriter(filePath, ios::app);
	StreamWriter << '\n';
	StreamWriter.close();
}

void WriteEmptyLineInConsole()
{
	cout << '\n';
}

void GetDataFromLine(string line, mon& m)
{
	string parts[4];
	for (int i = 0, index = 0; i < line.length(); i++)
	{
		if (line[i] == ' ')
		{
			index++;
		}
		else
		{
			parts[index] = parts[index] + line[i];
		}
	}

	for (int i = 0; i < 15; i++)
	{
		m.name[i] = NULL;
	}
	
	for (size_t i = 0; i < parts[0].length(); i++)
	{
		m.name[i] = parts[0][i];
	}
	for (size_t i = 0; i < parts[1].length(); i++)
	{
		m.type = parts[1][i];
	}

	char* Square = new char[parts[2].length()];
	for (int i = 0; i < parts[2].length(); i++)
	{
		Square[i] = NULL;
	}

	for (size_t i = 0; i < parts[2].length(); i++)
	{
		Square[i] = parts[2][i];
	}
	m.square = atoi(Square);

	delete[] Square;
	Square = nullptr;

	char* Urozhaj = new char[parts[3].length()];
	for (int i = 0; i < parts[3].length(); i++)
	{
		Urozhaj[i] = NULL;
	}

	for (size_t i = 0; i < parts[3].length(); i++)
	{
		Urozhaj[i] = parts[3][i];
	}
	m.urozhaj = atoi(Urozhaj);

	delete[] Urozhaj;
	Urozhaj = nullptr;
}

void RemoveFile(string filePath)
{
	int lengthOfPath = filePath.length() + 1;
	char* path = new char[lengthOfPath];
	
	for (int i = 0; i < lengthOfPath; i++)
	{
		path[i] = NULL;
	}
	
	for (int i = 0; i < lengthOfPath; i++)
	{
		path[i] = filePath[i];
	}
	
	remove(path);

	delete[] path;
	path = nullptr;
}

void RenameFile(string OldFileName, string NewFileName)
{
	int lengthOfOldPath = OldFileName.length() + 1;
	char* OldPath = new char[lengthOfOldPath];

	for (int i = 0; i < lengthOfOldPath; i++)
	{
		OldPath[i] = NULL;
	}

	for (int i = 0; i < lengthOfOldPath; i++)
	{
		OldPath[i] = OldFileName[i];
	}

	int lengthOfNewPath = NewFileName.length() + 1;
	char* NewPath = new char[lengthOfNewPath];

	for (int i = 0; i < lengthOfNewPath; i++)
	{
		NewPath[i] = NULL;
	}

	for (int i = 0; i < lengthOfNewPath; i++)
	{
		NewPath[i] = NewFileName[i];
	}

	int result = rename(OldPath, NewPath);

	delete[] OldPath;
	OldPath = nullptr;
	delete[] NewPath;
	NewPath = nullptr;
}

void AddTextAtTheBeginningOfTheFile(mon m, string filePath)
{
	string copyOfFilePath = filePath;
	copyOfFilePath.insert(copyOfFilePath.length() - 4, "1");
	WriteDataToFile(m, copyOfFilePath);

	ifstream StreamReader(filePath);
	string line;
	mon oldM;
	while (getline(StreamReader, line))
	{
		GetDataFromLine(line, oldM);
		WriteDataToFile(oldM, copyOfFilePath);
	}
	StreamReader.close();

	RemoveFile(filePath);
	RenameFile(copyOfFilePath, filePath);
}

int HowManyRecordsAreInTheFile(string filePath)
{
	int count = 0;
	ifstream StreamReader(filePath);
	string line;
	while (getline(StreamReader, line))
	{
		count++;
	}

	return count;
}

int GetNumberOfLineFromUser()
{
	int count = HowManyRecordsAreInTheFile("data.txt");
	cout << "На данный момент в файле записей: " << count << '\n';
	cout << "Введите номер записи > ";
	int numberOfLine;
	cin >> numberOfLine;
	
	while (numberOfLine < 1 || numberOfLine > count)
	{
		WriteEmptyLineInConsole();
		cout << "Неверный ввод. Повторите попытку" << '\n';
		WriteEmptyLineInConsole();
		cout << "На данный момент в файле записей: " << count << '\n';
		cout << "Введите номер записи > ";
		cin >> numberOfLine;
	}

	return numberOfLine;
}

void FindLineInFileAndWriteItToConsole()
{
	int numberOfLine = GetNumberOfLineFromUser();
	ifstream StreamReader("data.txt");
	string line;
	for (int i = 0; i < numberOfLine; i++)
	{
		getline(StreamReader, line);
	}
	StreamReader.close();
	cout << "Результат: " << line << '\n';
}

void ReadAllLinesFromFileAndWriteThemInToConsole()
{
	ifstream StreamReader("data.txt");
	string line;
	mon m;
	cout << "Результат: \n";
	while (getline(StreamReader, line))
	{
		cout << line << '\n';
	}
	StreamReader.close();
}

void CompleteItemSelectedByUser(char answer)
{
	int length = 1;
	mon m;
	if (answer == '1')
	{
		WriteEmptyLineInConsole();
		for (int i = 0; i < length; i++)
		{
			UserInput(&m);
			WriteDataToFile(m, "data.txt");
		}
	}
	else if (answer == '2')
	{
		for (int i = 0; i < length; i++)
		{
			RandomInput(&m);
			WriteDataToFile(m, "data.txt");
		}
	}
	else if (answer == '3')
	{
		WriteEmptyLineInConsole();
		UserInput(&m);
		AddTextAtTheBeginningOfTheFile(m, "data.txt");
	}
	else if (answer == '4')
	{
		UserInput(&m);
		WriteDataToFile(m, "data.txt");
	}
	else if (answer == '5')
	{
		WriteEmptyLineInConsole();
		if (HowManyRecordsAreInTheFile("data.txt") != 0)
		{
			FindLineInFileAndWriteItToConsole();
			WriteEmptyLineInConsole();
		}
		else
		{
			cout << "В файле нет записей. Пожалуйста сначала запишите что-нибудь в файл" << '\n';
		}
	}
	else if (answer == '6')
	{
		WriteEmptyLineInConsole();
		if (HowManyRecordsAreInTheFile("data.txt") != 0)
		{
			ReadAllLinesFromFileAndWriteThemInToConsole();
		}
		else
		{
			cout << "В файле нет записей. Пожалуйста сначала запишите что-нибудь в файл" << '\n';
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

void CreateFileForData(string fileName)
{
	ofstream StreamWriter(fileName);
	StreamWriter.close();
}

void StartTask()
{
	srand(time(0));

	SetRussianLanguage();

	CreateFileForData("data.txt");

	char answer;
	do
	{
		ShowMenu();
		WriteEmptyLineInConsole();
		answer = GetAnswerFromUser();
		if (answer < '7')
		{
			CompleteItemSelectedByUser(answer);
			PrintLine(40);
			WriteEmptyLineInConsole();
		}
	} while (answer != '7');
}