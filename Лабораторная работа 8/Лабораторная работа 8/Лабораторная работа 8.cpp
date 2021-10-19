#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

using namespace std;

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Array[200];
    int Array_Length = 200;

    srand(time(0));

    for (int i = 0; i < Array_Length; i++)
    {
        Array[i] = rand() % 101;
    }

    //Создаем массив numbers и инициализируем его
    int numbers[200];
    for (int i = 0; i < Array_Length; i++)
    {
        numbers[i] = -777;
    }
    
    //Находим все варианты чисел массива Array и записываем их в numbers
    int index = 0;
    int countOfPluses = 0;
    for (int i = 0; i < Array_Length; i++)
    {
        for (int j = 0; j < Array_Length; j++)
        {
            if (Array[i] == numbers[j])
            {
                break;
            }
            else
            {
                countOfPluses++;
            }
        }
        if (countOfPluses == Array_Length)
        {
            numbers[index] = Array[i];
            index++;
        }
        countOfPluses = 0;
    }

    //Сортируем все члены массива numbers от найбольшего к найменьшему
    for (int i = 0; i < 200; i++)
    {
        int indexOfMax = i;
        int temp = 0;
        for (int j = i; j < 200; j++)
        {
            if (numbers[j] > numbers[indexOfMax])
            {
                temp = numbers[indexOfMax];
                numbers[indexOfMax] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    int thirdByHeightValue = numbers[2];

    printf("Начальный массив:\n");
    for (int i = 0; i < Array_Length; i++)
    {
        printf("%3d  ", Array[i]);
    }
    printf("\n\n");


    for (int i = 0; i < 200; i++)
    {
        if (Array[i] > thirdByHeightValue)
        {
            Array[i] = thirdByHeightValue;
        }
    }

    printf("Массив-результат:\n");
    for (int i = 0; i < Array_Length; i++)
    {
        printf("%3d  ", Array[i]);
    }
    printf("\n\n");

    return 0;
}