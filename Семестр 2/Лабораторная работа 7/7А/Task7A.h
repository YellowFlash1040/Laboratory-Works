#pragma once

#include <string>

using namespace std;

void WriteArrayInToTheFile(int* array, int length, string filePath);
int GetCountOfNumbersInLine(string filePath, int numberOfLine);
int* ReadArrayFromFile(string filePath);
void PrintArray(int* array, int length);
void StartTask();
