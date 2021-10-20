#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

using namespace std;

int main(void)
{
    //Даем возможность консоли выводить и принимать русский текст правильно
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Объявляем наш массив
    int Array[200];
    //Создаем переменную которая будет хранить его длину
    int Array_Length = 200;

    //Создаем настоящий генератор случайных чисел, задавая его свойство srand текущем количеством секунд в системных часах
    srand(time(0));

    //Заполняем наш массив случайными числами в диапазоне от 0 до 100
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

    int thirdByHeightValue = numbers[2]; // Переменная хранящая значение третьего по величине елемента массива

    // Выводим на екран наш массив (начальный)
    printf("Начальный массив:\n");
    for (int i = 0; i < Array_Length; i++)
    {
        printf("%3d  ", Array[i]);
    }
    printf("\n\n");

    // Меняем значения всех элементов массива, которые превышают thirdByHeightValue, на thirdByHeightValue
    for (int i = 0; i < 200; i++)
    {
        if (Array[i] > thirdByHeightValue)
        {
            Array[i] = thirdByHeightValue;
        }
    }

    //Выводим видоизмененный массив
    printf("Массив-результат:\n");
    for (int i = 0; i < Array_Length; i++)
    {
        printf("%3d  ", Array[i]);
    }
    printf("\n\n");

    return 0;
}