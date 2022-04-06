#include <windows.h>
#include <iostream>

using namespace std;

//#define WriteUsersInput
//#define DEBUG
#define WriteResultOfProgramWork

int* FindNegativeElements(int* array, int lengthOfArray, int* lengthOfResultArray)
{
    *lengthOfResultArray = 0;
    for (int i = 0; i < lengthOfArray; i++)
    {
        if (*(array+i) < 0)
        {
            *lengthOfResultArray += 1;
        }
    }

    int* resultArray = new int[*lengthOfResultArray];
    for (int i = 0, index = 0; i < lengthOfArray; i++)
    {
        if (*(array + i) < 0)
        {
            *(resultArray + index) = *(array + i);
            index++;
        }
    }

    return resultArray;
}

int* FindPositiveElements(int* array, int lengthOfArray, int* lengthOfResultArray)
{
    *lengthOfResultArray = 0;
    for (int i = 0; i < lengthOfArray; i++)
    {
        if (*(array + i) > 0)
        {
            *lengthOfResultArray += 1;
        }
    }

    int* resultArray = new int[*lengthOfResultArray];
    for (int i = 0, index = 0; i < lengthOfArray; i++)
    {
        if (*(array + i) > 0)
        {
            *(resultArray + index) = *(array + i);
            index++;
        }
    }

    return resultArray;
}

int* FindZeroElements(int* array, int lengthOfArray, int* lengthOfResultArray)
{
    *lengthOfResultArray = 0;
    for (int i = 0; i < lengthOfArray; i++)
    {
        if (*(array + i) == 0)
        {
            *lengthOfResultArray += 1;
        }
    }

    int* resultArray = new int[*lengthOfResultArray];
    for (int i = 0, index = 0; i < lengthOfArray; i++)
    {
        if (*(array + i) == 0)
        {
            *(resultArray + index) = *(array + i);
            index++;
        }
    }

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

void StartTask()
{
    srand(time(0));

    SetConsoleOutputCP(1251);

    int lengthOfArray = GenerateRandomSizeOfArray();
    int* array = new int[lengthOfArray];

    //cout << "Введите длину массива > ";
    //cin >> lengthOfArray;

    cout << "Длина массива = " << lengthOfArray << "\n";
    cout << "Массив: ";
    for (int i = 0; i < lengthOfArray; i++)
    {
        *(array + i) = GenerateRandomNumberFromMinusNinetyNineToNinetyNine();
        cout << *(array + i) << " ";
    }
    cout << "\n";

    /*cout << "Введите массив целых чисел через пробел > ";
    for (int i = 0; i < lengthOfArray; i++)
    {
        cin >> *(array + i);
    }*/

#ifdef WriteUsersInput
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
#endif // WriteUsersInput

    int lengthOfNegativeElementsArray;
    int* negativeElementsArray = FindNegativeElements(array, lengthOfArray, &lengthOfNegativeElementsArray);

#ifdef DEBUG
    for (int i = 0; i < lengthOfNegativeElementsArray; i++)
    {
        cout << negativeElementsArray[i] << " ";
    }
    cout << "\n";
#endif // DEBUG


    int lengthOfPositiveElementsArray;
    int* positiveElementsArray = FindPositiveElements(array, lengthOfArray, &lengthOfPositiveElementsArray);

#ifdef DEBUG
    for (int i = 0; i < lengthOfPositiveElementsArray; i++)
    {
        cout << positiveElementsArray[i] << " ";
    }
    cout << "\n";
#endif // DEBUG

    int lengthOfZeroElementsArray;
    int* zeroElementsArray = FindZeroElements(array, lengthOfArray, &lengthOfZeroElementsArray);

#ifdef DEBUG
    for (int i = 0; i < lengthOfZeroElementsArray; i++)
    {
        cout << zeroElementsArray[i] << " ";
    }
    cout << "\n";
#endif // DEBUG

    int index = 0;
    for (int a = 0; a < lengthOfZeroElementsArray; a++, index++)
    {
        *(array + index) = *(zeroElementsArray + a);
    }
    for (int b = 0; b < lengthOfNegativeElementsArray; b++, index++)
    {
        *(array + index) = *(negativeElementsArray + b);
    }
    for (int c = 0; c < lengthOfPositiveElementsArray; c++, index++)
    {
        *(array + index) = *(positiveElementsArray + c);
    }

#ifdef WriteResultOfProgramWork
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << "\n";
#endif // WriteResultOfProgramWork
}