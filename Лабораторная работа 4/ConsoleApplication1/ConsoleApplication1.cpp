#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int c;
	int f; 
	int b;
	int n;
	unsigned int UnitStateWord;
	 
	printf("Введите код состояния (0 - 31) >");
	int first_scan = scanf("%d", &c);
	printf("Введите признак ошибки (0 / 1) >");
	int second_scan = scanf("%d", &f);
	printf("Введите признак занятости (0 / 1) >");
	int third_scan = scanf("%d", &b);
	printf("Введите количество переданных байт (0 - 255) >");
	int firth_scan = scanf("%d", &n);
	
	UnitStateWord = ((unsigned int)c & 0x1F) << 11;
	UnitStateWord |= ((unsigned int)f & 1) << 9;
	UnitStateWord |= ((unsigned int)b & 1) << 8;
	UnitStateWord |= n & 0xFF;
	
	printf("\nСлово состояния устройства = %04x\n", UnitStateWord);

	///////////////////////////////////////////////////////////////////////////////////////////

	printf("Введите cлово состояния устройства \n");
	printf("(16-ричное число от 0 до 0xFFFF) >");
	int fifth_scan = scanf("%x", &UnitStateWord);
	
	c = (UnitStateWord >> 11) & 0x1F;
	f = (UnitStateWord >> 9) & 1;
	b = (UnitStateWord >> 8) & 1;
	n = UnitStateWord & 0xFF;
	
	putchar('\n');
	printf("Код состояния = %d\n", c);
	printf("Признак ошибки = %d\n", f);
	printf("Признак занятости = %d\n", b);
	printf("Количество переданных байт = %d\n", n);
}
