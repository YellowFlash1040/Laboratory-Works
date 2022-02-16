#include <iostream>
#include <chrono>

using namespace std;

void SortArray(double array[], int lengthOfArray)
{
    int indexOfMinElement;

    double temp;
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

double FindAverage(double array[], int sizeOfArray)
{
    double sum = 0;
    for (int i = 0; i < sizeOfArray; i++)
    {
        sum += array[i];
    }
    return sum / (double)sizeOfArray;
}

void ReturnTheArrayToItsInitialState(int  array[], int size, int  copyOfArray[])
{
    for (int j = 0; j < size; j++)
    {
        array[j] = copyOfArray[j];
    }
}

void TruncateArray(double array[], int sizeOfArray, double trancatedArray[], int sizeOfTrancatedArray)
{
    int start = (sizeOfArray - sizeOfTrancatedArray) / 2;
    int end = sizeOfArray - start;
    for (int i = start, j = 0; i < end; i++, j++)
    {
        trancatedArray[j] = array[i];
    }
}

int main()
{
    srand(time(0));

    int size = 45;
    int array[45];
    int copyOfArray[45];


    int count = 100;

    int timeOfFirstMethod_Length = count;
    double timeOfFirstMethod[100];

    int timeOfSecondMethod_Length = count;
    double timeOfSecondMethod[100];


    for (int i = 0; i < size; i++)
    {
        //array[i] = i;
        //array[i] = 99 - i;
        array[i] = rand() % 100;
       
        copyOfArray[i] = array[i];
    }

    for (int i = 0; i < count; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        PancakeSort(array, size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        timeOfFirstMethod[i] = duration.count();

        ReturnTheArrayToItsInitialState(array, size, copyOfArray);
    }

    for (int i = 0; i < count; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        CountingSort(array, size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        timeOfSecondMethod[i] = duration.count();

        ReturnTheArrayToItsInitialState(array, size, copyOfArray);
    }

    //cout << "Ordered array\n";
    //cout << "Array in reverse order\n";
    cout << "Unordered array\n";
    cout << "Size of array: " << size << "\n";

    int sizeOfFirstTrancatedArray = 10;
    double FirstTruncatedArray[10];
    SortArray(timeOfFirstMethod, timeOfFirstMethod_Length);
    TruncateArray(timeOfFirstMethod, timeOfFirstMethod_Length, FirstTruncatedArray, sizeOfFirstTrancatedArray);

    double firstTime = FindAverage(FirstTruncatedArray, sizeOfFirstTrancatedArray);
    printf("Average time of pancake sort method = %.8lf\n", firstTime);

    int sizeOfSecondTrancatedArray = 10;
    double SecondTruncatedArray[10];
    SortArray(timeOfSecondMethod, timeOfSecondMethod_Length);
    TruncateArray(timeOfSecondMethod, timeOfSecondMethod_Length, SecondTruncatedArray, sizeOfSecondTrancatedArray);

    double secondTime = FindAverage(SecondTruncatedArray, sizeOfSecondTrancatedArray);
    printf("Average time of counting sort method= %.8lf\n\n", secondTime);
}