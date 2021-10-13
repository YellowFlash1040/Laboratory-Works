#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <iostream>

using namespace std;

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x, y;
    char answer = 'y';

    do
    {
        printf("Введите координату x > ");
        scanf("%lf", &x);
        printf("Введите координату y > ");
        scanf("%lf", &y);

        printf("x=%6.3lf;  y=%6.3lf\n\n", x, y);

        printf("Ответ : ");
        if ((x >= -1 && x <= 0 && y >= -1 && y <= 0) || (x >= 0 && x <= 1 && y >= -1 && y <= 1))
        {
            printf("Точка попадает в область\n\n");
        }
        else
        {
            printf("Точка не попадает в область\n\n");
        }

        printf("Хотите попробовать ввести значения еще раз (y/n) > ");
        cin >> answer;
        printf("\n");
    } while (answer == 'y');
    printf("\n\n");

    return 0;
}