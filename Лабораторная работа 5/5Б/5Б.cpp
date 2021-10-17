#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int k;
    char answer = 'y';

    do
    {
        printf("Введите число k > ");
        int first_scan = scanf("%d", &k);

        int number = k % 100;
        int secondNumber = number % 10;

        printf("\nРезультат : ");

        if (number >= 5 && number <= 20)
        {
            printf("У меня %d грибов", k);
        }
        else if (secondNumber == 1)
        {
            printf("У меня %d гриб", k);
        }
        else if (secondNumber >= 2 && secondNumber <= 4)
        {
            printf("У меня %d гриба", k);
        }
        else
        {
            printf("У меня %d грибов", k);
        }

        printf("\n\n");
        printf("Хотите ввести значение k еще раз? (y/n) > ");
        cin >> answer;
        printf("\n\n");
    } while (answer == 'y');

    return 0;
}
