#pragma once

void ShowRulesOfInput();
void GetInputFromUser(char* word);
void MoveAllNextSymbolsOneBack(char* word, int lengthOfWord, int currentIndex);
bool CheckIfSymbolIsABigLetterFromEnglishAlphabet(char symbol);
bool CheckIfSymbolIsASmallLetterFromEnglishAlphabet(char symbol);
bool CheckIfSymbolIsABigLetterFromRussianAlphabet(char symbol);
bool CheckIfSymbolIsASmallLetterFromRussianAlphabet(char symbol);
bool CheckIfSymbolFromLatOrKirAlphabet(char symbol);
char changeToBigRussianLetter(char letter);
char changeToSmallRussianLetter(char letter);
char changeToBigEnglishLetter(char letter);
char changeToSmallEnglishLetter(char letter);
char ChangeLetterOfOneAlphabetToAnother(char letter);
void CompleteTask6(char* word, int* lengthOfWord);
int GetLengthOfUsersInput(char* word);
void StartTask();