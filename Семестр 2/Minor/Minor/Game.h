#pragma once

#include <iostream>

struct Game
{
	int** Pitch;
	int widthOfPitch;
	int heightOfPitch;
	int countOfBombs;

	int countOfOpenedCells;
	int countOfCellsThatNeedToOpen;

	int* placesOfBombs;

	bool gameOver;

	int countOfFlags;

	Game()
	{
		gameOver = false;
		countOfBombs = 10;
		countOfFlags = countOfBombs;
		heightOfPitch = 10;
		widthOfPitch = 10;
		countOfOpenedCells = 0;
		countOfCellsThatNeedToOpen = heightOfPitch * widthOfPitch - countOfBombs;
		Pitch = new int* [heightOfPitch];
		for (int i = 0; i < heightOfPitch; i++)
		{
			Pitch[i] = new int[widthOfPitch];
			for (int j = 0; j < widthOfPitch; j++)
			{
				Pitch[i][j] = 0;
			}
		}

		srand(time(0));

		int lengthOfArray = heightOfPitch * widthOfPitch;
		int* arr = new int[lengthOfArray];
		for (int i = 0; i < lengthOfArray; i++)
		{
			arr[i] = i + 1;
		}
		Shuffle(arr, lengthOfArray);
		placesOfBombs = new int[countOfBombs];

		//
		for (int i = 0; i < countOfBombs; i++)
		{
			placesOfBombs[i] = 0;
		}
		//

		for (int i = 0; i < countOfBombs; i++)
		{
			placesOfBombs[i] = arr[i];
		}

		arr = nullptr;

		PlantTheBombs(placesOfBombs);

		FILE* pitchFile = fopen("pitchFile.txt", "w");
		char* pitchInStringForm = ToString();
		int lengthOfText = 0;
		while (pitchInStringForm[lengthOfText] != '\0')
		{
			lengthOfText++;
		}
		fwrite(pitchInStringForm, 1, lengthOfText, pitchFile);
		fclose(pitchFile);
		pitchFile = nullptr;
	}

	void PlantTheBombs(int* placesOfBombs) 
	{
		for (int i = 0; i < countOfBombs; i++)
		{
			int x = (placesOfBombs[i] - 1) / (heightOfPitch);
			int y = (placesOfBombs[i] - 1) % (widthOfPitch);
			Pitch[x][y] = 9;
			PlaceNumbersAroundTheBomb(x, y);
		}
	}

	void Shuffle(int* arr, int lengthOfArr)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int i = 0; i < lengthOfArr; i++)
			{
				int indexOfFirstRandomCell = rand() % lengthOfArr;
				int indexOfSecondRandomCell = rand() % lengthOfArr;
				int temp = arr[indexOfFirstRandomCell];
				arr[indexOfFirstRandomCell] = arr[indexOfSecondRandomCell];
				arr[indexOfSecondRandomCell] = temp;
			}
		}
	}

	//void PlaceNumbersAroundTheBomb(int x, int y)
	//{
	//	if (x > 0 && x < widthOfPitch)
	//	{
	//		if (y > 0 && y < heightOfPitch)
	//		{
	//			Pitch[x - 1][y - 1]++;//Слева сверху
	//			Pitch[x][y - 1]++;//Сверху
	//			Pitch[x + 1][y - 1]++;//Справа сверху
	//			Pitch[x - 1][y]++;//Слева
	//			Pitch[x + 1][y]++;//Справа
	//			Pitch[x - 1][y + 1]++;//Слева снизу
	//			Pitch[x][y + 1]++;//Снизу
	//			Pitch[x + 1][y + 1]++;//Справа снизу
	//		}
	//		else if (y == 0)
	//		{
	//			Pitch[x - 1][y]++;//Слева
	//			Pitch[x + 1][y]++;//Справа
	//			Pitch[x - 1][y + 1]++;//Слева снизу
	//			Pitch[x][y + 1]++;//Снизу
	//			Pitch[x + 1][y + 1]++;//Справа снизу
	//		}
	//		else
	//		{
	//			Pitch[x - 1][y - 1]++;//Слева сверху
	//			Pitch[x][y - 1]++;//Сверху
	//			Pitch[x + 1][y - 1]++;//Справа сверху
	//			Pitch[x - 1][y]++;//Слева
	//			Pitch[x + 1][y]++;//Справа
	//		}
	//	}
	//	else if (x == 0)
	//	{
	//		if (y > 0 && y < heightOfPitch)
	//		{
	//			Pitch[x][y - 1]++;//Сверху
	//			Pitch[x + 1][y - 1]++;//Справа сверху
	//			Pitch[x + 1][y]++;//Справа
	//			Pitch[x][y + 1]++;//Снизу
	//			Pitch[x + 1][y + 1]++;//Справа снизу
	//		}
	//		else if (y == 0)
	//		{
	//			Pitch[x + 1][y]++;//Справа
	//			Pitch[x][y + 1]++;//Снизу
	//			Pitch[x + 1][y + 1]++;//Справа снизу
	//		}
	//		else
	//		{
	//			Pitch[x][y - 1]++;//Сверху
	//			Pitch[x + 1][y - 1]++;//Справа сверху	
	//			Pitch[x + 1][y]++;//Справа
	//		}
	//	}
	//	else
	//	{
	//		if (y > 0 && y < heightOfPitch)
	//		{
	//			Pitch[x - 1][y - 1]++;//Слева сверху
	//			Pitch[x][y - 1]++;//Сверху
	//			Pitch[x - 1][y]++;//Слева
	//			Pitch[x - 1][y + 1]++;//Слева снизу
	//			Pitch[x][y + 1]++;//Снизу
	//		}
	//		else if (y == 0)
	//		{
	//			Pitch[x - 1][y]++;//Слева	
	//			Pitch[x - 1][y + 1]++;//Слева снизу
	//			Pitch[x][y + 1]++;//Снизу
	//		}
	//		else
	//		{
	//			Pitch[x - 1][y - 1]++;//Слева сверху
	//			Pitch[x][y - 1]++;//Сверху
	//			Pitch[x - 1][y]++;//Слева
	//		}
	//	}
	//}

	void PlaceNumbersAroundTheBomb(int x, int y)
	{
		int minX = x == 0 ? 0 : x - 1;
		int minY = y == 0 ? 0 : y - 1;
		int maxX = x == heightOfPitch - 1 ? heightOfPitch - 1 : x + 1;
		int maxY = y == widthOfPitch - 1 ? widthOfPitch - 1 : y + 1;

		for (int i = minX; i <= maxX; i++)
		{
			for (int j = minY; j <= maxY; j++)
			{
				if (i != x || j != y)
				{
					if (Pitch[i][j] != 9)
					{
						Pitch[i][j]++;
					}
				}
			}
		}
	}

	char* ToString()
	{
		int lengthOfText = 3 * heightOfPitch * widthOfPitch;
		char* text = new char[lengthOfText];
		for (int i = 0; i < lengthOfText; i++)
		{
			text[i] = NULL;
		}
		int indexOfText = 0;
		char* bufer = new char[3];

		for (int i = 0; i < heightOfPitch; i++)
		{
			for (int j = 0; j < widthOfPitch; j++)
			{
				itoa(Pitch[i][j], bufer, 10);
				int index = 0;
				while (bufer[index] != '\0')
				{
					text[indexOfText] = bufer[index];
					indexOfText++;
					index++;
				}
				for (index = 0; index < 2; index++)
				{
					bufer[index] = NULL;
				}
				text[indexOfText] = ' ';
				indexOfText++;
			}
			text[indexOfText] = '\n';
			indexOfText++;
		}

		delete[] bufer;
		bufer = nullptr;

		return text;
	}
};
