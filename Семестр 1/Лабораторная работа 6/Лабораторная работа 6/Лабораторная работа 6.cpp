#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <math.h> 

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    long n;
    double dbln;
    double sum = 0;
    double term;
    const double eps = 0.000001;
    short k1 = 1;

    for (n = 0; ; n++, k1 = -k1)
    {

        dbln = n;

        double two_dbln = dbln * dbln;

        term = k1 * (dbln + 1) / (two_dbln * dbln - two_dbln + 1);

        if (fabs(term) >= eps)
        {
            sum += term;
        }

        else
        {
            break;
        }

        if (n == 9)
        {
            printf("Сумма 10 членов ряда = %10.7lf\n", sum);
        }
    }

    printf("Полная сумма ряда = %10.7lf\n", sum);

    return 0;
}