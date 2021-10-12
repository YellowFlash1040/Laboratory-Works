#define _CRT_SECURE_NO_WARNINGS
/**************************************************/
/*            Лабораторная работа ╧3              */
/*       Арифметические выражения и функции       */
/*         Пример решения. Вариант ╧30.           */
/**************************************************/
#include <stdio.h>
#include <math.h>
#include <windows.h>

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/* параметры, которые вводятся */
	double x, y;
	/* параметры, которые задаются в программе */
	double a = 2, b = 3;
	double t1, t2;   /* результаты */
	double tg_ax_2, a_1;       /* рабочая переменная */

	printf("Введите x, y > ");
	int resultOfScanF = scanf("%lf %lf", &x, &y);

	t1 = (log(y/x)- a*a*x*x/(2*y*y))/(b*b*b);

	tg_ax_2 = tan(((a*x/2)*3.14/180)); //tg_ax_2 = tan(a*x/2);
	a_1 = 1 / a;
	t2 = a_1*tg_ax_2 + a_1*log(tg_ax_2);

	printf("t1 = %lg\n", t1);
	printf("t2 = %lg\n", t2);
	return 0;
}