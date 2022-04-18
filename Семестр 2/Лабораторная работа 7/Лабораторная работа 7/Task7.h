#pragma once

#include "Task2.h"
#include <iostream>

using namespace std;

void ShowMenu();
char GetAnswerFromUser();
void WriteDataToFile(mon m, string filePath);
void WriteEmptyLineToFile(string filePath);
void WriteEmptyLineInConsole();
void GetDataFromLine(string line, mon& m);
void RemoveFile(string filePath);
void RenameFile(string OldFileName, string NewFileName);
void AddTextAtTheBeginningOfTheFile(mon m, string filePath);
int HowManyRecordsAreInTheFile(string filePath);
int GetNumberOfLineFromUser();
void FindLineInFileAndWriteItToConsole();
void ReadAllLinesFromFileAndWriteThemInToConsole();
void CompleteItemSelectedByUser(char answer);
void PrintLine(int sizeOfLine);
void CreateFileForData(string fileName);
void StartTask();