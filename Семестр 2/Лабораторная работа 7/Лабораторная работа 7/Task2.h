#pragma once

struct mon
{
	char name[15];
	char type;
	int square;
	int urozhaj;
};

void UserInput(mon* m);
void RandomInput(mon* m);
void SetRussianLanguage();