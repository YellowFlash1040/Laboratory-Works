#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double a, b, c;
    char answer = 'y';
    do
    {
        printf("Введите значение коэффициента \'a\' > ");
        int first_scan = scanf("%lf", &a);
        printf("Введите значение коэффициента \'b\' > ");
        int second_scan = scanf("%lf", &b);
        printf("Введите значение коэффициента \'c\' > ");
        int third_scan = scanf("%lf", &c);

        printf("\n");

        double discriminant = b * b - 4 * a * c;
        if (discriminant >= 0)
        {
            double sqrt_discriminant = sqrt(discriminant);
            double x1 = (-b + sqrt_discriminant) / (2 * a);
            double x2 = (-b - sqrt_discriminant) / (2 * a);

            if (x1 == x2)
            {
                printf("Заданное уравнение имеет единственное решение : x = %lf\n", x1);
            }
            else
            {
                printf("Заданное уравнение имеет два решения : x1 = %lf; x2 = %lf\n", x1, x2);
            }
        }
        else
        {
            printf("Заданное уравнение не имеет решений\n");
        }
        printf("\n");
        printf("Хотите ввести значения еще раз? (y/n) > ");
        cin >> answer;
        printf("\n\n");
    } while (answer == 'y');

    return 0;
}