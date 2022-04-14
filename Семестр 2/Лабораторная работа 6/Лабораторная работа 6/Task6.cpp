#include "Task6.h"
#include <iostream>
#include <windows.h>

using namespace std;

void ShowRulesOfInput()
{
	cout << "Правила ввода:\n";
	cout << "1. Можно вводить буквы латинского алфавита\n";
	cout << "2. Можно вводить буквы кирилицы\n";
	cout << "3. Регистр ввода не имеет значения, то есть можно вводить как заглавные так и строчные буквы\n";
	cout << "4. Буквы латинского алфавита будут заменяться на буквы кирилицы и наоборот, с сохранением регистра\n";
	cout << "5. Ввод любых символов запрещен, в случае их ввода, ваша строка будет заменена на аналогичную строку, но без символов\n\n";
}

void GetInputFromUser(char* word)
{
	cout << "Ввод > ";
	cin.getline(word, 256);
	cout << "\n";
}

void MoveAllNextSymbolsOneBack(char* word, int lengthOfWord, int currentIndex)
{
	for (int i = currentIndex; i < lengthOfWord - 1; i++)
	{
		*(word + i) = *(word + i + 1);
	}
	*(word + lengthOfWord - 1) = NULL;
}

bool CheckIfSymbolIsABigLetterFromEnglishAlphabet(char symbol)
{
	int int_symbol = (int)symbol;

	if (int_symbol >= 65 && int_symbol <= 90)
	{
		return true;
	}

	return false;
}

bool CheckIfSymbolIsASmallLetterFromEnglishAlphabet(char symbol)
{
	int int_symbol = (int)symbol;

	if (int_symbol >= 97 && int_symbol <= 122)
	{
		return true;
	}

	return false;
}

//bool CheckIfSymbolIsABigLetterFromRussianAlphabet(char symbol)
//{
//	int int_symbol = (int)symbol;
//
//	if (int_symbol >= 192 && int_symbol <= 223)
//	{
//		return true;
//	}
//	else if (int_symbol == 168)
//	{
//		return true;
//	}
//
//	return false;
//}

bool CheckIfSymbolIsABigLetterFromRussianAlphabet(char symbol)
{
	int int_symbol = (int)symbol;

	if (int_symbol >= -64 && int_symbol <= -33)
	{
		return true;
	}

	return false;
}

//bool CheckIfSymbolIsASmallLetterFromRussianAlphabet(char symbol)
//{
//	int int_symbol = (int)symbol;
//
//	if (int_symbol >= 224 && int_symbol <= 255) 
//	{
//		return true;
//	}
//	else if (int_symbol == 184)
//	{
//		return true;
//	}
//
//	return false;
//}

bool CheckIfSymbolIsASmallLetterFromRussianAlphabet(char symbol)
{
	int int_symbol = (int)symbol;

	if (int_symbol >= -32 && int_symbol <= -1)
	{
		return true;
	}

	return false;
}

bool CheckIfSymbolFromLatOrKirAlphabet(char symbol)
{
	if (CheckIfSymbolIsABigLetterFromEnglishAlphabet(symbol))
	{
		return true;
	}
	else if (CheckIfSymbolIsASmallLetterFromEnglishAlphabet(symbol))
	{
		return true;
	}
	else if (CheckIfSymbolIsABigLetterFromRussianAlphabet(symbol))
	{
		return true;
	}
	else if (CheckIfSymbolIsASmallLetterFromRussianAlphabet(symbol))
	{
		return true;
	}

	return false;
}

char changeToBigRussianLetter(char letter)
{
	return (char)(rand() % 32 + 192);
}

char changeToSmallRussianLetter(char letter)
{
	return (char)(rand() % 32 + 224);
}

char changeToBigEnglishLetter(char letter)
{
	return (char)(rand() % 26 + 65);
}

char changeToSmallEnglishLetter(char letter)
{
	return (char)(rand() % 26 + 97);
}

char ChangeLetterOfOneAlphabetToAnother(char letter)
{
	if (CheckIfSymbolIsABigLetterFromEnglishAlphabet(letter))
	{
		return changeToBigRussianLetter(letter);
	}
	else if (CheckIfSymbolIsASmallLetterFromEnglishAlphabet(letter))
	{
		return changeToSmallRussianLetter(letter);
	}
	else if (CheckIfSymbolIsABigLetterFromRussianAlphabet(letter))
	{
		return changeToBigEnglishLetter(letter);
	}
	else if (CheckIfSymbolIsASmallLetterFromRussianAlphabet(letter))
	{
		return changeToSmallEnglishLetter(letter);
	}

	return NULL;
}

void CompleteTask6(char* word, int* lengthOfWord)
{
	for (int i = 0; i < *lengthOfWord; i++)
	{
		if (!CheckIfSymbolFromLatOrKirAlphabet(*(word + i)))
		{
			if (*(word + i) != ' ')
			{
				MoveAllNextSymbolsOneBack(word, *lengthOfWord, i);
				i--;
				*lengthOfWord -= 1;
			}
		}
		else
		{
			*(word + i) = ChangeLetterOfOneAlphabetToAnother(*(word + i));
		}
	}
}

int GetLengthOfUsersInput(char* word)
{
	int length = 0;
	int i = 0;
	while (*(word + i) != '\0')
	{
		length++;
		i++;
	}

	return length;
}

void StartTask()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));

	char* word = new char[256];

	ShowRulesOfInput();

	GetInputFromUser(word);
	int lengthOfWord = GetLengthOfUsersInput(word);
	CompleteTask6(word, &lengthOfWord);
	cout << "Результат: " << word << "\n";

	delete[] word;
	word = nullptr;
}