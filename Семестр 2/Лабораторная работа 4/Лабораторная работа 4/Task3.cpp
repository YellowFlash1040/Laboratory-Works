#include <iostream>
#include <windows.h>

using namespace std;

#define WriteResultOfProgramWork

int* FindFirstMaxNumbersInArray(int* array, int lengthOfArray)
{
    int* copyOfArray = new int[lengthOfArray];
    int lengthOfCopyOfArray = lengthOfArray;
    for (int i = 0; i < lengthOfArray; i++)
    {
        *(copyOfArray + i) = *(array + i);
    }

    int* resultArray = new int[3];
    for (int i = 0; i < 3; i++)
    {
        int indexOfMaxElement = i;
        for (int j = i + 1; j < lengthOfCopyOfArray; j++)
        {
            if (*(copyOfArray + j) > *(copyOfArray + indexOfMaxElement))
            {
                indexOfMaxElement = j;
            }
        }
        int temp = *(copyOfArray + i);
        *(copyOfArray + i) = *(copyOfArray + indexOfMaxElement);
        *(copyOfArray + indexOfMaxElement) = temp;
    }
    for (int i = 0; i < 3; i++)
    {
        *(resultArray + i) = *(copyOfArray + i);
    }

    delete[] copyOfArray;

    return resultArray;
}

int GenerateRandomSizeOfArray()
{
    return rand() % 31;
}

int GenerateRandomNumberFromMinusNinetyNineToNinetyNine()
{
    int symbol = rand() % 2;
    if (symbol == 0)
    {
        return rand() % 100;
    }

    return -rand() % 100;
}

int* FillArray(int lengthOfArray)
{
    int* array = new int[lengthOfArray];
    for (int i = 0; i < lengthOfArray; i++)
    {
        *(array + i) = GenerateRandomNumberFromMinusNinetyNineToNinetyNine();
    }

    return array;
}

void StartTask()
{
    srand(time(0));

    SetConsoleOutputCP(1251);

    int lengthOfArray = GenerateRandomSizeOfArray();
    cout << "Длина массива = " << lengthOfArray << "\n";
    cout << "Массив: ";
    int* array = FillArray(lengthOfArray);
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << "\n";

    int* resultArray = FindFirstMaxNumbersInArray(array, lengthOfArray);

#ifdef WriteResultOfProgramWork
    for (int i = 0; i < 3; i++)
    {
        cout << *(resultArray + i) << " ";
    }
    cout << "\n";
#endif // WriteResultOfProgramWork

    delete[] array;
    delete[] resultArray;
}