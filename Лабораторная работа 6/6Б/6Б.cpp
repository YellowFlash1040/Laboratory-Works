#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    int first_number = 0;
    int second_number = 0;
    char answer = 'y';
    int userInput = 0;

    printf("Сейчас мы проверим ваши знания таблицы умножения.\n");
    printf("Вам будет предоставлено десять примеров для решения и в итоге после анализа ваших ответов,\nвам будет выставлена оценка от 1 до 12.\n");
    printf("Итак. Поехали : \n\n");

    int first_scan;
    int sum = 0;

    do
    {
        for (int i = 1; i < 11; i++)
        {
            first_number = rand() % 10 + 1;
            second_number = rand() % 10 + 1;

            printf("%d. %d x %d = ", i, first_number, second_number);
            first_scan = scanf("%d", &userInput);

            if (userInput == first_number * second_number)
            {
                sum++;
            }
        }

        printf("\n");
        printf("Ваш результат %d/12", (int)round(sum * 12 / 10.0));
        sum = 0;

        printf("\n\n");
        printf("Хотите попробовать еще раз? (y/n) > ");
        cin >> answer;
        printf("\n\n");
    } while (answer == 'y');
}