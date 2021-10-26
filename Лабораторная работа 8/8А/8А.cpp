#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>

using namespace std;

enum Status
{
    Свободно,
    Забронировано
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Status places[10];

    //Second Variant
    char answer[4];

    //First Variant
    //string answer;

    int countOfFreePlacesInFirstPart = 0;
    int countOfFreePlacesInSecondPart = 0;
    do
    {
        printf("Курите? > ");

        //Second Variant
        int first_scan = scanf("%s", answer);
         
        //First Variant
        //cin >> answer;

        if(strcmp(answer, "да") == 0)
        { 
        /*if (answer == "да")
        {*/
            if (countOfFreePlacesInFirstPart != 5)
            {
                places[countOfFreePlacesInFirstPart] = Забронировано;
                countOfFreePlacesInFirstPart++;
                printf("Вы забронировали %d место. Приятного полета.\n\n", countOfFreePlacesInFirstPart);
                

                if (countOfFreePlacesInFirstPart + countOfFreePlacesInSecondPart == 10)
                {
                    break;
                }
            }
            else
            {
                if (countOfFreePlacesInFirstPart + countOfFreePlacesInSecondPart == 10)
                {
                    break;
                }
                else
                {
                    printf("Извините в этом секторе все места уже заняты.\n");
                    printf("Попробуйте сесть в другом :\n");
                }
            }
        }
        else if (strcmp(answer, "нет") == 0)
        {
        /*else if (answer == "нет")
        {*/
            if (countOfFreePlacesInSecondPart != 5)
            {
                places[countOfFreePlacesInSecondPart] = Забронировано;
                countOfFreePlacesInSecondPart++;
                printf("Вы забронировали %d место. Приятного полета.\n\n", countOfFreePlacesInSecondPart + 5);

                if (countOfFreePlacesInFirstPart + countOfFreePlacesInSecondPart == 10)
                {
                    break;
                }
            }
            else
            {
                if (countOfFreePlacesInFirstPart + countOfFreePlacesInSecondPart == 10)
                {
                    break;
                }
                printf("Извините в этом секторе все места уже заняты.\n");
                printf("Попробуйте сесть в другом :\n");
            }
        }
        else
        {
            printf("Не корректный ввод. Пожалуйста повторите попытку :\n");
        }
    } while (countOfFreePlacesInFirstPart + countOfFreePlacesInSecondPart != 10);

    printf("Все места забронированы. Мы готовы взлетать.");
    printf("\n\n\n");
}