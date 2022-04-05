#include <iostream>
#include <windows.h>

using namespace std;

//#define WriteUsersInput
#define WriteResultOfProgramWork

int* FindFirstMaxNumbersInArray(int* array, int lengthOfArray)
{
    int* copyOfArray = new int[lengthOfArray];
    int lengthOfCopyOfArray = lengthOfArray;
    for (int i = 0; i < lengthOfArray; i++)
    {
        copyOfArray[i] = array[i];
    }

    int* resultArray = new int[3];
    for (int i = 0; i < 3; i++)
    {
        int indexOfMaxElement = i;
        for (int j = i + 1; j < lengthOfCopyOfArray; j++)
        {
            if (copyOfArray[j] > copyOfArray[indexOfMaxElement])
            {
                indexOfMaxElement = j;
            }
        }
        int temp = copyOfArray[i];
        copyOfArray[i] = copyOfArray[indexOfMaxElement];
        copyOfArray[indexOfMaxElement] = temp;
    }
    for (int i = 0; i < 3; i++)
    {
        resultArray[i] = copyOfArray[i];
    }

    delete[] copyOfArray;

    return resultArray;
}
void StartTask()
{
    SetConsoleOutputCP(1251);

    int lengthOfArray;
    cout << "¬ведите длину массива > ";
    cin >> lengthOfArray;
    int* array = new int[lengthOfArray];
    cout << "¬ведите массив целых чисел через пробел > ";
    for (int i = 0; i < lengthOfArray; i++)
    {
        cin >> array[i];
    }

#ifdef WriteUsersInput
    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
#endif // WriteUsersInput

    int* resultArray = FindFirstMaxNumbersInArray(array, lengthOfArray);

#ifdef WriteResultOfProgramWork
    for (int i = 0; i < 3; i++)
    {
        cout << resultArray[i] << " ";
    }
    cout << "\n";
#endif // WriteResultOfProgramWork

    delete[] array;
    delete[] resultArray;
}