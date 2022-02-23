#pragma once

#include <iostream>
using namespace std;

struct mon;

void ShowMenu();
void UserInput(mon mm[10], int& length);
void RandomInput(mon mm[10], int& length);
void PrintTable(mon mm[10], int length);
void SortArray(mon mm[10], int length);
void SetRussianLanguage();
void ShowMenuWithOnlyUserInput();
void ShowMenuWithOnlyRandomInput();
void PrintCurrentTimeAndDate();
void PrintCurrentFileNameAndFunctionName(string FunctionName);