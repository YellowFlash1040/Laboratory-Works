#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    int number = 0;
    char answer = 'y';
    int userInput = 0;
    do
    {
        number = rand() % 100;
        printf("Компьютер загадал число от 0 до 100. Теперь ваша задача угадать его : \n", number);
        printf("Введите число > ");
        int first_scan = scanf("%d", &userInput);
        while (userInput != number)
        {
            printf("\n");
            if (userInput < number)
            {
                printf("Больше\n");
            }
            else
            {
                printf("Меньше\n");
            }
            printf("\n");
            printf("Введите число > ");
            first_scan = scanf("%d", &userInput);
        }

        printf("\n");
        printf("Поздравляю! Вы угадали!\n");

        printf("Хотите сыграть еще раз? (y/n) > ");
        cin >> answer;
        printf("\n");
    } while (answer == 'y');
}