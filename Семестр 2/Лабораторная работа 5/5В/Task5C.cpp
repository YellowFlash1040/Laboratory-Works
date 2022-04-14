#include "Task5C.h"
#include <iostream>

using namespace std;

void BubbleSort(int array[], int lengthOfArray)
{
    int indexOfMinElement;

    int temp;
    for (int i = 0; i < lengthOfArray; i++)
    {
        indexOfMinElement = i;
        for (int j = i + 1; j < lengthOfArray; j++)
        {
            if (array[j] < array[indexOfMinElement])
            {
                indexOfMinElement = j;
            }
        }
        temp = array[i];
        array[i] = array[indexOfMinElement];
        array[indexOfMinElement] = temp;
    }
}

void PancakeSort(int array[], int length)
{
    int IndexOfMaxElementInArray;
    for (int i = length; i > 1; i--)
    {
        IndexOfMaxElementInArray = 0;
        for (int j = i - 1; j > 0; j--)
        {
            if (array[j] > array[IndexOfMaxElementInArray])
            {
                IndexOfMaxElementInArray = j;
            }
        }

        if (IndexOfMaxElementInArray == i - 1)
        {
            continue;
        }

        int temp;
        int index = i;
        for (int j = IndexOfMaxElementInArray; j < --index; j++)
        {
            temp = array[j];
            array[j] = array[index];
            array[index] = temp;
        }
    }
}

void CountingSort(int array[], int lengthOfArray)
{
    int min = array[0];
    int max = array[0];
    for (int i = 1; i < lengthOfArray; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }

        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int length = 100;
    int AllVariantsOfNumbersInTheArrayThatCameToTheFunction[100];
    for (int i = 0; i < length; i++)
    {
        AllVariantsOfNumbersInTheArrayThatCameToTheFunction[i] = 0;
    }

    for (int i = 0; i < lengthOfArray; i++)
    {
        AllVariantsOfNumbersInTheArrayThatCameToTheFunction[array[i] - min]++;
    }

    int i = 0;
    for (int j = 0; j < length; j++)
    {
        while (AllVariantsOfNumbersInTheArrayThatCameToTheFunction[j] != 0)
        {
            array[i] = min + j;
            AllVariantsOfNumbersInTheArrayThatCameToTheFunction[j]--;
            i++;
        }
    }
}

void SortArray(int* array, int length, int (*ChoosesortMethod)())
{
    int numberOfMethod = ChoosesortMethod();
    if (numberOfMethod == 1)
    {
        cout << "Choosed method: Bubble sort\n";
        BubbleSort(array, length);
    }
    else if (numberOfMethod == 2)
    {
        cout << "Choosed method: Pancake sort\n";
        PancakeSort(array, length);
    }
    else if (numberOfMethod == 3)
    {
        cout << "Choosed method: Counting sort\n";
        CountingSort(array, length);
    }
}

int ChooseMethod()
{
    return rand() % 3 + 1;
}

void StartTask()
{
    srand(time(0));

    int length = rand() % 11 + 4;
    int* array = new int[length];
    cout << "Generated array: ";
    for (int i = 0; i < length; i++)
    {
        *(array + i) = rand() % 11;
        cout << *(array + i) << " ";
    }
    cout << "\n";

    SortArray(array, length, ChooseMethod);

    cout << "Sorted array: ";
    for (int i = 0; i < length; i++)
    {
        cout << *(array + i) << " ";
    }
    cout << "\n";
}