#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char answer = 'y';

    do
    {
        int number = 0;
        printf("Введите число > ");
        int first_scan = scanf("%d", &number);
        int stepen = 0;
        int result = 0;
        int tenInStepen = 1;
        do
        {
            stepen++;
            tenInStepen = pow(10, stepen);
            result = number % tenInStepen;
        } while (result != number);


        int firstNumber = stepen % 100;
        int secondNumber = stepen % 10;

        if (firstNumber >= 5 && firstNumber <= 20)
        {
            printf("\nВ вашем числе %d цифр\n", stepen);
        }
        else if (secondNumber == 1)
        {
            printf("\nВ вашем числе %d цифра\n", stepen);
        }
        else if (secondNumber >= 2 && secondNumber <= 4)
        {
            printf("\nВ вашем числе %d цифры\n", stepen);
        }
        else
        {
            printf("\nВ вашем числе %d цифр\n", stepen);
        }

        int sum = 0;
        int ten = 1;
        int* arrayOfNumbers = new int[stepen];
        for (int i = 1; i <= stepen; i++)
        {
            ten = pow(10, i);
            int num = number % ten / (ten / 10);
            sum += num;
            arrayOfNumbers[i - 1] = num;
        }
        printf("Сумма цифр введенного числа равна %d\n", sum);
        printf("Введенное вами число наоборот это : ");
        for (int i = 0; i < stepen; i++)
        {
            printf("%d", arrayOfNumbers[i]);
        }
        printf("\n");


        printf("\nХотите ввести число еще раз?\n");
        printf("Ваш ответ (y/n) > ");
        cin >> answer;
        printf("\n");
    } while (answer == 'y');
}
