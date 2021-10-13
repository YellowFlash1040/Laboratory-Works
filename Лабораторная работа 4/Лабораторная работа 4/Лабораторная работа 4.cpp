#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int g = ' ';
	int s = ' ';
	int p = ' ';
	unsigned int UserProfileElementInAComputingSystem;

	printf("Введите идентификатор группы, к которой притнадлежит пользователь (0 - 255) > ");
	int first_scan = scanf("%d", &g);
	printf("Введите код системы, которая загружается для пользователя (0 - 15) > ");
	int second_scan = scanf("%d", &s);
	printf("Введите признак привилегированного пользователя (0 / 1) > ");
	int third_scan = scanf("%d", &p);

	UserProfileElementInAComputingSystem = ((unsigned int)g & 0xFF) << 8;
	UserProfileElementInAComputingSystem |= ((unsigned int)s & 0xF) << 4;
	UserProfileElementInAComputingSystem |= ((unsigned int)p & 0x1) << 3;

	printf("\nЭлемент профиля пользователя в вычислительной системе = %0x\n", UserProfileElementInAComputingSystem);

	return 0;
}