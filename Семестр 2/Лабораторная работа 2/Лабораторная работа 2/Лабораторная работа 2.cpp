#include "Task1.h"
#define PRINT_TYPE

#include <iostream>
using namespace std;

int main(void)
{
	SetRussianLanguage();

#ifdef PRINT_TYPE
	ShowMenuWithOnlyUserInput();
#else
	ShowMenuWithOnlyRandomInput();
#endif

	return 0;
}