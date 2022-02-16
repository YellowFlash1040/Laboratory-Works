#include <iostream>

using namespace std;

void TenthTask(int array[], int lengthOfTheArray)
{
	//Create matrix
	int length = sqrt(lengthOfTheArray);
	int** matrix = new int* [length];

	//Converting array to the matrix
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		matrix[i] = new int[length];
		for (int j = 0; j < length; j++)
		{
			matrix[i][j] = array[index];
			index++;
		}
	}

	//Outputting the matrix to the console
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			/*cout << matrix[i][j] << " ";*/
			printf("%2d ", matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl << "=>" << endl;
	cout << endl;

	//Completing the tenth task
	int IndexOfMaxElementInColumn;
	for (int j = 0; j < length; j++)
	{
		IndexOfMaxElementInColumn = 0;
		for (int i = 1; i < length; i++)
		{
			if (matrix[i][j] > matrix[IndexOfMaxElementInColumn][j])
			{
				IndexOfMaxElementInColumn = i;
			}
		}
		int maxElementInColumn = matrix[IndexOfMaxElementInColumn][j];
		for (int i = 0; i < length; i++)
		{
			matrix[i][j] += maxElementInColumn;
		}
	}

	//Outputting the resultMatrix
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			/*cout << matrix[i][j] << " ";*/
			printf("%2d ", matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl << "=>" << endl;
	cout << endl;

	//Converting resultMatrix to the resultArray
	int ind = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			array[ind] = matrix[i][j];
			ind++;
		}
	}

	//Freeing memory
	for (int i = 0; i < length; i++)
	{
		delete[]matrix[i];
		matrix[i] = nullptr;
	}
	delete[]matrix;
	matrix = nullptr;
}


int main()
{
	srand(time(0));

	int sqrtOflengthOfArray = rand() % 4 + 2;
	int length = sqrtOflengthOfArray * sqrtOflengthOfArray;

	//Initializing the array
	int* array = new int[length];
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 11;
	}

	//Outputting the array to the console
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n\n" << "=>" << "\n\n";

	//Call the tenth task function and fill array
	TenthTask(array, length);

	//Outputting the result array
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n\n";

	//Freeing memory
	delete[]array;
	array = nullptr;
}